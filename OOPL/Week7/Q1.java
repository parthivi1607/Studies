import java.util.*;
import java.lang.*;

class Phone
{
	String brand;
	int memCapacity;

	Phone(String b, int m)
	{
		brand=b;
		memCapacity = m;
	}

	interface Callable
	{
		void makeAudioCall(String cellNum);
		void makeVideoCall(String cellNum);
	}
}

class BasicPhone extends Phone implements Phone.Callable
{
	BasicPhone(String b, int m)
	{
		super(b,m);
	}
	void display()
	{
		System.out.println("Brand : "+brand);
		System.out.println("Memory Capacity : "+memCapacity);
	}
	public void makeAudioCall(String cellNum)
	{
		System.out.println("Number : "+cellNum);
		System.out.println("Basic Phone - Audio call allowed.");
	}
	public void makeVideoCall(String cellNum)
	{
		System.out.println("Number : "+cellNum);
		System.out.println("Basic Phone - Video call not allowed.");
	}
}

class SmartPhone extends Phone implements Phone.Callable
{
	SmartPhone(String b, int m)
	{
		super(b,m);
	}
	void display()
	{
		System.out.println("Brand : "+brand);
		System.out.println("Memory Capacity : "+memCapacity);
	}
	public void makeAudioCall(String cellNum)
	{
		System.out.println("Number : "+cellNum);
		System.out.println("Smart Phone - Audio call allowed.");
	}
	public void makeVideoCall(String cellNum)
	{
		System.out.println("Number : "+cellNum);
		System.out.println("Smart Phone - Video call allowed.");
	}
}

class Q1
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter brand, memory capacity & cell no. of phone :");
		String b = sc.nextLine();
		int m = sc.nextInt();
		sc.nextLine();
		String n = sc.nextLine();
		System.out.print("Is your phone 1.basic or 2.smart? ");
		int c = sc.nextInt();
		if(c==1)
		{
			BasicPhone bp = new BasicPhone(b,m);
			bp.display();
			bp.makeAudioCall(n);
			bp.makeVideoCall(n);
		}
		else if(c==2)
		{
			SmartPhone sp = new SmartPhone(b,m);
			sp.display();
			sp.makeAudioCall(n);
			sp.makeVideoCall(n);
		}
	}
}