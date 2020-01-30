#include <stdlib.h>
#include <stdio.h>

struct Graph
{
	int V;
	int **arr;
	int *visited;
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
	*(*(g->arr+y)+x) = 1;
}

void dfs(struct Graph* g, int v)
{
	printf("%d ",v);
	g->visited[v]=1;
	for(int i=0;i<g->V;i++)
	{
		if(g->arr[v][i] == 1&&(!g->visited[i]))
		{
			dfs(g,i);
		}
	}
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

int main()
{
	printf("Enter no. of vertices : ");
	int v=0;
	scanf("%d",&v);
	struct Graph* g = createGraph(v);
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
	printf("Enter starting vertex : ");
	scanf("%d",&v);
	printf("DFS : ");
	dfs(g,v);
	return 0;
}

/*
OUTPUT:
Enter no. of vertices : 5
Enter no. of edges : 5
Enter 2 vertices : 0 1
Enter 2 vertices : 0 2
Enter 2 vertices : 0 3
Enter 2 vertices : 1 2
Enter 2 vertices : 2 4
Enter starting vertex : 0
DFS : 0 1 2 4 3
*/