#include <stdio.h>
#include <stdlib.h>
//you need to create two linked lists based on the number of nodes 
struct node{
  int coeff;
  int exp;
  struct node *next;
  struct node *prev;
}*first=NULL,*last=NULL,*first1=NULL,*first2=NULL;
int e=1;

void polyCreate(int no){
  int k=0;
  printf("Enter Expression %d:\n",e);
  // struct node *cpt= first1;
  
  if(e==1) {
      while(k<no) {
        k++;
        struct node *ptr =(struct node*) malloc(sizeof(struct node));
        printf("Enter info of node %d \n",k);
        printf("Enter Coefficient:");
        scanf("%d",&ptr->coeff);
        printf("Enter Exponent:");
        scanf("%d",&ptr->exp);
        if(first1==NULL)
        { 
          first1 = ptr;
          ptr->next = NULL;
          ptr->prev = NULL;
        }
        else {
          first1->prev = ptr; //DLL Code
          ptr->next = first1;
          ptr->prev = NULL; //DLL Code
          first1 = ptr;
        }
      }
  }
  if(e==2) {
        while(k<no) {
            k++;
            struct node *ptr =(struct node*) malloc(sizeof(struct node));
            // struct node *cpt= (struct node*) malloc(sizeof(struct node));
            printf("Enter info of node %d \n",k);
            printf("Enter Coefficient:");
            scanf("%d",&ptr->coeff);
            printf("Enter Exponent:");
            scanf("%d",&ptr->exp);
            if(first2==NULL)
            { 
              first2 = ptr;
              ptr->next = NULL;
              ptr->prev = NULL;
            }
            else {
              first2->prev = ptr; //DLL Code
              ptr->next = first2;
              ptr->prev = NULL; //DLL Code
              first2 = ptr;
            }
      }
  }
} 

int lastR = 0;
void delNode(int info) {
  struct node *ptr;
  struct node *cpt;
    if(first->coeff ==info){
    ptr = first;
    first = first->next;
    first->prev = NULL; //DLL Code
    free(ptr);
    return;
  }
  else if(last->coeff == info) 
  lastR = 1;
  else {
    ptr = first;
    while(ptr->coeff != info) {
      cpt = ptr;
      ptr = ptr->next; 
    }
    cpt->next = ptr->next;
    ptr->next->prev = cpt; //DLL Code
    ptr->next = NULL;
    free(ptr);
  return;
  }
}


void polyAdd() {
  struct node* ptr = first1;
  struct node* cpt;
  printf("SUM IS:\n");
  //combining the two lists 
  while(ptr->next!=NULL)
    ptr= ptr->next; //reaches last node

  ptr->next = first2;
  first2->prev = ptr; //DLL , second last is combined 
  first = first1;
  ptr = first;
  while(ptr->next!=NULL)
    ptr = ptr->next;
  last = ptr;
  printf("%d is the last node \n",last->coeff);

  //now we have to find the terms with the common exponent and add them
  struct node *ptrx = first;
  struct node *cptx;
  
  while(ptrx->next!=NULL) {
      cptx = ptrx ->next;
      while(cptx!=NULL) {
        if( ptrx->exp == cptx->exp )  {
            ptrx->coeff = ptrx->coeff + cptx->coeff;
            printf("%d is node to be deleted\n",cptx->coeff);
            delNode(cptx->coeff);   
        }
      cptx = cptx->next;
    }
  ptrx = ptrx->next;
  }

//checking to see if last node has to be deleted 
if(lastR==1)
  {
    ptr = first;
    while(ptr!=last){
      cpt = ptr;
      ptr = ptr->next;
    } 
    last = cpt;
    cpt->next = NULL;
    ptr->prev = NULL;
    free(ptr);
  }
int t1,t2;
  //sorting the list 
  ptr = first;
  cpt = NULL;
  while(ptr->next!=NULL) {
    cpt = ptr->next;
    while(cpt!=NULL) {
      if(ptr->exp > cpt->exp) {
        t1 = ptr->coeff;
        ptr->coeff = cpt->coeff;
        cpt->coeff = t1;
        t2 = ptr->exp;
        ptr->exp = cpt->exp;
        cpt->exp = t2;
      }
    cpt = cpt->next;
    }
  ptr = ptr->next;
  }
}


void polyPrint(struct node*f) {
  struct node *ptr =f;
  if(ptr==NULL)
    return;
  printf("Printing LL in Reverse using DLL :\n");
  while(ptr->prev!=NULL)
  {
    printf("%d^%d + ",ptr->coeff,ptr->exp);
    ptr = ptr->prev;
  }
  printf("%d^%d\n",ptr->coeff,ptr->exp);
}

int main(void) {
  printf("POLYNOMIAL \n\n");
  polyCreate(3);
  e++;
  polyCreate(2);
  // polyPrint(first1);
  // polyPrint(first2);
  polyAdd();
  polyPrint(last);
  return 0;
}


//Simple Algo
c global = 1
polyCreate() {
	1. Read the number of coefficients required , no
	2. repeat step 3-4 while(k<no) for first1 pointer
	3. read the coeff and expo of the node 
	4. increment k 
	5. if c == 2 -> repeat 2-4 with first2 pointer
	6. Two Linked Lists formed with first1 and first2 pointer
}

polyAdd() {
	1. ptr=first1
	2. while(ptr!=NULL)
	3. 	ptr= ptr->next
	4. ptr->next = first2. -> two linked lists combined
	5. reinitialize ptr=first and cpt.
	6. while(ptr->next!=NULL)
	7.	cpt = ptr->next
	8.	while(cpt!=NULL)
	9.		if(ptr->exp==cpt->exp)
	10.			add coeff of both and store in ptr->coeff
	11.			delete node containing ptr->coeff.
	12. added list has been formed 
	13. Sort the list according to ptr->exp>cpt->exp , use two t1,t2 variables.
	14. final linked list first node is pointed by "first" pointer.
	
}