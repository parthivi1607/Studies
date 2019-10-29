#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct
{
  int data[MAX];
  int top;
}STACK;

int isEmpty(STACK *s)
{
  if(s->top == 0)return 1;
  return 0;
}

int isFull(STACK *s)
{
 if(s->top == MAX) return 1;
 return 0;
}

void push(STACK *s, char ele)
{
  s->data[s->top]=ele;
  (s->top)++;
}

int pop(STACK *s)
{
  (s->top)--;
  return s->data[s->top];
}

void main()
{
  int num;
  printf("Enter a decimal no. : ");
  scanf("%d",&num);
  STACK s;
  s.top=0;
  while(num!=0)
  {
    if(!isFull(&s))
    {
      push(&s,num%2);
      num=num/2;
    }
    else
    {
      printf("Stack overflow");
      exit(0);
    }
  }
  while(!isEmpty(&s))
  {
    printf("%d",pop(&s));
  }
  printf("\n");
}
