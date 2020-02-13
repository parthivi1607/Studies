#include <stdio.h> 
#include <stdlib.h> 

struct node 
{ 
    int data; 
    struct node* left, *right; 
}; 

struct node* newNode() 
{ 
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->left = NULL; 
  node->right = NULL; 
  return node; 
}

struct node* create()
{
  struct node* root;
  int x;
  scanf("%d",&x);
  if(x==-1) return NULL;
  root = newNode();
  root->data = x;
  printf("Enter left child of %d : ",x);
  root->left = create();
  printf("Enter left child of %d : ",x);
  root->right = create();
  return root;
}

int inorder(struct node *root)
{
	static int count = 0;
	struct node *temp = root;
	if(temp != NULL)
	{
		inorder(temp->left);
		count++;
		inorder(temp->right);
	}
	return count;
}

int main()
{
  printf("Enter data for root (-1 for no data) : ");
  struct node* root = create();
  int c = inorder(root);
  printf("The number of nodes are: %d\n", c);
  return 0;
}