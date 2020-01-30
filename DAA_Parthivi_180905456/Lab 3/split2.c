#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	int sum=0;
	FOR(i,0,n)
	{
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	sum/=2;
	int flag=0;
	FOR(i,0,pow(2,n))
	{
		int j=i;
		int ind=0;
		int csum=0;
		FOR(k,0,n)
		{
			if(j&1)
			{
				csum+=arr[ind];
			}
			ind+=1;
			j>>=1;
		}
		if(csum==sum)
		{
			printf("Subset found\n");
			j=i;
			ind=0;
			printf("The set is: ");
			FOR(k,0,n)
			{
				if(j&1)
				{
					printf("%d ",arr[ind]);
				}
				ind+=1;
				j>>=1;
			}
			printf("\n");
			j=i;
			ind=0;
			printf("The other set: ");
			FOR(k,0,n)
			{
				if(!(j&1))
				{
					printf("%d ",arr[ind]);
				}
				ind+=1;
				j>>=1;
			}
			printf("\n");
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		printf("No such subset possible\n");
	}
	return 0;
}