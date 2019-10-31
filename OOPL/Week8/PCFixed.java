import java.util.*;
import java.lang.*;

import java.util.*;
import java.lang.*;

class Q
{
	int n;
	boolean valueSet = false;

	int get()
	{
		if(!valueSet)
			try
			{
				wait();
			}
			catch(InterruptedException e)
			{
				System.out.println("Interrupted Exception caught.");
			}
		System.out.println("Get : "+n);
		valueSet=false;
		notifyAll();
		return n;
	}
	void put(int n)
	{
		if(valueSet)
			try
			{
				wait();
			}
			catch(InterruptedException e)
			{
				System.out.println("Interrupted Exception caught.");
			}
		this.n=n;
		valueSet = true;
		System.out.println("Put : "+n);
		notify();
	}
}
class Producer implements Runnable
{
	Q q;
	Producer(Q q)
	{
		this.q=q;
		new Thread(this,"Producer").start();
	}
	public void run()
	{
		int i=0;
		while(true)
		{
			synchronized(q)
			{
				q.put(i++);
			}
		}
	}
}
class Consumer implements Runnable
{
	Q q;
	Consumer(Q q)
	{
		this.q=q;
		new Thread(this,"Consumer").start();
	}
	public void run()
	{
		while(true)
		{
			synchronized(q)
			{
				q.get();
			}
		}
	}
}
public class PCFixed
{
	public static void main(String args[])
	{
		Q q = new Q();
		new Producer(q);
		new Consumer(q);
	}
}