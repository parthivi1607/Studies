import java.lang.*;
import java.util.Scanner;

public class Question3
{
	public static void main(String [] args)
	{
	   Scanner sc = new Scanner(System.in);
	   System.out.println("Enter n : ");
	   int n = sc.nextInt();
	   System.out.println("Enter r : ");
	   int r = sc.nextInt();
	   if(r>n)
	   	System.out.println("r should be less than n.");
	   else
	   {
	   	Question3 obj = new Question3();
	    int nn = obj.fact(n);
	    int rr = obj.fact(r);
	    int di = obj.fact(n-r);
	    double val = nn/(rr*di);
	    System.out.println("nCr = "+val);
	   }
	}

	public int fact(int n)
	{
		if(n==0) return 1;
		else
		{
			return n*fact(--n);
		}
	}
}