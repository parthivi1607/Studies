#include <stdlib.h>
#include<stdio.h>
#define MaxSize 100

//treeeeeeeeeeeeeeeeeeeeeeeeeee

typedef struct node* Nodeptr;

struct node{
    int data;
    Nodeptr lchild;
    Nodeptr rchild; 
};

Nodeptr getnode(){
    Nodeptr temp;
    temp=(Nodeptr)malloc(sizeof(struct node));
    temp->rchild=temp->lchild=NULL;
    return temp;
}

int isEmpty(Nodeptr first){
    return (first==NULL?1:0);
}

Nodeptr create(int x)
{
	if(x!=-1)
	{
		Nodeptr temp=getnode();
		int a;
		temp->data=x;
		printf("Enter lchild of %d: ",x);
		scanf("%d",&a);
		temp->lchild=create(a);
		printf("Enter rchild of %d: ",x);
		scanf("%d",&a);
		temp->rchild=create(a);
		return temp;
	}
	return NULL;
}
void inorder(Nodeptr root){
	if(root){
		inorder(root->lchild);
		printf("%d\t",root->data );
		inorder(root->rchild);
	}
}

//stackkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk

typedef struct{
	Nodeptr stk[MaxSize];
	int top;
}STACK; 

int isFull(STACK *s){
	if(s->top==MaxSize-1)
		return 1;
	else 
		return 0;
}
int isEmptyStack(STACK *s){
	if(s->top==-1)
		return 1;
	else 
		return 0;
}
void Push(STACK *s, Nodeptr c){
	if(isFull(s))
	{
		printf("Stack overflow");
		return;
	}
	s->stk[++(s->top)]=c;
}
Nodeptr Pop(STACK *s){
	if(isEmptyStack(s))
	{
		printf("Stack underflow");
		return NULL;
	}
return (s->stk[(s->top)--]);
}

//queueeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee

typedef struct{
	Nodeptr Q[MaxSize];
	int front;
	int rear;
}QUEUE;

void Insert(QUEUE *q,Nodeptr item)
{
	q->Q[++q->rear]=item;
}

Nodeptr Delete(QUEUE *q)
{
	return q->Q[++q->front];
}

int isEmptyQueue(QUEUE *q)
{
    if(q->front==q->rear)
        return 1;
    return 0;
}
