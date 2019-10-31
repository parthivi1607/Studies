import java.lang.*;
import java.util.*;

abstract class Figure
{
	int x,y;
	abstract float area();
}

class Rectangle extends Figure
{
	Rectangle(int l,int b)
	{
		x=l; y=b;
	}
	float area()
	{
		return x*y;
	}
}

class Triangle extends Figure
{
	Triangle(int h, int b)
	{
		x=h; y=b;
	}
	float area()
	{
		return 0.5f*x*y;
	}
}

class Square extends Figure
{
	Square(int s)
	{
		x=y=s;
	}
	float area()
	{
		return x*y;
	}
}

class Q3
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter length & breadth of rectangle : ");
		int x=sc.nextInt();
		int y=sc.nextInt();
		Figure r = new Rectangle(x,y);
		System.out.print("Enter side of square : ");
		x=sc.nextInt();
		Figure s = new Square(x);
		System.out.println("Enter height & base of triangle : ");
		x=sc.nextInt();
		y=sc.nextInt();
		Figure t = new Triangle(x,y);
		System.out.println("Area of rectangle : "+r.area());
		System.out.println("Area of triangle : "+t.area());
		System.out.println("Area of square : "+s.area());
	}
}