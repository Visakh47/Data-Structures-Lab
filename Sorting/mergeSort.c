//program to perform merge sorting on a given array - Visakh B - S3R2 - 34

#include<stdio.h>

//Declaring arrays as global
int a[50] , b[50]; //a --> array to be sorted , b--> temporary array 

void merge(int l,int mid , int h)
{
	int i,j,k;
	i=l; //first split array counter
	j=mid+1; //second split array counter
	k=l; //temp array counter
	
	while(i<=mid && j<=h)
	{
		if(a[i]<=a[j])
			b[k++] = a[i++];
		else  // a[j] < a[i]
			b[k++] = a[j++]; //post increment of values after assignment 
	}
	
	//assigning remaining elements to temp array
	
	if(i>mid) //remaining elements in second sublist --> first traversed 
	{
		while(j<=h)
			b[k++] = a[j++];
	}
	else // i< mid --> remaining elements in first sublist --> second traversed
	{
		while(i<=mid)
			b[k++] = a[i++]; 
	}
	
	for(k=l;k<=h;k++)
		a[k] = b[k]; // copying sorted elements into original array
}

void mergeSort(int l , int h)
{	int mid; 
	if(l<h)
	{
		mid = (l+h)/2;
		mergeSort(l,mid);
		mergeSort(mid+1,h);
		merge(l,mid,h);
	}
}

void main()
{
	int n,i;
	printf("Enter the number of elements in array :\n");
	scanf("%d",&n);
	printf("Enter the elements in the array :\n");
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	mergeSort(0,n-1);
	printf("Array After MergeSort : \n");
	for(i=0;i<n;i++)
		printf("%d\t", a[i]);
}
			
