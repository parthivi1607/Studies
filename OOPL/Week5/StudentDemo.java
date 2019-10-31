import java.lang.*;
import java.util.Scanner;
import java.util.GregorianCalendar;

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
	Student(String n, GregorianCalendar obj, short s, float gp, float cg)
	{
		c++;
		regno=(obj.get(GregorianCalendar.YEAR)%100)*100+c;
		name=n;
		doj = new GregorianCalendar(obj.get(GregorianCalendar.YEAR), obj.get(GregorianCalendar.MONTH),obj.get(GregorianCalendar.DAY_OF_MONTH));
		sem=s;
		gpa=gp;
		cgpa=cg;
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

	void initialName()
	{
		String s=name;
		String result=s.charAt(0)+"."+s.charAt(s.indexOf(' ')+1)+"."+s.substring(s.lastIndexOf(' ')+1);
		System.out.println("Shortened name : "+result);
	}

	void sortSemnCgpa(Student arr[])
	{
		int n=arr.length;
		Student temp;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-1-i;j++)
			{
				if(arr[j].sem>arr[j+1].sem)
				{
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
				if(arr[j]==arr[j+1])
				{
					if(arr[j].cgpa > arr[j+1].cgpa)
					{
						temp=arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temp;
					}
				}
			}
		}
		for(int i=0;i<n;i++)
			arr[i].display();
	}

	void sortName(Student arr[])
	{
		int n=arr.length;
		Student temp;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-1-i;j++)
			{
				if(arr[j].name.compareTo(arr[j+1].name)>0)
				{
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
		for(int i=0;i<n;i++)
			arr[i].display();
	}

	void startingChar(Student arr[])
	{
		int n=arr.length;
		Scanner sc =new Scanner(System.in);
		System.out.println("Enter the string char below : ");
		char c=sc.next().charAt(0);
		for(int i=0;i<n;i++)
			if(arr[i].name.charAt(0)==c)
				arr[i].display();
	}

	void checkSubStr(Student arr[])
	{
		int n=arr.length;
		Scanner sc =new Scanner(System.in);
		System.out.println("Enter substring below : ");
		String sub=sc.nextLine();
		for(int i=0;i<n;i++)
			if(arr[i].name.indexOf(sub) !=-1)
				arr[i].display();
	}
}

public class StudentDemo
{
	public static void main(String [] args)
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter no. of students : ");
		int n=sc.nextInt();
		Student obj[] = new Student[n];
		Student.c=0;
		for(int i=0; i<n; i++)
		{
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
		}
		System.out.println("");
		System.out.println("Student Records :-");
		for(int i=0;i<n;i++)
		{
			System.out.println("Student "+(i+1)+" :");
			obj[i].display();
		}
		System.out.println("");
		System.out.println("Sorting by sem & cgpa :");
		obj[0].sortSemnCgpa(obj);
		System.out.println("Sorting by name :");
		obj[0].sortName(obj);
		System.out.println("Searching by starting char :");
		obj[0].startingChar(obj);
		System.out.println("Searching by substring :");
		obj[0].checkSubStr(obj);
		System.out.println("Initials :");
		for(int i=0;i<n;i++)
			obj[i].initialName();
	}
}