import java.lang.*;
import java.util.Scanner;

public class Question3
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
	   Question3 obj = new Question3();
	   System.out.print("Original array : ");
	   obj.print(arr);
	   boolean flag = obj.search(arr);
	   if(flag==false) System.out.println("Element not found.");
	   else System.out.println("Element found.");
	}

	public void print(int arr[])
	{
		for(int i=0;i<arr.length;i++)
	   {
	   	System.out.print(arr[i]+" ");
	   }
	   System.out.println("");
	}

	public boolean search(int arr[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter element to be searched : ");
	    int p = sc.nextInt();
	    boolean flag=false;
	    for(int i=0;i<arr.length;i++)
	    {
	    	if(arr[i]==p)
	    	{
	    		flag=true;
	    		break;
	    	}
	    }
	    return flag;
	}
}