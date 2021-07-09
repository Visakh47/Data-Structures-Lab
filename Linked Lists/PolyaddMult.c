#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int coeff;
	int exp;
	struct Node* next;
};

void readPolynomial(struct Node** poly)
{
	int coeff, exp, ch;
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	*poly = ptr;
	do{
		printf("\n Coeffecient: ");
		scanf("%d", &coeff);
		printf("\n Exponent: ");
		scanf("%d", &exp);
		ptr->coeff = coeff;
		ptr->exp = exp;
		ptr-> next = NULL;
		printf("\nHave more terms? 1 for y and 0 for no: ");
		scanf("%d", &ch);
		if(ch)
		{
			ptr->next = (struct Node*)malloc(sizeof(struct Node));
			ptr = ptr->next;
			ptr->next = NULL;
		}
	}while(ch);	
}

void displayPolynomial(struct Node* polyres)
{
	printf("\nPolynomial expression is: ");
	while(polyres != NULL)
	{
		printf("%dX^%d", polyres->coeff, polyres->exp);
		polyres = polyres->next;
		if(polyres != NULL)
			printf("+");
	}
}

void addPoly(struct Node** polyres, struct Node* first1, struct Node* first2)
{
 	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
 	ptr->next = NULL;
 	*polyres = ptr;
 	while(first1!=NULL && first2!=NULL)
 	{
 		if(first1->exp > first2->exp)
 		{
 			ptr->coeff = first1->coeff;
 			ptr->exp = first1->exp;
 			first1 = first1->next;
 		}
 		else if(first1->exp < first2->exp)
 		{
 			ptr->coeff = first2->coeff;
 			ptr->exp = first2->exp;
 			first2 = first2->next;
 		}
 		else
 		{
 			ptr->coeff = first1->coeff + first2->coeff;
 			ptr->exp = first1->exp;
 			first1 = first1->next;
 			first2 = first2->next;
 		}

 		if(first1!=NULL && first2!=NULL)
 		{
 			ptr->next = (struct Node*)malloc(sizeof(struct Node));
 			ptr = ptr->next;
 			ptr->next = NULL;
 		}
 	}
 	while(first1!=NULL || first2!=NULL)
 	{
 		ptr->next = (struct Node*)malloc(sizeof(struct Node));
 		ptr = ptr->next;
 		ptr->next = NULL;
 			
 		if(first1!=NULL)
 		{
 			ptr->coeff = first1->coeff;
 			ptr->exp = first1->exp;
 			first1 = first1->next;
 		}

 		else if(first2!=NULL)
 		{
 			ptr->coeff = first2->coeff;
 			ptr->exp = first2->exp;
 			first2 = first2->next;
 		}
 	}
}

int main()
{

	struct Node* first1 = NULL;
	struct Node* first2 = NULL;
	struct Node* polyres = NULL;
	printf("Enter The:-\n");
	printf("First polynomial:\n");
	readPolynomial(&first1);
	displayPolynomial(first1);
	printf("\nSecond polynomial:\n");
	readPolynomial(&first2);
	displayPolynomial(first2);
  printf("\n");
	addPoly(&polyres, first1, first2);
  printf("Final Resultant - ");
	displayPolynomial(polyres);
	return 0;
}