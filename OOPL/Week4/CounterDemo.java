import java.lang.*;
import java.util.*;

class Counter
{
	static int c;

	Counter()
	{
		c++;
	}
	static void showCount()
	{
		System.out.println("No. of objects created = "+c);
	}
}

public class CounterDemo
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		Counter obj[] = new Counter[100];
		System.out.println("Do you want to create an obj? y/n");
		char c=sc.next().charAt(0);
		sc.nextLine();
		for(int i=0;c=='y';i++)
		{
			obj[i] = new Counter();
			System.out.println("Do you want to create an obj? y/n");
			c=sc.next().charAt(0);
			sc.nextLine();
		}
		Counter.showCount();
	}
}