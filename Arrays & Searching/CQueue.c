//Program to Implement Circular Queue


#include<stdio.h>
#include<stdlib.h>

int F=-1,R=-1; //Front and Rear end of Circular Queue is initialized to value -1.
int N;
int CQ[100];

void CQInsert(int item)
{
	//Insertion from the Rear End	

	
	if(F==0 && R==N-1|| F==R+1 )
	{
		printf("Circular Queue Overflow , no element can be inserted\n");
		return;
	}
	if( F==-1 )// if queue is empty & element is inserted for the first time 
	{
		F=R=0;
	}
	else if(R==N-1) // Rear is at the end
	R=0; 
	else		
	R=R+1;
	CQ[R] = item;
	printf("Element %d is inserted to Circular Queue\n",item);
	//if first element is being entered , initialize F=0 from F=-1 as CQ is not empty anymore
	
}

void CQDel()
{
	//Deletion From The Front End.
	
	if(F==-1)
	{
		printf("Circular Queue Underflow , No Element Is Present \n");
		return; 
	}
	
	printf("Element %d is deleted from Circular Queue\n",CQ[F]);
	if(F==R) //both the F & R at the same position , only one element is there in the array
	F=R=-1;
	else if(F==N-1)
	F=0; //reset to first space.
	else 
	F=F+1;
	
}

void CQPrint()
{  
	if(F==-1) 
	{
		printf("Circular Queue Underflow , No element present inside Queue\n");
		return;
	}
	printf("The Ciucular Queue Elements:\n");
	if(R>F)
	{
		for(int i=F;i<=R;i++)
		printf("%d\t",CQ[i]);
	}
	else 
	{
		for(int i=F;i<=N-1;i++)
		printf("%d\t",CQ[i]);
		for(int i=0;i<=R;i++)
		printf("%d\t",CQ[i]);
	}
	printf("\n");
}

void main()
{
	int Item;//element to be inserted
	int ch=1;

	printf("Enter the Maximum Number Of Elements\n");
	scanf("%d",&N);
	while(ch>=1 && ch<=3)
	{  
		printf("Enter your choice:\n");


		printf("1. Circular Queue Insert\n");
		printf("2. Circular Queue Delete\n");
		printf("3. Circular Queue Display\n");
		printf("4. Exit\n");

		scanf("%d" , &ch);

		switch(ch)
		{
		case 1 : printf("Enter the item to be inserted\n");
			scanf("%d" , &Item);
			CQInsert(Item);
			break;
			
		case 2 : CQDel();
			break;
			
		case 3 : CQPrint();
			break;
			
		case 4 : exit(0);
			
			default : printf("Invalid choice\n");
			
		}
		
		
	}
} //end of void main







