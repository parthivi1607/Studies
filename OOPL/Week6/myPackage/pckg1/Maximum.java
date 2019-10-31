package myPackage.pckg1;

public class Maximum
{
	public int max(int a, int b, int c)
	{
		if(a>b)
		{
			if(a>c) return a;
		}
		else
		{
			if(b>c) return b;
		}
		return c;
	}
	public float max(float a, float b, float c)
	{
		if(a>b)
		{
			if(a>c) return a;
		}
		else
		{
			if(b>c) return b;
		}
		return c;
	}
	public int max(int arr[])
	{
		int m=arr[0];
		for(int i=1;i<arr.length;i++)
		{
			if(arr[i]>m) m=arr[i];
		}
		return m;
	}
	public int max(int arr[][])
	{
		int m=arr[0][0];
		for(int i=0;i<arr.length;i++)
		{
			for(int j=0;j<arr[i].length;j++)
			{
				if(arr[i][j]>m) m=arr[i][j];
			}
		}
		return m;
	}
}