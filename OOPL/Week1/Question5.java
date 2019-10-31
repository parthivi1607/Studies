import java.lang.*;
import java.util.Scanner;

public class Question5
{
	public static void main(String [] args)
	{
	   Scanner sc = new Scanner(System.in);
	   System.out.println("Enter n : ");
	   int n = sc.nextInt();
	   Question5 obj = new Question5();
	   if(obj.isArmstrong(n)) System.out.println("Armstrong no.");
	   else System.out.println("Not Armstrong no.");
	}
	public boolean isArmstrong(int x)
	{
		int t=x,sum=0;
		boolean flag=false;
		for(;x>0;x=x/10)
		{
			int r=x%10;
			sum = sum + (int)Math.pow(r,3);
		}
		if(sum == t) flag=true;
		return flag;
	}
}