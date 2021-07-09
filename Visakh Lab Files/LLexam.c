#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node {
	int info;
	struct node* next;
}*first=NULL;

void addBeg(int uinfo) {
	struct node *ptr = (struct node*) malloc(sizeof(struct node));
	ptr->info = uinfo;
	if(first == NULL)
	{
		first = ptr;
		ptr->next = NULL;
	}
	else 
	{
		ptr->next = first;
		first = ptr;
	}
}

void addEnd(int uinfo)
{
	struct node *ptr = (struct node*) malloc(sizeof(struct node));
	ptr->info = uinfo;
	if(first == NULL)
	{
		first = ptr;
		ptr->next = NULL;
	}
	else{
		struct node* cpt;
		cpt = first;
		while(cpt->next!=NULL) {
			cpt = cpt->next;
		}
		cpt->next = ptr;
		ptr->next = NULL;
	}
}

void addBtw(int uinfo, int btwinfo) {
	struct node* ptr = (struct node*) malloc(sizeof(struct node));
	ptr->info = uinfo;
	if(first == NULL)
	{
		first = ptr;
		ptr->next = NULL;
	}
	struct node* cpt;
	cpt = first;
	while(cpt->info!=btwinfo)
		cpt = cpt->next;
	ptr->next = cpt->next;
	cpt->next = ptr;
}

void delBeg() {
	if(first == NULL)
		return;
	struct node* ptr = (struct node*) malloc(sizeof(struct node));
	struct node* cpt = (struct node*) malloc(sizeof(struct node));
	ptr = first;
	first = first->next;
	ptr->next = NULL;
}

void delEnd() {
	if(first == NULL)
		return;
	struct node* ptr = (struct node*) malloc(sizeof(struct node));
	struct node* cpt = (struct node*) malloc(sizeof(struct node)); 
	ptr = first;
	while(ptr->next!=NULL)
	{
		cpt = ptr;
		ptr= ptr->next;
	}
	cpt->next = NULL;
}

void delBtw(int delinfo) {
	if(first == NULL)
		return;
	struct node* ptr = (struct node*) malloc(sizeof(struct node));
	struct node* cpt = (struct node*) malloc(sizeof(struct node)); 
	ptr = first;
	while(ptr->info!=delinfo)
	{
		cpt = ptr;
		ptr = ptr->next;
	}
	cpt->next = ptr->next;
	ptr->next = NULL;
	
}

void printLL() {
	struct node *ptr = (struct node*) malloc(sizeof(struct node*));
	if(first==NULL)
	{
		printf("No element present inside linked list\n");
		return;
	}
	ptr= first;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->info);
		ptr = ptr->next;
	}
}
	
void main(){

addBeg(10);
addBeg(20);
addBeg(30);
addBtw(35,30);
addBeg(40);
addBeg(50);
addEnd(90);
printLL();
printf("\n");
delBeg();
delEnd();
delBtw(10);
printLL();

}
