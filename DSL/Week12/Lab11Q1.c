#include <stdio.h>
#include <stdlib.h>

typedef struct Node * Nodeptr;
typedef struct Node{
	int data;
	Nodeptr rchild, lchild;
}Node;

void inorder(Nodeptr ptr)
{
	if(ptr!=NULL)
	{
		inorder((ptr)->left);
		printf("%d ",(ptr)->data);
		inorder((ptr)->right);
	}
}

