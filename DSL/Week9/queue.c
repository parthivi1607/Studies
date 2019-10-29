#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodePointer;
typedef struct node{
	int data;
	nodePointer link;
} node;
typedef struct{
	nodePointer front;
	nodePointer rear;
} queue;
void init(queue* q){
	q->front=NULL;
	q->rear=NULL;
}
void queueFull(){
	fprintf(stderr,"Queue Full");
	exit(EXIT_FAILURE);
}
int queueEmpty(){
	return -1;
}
void insert(queue* q,int x){
	node* temp;
	if(q->front==NULL){
		temp=malloc(sizeof(node));
		temp->data=x;
		temp->link=NULL;
		q->front=temp;
		q->rear=temp;
	}
	else
	{
		temp=malloc(sizeof(node));
		temp->data=x;
		temp->link=NULL;
		q->rear->link=temp;
		q->rear=temp;
	}
}
int delete(queue* q){
	int temp;
	node* t;
	if(q->front==NULL){
		return queueEmpty();
	}
	else if(q->front==q->rear){
		temp=q->front->data;
		init(q);
	}
	else{
		temp=q->front->data;
		t=q->front;
		q->front=q->front->link;
		free(t);
	}
	return temp;
}
void display(queue* q){
	queue temp;
	init(&temp);
	int i;
	while(q->front!=NULL){
		i=delete(q);
		printf("\n%d",i);
		insert(&temp,i);
	}
	*q=temp;
}
int main(){
	queue q;
	int opt,ele;
	printf("\nEnter:\n1 to insert \n2 to delete \n3 to display \n4 to exit");
	scanf("%d",&opt);
	init(&q);
	while(opt!=4){
		switch(opt){
				case 1:{
				printf("\nEnter element");
				scanf("%d",&ele);
				insert(&q,ele);
				break;
			}
			case 2:{
				printf("\nYou have deleted %d",delete(&q));
				break;
			}
			case 3:{
				display(&q);
				break;
			}
		}
		printf("\nEnter option");
		scanf("%d",&opt);
	}
	return 0;
}
