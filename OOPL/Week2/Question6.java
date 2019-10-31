import java.lang.*;
import java.util.Scanner;

public class Question6
{
	public static void main(String [] args)
	{
	   Scanner sc = new Scanner(System.in);
	   System.out.print("Enter no. of rows of array : ");
	   int r = sc.nextInt();
	   System.out.print("Enter no. of columns of array : ");
	   int c = sc.nextInt();
	   int arr[][] = new int[r][c];
	   System.out.println("Enter elements of array A : ");
	   for(int i=0;i<r;i++)
	   {
	   	for(int j=0; j<c; j++)
	   	{
	   		arr[i][j] = sc.nextInt();
	   	}
	   }
	   Question6 obj = new Question6();
	   System.out.println("Array A : ");
	   obj.print(arr);
	   int trc = obj.trace(arr);
	   System.out.println("Trace = "+trc);
	   double nrm = obj.norm(arr);
	   System.out.println("Norm = "+nrm);
	}

	public void print(int arr[][])
	{
		for(int i=0;i<arr.length;i++)
		{
			for(int j=0; j<arr[0].length; j++)
			{
				System.out.print(arr[i][j]+" ");
			}
			System.out.println("");
		}
	}

	public int trace(int arr[][])
	{
		int t=0;
		for(int i=0; i<arr.length; i++)
		{
			for(int j=0; j<arr[0].length; j++)
			{
				if(i==j)
				{
					t = t+arr[i][j];
				}
			}
		}
		return t;
	}	

	public double norm(int arr[][])
	{
		double n=0;
		for(int i=0; i<arr.length; i++)
		{
			for(int j=0; j<arr[0].length; j++)
			{
				n = n + arr[i][j]*arr[i][j];
			}
		}
		n = Math.sqrt(n);
		return n;
	}	
}