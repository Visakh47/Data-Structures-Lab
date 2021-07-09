//DLL
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int coeff;
	int exp;
	struct node *link;
}*first1=NULL,*first2=NULL;

int n1;//for the number of coeffs in list 1
int n2;//for list 2
int count;

void create()
{
	struct node ptr=(struct node)malloc(sizeof(struct node));
	struct node cpt=(struct node)malloc(sizeof(struct node));
	
	//entering the coeffs
	printf("Enter the coefficient:");
	scanf("%d",&ptr->coeff);
	printf("Enter the exponent:");
	scanf("%d",&ptr->exp);
	printf("\n");
	//storing elements in list 1
	if(count==1)
	{
		if(first1==NULL)
		{
			
			first1=ptr;
			ptr->link=NULL;
			ptr->prev=NULL;
		}
		else
		{
			cpt=first1;
			while(cpt->link!=NULL)
			cpt=cpt->link;
			cpt->link=ptr;
			ptr->prev=cpt;
			ptr->link=NULL;
		}
	}
	//storing elements in list 2
	if(count==2)
	{
		if(first2==NULL)
		{
			
			first2=ptr;
			ptr->link=NULL;
			ptr->prev=NULL;
		}
		else
		{
			cpt=first2;
			while(cpt->link!=NULL)
			cpt=cpt->link;
			cpt->link=ptr;
			ptr->prev=cpt;
			ptr->link=NULL;
		}
	}
}

void PolyAdd()
{
	struct node ptr1=(struct node)malloc(sizeof(struct node));
	
	ptr1=first1;
	//comparing each element of list 1 with list 2
	while(ptr1!=NULL)
	{
		int ch;//counter variable 
		struct node ptr2=(struct node)malloc(sizeof(struct node));
		struct node cpt2=(struct node)malloc(sizeof(struct node));
		
		ptr2=first2;
		//comparing each element of list 2 with the particular one from list 1
		while(ptr2!=NULL)
		{
			ch=0;
			if(ptr2->exp==ptr1->exp)
			{
				ptr1->coeff=ptr1->coeff+ptr2->coeff;
				ch=1;
			}
			
			if(ch==1)
			{
				//when the element from list 2 is in the first position
				if(ptr2==first2)
				{
					first2=ptr2->link;
					ptr2->link=NULL;
					ptr2->prev=NULL;
					free(ptr2);
					break;
				}
				//when the element from list 2 is in the end
				else if(ptr2->link==NULL)
				{
					cpt2=first2;
					while(cpt2->link!=ptr2)
					cpt2=cpt2->link;
					
					cpt2->link=NULL;
					ptr2->link=NULL;
					ptr2->prev=NULL;
					free(ptr2);
					break;
				}
				//when the element from list 2 is in the middle
				else
				{
					struct node ptr=(struct node)malloc(sizeof(struct node));
					
					cpt2=first2;
					while(cpt2!=ptr2)
					{
						ptr=cpt2;
						cpt2=cpt2->link;
					}
					cpt2=ptr2->link;
					ptr->link=cpt2;
					cpt2->prev=ptr;
					ptr2->link=NULL;
					ptr2->link=NULL;
					free(ptr2);
					break;
				}
			}
			
			ptr2=ptr2->link;
		}
		ptr1=ptr1->link;
	}
}


void Display()
{
	struct node ptr1=(struct node)malloc(sizeof(struct node));
	struct node ptr2=(struct node)malloc(sizeof(struct node));
	
	ptr1=first1;
	ptr2=first2;
	
	printf("The final expression:");
	while(ptr1!=NULL)
	{
		printf("%dx^%d",ptr1->coeff,ptr1->exp);
		ptr1=ptr1->link;
		if(ptr1!=NULL)
			printf("+");
	}
	if(ptr2!=NULL)
	printf("+");
	while(ptr2!=NULL)
	{
		printf("%dx^%d",ptr2->coeff,ptr2->exp);
		ptr2=ptr2->link;
		if(ptr2!=NULL)
			printf("+");
	}
	
	printf("\n");
}


void main()
{
	int i;
	printf("Enter the number of terms for expression 1:\n");
	scanf("%d",&n1);
	printf("Enter the respective values for each terms in expression 1\n");
	for(i=0;i<n1;i++)
	{
		count=1;
		create();
	}
	printf("Enter the number of terms for expression 2:\n");
	scanf("%d",&n2);
	printf("Enter the respective values for each terms in expression 2\n");
	for(i=0;i<n2;i++)
	{
		count=2;
		create();
	}
	PolyAdd();
	Display();
	printf("The End\n");
}