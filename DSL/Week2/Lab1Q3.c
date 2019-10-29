#include <stdio.h>
#include <stdlib.h>

int i,j;

void print(int **p, int r, int c)
{
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d ",*(*(p+i)+j));
		printf("\n");
	}
}

void product(int **arr, int **brr, int **crr, int a, int b, int c, int d)
{
	int k,sum;
	for(k=0; k<a; k++)
	{
	  for(i=0; i<d; i++)
	  {
	    for(j=0; j<b; j++)
	    {
	    	sum = sum + (*(*(arr+k)+j))*(*(*(brr+j)+i));
	    }
	    *(*(crr+k)+i)= sum;
	    sum=0;
	  }
	}
}

void main()
{
	int a,b,c,d,i,j;
	printf("Enter row of A : ");
	scanf("%d",&a);
	printf("Enter column of A : ");
	scanf("%d",&b);
	printf("Enter row of B : ");
	scanf("%d",&c);
	printf("Enter column of B : ");
	scanf("%d",&d);
	if(b!=c)
	{
		printf("Invalid input");
		exit(0);
	}
	else
	{
		int **arr;
		arr = (int**)calloc(a,sizeof(int*));
		for(i=0;i<b;i++)
		{
			arr[i] = (int*)calloc(b,sizeof(int));
		}
		printf("Matrix A : \n");
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
				scanf("%d",(*(arr+i)+j));
		}

		int **brr;
		brr = (int**)calloc(c,sizeof(int*));
		for(i=0;i<d;i++)
		{
			brr[i] = (int*)calloc(d,sizeof(int));
		}
		printf("Matrix B : \n");
		for(i=0;i<c;i++)
		{
			for(j=0;j<d;j++)
				scanf("%d",(*(brr+i)+j));
		}

		printf("Matrix A : \n");
		print(arr,a,b);
		printf("Matrix B : \n");
		print(brr,c,d);

		int **crr;
		crr = (int**)calloc(a,sizeof(int*));
		for(i=0;i<d;i++)
		{
			crr[i] = (int*)calloc(d,sizeof(int));
		}

		printf("Matrix C : \n");
		product(arr, brr, crr, a, b, c, d);
		print(crr, a, d);
	}
}