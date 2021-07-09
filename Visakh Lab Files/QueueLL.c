//Visakh B - S3R2 - 34- Program to implement Queue using linked list

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node {
				int info;
				struct node * link;
             }*front=NULL,*rear=NULL,*ptr;
			 
void AddQ(int uinfo)
{	
	//read info from user and store
	struct node* rear = (struct node*) malloc(sizeof(struct node));
	rear->info = uinfo;
	rear->link = NULL;
	if(front==NULL)
	{	front = rear;
		ptr = rear;
		
	}
	else
	{
		ptr->link = rear;
		ptr=rear; //moves to next node
	}
		
}


void DelQ()
{
	if(front==NULL)
	{	printf("Underflow No element Present inside Linked List\n");
		return;
	}
	else
	{
		printf("Element Deleting\n");
		ptr=front;
		int dinfo = ptr->info;
		front = ptr->link;
		ptr->link = NULL;
		free(ptr);
		printf("Element %d has been deleted\n",dinfo);
	}
}


void DisplayQ()
{
	if(front == NULL)
	{
		printf("Underflow\n");
		return;
	}
	else
	{	printf("The Queue Elements Are :\n");
		struct node *ptr = (struct node*) malloc(sizeof(struct node));
		ptr = front;
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->info);
			ptr=ptr->link;
		}
		printf("\n");
	}
}

void main()
{
	/*(AddQ(10);
	AddQ(20);
	AddQ(30);
	AddQ(40);
	AddQ(50);
	DisplayQ();
	DelQ();
	DelQ();
	DisplayQ(); 
	*/
	int choice,uinfo;
	while(1)
	{
		
		printf("Enter A Choice: 1. Insert To Queue , 2. Delete From Queue , 3. Display Queue , 4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : printf("Enter the Element to be Inserted to Queue\n");
					 scanf("%d",&uinfo); 
					 AddQ(uinfo);
					 break;
			
			case 2 : DelQ();
					 break;
			
			case 3 : DisplayQ();
					 break;

			case 4 : exit(0);
			
			default : printf("Invalid Choice , Try Again\n");
					  break;
		
		}
			
		
	}
}

	
			
		
		
		