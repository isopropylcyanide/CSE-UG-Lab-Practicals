import java.util.*;
import java.lang.*;

class A{
	protected List<Integer>mylist;
	int len;

	A(){
		mylist=null;
	}
	A(int v,String args[])
	{
		this.len=v;
		mylist=new LinkedList<Integer>();
		for(int i=0; i<v; i++){
			int x=Integer.parseInt(args[i]);
			if(!mylist.contains(x))
				mylist.add(x);
		}
	}
}

j 

class B extends A{
	private int i;

	B(){
		super();
	}

	B(int v,String args[])
	{
		super(v,args);
	}
	public void display()
	{
		if(mylist==null){
			System.out.println("List is empty");
			return;
		}

		for(i=0; i<mylist.size(); i++){
			System.out.print(" -> "+mylist.get(i));
		}
	}

	public void add(int x)
	{
		if (mylist.contains(x)){
			System.out.println(x+ " exists already ");
			return;
		}
		else mylist.add(x);
	}


	public static void main(String args[])
	{
		B b1=new B(args.length,args);
		b1.display();
		System.out.println("\n");
		
		B b2=new B();
		b2.display();
		System.out.println("\n");
	}
}