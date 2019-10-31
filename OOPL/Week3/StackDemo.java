import java.lang.*;
import java.util.*;

class Stack
{
	int arr[], tos;

	void initialize()
	{
		tos = -1;
	}

	void push(int e)
	{
		if(tos == arr.length-1)
		{
			System.out.println("Stack overflow");
		}
		else
		{
			tos++;
			arr[tos]=e;
		}
	}

	void pop()
	{
		if(tos==-1)
		{
			System.out.println("Stack underflow");
		}
		else
		{
			arr[tos]=0;
			tos--;
		}
	}

	void display()
	{
		System.out.print("Contents of array : ");
		for(int i=0;i<=tos;i++)
			System.out.print(arr[i]+" ");
		System.out.println("");
	}
}

public class StackDemo
{
	public static void main(String [] args)
	{
		Stack obj = new Stack();
		obj.initialize();
		System.out.print("Enter length of array : ");
		Scanner sc = new Scanner(System.in);
		int l = sc.nextInt();
		obj.arr = new int[l];
		System.out.println("Pushing 2, 5, 6, 9 into the stack :");
		obj.push(2);
		obj.push(5);
		obj.push(6);
		obj.push(9);
		obj.display();
		System.out.println("Popping 6, 9 from the stack :");
		obj.pop();
		obj.pop();
		obj.display();
		System.out.println("Pushing 1-9 into the stack :");
		for(int i=1;i<=9;i++)
			obj.push(i);
		obj.display();
		System.out.println("Popping 10 times from the stack :");
		for(int i=1;i<=10;i++)
			obj.pop();
		obj.display();
		System.out.println("Popping once more from the stack :");
		obj.pop();
	}
}