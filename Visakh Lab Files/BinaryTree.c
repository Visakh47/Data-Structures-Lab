//Program to Implement Binary Trees - Visakh Bobby S3R2 34 

#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *left , *right;
};



//Global Variables

struct node *root , *last;

//creation and insertion of binary tree

struct node *create_insert() {
	int info;
	struct node *new;
	new = (struct node*) malloc(sizeof(struct node));
	printf("Enter data to be inserted :(-1 for No New Node) :");
	scanf("%d",&info);
	
	if(info == -1) //no new node -- return 
		return NULL;
	new -> data = info;
	
	printf("Enter the left child of %d\n" , info);
	new -> left = create_insert();
	
	printf("Enter the right child of %d\n", info);
	new -> right = create_insert(); //recurusively calls function till it returns value 
	
	return new;
}


void preOrder(struct node *rt) {
	if(rt!=NULL) {
		printf("%d\n",rt->data);
		preOrder(rt->left);
		preOrder(rt->right);
	}
}

int main()
{
	
	root = create_insert();
	printf("\nThe Preorder traversal of tree is:\n");
	preOrder(root);
	printf("\n");
	return 0;
}
	
	




	