import java.lang.*;
import java.util.*;

class Complex
{
	private double a,b;

	Complex()
	{
		a=b=0.0;
	}

	Complex(double a,  double b)
	{
		this.a=a;
		this.b=b;
	}

	void assign(double a, double b)
	{
		this.a=a;
		this.b=b;
	}

	void display()
	{
		System.out.println("Complex no. : "+a+" + i"+b);
	}

	Complex add(Complex obj1, Complex obj2)
	{
		Complex obj = new Complex();
		obj.a = obj1.a + obj2.a;
		obj.b = obj1.b + obj2.b;
		return obj;
	}

	Complex sub(Complex obj1)
	{
		Complex obj = new Complex();
		obj.a = (obj1.a - this.a);
		obj.b = (obj1.b - this.b);
		return obj;
	}
}

public class ComplexDemo
{
	public static void main(String [] args)
	{
		Scanner sc = new Scanner(System.in);
		Complex obj1 = new Complex();
		System.out.println("Enter real and imaginary part of first complex no. : ");
		double a = sc.nextDouble();
		double b = sc.nextDouble();
		obj1.assign(a,b);
		System.out.println("Enter real and imaginary part of second complex no. : ");
		a = sc.nextDouble();
		b = sc.nextDouble();
		Complex obj2 = new Complex(a,b);
		Complex obj = new Complex();
		obj=obj.add(obj1,obj2);
		System.out.println("Sum : ");
		obj.display();
		obj=obj2.sub(obj1);
		System.out.println("Difference : ");
		obj.display();
	}
}