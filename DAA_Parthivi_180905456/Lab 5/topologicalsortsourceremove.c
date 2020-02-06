#include <stdlib.h>
#include <stdio.h>

struct Graph
{
	int V;
	int **arr;
};

struct Graph* createGraph(int v)
{
	struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
	g->V = v;
	g->arr = (int**)calloc(v,sizeof(int*));
	for(int i=0; i<v; i++)
	{
		*(g->arr+i) = (int *)calloc(v,sizeof(int));
		for(int j=0; j<v; j++)
			*(*(g->arr+i)+j) = 0;
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

int main()
{
	printf("Enter no. of vertices : ");
	int v=0;
	scanf("%d",&v);
	struct Graph* g = createGraph(v);

	int indeg[v],flag[v];
	for(int i=0;i<v;i++)
	{
        indeg[i]=0;
        flag[i]=0;
    }

	printf("Enter no. of edges : ");
	scanf("%d",&v);
	int i=0, count=0;
	int x,y;
	while(i<v)
	{
		printf("Enter 2 vertices : ");
		scanf("%d %d",&x,&y);
		addEdge(g,x,y);
		i++;
	}
	//display(g);
	for(i=0;i<g->V;i++)
        for(int j=0;j<g->V;j++)
            indeg[i]=indeg[i]+g->arr[j][i];

	printf("Topologically  sorted array : ");
	//topological(g);
	while(count<g->V){
        for(int k=0;k<g->V;k++)
        {
            if((indeg[k]==0) && (flag[k]==0))
            {
                printf("%d ",k);
                flag [k]=1;
            }
 
            for(i=0;i<g->V;i++)
            {
                if(g->arr[i][k]==1)
                    indeg[k]--;
            }
        }
        count++;
    }
	return 0;
}

/*
OUTPUT:
Enter no. of vertices : 6
Enter no. of edges : 6
Enter 2 vertices : 5 2
Enter 2 vertices : 5 0
Enter 2 vertices : 4 0
Enter 2 vertices : 4 1
Enter 2 vertices : 2 3
Enter 2 vertices : 3 1
Topologically  sorted array : 4 5 0 1 2 3
*/