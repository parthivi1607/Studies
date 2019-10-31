import java.lang.*;
import java.util.Scanner;

public class Question6
{
	public static void main(String [] args)
	{
	   Scanner sc = new Scanner(System.in);
	   System.out.println("Enter n : ");
	   int n = sc.nextInt();
	   Question6 obj = new Question6();
	   obj.sumdigit(n);
	}
	public void sumdigit(int x)
	{
		int t=x,sum=0;
		boolean flag=false;
		for(;x>0;x=x/10)
		{
			int r=x%10;
			sum = sum + r;
		}
		System.out.println("Sum of digits = "+sum);
	}
}