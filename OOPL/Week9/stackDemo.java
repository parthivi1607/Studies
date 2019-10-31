import java.util.*;
class Student
{
	String name;
	int rollno;
	Student(String s, int n)
	{
		name=s;
		rollno=n;
	}
	public String  toString()
	{
		return "Student name: "+name+"\nStudent rollno: "+rollno+"\n";
	}
}
class Employee
{
	String name;
	int idno;
	Employee(String s, int n)
	{
		name=s;
		idno=n;
	}
	public String  toString()
	{
		return "Employee name: "+name+"\nEmployee idno: "+idno+"\n";
	}
}
class  stackClass<T>
{
	int top;
	T[] arr=(T[])new Object[5];

	stackClass()
	{top=-1;
	// arr=(T[]) new Object[5];
	}
	void push(T obj)
	{
		if(top+1<5)
			arr[++top]=obj;
		else
			System.out.println("Overload!");
		System.out.println("top = "+top);

	}
	void pop()
	{
		System.out.println("After popping!");
		if(top>=0)
			 System.out.println(arr[top--]);
		else
			System.out.println("Underload!");
	}
	void display1()
	{	
		if(top<0)
		{
			System.out.println("Empty list!"); return;
		}
		// System.out.println("Stack element type: "+arr[0].getClass().getName());
		for(int i=0;i<=top;i++)
			System.out.println(arr[i]);
		System.out.println();

	}
}
class stackDemo
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		stackClass<Student> s1 = new stackClass<Student>();
		for(int i=0;i<3;i++)
		{
			System.out.println("Enter details for student "+(i+1)+" below!");
			s1.push(new Student(sc.nextLine(),sc.nextInt()));
			sc.nextLine();
		}
		s1.display1();		
		s1.pop();
		s1.pop();
		System.out.println("Stack remaining!");
		s1.display1();

		System.out.println("For employee class");
		stackClass<Employee> s2 = new stackClass<Employee>();
		for(int i=0;i<3;i++)
		{
			System.out.println("Enter details for employee "+(i+1)+" below!");
			s2.push(new Employee(sc.nextLine(),sc.nextInt()));
			sc.nextLine();
		}
		s2.display1();		
		s2.pop();
		s2.pop();
		System.out.println("Stack remaining!");
		s2.display1();
	}
}