#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char *a;
  int top;
}STACK;

int isEmpty(STACK *s)
{
  if(s->top == 0)return 1;
  return 0;
}

int isFull(STACK *s, int x)
{
 if(s->top == x) return 1;
 return 0;
}

void push(STACK *s, char ele, int x)
{
  if(isFull(s,x))
  {
    printf("Stack is full.\n");
  }
  else
  {
    *((s->a)+(s->top))=ele;
    (s->top)++;
  }
}

char pop(STACK *s)
{
  if(isEmpty(s))
  {
    printf("Stack is empty.\n");
    exit(0);
  }
  {
    (s->top)--;
    return *((s->a)+(s->top));
  }
}

void display(STACK s)
{
  for(int i=0;i<(s.top);i++)
  {
    printf("%c ",*(s.a+i));
  }
  printf("\n");
}

void main()
{
  int n;
  char c;
  char x;
  printf("Enter length of stack : ");
  scanf("%d",&n);
  fflush(stdin);
  STACK s;
  s.a = (char*)calloc(n,sizeof(char));
  s.top=0;

  for(int i=0;i<n;i++)
  {
    scanf("%c",&x);
    printf("Enter a char : ");
    scanf("%c",&c);
    push(&s,c,n);
    printf("Stack after pushing\n");
    display(s);
  }
  printf("Pushing one more character : ");
  push(&s,'x',n);
  
  for(int i=0;i<n;i++)
  {
    printf("Element popped : %c\n", pop(&s));
    printf("Stack after popping\n");
    display(s);
  }
  printf("Popping again : %c\n", pop(&s));
}
