import java.util.*;
import java.lang.*;

class SeatsFilledException extends Exception
{
	public String toString()
	{
		return ("All seats filled.");
	}
}

class Student
{
	int regno;
	String name;
	GregorianCalendar doj;
	short sem;
	float gpa,cgpa;
	static int c;

	Student()
	{
		regno=0;
		name="";
		sem=0;
		gpa=cgpa=0;
		c=0;
	}
	Student(String n, GregorianCalendar obj, short s, float gp, float cg) throws SeatsFilledException
	{
		name=n;
		doj = new GregorianCalendar(obj.get(GregorianCalendar.YEAR), obj.get(GregorianCalendar.MONTH),obj.get(GregorianCalendar.DAY_OF_MONTH));
		sem=s;
		gpa=gp;
		cgpa=cg;
		c++;
		if(c<=2) regno=(obj.get(GregorianCalendar.YEAR)%100)*100+c;
		else throw (new SeatsFilledException());
	}	

	void display()
	{
		System.out.println("Reg. no. : "+regno);
		System.out.println("Name : "+name);
		System.out.println("Date of joining : "+doj.get(GregorianCalendar.DAY_OF_MONTH)+"/"+(doj.get(GregorianCalendar.MONTH)+1)+"/"+doj.get(GregorianCalendar.YEAR));
		System.out.println("Sem : "+sem);
		System.out.println("GPA : "+gpa);
		System.out.println("CGPA : "+cgpa);
	}
}

public class Q3
{
	public static void main(String [] args)
	{
		Scanner sc=new Scanner(System.in);
		Student obj[] = new Student[26];
		Student.c=0;
		try
		{
			System.out.print("Do you want to enter details? (y/n) : ");
			char ch = sc.next().charAt(0);
			int i=-1;
			while(ch=='y')
			{
				i++;
				sc.nextLine();
				System.out.println("Enter record for student "+(i+1)+" :");
				System.out.print("Enter name : ");
				String nm=sc.nextLine();
				System.out.println("Enter date of joining (y,m,d) : ");
				int y=sc.nextInt();
				int m=sc.nextInt();
				int d=sc.nextInt();
				GregorianCalendar gc = new GregorianCalendar(y,m-1,d);
				System.out.print("Enter sem : ");
				short s=sc.nextShort();
				System.out.print("Enter GPA : ");
				float gp=sc.nextFloat();
				System.out.print("Enter CGPA : ");
				float cg=sc.nextFloat();
				obj[i]=new Student(nm,gc,s,gp,cg);
				System.out.println("");
				System.out.print("Do you want to enter details? (y/n) : ");
				ch = sc.next().charAt(0);
			}
		}
		catch(SeatsFilledException sfe)
		{
			System.out.println(sfe);
			Student.c--;
		}
		System.out.println("");
		System.out.println("Student Records :-");
		for(int i=0;i<Student.c;i++)
		{
			System.out.println("Student "+(i+1)+" :");
			obj[i].display();
		}
	}
}