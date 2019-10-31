import java.lang.*;
import java.util.Scanner;

public class Question2
{
	public static void main(String [] args)
	{
	   Scanner sc = new Scanner(System.in);
	   System.out.println("Enter 3 nos. : ");
	   int a = sc.nextInt();
	   int b = sc.nextInt();
	   int c = sc.nextInt();
	   Question2 obj = new Question2();
	   int dis = b*b - 4*a*c;
	   obj.quadratic(dis,a,b,c);
	}

	public void quadratic(int dis, int a, int b, int c)
	{
       int flag=0;
	   if(dis == 0) flag=1;
	   else if (dis>0) flag=2;
	   else flag=3;
	   switch(flag)
	   {
	   	  case 1:
	   	  System.out.println("Real and equal roots.");
	   	  equal(dis,a,b,c);
	   	  break;

	   	  case 2:
	   	  System.out.println("Real and distinct roots;");
	   	  distinct(dis,a,b,c);
	   	  break;

	   	  case 3:
	   	  System.out.println("Imaginary roots.");
	   	  imaginary(dis,a,b,c);
	   	  break;

	   	  default:
	   	  System.out.println("Invalid input.");
	   }
	}

	public void equal(int dis, int a, int b, int c)
	{
		double x = (-b + Math.sqrt(dis))/(2*a);
		System.out.println("Roots = "+x);
	}

	public void distinct(int dis, int a, int b, int c)
	{
		double x = (-b + Math.sqrt(dis))/(2*a);
		double y = (-b - Math.sqrt(dis))/(2*a);
		System.out.println("Root 1 = "+x);
		System.out.println("Root 2 = "+y);
	}

	public void imaginary(int dis, int a, int b, int c)
	{
		double x = -b/(2*a);
		double y = (Math.sqrt(Math.abs(dis)))/(2*a);
		System.out.println("Root 1 = "+x+"+"+y+"i");
		System.out.println("Root 1 = "+x+"-"+y+"i");
	}
}