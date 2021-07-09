//Sparse Matrix 

#include<stdio.h>
#include<stdlib.h>

void sparse(int A[10][10] , int m , int n) {
	int S[10][10];
	int i,j,k=1 ; //for counting no of rows
	S[0][0]  = m ;
	S[0][1] = n;
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			if(A[i][j] != 0) 
			{
				S[k][0] = i;
				S[k][1] = j;
				S[k][2] = A[i][j];
				k++;
			}
		}
	}
	k = k-1;
	S[0][2] = k;
	
	printf("Rows\tCol\tVal\n");
	for( i=0;i<=k;i++) {
		for(j=0;j<3;j++) {
			printf("%d\t",S[i][j]);
		}
		printf("\n");
	}
}



void main() {
	int A[10][10],i,j,m,n;
	printf("Enter the number of rows and columns\n");
	scanf("%d%d",&m,&n);
	printf("Enter the values:");
	for( i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			scanf("%d",&A[i][j]);
		}
	}
	sparse(A,m,n);
}