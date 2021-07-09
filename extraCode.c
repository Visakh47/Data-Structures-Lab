BST_Insert(50);
	BST_Insert(30);
	BST_Insert(70);
	BST_Insert(60);
	BST_Insert(10);
	BST_Insert(90);
	
	
	printf("Binary Search Tree After Insertion\n");
	inOrder(root);
	printf("\n");
	
	delVal = 90;
	delNode = BST_Delete(root,delVal);
	printf("Tree After Deleting %d\n",delVal);
	inOrder(root);
	printf("\n");
	
	delVal = 30;
	delNode = BST_Delete(root,delVal);
	printf("Tree After Deleting %d\n",delVal);
	inOrder(root);
	printf("\n");
	
	delVal = 50;
	delNode = BST_Delete(root,delVal);
	printf("Tree After Deleting %d\n",delVal);
	inOrder(root);
	printf("\n");
	
	printf("Enter Your Choice:\n 1.Insert To Binary Search Tree\n 2.Delete From Binary Search Tree\n 3. Search In Binary Search Tree\n 4.Display Binary Search Tree(InOrder)\n");
	scanf("%d",&ch);
	
	
	
	void BST_Insert(int info)
{
	struct node *new = createNode(info);
	struct node *ptr = root;
	struct node *cpt = NULL;
	if(root==NULL)
	{
		root = new;
		return 
	}
	else 
	{
		while(ptr!=NULL)
		{
			cpt=ptr;
			if(new->info < ptr->info)
				ptr = ptr->lt;
			else 
				ptr = ptr->rt;
		}
	}
//inserting the new node , cpt is currently at the position of insertion
	if(new->info < cpt ->info)
		cpt->lt = new;
	else 
		cpt->rt = new;	
}