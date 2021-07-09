//Stack Program 
#include<stdio.h>
int top;
int Stack[100];

void PUSH(int Stack[],int max)
{ int item; 
 if(top>=max)
	printf("Stack Overflow, no element can be inserted.\n");
  else 
  {  printf("Enter item to be inserted:\n");
      scanf("%d",&item);
	  top++;
	  Stack[top] = item;
  }
}

void POP(int Stack[])
{
	if(top==-1)
		printf("Stack Underflow , no element to be deleted\n");
	else
	{ 
      int item= Stack[top];
	  top--;
	  printf("Element %d is deleted from stack\n",item );
	}
}

void Display(int Stack[])
{   if(top==-1)
    printf("Stack is empty\n");
	else 
	{
	printf("The elements in stack are:\n");
	printf("%d <- Top\n", Stack[top]);
	for(int i=top-1 ; i>=0 ; i--)
	printf("%d\n",Stack[i]);
    }
}

void main()
{   
    top=-1;//top at -1 means no element is present 
	int Max;
	int ch;
	printf("Enter the maximum number of elements:");
	scanf("%d",&Max);

  		
	 printf("Enter choice:\n");
	 printf("1.PUSH\n");
	 printf("2.POP\n");
	 printf("3.DISPLAY\n");
	 scanf("%d",&ch);
	 while(ch >= 1 && ch <=3)
   {
	 
		switch(ch)
		{
			case 1 : PUSH(Stack,Max);
					 break;
			case 2 : POP(Stack);
					 break;
			case 3 : Display(Stack); 
					 break;
			default : printf("INVALID Choice\n");
		 }
	 
	 printf("Enter another choice from 1-3 1.PUSH\t 2.POP\t 3.Display\t 4.Exit\n");
	 scanf("%d",&ch);
  }
}
	
	
	

	