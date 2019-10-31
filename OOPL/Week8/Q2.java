import java.util.*;
import java.lang.*;

class RowSum implements Runnable
{
	private int arr[];
	private int sum;
	Thread t;

	RowSum(int arr[], String threadName)
	{
		t = new Thread(this,threadName);
		this.arr=arr;
		sum=0;
		t.start();
	}

	public void run()
	{
		for(int i=0;i<arr.length;i++)
			sum=sum+arr[i];
		System.out.println("Sum of "+t.getName()+" = "+sum);
	}
	int getSum()
	{
		return sum;
	}
}

public class Q2
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no. of rows and columns : ");
		int r = sc.nextInt();
		int c = sc.nextInt();
		int arr[][] = new int[r][c];
		RowSum t[] = new RowSum[r];
		int sum=0;
		System.out.println("Enter elements : ");
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
				arr[i][j]=sc.nextInt();
		}
		for(int i=0;i<r;i++)
		{
			t[i] = new RowSum(arr[i],"row "+i);
		}
		for(int i=0;i<r;i++)
		{
			try
			{
				t[i].t.join();
			}
			catch(InterruptedException e)
			{
				System.out.println("IE caught");
			}
		}
		for(int i=0;i<r;i++)
		{
			sum = sum + t[i].getSum();
		}
		System.out.println("Total sum = "+sum);
	}
}