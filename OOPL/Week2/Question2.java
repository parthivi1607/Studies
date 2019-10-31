import java.lang.*;
import java.util.Scanner;

public class Question2
{
	public static void main(String [] args)
	{
	   Scanner sc = new Scanner(System.in);
	   System.out.print("Enter length of array : ");
	   int n = sc.nextInt();
	   int arr[] = new int[n];
	   int brr[] = new int[n];
	   System.out.println("Enter elements of array : ");
	   for(int i=0;i<n;i++)
	   {
	   	arr[i] = sc.nextInt();
	   }
	   Question2 obj = new Question2();
	   System.out.print("Original array : ");
	   obj.print(arr);

	   System.out.print("Enter position where element is to be inserted : ");
	   int p = sc.nextInt();
	   System.out.print("Enter element to be inserted : ");
	   int x = sc.nextInt();
	   brr = obj.insert(arr,p,x);
	   obj.print(brr);

	   System.out.print("Enter position where element is to be deleted : ");
	   p = sc.nextInt();
	   brr = obj.delete(arr,p);
	   obj.print(brr);
	}

	public void print(int arr[])
	{
		for(int i=0;i<arr.length;i++)
	   {
	   	System.out.print(arr[i]+" ");
	   }
	   System.out.println("");
	}

	public int[] insert(int arr[], int p, int x)
	{
		int brr[] = new int[arr.length+1];
		for(int i=0, j=0; i<arr.length && j<brr.length; j++)
		{
			if(j==(p-1))
			{
				brr[j] = x;
			}
			else
			{
				brr[j] = arr[i];
				i++;
			}
		}
		return brr;
	}

	public int[] delete(int arr[], int p)
	{
		int brr[] = new int[arr.length-1];
		for(int i=0, j=0; i<arr.length && j<brr.length; i++)
		{
			if(i!=(p-1))
			{
				brr[j]=arr[i];
				j++;
			}
		}
		return brr;
	}
}