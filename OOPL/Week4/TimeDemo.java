import java.lang.*;
import java.util.*;

class Time
{
	private int h, m, s;

	Time()
	{
		h=0; m=0; s=0;
	}

	Time(int h, int m, int s)
	{
		this.h=h;
		this.m=m;
		this.s=s;
	}

	public void display()
	{
		if(h<10) System.out.print("0"+h+":");
		else System.out.print(h+":");
		if(m<10) System.out.print("0"+m+":");
		else System.out.print(m+":");
		if(s<10) System.out.print("0"+s);
		else System.out.print(s);
		System.out.println("");
	}

	Time add(Time obj1)
	{
		int r=0;
		Time obj = new Time();
		obj.s = this.s + obj1.s;
		if(obj.s>=60)
		{
			r = obj.s / 60;
			obj.s = obj.s % 60;
		}
		obj.m = this.m + obj1.m + r;
		r=0;
		if(obj.m>=60)
		{
			r = obj.m / 60;
			obj.m = obj.m % 60;
		}
		obj.h = this.h + obj1.h +r;
		if(obj.h>=24) obj.h=obj.h-24;
		return obj;
	}

	Time sub(Time obj1)
	{
		int r=0;
		Time obj = new Time();

		int t1 = this.h*3600 + this.m*60 + this.s;
		int t2 = obj1.h*3600 + obj1.m*60 + obj1.s;
		int sub = (int)Math.abs(t1-t2);

		obj.h = sub/3600;
		obj.m = (sub%3600)/60;
		obj.s = (sub%3600)%60;

		return obj;
	}

	int compare(Time obj)
	{
		int status=0;
		if(this.h==obj.h)
		{
			if(this.m==obj.m)
			{
				if(this.s==obj.s)
					status=0;
				else if(this.s>obj.s)
					status=1;
				else
					status=2;
			}
			else if(this.m>obj.m)
				status=1;
			else
				status=2;
		}
		else if(this.h>obj.h)
			status=1;
		else 
			status=2;
		return status;
	}
}

public class TimeDemo
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter time 1 in 24 hour format (hh:mm:ss) : ");
		int h = sc.nextInt();
		int m = sc.nextInt();
		int s = sc.nextInt();
		Time t1 = new Time(h,m,s);
		System.out.println("Enter time 2 in 24 hour format (hh:mm:ss) : ");
		h = sc.nextInt();
		m = sc.nextInt();
		s = sc.nextInt();
		Time t2 = new Time(h,m,s);
		System.out.print("Time 1 : ");
		t1.display();
		System.out.print("Time 2 : ");
		t2.display();
		Time t = new Time();
		System.out.print("Sum : ");
		t = t2.add(t1);
		t.display();
		System.out.print("Difference : ");
		t = t2.sub(t1);
		t.display();
		System.out.println("Comparing : ");
		int status = t1.compare(t2);
		if(status==0)
			System.out.println("Both times are equal.");
		else if(status==1)
			System.out.println("Time1 is greater than Time2.");
		else
			System.out.println("Time2 is greater than Time1.");
	}
}