#include <stdio.h>
#include <stdlib.h>

int n, r1=0, opcount=0;
int combinations[100][10];

int fact(int n)
{
	if(n==1 || n==0) return 1;
	else return fact(n-1)*n;
}
void permute(int num[], int l, int r)
{
	if(l==r)
	{
		for (int i=0;i<n;i++)
			combinations[r1][i]=num[i];
		r1++;
		return;
	}
	for(int i=l;i<=r;i++)
	{
		int t = num[l];
		num[l]=num[i];
		num[i]=t;
		permute(num,l+1,r);
		t = num[l];
		num[l]=num[i];
		num[i]=t;
	}
}
void main()
{
	printf("Enter n : ");
	scanf("%d",&n);
	int square[n][n];
	for(int i=0;i<n;i++)
	{
		printf("Enter cost for person %d : ",(i+1));
		for(int j=0;j<n;j++)
			scanf("%d",&square[i][j]);
	}
	int num[n], temp[n], jobs[n], ans[fact(n)];
	for(int i=0;i<fact(n);i++)
		ans[i]=0;
	int min=0;
	for(int i=0;i<n;i++)
		num[i]=i;
	permute(num,0,n-1);
	for(int i=0;i<fact(n);i++)
	{
		opcount++; int sum=0;
		for(int j=0;j<n;j++)
		{
			temp[j] = combinations[i][j];
			jobs[j] = square[i][temp[j]];
			sum += jobs[j];
		}
		ans[i]=sum;
		if(ans[i]<ans[min]) min =i;
	}
	printf("Minimum cost = %d\n",ans[min]);
	printf("Person :\t");
	for(int i=0;i<n;i++)
		printf("%d\t",i+1);
	printf("\nJob :\t");
	for(int i=0;i<n;i++)
		printf("%d\t",combinations[min][i]+1);
	printf("\nOpcount = %d\n",opcount);
}