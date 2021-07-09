#include<stdio.h>

//Structure

struct node {
	int info;
	struct node*link;
}*first = NULL;


void InsertBeg(int uinfo){
	
	struct node *ptr = (struct node*) malloc(sizeof(struct node*);
	if(first==NULL)
	{
		first = ptr;
		ptr->info = uinfo;
		ptr->link = NULL;
	}
	else{
		ptr->info=uinfo;
		ptr->link= first;
		first=ptr;
	}
}


void PrintLL(){
	struct node *ptr = (struct node*) malloc(sizeof(struct node*);
	if(first==NULL)
	{
		printf("No element present inside linked list\n")
		return;
	}
	ptr= first;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->info);
		ptr = ptr->link;
	}
}

void main(){

InsertBeg(10);
InsertBeg(20);
InsertBeg(30);
InsertBeg(40);
InsertBeg(50);
PrintLL();

}