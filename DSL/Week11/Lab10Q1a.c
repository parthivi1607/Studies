#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

void insert(struct Node** root,int data)
{
	struct Node* node=malloc(sizeof(struct Node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	if (*root==NULL)
	{
		*root=node;
		return;
	}
	struct Node* temp;
	char str[10];
	for(temp=*root;temp!=NULL;)
	{
		printf("Insert to left or right of %d?\n", temp->data);
		scanf("%s",str);
		if (strcmp(str,"left")==0)
		{
			if (temp->left==NULL)
			{
				temp->left=node;
				break;
			}
			else{
				temp=temp->left;
			}
		}
		else{
			if(temp->right==NULL)
			{
				temp->right=node;
				break;
			}
			else{
				temp=temp->right;
			}
		}
	}	
}
void preorder(struct Node* root)
{
	if(!root)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
	return;
}
void inorder(struct Node* root)
{
	if(!root)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
	return;
}
void postorder(struct Node* root)
{
	if(!root)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
	return;
}
int main()
{
	struct Node* root=NULL;
	int n;
	printf("Enter no. of nodes : ");
	scanf("%d",&n);
	int k;
	struct Node* temp=root;
	for(int i=0;i<n;i++)
	{	
		printf("Give the integer to go in the tree\n");
		scanf("%d",&k);
		insert(&root,k);
	}
	printf("Preorder : ");
	preorder(root);
	printf("\nInorder : ");
	inorder(root);
	printf("\nPostorder : ");
	postorder(root);
	printf("\n");
	return 0;
}

/*
Enter no. of nodes : 5
Give the integer to go in the tree
0
Give the integer to go in the tree
10
Insert to left or right of 0?
left
Give the integer to go in the tree
20
Insert to left or right of 0?
right
Give the integer to go in the tree
30
Insert to left or right of 0?
left
Insert to left or right of 10?
left
Give the integer to go in the tree
40
Insert to left or right of 0?
right
Insert to left or right of 20?
right
Preorder : 0	10	30	20	40	
Inorder : 30	10	0	20	40	
Postorder : 30	10	40	20	0	
*/