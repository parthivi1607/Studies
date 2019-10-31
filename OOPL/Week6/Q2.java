import myPackage.pckg1.Maximum;
import java.util.*;

class Q2
{
	public static void main(String args[])
	{
		Maximum m = new Maximum();
		System.out.println(m.max(2,7,5));
		System.out.println(m.max(4.7f,3.6f,7.9f));
		int a[] = {9,7,33,2,16};
		System.out.println(m.max(a));
		int b[][] = {{10,3},{7,4}};
		System.out.println(m.max(b));
	}
}