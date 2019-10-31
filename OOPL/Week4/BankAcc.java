import java.lang.*;
import java.util.*;

class Bank
{
	String name, type;
	long accno;
	double bal;
	static long number;
	static int roi;

	static
	{
		number=0;
		roi=0;
	}
	Bank()
	{
		name=type="";
		accno=0;
		bal=0.0;
	}
	Bank(String name, String type, double bal)
	{
		this.name=name;
		this.type=type;
		this.bal=bal;
		this.accno=++number;
	}

	void deposit(double b)
	{
		this.bal=this.bal + b;
	}
	void withdraw(double b)
	{
		if(this.bal<b)
		{
			System.out.println("Insufficient balance.");
		}
		else
		{
			this.bal=this.bal-b;
		}
	}
	void display()
	{
		System.out.println("Name: "+name);
		System.out.println("Acc type: "+type);
		System.out.println("Acc no: "+accno);
		System.out.println("Balance= Rs. "+bal);
	}
	static void rate()
	{
		System.out.println("Roi: "+roi+"%");
	}
}

public class BankAcc
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter no. of members : ");
		int c=sc.nextInt();
		System.out.print("Enter acc no initialize : ");
		int num=sc.nextInt();
		Bank.number=num;
		Bank obj[] = new Bank[c];
		for(int i=0;i<c;i++)
		{
			System.out.println("Enter name, type, bal, roi : ");
			String name=sc.nextLine();
			String type=sc.nextLine();
			sc.nextLine();
			double bal=sc.nextDouble();
			int roi=sc.nextInt();
			obj[i] = new Bank(name,type,bal);
			Bank.roi=roi;
			System.out.println("Enter amt to deposit:");
			double amt=sc.nextDouble();
			obj[i].deposit(amt);
			System.out.println("Enter amt to withdraw:");
			amt=sc.nextDouble();
			obj[i].withdraw(amt);
			obj[i].display();
			Bank.rate();
		}
	}
}