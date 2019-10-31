import java.lang.*;
import java.util.Scanner;

public class Question1
{
	public static void main(String [] args)
	{
	   Scanner sc = new Scanner(System.in);
	   System.out.println("Enter 3 nos. : ");
	   int a = sc.nextInt();
	   int b = sc.nextInt();
	   int c = sc.nextInt();
	   Question1 obj = new Question1();
	   int large = obj.largest(a,b,c);
	   System.out.println("Largest no. = "+large);
	}

	public int largest(int a, int b, int c)
	{
	   int large=0;
	   if(a>b)
	   {
	      if(a>c) large = a;
	      else large = c;
	   }
	   else
	   {
	      if(b>c) large = b;
	      else large = c;
	   }
	   return large;
	}
}