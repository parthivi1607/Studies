#include <stdio.h>
#include <stdlib.h>
void heapify(int h[],int n)
{
	int i,k,v,heapify,j;
	for(i=n/2;i>=1;i--)
	{
		k=i;v=h[k];heapify=0;
		while(heapify==0 && 2*k<=n)
		{
			j=2*k;
			if(j<n)
				if(h[j]<h[j+1])
					j++;
			if(v>=h[j])
				heapify=1;
			else
			{
				h[k]=h[j];
				k=j;
			}
		}
		h[k]=v;
	}
}
void heapSort(int arr[], int n) 
{ 
    for (int i=n; i>0; i--) 
    {  
    	heapify(arr, i); 
        int t=arr[1];
        arr[1]=arr[i];
        arr[i]=t;
        
    } 
} 
void main()
{
	int h[20],i,n;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	printf("Enter elements\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
	}
	heapSort(h,n);
	printf("Sorted\n");
	for(i=1;i<=n;i++)
	{
		printf("%d ",h[i]);
	}
	printf("\n");
}