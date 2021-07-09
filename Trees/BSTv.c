#include<stdio.h>
#include<stdlib.h>


struct node 
{ int info;
  struct node *left;
  struct node *right;
} *root = NULL;

int sf =0; //search flag
//function to insert node

void insertBST() {
	struct node *new = (struct node*) malloc(sizeof(struct node));
	printf("Enter value of node\n");
	scanf("%d",&new->info);
	new->left = NULL;
	new->right = NULL;
	if(root==NULL) 
	{
		root = new;
		return;
	}
	else {
		struct node *ptr= root;
		struct node *cpt=NULL;
		while(ptr!=NULL) {
			cpt = ptr;
			if(new->info<ptr->info) 
				ptr = ptr->left;
			else
				ptr = ptr->right;
		}
		if(new->info < cpt->info) //last node 
			cpt->left = new; 
		else 
			cpt->right = new;
	}
}


//function to perform searching 

struct node* searchBST(struct node* node, int sinfo) {

	if(node==NULL)
		return NULL;
	else if(sinfo==node->info)
	{
		printf("Element has been found\n");
		sf=1;
	}
	else if(sinfo<node->info) 
		return searchBST(node->left,sinfo);
	else 
		return searchBST(node->right,sinfo);
		
}


//function to find minimum 

struct node* minimumBST(struct node* temp) {
	
	if(temp->left == NULL)
		return temp;
	else 
		return minimumBST(temp->left);

}

//function to delete 

struct node* deleteBST(struct node* node,int dinfo) {
		
		if(root==NULL) {
			printf("No BST PRESENT\n");
			return NULL;
		}
		else if(dinfo > node->info) 
			node->right = deleteBST(node->right,dinfo);
		else if(dinfo < node->info)
			node->left = deleteBST(node->left,dinfo);
		else {
			
			//no child
			if(node->left==NULL && node->right == NULL)
			{
				free(node);
				return NULL;
			}
			//one child
			else if(node->left==NULL || node->right == NULL) {
				struct node *temp;
				if(node->left == NULL)
				temp = node->right;
				else if(node->right == NULL)
				temp = node->left;
				free(node);
				return temp;
			}
			//two child
			else {
				struct node *temp = minimumBST(node->right); //finding the minimum element from the right subtree
				node->info = temp->info;
				node->right = deleteBST(node->right,temp->info);
			}
			
			return node;	
		}
}
void inOrder(struct node *node)
{
	if(root==NULL)
	{
		printf("The Binary Search Tree is empty\n");
		return;
	}
	else
	{
		if(node->left!=NULL)
		inOrder(node->left);
		printf("%d\t",node->info);
		if(node->right!=NULL)
		inOrder(node->right);
	}
}


void main()
{
	int c;
	int data;
	printf("Binary Search Trees!\n");
	printf("Enter your choice\n");
	printf("1.Insert an Element\n2.Delete an element\n3.Display the BST\n4.To search an element\n5.Exit\n");
	scanf("%d",&c);
	while(c>=1&&c<=4)
	{
		switch(c)
		{
			case 1:
			{
				insertBST();
				break;
			}
			case 2:
			{
				printf("Enter the value to be deleted\n");
				scanf("%d",&data);
				deleteBST(root,data);
				printf("Deleted %d.\n",data);
				break;
			}
		    case 3:
		    {
			    inOrder(root);
				printf("\n");
			    break;
		    }
			case 4:
			{
				printf("Enter the element to be searched\n");
				scanf("%d",&data);
				searchBST(root,data);
				if(sf==0)
	            printf("The entered element is not found!\n");
				sf=0;
				break;
			}
			
	    }
		printf("Enter your choice again\n");
    	scanf("%d",&c);
	}
	printf("Thank You\n");
}



	



