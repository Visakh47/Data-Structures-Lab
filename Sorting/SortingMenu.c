//Visakh B - S3R2 - 34- Program to implement selection,bubble and insertion sort


#include<stdio.h>
#include<stdlib.h>

int i,j;

void BubbleSort(int A[] , int N)
{
	int temp;
	for(i=0;i<N-1;i++)
	{
		for(j=0;j<N-1-i;j++)
		{
			if(A[j] > A[j+1])
			{
				temp = A[j];
				A[j]  = A[j+1];
				A[j+1] = temp;
			}
		}
	}
	
	printf("Array After Bubble Sort :\n"); 
	//Displaying 
	for(i=0;i<N;i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\n");
	
}

void SelectionSort(int A[] , int N)
{
	int min,temp,loc;
	for(i=0;i<N;i++)
	{
		min = A[i]; //setting minimum as the first value
		loc = i;
		for(j=i+1;j<N;j++)
		{
			if(A[j]<min)
			{
				min = A[j];
				loc = j;
			}
		}
		//Swapping after determining the minimum value
		temp = A[i];
		A[i] = A[loc];
		A[loc] = temp;
	}
	//Printing
	printf("Array After Selection Sort :\n");
	for(i=0;i<N;i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\n");
	
}

void InsertionSort(int A[] , int N)
{
	int key;
	for(i=1;i<N;i++)
	{
		key = A[i];
		j=i-1;
		
		while(j>=0 && A[j] >key) //A[j] here refers to the previous element , if previous element is greater - then it changes the current element with previous element 
			//Predessor checking goes on till A[j] > key & till j reaches 0.
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key; //if above condition is false , then j never gets decremented 
	}
	printf("Array After Insertion Sort :\n");
	for(i=0;i<N;i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\n");
	
}

void Display(int A[],int N)
{	
	printf("The Array Is:\n");
	for(i=0;i<N;i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\n");
}

void main()
{
	int A[50],N,ch;
	
	printf("Enter the Number of elements:");
	scanf("%d",&N);
	printf("Enter an Array:\n");
	for(i=0;i<N;i++)
		scanf("%d",&A[i]);
	
	printf(" Sorting Menu :\n");
	printf("1.Insertion Sort \n2.Bubble Sort\n3.Selection Sort\n4.Display\n5.Exit\n");
	printf("Enter Your Choice:\n");
	scanf("%d",&ch);
	
	while(ch<=4)
	{
		switch(ch)
		{
			case 1 : InsertionSort(A,N);
					 break;

			case 2 : BubbleSort(A,N);
					 break;
			
			case 3 : SelectionSort(A,N);
					 break;
			
			case 4 : Display(A,N);
					 break;
		}
			
		printf("Enter Your Choice Again :\n");
		scanf("%d",&ch);
	}
	
}

	