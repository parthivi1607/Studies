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

	public Time add(Time obj1)
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
		if(obj.m>=60)
		{
			r = obj.m / 60;
			obj.m = obj.m % 60;
		}
		obj.h = this.h + obj1.h +r;
		return obj;
	}

	public Time sub(Time obj1)
	{
		int r=0;
		Time obj = new Time();
		obj.s = Math.abs(this.s - obj1.s);
		if(obj.s>=60)
		{
			r = obj.s / 60;
			obj.s = obj.s % 60;
		}
		obj.m = Math.abs(this.m - obj1.m) + r;
		if(obj.m>=60)
		{
			r = obj.m / 60;
			obj.m = obj.m % 60;
		}
		obj.h = Math.abs(this.h - obj1.h) +r;
		return obj;
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
		System.out.println("");
	}
}