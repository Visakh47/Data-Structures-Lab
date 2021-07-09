// Program to Represent A Sparse Matrix in a tabular form - Visakh Bobby - 43 - S3R2

#include<stdio.h>
void sparse(int a[10][10],int m,int n)
{
  int i,j;
  int s[10][10];
  int k=1; //used to detemine the number of rows (n values)that's supposed to be there
  // 1 st row of sparse matrix is supposed to give the number of (rows , columns and values).
  s[0][0] = m; //no of rows
  s[0][1] = n; //no of columns
 for(i=0;i<m;i++)
  { 
 for(j=0;j<n;j++)
  {   
    if(a[i][j] != 0)
	{  
     s[k][0] =  i;
	 s[k][1] = j;
     s[k][2] = a[i][j];
	 k++;
	}
  }
  }
  k=k-1; //no of values : it starts at k=1 , that's why , we have to do subtract 1. 
  s[0][2] = k; //no of values assigned to 1st row ,3rd col element
 
//printing the sparse matrix 
printf("The Sparse Matrix is Represented as follows\n");

printf("Row\tCol\tVal\n");

     for(i=0;i<=k;i++)
		{
			for(j=0;j<3;j++) //no of columns in a sparse matrix representation is 3. 
			{
				printf("%d\t",s[i][j]);
			}
		printf("\n");
		}


}

void main()
{
	int a[10][10];
	int m,n,i,j;
	printf("Enter the maximum no of rows & columns\n");
	scanf("%d%d",&m,&n);
	printf("Enter the 2D array:");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		printf(" Element [%d][%d]: ",i,j);
		scanf("%d",&a[i][j]);
	    }
	}
	sparse(a,m,n);
}


		
    
	
	
	
	