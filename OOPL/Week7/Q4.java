import java.util.*;
import java.lang.*;

interface Series
{
	int getNext();
	void reset();
	void setStart(int x);
}
class ByTwos implements Series
{
	int s;
	public int getNext()
	{
		s=s+2;
		return s;
	}
	public void reset()
	{
		s=0;
	}
	public void setStart(int x)
	{
		s=x;
	}
}
class Q4
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		ByTwos obj = new ByTwos();
		System.out.print("Enter starting of series : ");
		int x = sc.nextInt();
		if(x==0) obj.reset();
		else obj.setStart(x);
		System.out.print("Enter no. of terms : ");
		int n = sc.nextInt();
		System.out.print(obj.s+" ");
		for(int i=1;i<n;i++)
			System.out.print(obj.getNext()+" ");
		System.out.println();
		obj.reset();
	}
}