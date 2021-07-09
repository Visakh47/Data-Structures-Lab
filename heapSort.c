#include<stdio.h>

int temp;

void createHeap(int a[] , int n , int i)
{
	int root = i; // root position
	int left = 2*i+1; //left child postion
	int right = 2*i+2; //right child
	
	if(left<n && a[left] > a[root]) //changing root , if left is greater than root
		root = left;
	
	if(right <n && a[right] > a[root]) //changing root , if right is greater than root
		root = right;
	
	if(root!=i)
	{
		//swapping largest element and current root , if root is no longer the largest 
		temp = a[i];
		a[i] = a[root];
		a[root] = temp;
		createHeap(a,n,root);	//recursive
	}
}

void heapSort(int a[],int n)
{
	int i;
	//For Step 1: Create A Heap 
	for(i = (n/2)-1;i>=0;i--)
		createHeap(a,n,i); 
	
	// Step 2: Removing element one by one from heap and the constantly creating heap with remaining elements 
	for(i = n-1 ; i>=0 ;i--)
		{ 
			temp = a[i];
			a[i] = a[0];
			a[0] = temp;
			createHeap(a,i,0);
		}
}

void main()
{
	int a[50];
	int i,n;
	
	printf("Enter The No of Elements :\n");
	scanf("%d",&n);
	
	printf("Enter the Array Elements : \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	heapSort(a,n);
	printf("Array After Heap Sort :\n");
	
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
	