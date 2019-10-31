import java.lang.*;
import java.util.Scanner;

public class Question1
{
	public static void main(String [] args)
	{
	   Scanner sc = new Scanner(System.in);
	   System.out.print("Enter length of array : ");
	   int n = sc.nextInt();
	   int arr[] = new int[n];
	   int brr[] = new int[n];
	   int crr[] = new int[n];
	   System.out.println("Enter elements of array : ");
	   for(int i=0;i<n;i++)
	   {
	   	arr[i] = sc.nextInt();
	   }
	   Question1 obj = new Question1();
	   System.out.print("Original array : ");
	   obj.print(arr);
	   brr = obj.ascending(arr);
	   System.out.print("Ascending order : ");
	   obj.print(brr);
	   crr = obj.descending(arr);
	   System.out.print("Descending order : ");
	   obj.print(crr);
	}

	public void print(int arr[])
	{
		for(int i=0;i<arr.length;i++)
	   {
	   	System.out.print(arr[i]+" ");
	   }
	   System.out.println("");
	}

	public int[] ascending(int arr[])
	{
		int temp;
		for(int i=0; i<arr.length-1; i++)
		{
			for(int j=i+1; j<arr.length; j++)
			{
				if(arr[i]>arr[j])
				{
					temp = arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}
		}
		return arr;
	}

	public int[] descending(int arr[])
	{
		int temp;
		for(int i=0; i<arr.length-1; i++)
		{
			for(int j=i+1; j<arr.length; j++)
			{
				if(arr[i]<arr[j])
				{
					temp = arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}
		}
		return arr;
	}
}