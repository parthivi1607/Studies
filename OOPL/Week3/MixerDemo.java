import java.lang.*;
import java.util.*;

class Mixer
{
	int arr[];

	void accept()
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter length : ");
		int l = sc.nextInt();
		arr = new int[l];
		System.out.println("Enter an array sorted in ascending order w/o duplicates : ");
		for(int i=0; i<arr.length; i++)
			arr[i] = sc.nextInt();
	}

	void display()
	{
		for(int i=0; i<arr.length; i++)
			System.out.print(arr[i]+" ");
		System.out.println();
	}

	Mixer mix(Mixer A)
	{
		Mixer m = new Mixer();
		m.arr = new int[this.arr.length + A.arr.length];
		int i,j, k;
		for(i=0, j=0, k=0; i<this.arr.length && j<A.arr.length;)
		{
			if(this.arr[i]<A.arr[j])
			{
				m.arr[k] = this.arr[i];
				k++;
				i++;
			}
			else if(this.arr[i]>A.arr[j])
			{
				m.arr[k] = A.arr[j];
				k++;
				j++;
			}
			else if(this.arr[i] == A.arr[j])
			{
				m.arr[k] = this.arr[i];
				k++;
				i++;
				j++;
			}
		}
		if(i == this.arr.length && j<A.arr.length)
		{
			for(;j<A.arr.length; j++, k++)
			{
				m.arr[k] = A.arr[j];
			}
		}
		else if(i<this.arr.length && j == A.arr.length)
		{
			for(;i<this.arr.length; i++, k++)
			{
				m.arr[k] = this.arr[i];
			}
		}
		Mixer mn = new Mixer();
		mn.arr = new int[k];
		for(i=0;i<k;i++)
		{
			mn.arr[i]=m.arr[i];
		}
		return mn;
	}
}

public class MixerDemo
{
	public static void main(String args[])
	{
		System.out.println("Array 1 :");
		Mixer m1 = new Mixer();
		m1.accept();
		System.out.println("Array 2 :");
		Mixer m2 = new Mixer();
		m2.accept();
		Mixer m = new Mixer();
		System.out.print("Array 1 : ");
		m1.display();
		System.out.print("Array 2 : ");
		m2.display();
		System.out.print("Merged array : ");
		m = m2.mix(m1);
		m.display();
	}
}