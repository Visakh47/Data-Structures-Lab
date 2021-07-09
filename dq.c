#include<stdio.h>
#include<stdlib.h>

int DQ[100],F=-1, R=-1,N;

void InsertFromRear(int item){

//Check 
	if(F==0 && R==N-1 || F==R+1)
	{
		printf("Underflow\n");
		return;
	}
	
	if(R==N-1)
		R=0;
	else 
		R=R+1;
	
	DQ[R] = item;
	printf("%d has been inserted\n",item);
	if(F==-1)
		F=0;
	
}

void DeleteFromFront(){

//check
	if(F==-1){
	printf("Underflow\n");
	return;
	}
	
	printf("%d has been deleted\n", DQ[F]);
	
	if(F==R)
		F=R=-1;
	else if(F==N-1)
		F=0;
	else 
		F++;
	
	
}


//Extra operations 

void DeleteFromRear(){

	if(R==-1){
		printf("Underflow\n");
		return;
	}
	
	printf("%d has been deleted\n", DQ[R]);
	
	if(F==R)
		F=R=-1;
	else if(R==0)
		R=N-1;
	else 
		R--;
}


void InsertFromFront(int item){
	
	if(F==0 && R==N-1 || F==R+1)
	{
		printf("Underflow\n");
		return;
	}
	
	if(F==-1) //No element
		F=R=0;
	else if(F==0)
		F=N-1;
	else 
		F--;
	
	DQ[F] = item;
	
	printf("%d has been inserted\n",item);
}
	
}