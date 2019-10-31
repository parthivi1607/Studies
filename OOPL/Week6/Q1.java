import java.lang.*;
import java.util.*;

class Person
{
	private String name;
	private int y,m,d;

	Person(String n, int y, int m, int d)
	{
		name = n;
		this.y=y;
		this.m=m;
		this.d=d;
	}

	String getName()
	{
		return name;
	}
	int getDate()
	{
		return d;
	}
	int getMonth()
	{
		return m;
	}
	int getYear()
	{
		return y;
	}
}

class CollegeGrad extends Person
{
	private float gpa;
	private int yog;

	CollegeGrad(String n,int y,int m,int d,float gp,int yg)
	{
		super(n,y,m,d);
		gpa=gp;
		yog=yg;
	}

	float getGpa()
	{
		return gpa;
	}
	int getYoG()
	{
		return yog;
	}
}

class Q1
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter name : ");
		String name=sc.nextLine();
		System.out.println("Enter DOB (dd/mm/yyyy) :");
		int d=sc.nextInt();
		int m=sc.nextInt();
		int y=sc.nextInt();
		System.out.print("Enter GPA : ");
		float g=sc.nextFloat();
		System.out.print("Enter year of graduation : ");
		int yg=sc.nextInt();

		CollegeGrad obj = new CollegeGrad(name,y,m,d,g,yg);
		System.out.println("Name : "+obj.getName());
		System.out.println("DOB : "+obj.getDate()+"/"+obj.getMonth()+"/"+obj.getYear());
		System.out.println("GPA : "+obj.getGpa());
		System.out.println("YOG : "+obj.getYoG());
	}
}