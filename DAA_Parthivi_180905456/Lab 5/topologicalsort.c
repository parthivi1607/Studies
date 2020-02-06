#include <stdlib.h>
#include <stdio.h>

struct Graph
{
	int V;
	int **arr;
	int *visited;
};

struct Stack
{
	int* arr;
	int top;
};

struct Graph* createGraph(int v)
{
	struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
	g->V = v;
	g->arr = (int**)calloc(v,sizeof(int*));
	g->visited = (int*)calloc(v,sizeof(int));
	for(int i=0; i<v; i++)
	{
		*(g->arr+i) = (int *)calloc(v,sizeof(int));
		for(int j=0; j<v; j++)
			*(*(g->arr+i)+j) = 0;
		g->visited[i]=0;
	}
	return g;
}

void addEdge(struct Graph* g, int x, int y)
{
	*(*(g->arr+x)+y) = 1;
	//*(*(g->arr+y)+x) = 1;
}

void display(struct Graph* g)
{
	for(int i=0;i< g->V;i++)
	{
		for(int j=0;j< g->V;j++)
			printf("%d ",*(*(g->arr+i)+j));
		printf("\n");
	}
	for(int i=0;i< g->V;i++)
	{
		printf("Vertex %d is connected to ",i);
		for(int j=0;j< g->V;j++)
			if(*(*(g->arr+i)+j) == 1)
				printf("%d\t",j);
		printf("\n");
	}
}

int isEmpty(struct Stack* s)
{
	if(s->top == -1) return 1;
	return 0;
}

void push(struct Graph* g, struct Stack* s, int ele)
{
	if(s->top < g->V)
	{
		(s->top)++;
		s->arr[s->top]=ele;
	}
}

int pop(struct Stack* s)
{
	return s->arr[s->top--];
}

void toposort(struct Graph* g, struct Stack* s, int x)
{
	g->visited[x]=1;
	for(int i=0;i<g->V;i++)
	{
		if(g->arr[x][i]==1)
		{
			if(!g->visited[i])
				toposort(g,s,i);
		}
	}
	push(g,s,x);
}

void topological(struct Graph* g, struct Stack* s)
{
	for(int i=0;i<g->V;i++)
	{
		if(g->visited[i]==0)
			toposort(g,s,i);
	}

	while(!isEmpty(s))
	{
		printf("%d ",pop(s));
	}
}

int main()
{
	printf("Enter no. of vertices : ");
	int v=0;
	scanf("%d",&v);
	struct Graph* g = createGraph(v);

	struct Stack * s = (struct Stack*)malloc(sizeof(struct Stack));
	s->top = -1;
	s->arr = (int*)calloc(v, sizeof(int));

	printf("Enter no. of edges : ");
	scanf("%d",&v);
	int i=0;
	int x,y;
	while(i<v)
	{
		printf("Enter 2 vertices : ");
		scanf("%d %d",&x,&y);
		addEdge(g,x,y);
		i++;
	}
	//display(g);

	printf("Topologically  sorted array : ");
	topological(g,s);
	return 0;
}