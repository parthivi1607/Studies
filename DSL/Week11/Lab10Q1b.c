#include <stdio.h>
#include <stdlib.h>

typedef struct Node * Nodeptr;
typedef struct Node{
	int data;
	Nodeptr rchild, lchild;
}Node;

Nodeptr create()
{
	int ele;
	printf("Enter the element to insert (-1 for no data) : ");
	scanf("%d",&ele);
	if(ele==-1) return NULL;
	Nodeptr temp;
	temp = malloc(sizeof(Node));
	temp->data = ele;
	printf("Enter left child of %d : \n",ele);
	temp->lchild = create();
	printf("Enter right child of %d : \n",ele);
	temp->rchild = create();
	return temp;
}

void inorder(Nodeptr ptr)
{
	if(ptr!=NULL)
	{
		inorder((ptr)->lchild);
		printf("%d ",(ptr)->data);
		inorder((ptr)->rchild);
	}
}
void postorder(Nodeptr ptr)
{
	if(ptr!=NULL)
	{
		postorder((ptr)->lchild);
		postorder((ptr)->rchild);
		printf("%d ",(ptr)->data);
	}
}
void preorder(Nodeptr ptr)
{
	if(ptr!=NULL)
	{
		printf("%d ",(ptr)->data);
		preorder((ptr)->lchild);
		preorder((ptr)->rchild);
	}
}

int main()
{
	int ch;
	Nodeptr root;
	root = NULL;
	printf("MENU : 1.insert 2.traverse 3.exit\n");
	while(1)
	{
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			root = create();
			break;

			case 2:
			printf("Inorder : ");
			inorder(root);
			printf("\nPostorder : ");
			postorder(root);
			printf("\nPreorder : ");
			preorder(root);
			printf("\n");
			break;

			case 3: exit(0);
		}
	}
	return 0;
}

/*
MENU : 1.insert 2.traverse 3.exit
Enter your choice : 1
Enter the element to insert (-1 for no data) : 0
Enter left child of 0 : 
Enter the element to insert (-1 for no data) : 10
Enter left child of 10 : 
Enter the element to insert (-1 for no data) : 30
Enter left child of 30 : 
Enter the element to insert (-1 for no data) : -1
Enter right child of 30 : 
Enter the element to insert (-1 for no data) : -1
Enter right child of 10 : 
Enter the element to insert (-1 for no data) : -1
Enter right child of 0 : 
Enter the element to insert (-1 for no data) : 20
Enter left child of 20 : 
Enter the element to insert (-1 for no data) : -1
Enter right child of 20 : 
Enter the element to insert (-1 for no data) : 40
Enter left child of 40 : 
Enter the element to insert (-1 for no data) : -1
Enter right child of 40 : 
Enter the element to insert (-1 for no data) : -1
Enter your choice : 2
Inorder : 30 10 0 20 40 
Postorder : 30 10 40 20 0 
Preorder : 0 10 30 20 40 
Enter your choice : 3
*/