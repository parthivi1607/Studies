import java.util.*;
class Node<T>
{
	T data;
	Node <T> next;
	Node(T d)
	{data=d;}
	void displayNode()
	{
		System.out.println(data);
	}
}
class LinkedList<T>
{
	Node <T> first;
	LinkedList()
	{
		first=null;
	}
	void insertFront(T data)
	{
		Node <T> n =new Node<T>(data);
		n.next=first;
		first=n;
	}
	Node<T> deleteFront()
	{
		if(first==null)
			System.out.println("List is empty!");
		Node<T> temp = first;
		first=first.next;
		temp.displayNode();
		return temp;
	}
	void displayList()
	{
		System.out.println("The nodes in the linked list are:");
		Node <T> temp = first;
		while(temp!=null)
		{
			temp.displayNode();
			temp=temp.next;
		}
		System.out.println();
	}
}
class genericList
{
	public static void main(String[] args) 
	{
		LinkedList<Integer> l1 = new LinkedList<Integer>();
		LinkedList<Double> l2= new LinkedList<Double>();	
		System.out.println("Inserting 3 items into both lists at the front :");
		for(int i=1;i<=3;i++)
		{
			l1.insertFront(i);
			l2.insertFront(5.0*i);
		}	
		l1.displayList();	
		l2.displayList();
		System.out.println("Popping 2 items from both lists from the front :");
		for(int i=1;i<=2;i++)
		{
			l1.deleteFront();
			l2.deleteFront();
		}
		System.out.println("Remaining list :");
		l1.displayList();
		l2.displayList();
	}
}