import java.lang.*;
import java.util.Scanner;

class CommaDigit
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Input string : ");
		String ip = sc.next();
		sc.nextLine();
		String op="";
		int c=0;
		for(int i=ip.length()-1;i>=0;i--)
		{
			if(c%3==0 && c!=0)
			{
				op=","+op;
			}
			op=ip.charAt(i)+op;
			c++;
		}
		System.out.println("Output string : "+op);
	}
}