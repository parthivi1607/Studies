#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count;

void Merge(int *brr, int p, int *crr, int q)
{
	int i=0, j=0;
	while(i<p)
	{
		j=0;
		while(j<q)
		{
			//printf("%d %d\n",brr[i],crr[j]);
			if(brr[i]>crr[j])
			{
				count++;	
			}
			j++;
		}
		i++;
	}
}

void InversionCount(int n, int *arr)
{
	int i=0,j=0;
	if (n==1) return;
	int p = (int)floor(n/2);
	int q = (int)floor((n+1)/2);
	printf("q=%d\n",q);
	int brr[p], crr[q];
	while(j<p)
	{
		brr[i++]=arr[j++];
	}
	i=0;
	while(j<n)
	{
		crr[i++]=arr[j++];
	}
	InversionCount(p,brr);
	InversionCount(q,crr);
	Merge(brr, p, crr, q);
}

void main()
{
	int n;
	printf("Enter no. of distinct elements : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter distinct elements :\n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	InversionCount(n,arr);
	printf("Inversion count = %d\n",count);
}