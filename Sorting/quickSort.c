//Visakh B - S3R2 - 34- Program to implement Quick Sort
#include <stdio.h>

int i,j;
int parition(int A[],int l, int h) //l=low , h=high
{	int temp;
	int pivot = A[l];
	i=l;j=h;
	while(i<j)
	{
		do{
			i++;
		} while(A[i]<=pivot);
		
		do{
			j--;
		} while(A[j]>pivot) ;
		
		if(i<j)
		{	//Swap A[i] & A[j]
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
		
	}
	//Swapping A[l] and A[j]
	temp = A[l];
	A[l] = A[j];
	A[j] = temp;
	return j;
}

void quickSort(int a[],int l,int h)
{
	if(l<h)
	{
		j=parition(a,l,h);
		quickSort(a,l,j);
		quickSort(a,j+1,h);
	}
}

void main()
{
	int a[50],n;
	printf("Enter The Size Of The Array:\n");
	scanf("%d",&n);
	printf("Enter The Array:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quickSort(a,0,n);
	printf("The Array After Quick Sort:\n");
	for(int i =0;i<n ;i++)
	printf("%d\t",a[i]);
}
	