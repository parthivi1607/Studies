#include <stdio.h>
#include <stdlib.h>
typedef struct node* nodeptr;
struct node{
	int data;
	nodeptr rchild,lchild,par;
};
typedef struct{
	nodeptr arr[100];
	int f,r;
}Q;
void add(Q *q,nodeptr n)
{
	if(q->r==100)
		return;
	q->arr[q->r++]=n;
}
nodeptr del(Q *q)
{
	if(q->f==q->r)
		return NULL;
	else
		return q->arr[q->f++];
}
Q* init()
{
	Q *a=(Q*)malloc(sizeof(Q));
	a->f=a->r=0;
	return a;
}
nodeptr getnode(int x)
{
	nodeptr temp=(nodeptr)malloc(sizeof(struct node));
	temp->data=x;
	temp->lchild=temp->rchild=NULL;
	temp->par=NULL;
	return temp;
}
nodeptr insert(nodeptr root,int n)
{
	nodeptr temp=getnode(n);
	if(!root){
		temp->par=NULL;
		return temp;
	}
	nodeptr cur=NULL,p=NULL;
	Q *q=init();
	add(q,root);
	while(1)
	{
		cur=del(q);
		if(cur->lchild)
			add(q,cur->lchild);
		if(cur->rchild)
			add(q,cur->rchild);
		else
			break;
	}
	temp->par=cur;
	if(cur->lchild)
		cur->rchild=temp;
	else
		cur->lchild=temp;
	printf("Added %d as child of %d\n",temp->data,cur->data);
	p=cur;
	cur=temp;
	while(p && p->data<cur->data)
	{

		int t=p->data;
		p->data=cur->data;
		cur->data=t;
		printf("Swapped: %d and %d\n",p->data,cur->data);
		cur=p;
		p=p->par;
	}
	return root;
}
void inorder(nodeptr root)
{
	if(root)
	{
		printf("%d ",root->data);
		inorder(root->lchild);
		
		inorder(root->rchild);
	}
}
void main()
{
	nodeptr root=NULL;
	printf("Enter elements(-99 to exit)\n");
	int n;
	scanf("%d",&n);
	while(n!=-99)
	{
		root=insert(root,n);
		scanf("%d",&n);
	}
	printf("Heap in preorder\n");
	inorder(root);
	printf("\n");
}