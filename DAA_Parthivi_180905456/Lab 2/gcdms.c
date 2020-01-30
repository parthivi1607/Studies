#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int sieveofE(int x, int pf[])
{
	int arr[x+1];
	arr[0]=0; arr[1]=0;
	for(int i=2;i<=x;i++)
	{
		arr[i]=i;
	}
	for(int i=2;i<=(int)sqrt(x);i++)
	{
		int j=i*i;
		while (j<=x)
		{
			arr[j]=0;
			j=j+i;
		}
	}

    int k=0;
	for(int i=2;i<=x;i++)
	{
		if (arr[i]!=0)
		{
			pf[k]=arr[i];
			k++;
		}
	}
	return k;
}
int primefac(int n,int pf[], int length, int fac[])
{
	int k=0;
        for(int i=0;i<length && n!=1; )
        {
        	if(n%pf[i]==0)
        		{
        			fac[k]=pf[i];
        			k++;
        			n=n/pf[i];
        		}
        	else
        		i++;

        }
        return k;
}
int comfac(int fac1[], int fac2[], int len1, int len2)
{
	int gcd=1;
	int l1=0; int l2=0;
	while(l1<len1 && l2<len2)
	{
		if(fac1[l1]==fac2[l2])
		{
			gcd=gcd*fac1[l1];
			l1++; l2++;
		}
		else if(fac1[l1]>fac2[l2])
			l2++;
		else
			l1++;
	}
	return gcd;

}

int main()
{
	int a; int b;
	printf("Enter two numbers:\n");
	scanf("%d%d",&a,&b);
	int pf1[a]; int pf2[b];
	int fac1[a]; int fac2[b];

	int length1=sieveofE(a,pf1);
	int length2=sieveofE(b,pf2);

	int facno1=primefac(a,pf1,length1,fac1);
	int facno2=primefac(b,pf2,length2,fac2);

	int gcd=comfac(fac1,fac2,facno1,facno2);
	printf("GCD:%d\n", gcd);
	
}