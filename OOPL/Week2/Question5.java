import java.lang.*;
import java.util.Scanner;

public class Question5
{
	public static void main(String [] args)
	{
	   Scanner sc = new Scanner(System.in);
	   System.out.print("Enter length of array : ");
	   int n = sc.nextInt();
	   int arr[] = new int[n];
	   System.out.println("Enter elements of array : ");
	   for(int i=0;i<n;i++)
	   {
	   	arr[i] = sc.nextInt();
	   }
	   Question5 obj = new Question5();
	   System.out.print("Original array : ");
	   obj.print(arr);
	   obj.prime(arr);
	}

	public void print(int arr[])
	{
		for(int i=0;i<arr.length;i++)
	   {
	   	System.out.print(arr[i]+" ");
	   }
	   System.out.println("");
	}

	public void prime(int arr[])
	{
		System.out.print("Prime nos. : ");
		for(int i=0; i<arr.length; i++)
		{
			int c=0;
			for(int j=2; j<arr[i]; j++)
			{
				if(arr[i]%j == 0) c++;
			}
			if(c==0) System.out.print(arr[i]+" ");
		}
		System.out.println();
	}
}