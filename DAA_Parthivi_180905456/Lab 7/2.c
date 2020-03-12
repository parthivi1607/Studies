#include<stdio.h>
#include<stdlib.h>

int opcount=0;

int Partition(int a[],int l,int r){
	int p=a[l],i=l,j=r+1,t;
	do
	{
		do{
			opcount++;
			i++;
		}while(a[i]<p);

		do{
			opcount++;
			j--;
		}while(a[j]>p);

		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}while(i<j);

	t=a[i];
	a[i]=a[j];
	a[j]=t;

	t=a[l];
	a[l]=a[j];
	a[j]=t;
	return j;
}

void QuickSort(int a[],int l,int r){
	if(l<r){
		int s=Partition(a,l,r);
		QuickSort(a,l,s-1);
		QuickSort(a,s+1,r);
	}
}

int main(){
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i] );
	printf("Array:\t");
	for(int i=0;i<n;i++)
		printf("%d\t",a[i] );
	QuickSort(a,0,n-1);
	printf("\nSorted Array:\t");
	for(int i=0;i<n;i++)
		printf("%d\t",a[i] );
	printf("Opcount: %d\n",opcount);
}