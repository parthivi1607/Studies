import java.lang.*;
import java.util.Scanner;

public class Question4
{
	public static void main(String [] args)
	{
	   Scanner sc = new Scanner(System.in);
	   System.out.print("Enter no. of rows of array : ");
	   int r = sc.nextInt();
	   System.out.print("Enter no. of columns of array : ");
	   int c = sc.nextInt();
	   int arr[][] = new int[r][c];
	   int brr[][] = new int[r][c];
	   int crr[][] = new int[r][c];
	   System.out.println("Enter elements of array A : ");
	   for(int i=0;i<r;i++)
	   {
	   	for(int j=0; j<c; j++)
	   	{
	   		arr[i][j] = sc.nextInt();
	   	}
	   }
	   System.out.println("Enter elements of array B : ");
	   for(int i=0;i<r;i++)
	   {
	   	for(int j=0; j<c; j++)
	   	{
	   		brr[i][j] = sc.nextInt();
	   	}
	   }
	   Question4 obj = new Question4();
	   System.out.println("Array A : ");
	   obj.print(arr);
	   System.out.println("Array B : ");
	   obj.print(brr);
	   System.out.println("Array C = A + B : ");
	   crr = obj.sum(arr,brr);
	   obj.print(crr);
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

	public int[][] sum(int arr[][], int brr[][])
	{
		int crr[][] = new int[brr.length][brr[0].length];
		for(int i=0; i<arr.length; i++)
		{
			for(int j=0; j<arr[0].length; j++)
			{
				crr[i][j] = arr[i][j] + brr[i][j];
			}
		}
		return crr;
	}	
}