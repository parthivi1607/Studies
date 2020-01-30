#include <stdio.h>
#include <stdlib.h>

typedef struct Node * Nodeptr;
typedef struct Node
{
	int key;
	Nodeptr left,right;
}Node;

Nodeptr newNode(int item)
{
	Nodeptr temp = (Nodeptr)malloc(sizeof(Node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

Nodeptr insert(Nodeptr node, int key) 
{
	if(node == NULL)
		return newNode(key);
	if(key == node->key)
	{
		printf("Already present in tree\n");
		return node;
	}
	else if(key < node->key)
	{
		node->left = insert(node->left,key);
	}
	else
	{
		node->right = insert(node->right,key);
	}
	return node;

} 

void inorder(Nodeptr root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ",root->key);
		inorder(root->right);
	}
}

void preorder(Nodeptr root)
{
	if(root != NULL)
	{
		
		printf("%d ",root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Nodeptr root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->key);
	}
}

int main()
{
	printf("Enter root of BST : ");
	int n=0;
	scanf("%d",&n);
	Nodeptr root = NULL;
	root = insert(root,n);
	while(1)
	{
		printf("Enter a value (enter -9999 to exit) : ");
		scanf("%d",&n);
		if(n!=-9999) root = insert(root,n);
		else
		{
			printf("End\n");
			break;
		}
	}

    printf("\nInorder traversal of the given tree : "); 
    inorder(root); 
    printf("\nPreorder traversal of the given tree : "); 
    preorder(root); 
    printf("\nPostorder traversal of the given tree : "); 
    postorder(root); 
	return 0;
}