import java.util.*;
import java.lang.*;

class Table extends Thread
{
	private int n;
	Table(int n, String threadName)
	{
		super(threadName);
		this.n=n;
		start();
	}
	public void run()
	{
		if(n==5)setPriority(3);
		if(n==7)setPriority(7);
		for(int i=1;i<=5;i++)
			System.out.println(getName()+" = "+(n*i));
		Thread t = Thread.currentThread();
		System.out.println(t);
	}
}
public class Q1
{
	public static void main(String args[])
	{
		Table t1 = new Table(5,"Table of 5");
		Table t2 = new Table(7,"Table of 7");
		System.out.println("T1 still alive? "+t1.isAlive());
		System.out.println("T2 still alive? "+t2.isAlive());
		System.out.println("T1 priority? "+t1.getPriority());
		System.out.println("T1 priority? "+t1.getPriority());
		Thread t = Thread.currentThread();
		System.out.println(t);
	}
}