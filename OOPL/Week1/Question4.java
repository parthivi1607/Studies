import java.lang.*;
import java.util.Scanner;

public class Question4
{
	public static void main(String [] args)
	{
	   Scanner sc = new Scanner(System.in);
	   System.out.println("Enter n : ");
	   int n = sc.nextInt();
	   Question4 obj = new Question4();
	   int c=0;
	   System.out.println("Prime nos. : ");
	   for(int i=2; c<n; i++)
	   {
	   	if(obj.isPrime(i))
	   	{
	   		System.out.println(i);
	   		c++;
	   	} 
	   }
	}

	public boolean isPrime(int x)
	{
		boolean flag=false;
		int c=0;
		for(int i=2;i<x;i++)
		{
			if(x%i == 0)c++;
		}
		if(c==0) flag=true;
		else flag=false;
		return flag;
	}
}