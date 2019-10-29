#include <stdio.h>
#include <stdlib.h>

void move(int **a, int x)
{
	int n=*(*(a+x-1)+0);
	for(int i=0;i<x-1;i++)
	{
		int y=*(*(a+i)+0);
		a[x-1]=(int*)realloc(*(a+x-1),(n+y)*sizeof(int));
		for(int j=1;j<=y;j++)
		{
			*(*(a+x-1)+(n+j+1))=*(*(a+i)+j);
		}
		for(int k=0;k<*(*(a+i)+0);k++)
		{
			*(*(a+i)+k)=0;
		}
	}
	printf("New \n");
	loop: for(int i=0;i<x;i++)
	{
		for(int j=0;j<=*(*(a+i)+0);j++)
		{
			if(*(*(a+i)+0)==0)
			{
				printf("NULL\n");
				goto loop;
			}
			else
				printf("%d ",*(*(a+i)+j));
		}
		printf("\n");
	}
}

int main()
{
	int rn,cn,i,j;
	int **table;
	printf("Enter no. of rows : ");
	scanf("%d",&rn);
	table=(int**)calloc(rn+1,sizeof(int*));
	for(i=0;i<rn;i++)
	{
		printf("Enter size of row %d : ",(i+1));
		scanf("%d",&cn);
		table[i]=(int*)calloc(cn+1,sizeof(int));
		printf("Enter row elements :\n");
		for(j=1;j<=cn;j++)
			scanf("%d",&table[i][j]);
		table[i][0]=cn;
		printf("Size of row %d = %d\n",(i+1),table[i][0]);
	}
	table[i]=NULL;

	for(i=0;i<rn;i++)
	{
		printf("%d ",table[i][0]);
		for(j=1;j<=*table[i];j++)
			printf("%5d",table[i][j]);
		printf("\n");
	}

	move(table,rn);
	
	//for(i=0;i<rn;i++)
	//	free(table[i]);
	//free(table);
	return 0;
}