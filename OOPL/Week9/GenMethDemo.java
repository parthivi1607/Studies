import java.lang.*;
import java.util.*;

class Generic
{
	public static <T> void swap(T [] arr, int x, int y)
	{
		T t = arr[x];
		arr[x] = arr[y];
		arr[y]=t;
		System.out.print("Output : ");
		for(T i:arr)
			System.out.print(i+" ");
		System.out.println();
	}
}
public class GenMethDemo
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter length of array : ");
		int n = sc.nextInt();
		Integer arr[] = new Integer[n];
		System.out.println("Enter values :");
		for(int i=0;i<n;i++)
			arr[i] = sc.nextInt();
		System.out.println("Enter indexes to swap :");
		int y = sc.nextInt();
		int z = sc.nextInt();
		Generic.swap(arr,y,z);
	}
}