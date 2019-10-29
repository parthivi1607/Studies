#include <stdio.h>

int i=0;

void sumOfArray(int arr[], int n)
{
	int sum=0;
	for(i=0; i<n; i++)
	{
	  sum=sum+arr[i];
	}
	printf("Sum = %d \n", sum);
}

void linearsearch(int arr[], int num, int n)
{
	int flag=0;
	for(i=0; i<num; i++)
	{
	  if(arr[i]==n)
	  {
	    printf("No. found.\n");
	    flag=1;
	    break;
	  }
	}
	if(flag==0)
	  printf("No. not found.\n");
}

void product(int a, int b, int c, int d)
{
	int arr[100][100];
	int brr[100][100];
	int crr[100][100];
	int sum=0;
	int j=0,k=0;

	printf("Matrix A : \n");
	for(i=0; i<a; i++)
	{
	  for(j=0; j<b; j++)
	  {
	    scanf("%d", &arr[i][j]);
	  }
	}
	printf("Matrix B : \n");
	for(i=0; i<c; i++)
	{
	  for(j=0; j<d; j++)
	  {
	    scanf("%d", &brr[i][j]);
	  }
	}

	for(k=0; k<a; k++)
	{
	  for(i=0; i<d; i++)
	  {
	    for(j=0; j<b; j++)
	    {
	    	sum = sum + arr[k][j]*brr[j][i];
	    }
	    crr[k][i] = sum;
	    sum=0;
	  }
	}
	
	printf("Product of the matrices are : \n");
	for(i=0;i<a;i++)
	{
		for(j=0;j<d;j++)
		{
			printf("%d ",crr[i][j]);
		}
		printf("\n");
	}
}

void secondlarge(int arr[], int n)
{
	int l1=arr[0];
	int p=0, l2=0;
	for(i=1;i<n;i++)
	{
		if(arr[i]>l1) 
		{
			l1=arr[i];
			p=i;
		}
	}
	if (p==0) l2=arr[1];
	else l2=arr[0];
	for(i=0;i<n;i++)
	{
		if(arr[i]<l1 && arr[i]>l2) l2=arr[i];
	}
	printf("2nd largest no. = %d \n", l2);
}

void main()
{
	int n=0,num=0,r;
	int a=0,b=0,c=0,d=0;
	printf("Options :- \n");
	printf("1. find sum of nos. in a 1D array \n");
	printf("2. linear search \n");
	printf("3. product of 2 matrices \n");
	printf("4. find 2nd largest in a list of nos. \n");
	printf("Enter your choice : ");
	scanf("%d", &n);
	switch(n)
	{
		case 1:
		printf("Enter no. of elements : ");
		scanf("%d", &num);
		int arr[100];
		printf("Enter elements of array :\n");
		for(i=0;i<num;i++)
		{
			scanf("%d", &arr[i]);
		}
		sumOfArray(arr,num);
		break;

		case 2:
		printf("Enter no. of elements : ");
		scanf("%d", &num);
		int brr[100];
		printf("Enter elements of array :\n");
		for(i=0;i<num;i++)
		{
			scanf("%d", &brr[i]);
		}
		printf("Enter no. to be searched : ");
		scanf("%d", &r);
		linearsearch(brr,num,r);
		break;

		case 3:
		printf("Enter a : ");
		scanf("%d",&a);
		printf("Enter b : ");
		scanf("%d",&b);
		printf("Enter c : ");
		scanf("%d",&c);
		printf("Enter d : ");
		scanf("%d",&d);
		if(b==c)
			product(a,b,c,d);
		else 
			printf("Invalid input");
		break;

		case 4:
		printf("Enter no. of elements : ");
		scanf("%d", &num);
		int crr[100];
		printf("Enter elements of array :\n");
		for(i=0;i<num;i++)
		{
			scanf("%d", &crr[i]);
		}
		secondlarge(crr, num);
		break;

		default:
		printf("Invalid input.");
		break;
	}
}