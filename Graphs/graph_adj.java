import java.io.*;
import java.util.*;

class Graph{
	private Map<Integer,List<Integer>> adjList;
	private int nature,num;

	Graph(int v,int nature)
	{
		adjList=new HashMap<Integer,List<Integer>>();
		this.nature=nature;
		this.num=v;

		for(int i=1; i<=num; i++)
			adjList.put(i,new LinkedList<Integer>());
	}
    
    public void display(List<Integer>lis)
    {		
    	boolean already_list=false;
    	if (lis!=null)already_list=true;

    	System.out.println("\n Displaying adjacency list: \n");
    	for(int i=1; i<=num; i++)
    	{
    		List<Integer>display_list;
    		if(already_list)
    			 display_list=lis;
    		else {
    			display_list=adjList.get(i);
    			System.out.print(" "+i+": ");
    		}

    		try	{
    			for (int j = 0;; j++) 
    			{
            	   if (j != display_list.size()-1)
            	        System.out.print(" "+display_list.get(j)+" -> ");
            	   else  
            	   {
            	   	 System.out.print(" "+display_list.get(j)+" -> X");
            	   	   break;
            	   }
            	}
             }
             catch(java.lang.IndexOutOfBoundsException e)	{
             	System.out.print(" X ");
             }     
    			System.out.println();
    			if(already_list)break; 
    	}
    }


    public List<Integer> getEdgeList(int src)
    {
    	if (src>adjList.size()){
    		System.out.print("The edge does not exist ");
    		return null;
    	}
    	List<Integer> srclist=adjList.get(src);
    	return srclist;
    }


    public void addEdge(int src,int dest)
    {
    	if (src>adjList.size() || dest>adjList.size()){
    		System.out.print(" The vertices do not exist ");
    		return;
    	}
    	boolean flag=false;
    	List<Integer> srclist=adjList.get(src);
    	if(srclist.contains(dest)) {
    		System.out.print(" Edge already exists");
    		return;
    	}

    	srclist.add(dest);

    	if(this.nature==-1){
    		srclist=adjList.get(dest);
    		srclist.add(src);
    		flag=true;
    	}
    	System.out.print(" Edge "+src+"-"+dest+" added.");
    	if(flag)
    		System.out.print(" Edge "+dest+"-"+src+" added.");
    }


    public void removeEdge(int src,int dest)
    {
    	if (src>adjList.size() || dest>adjList.size()){
    		System.out.print(" The vertices do not exist ");
    		return;
    	}

    	boolean flag=false;
    	List<Integer> srclist=adjList.get(src);
    	if (!srclist.contains(dest)){
    		System.out.print(" No such edge exists\n");
    		return;
    	}
    	srclist.remove(new Integer(dest));

    	if(this.nature==-1){
    		srclist=adjList.get(dest);
    		srclist.remove(src);
    		flag=true;
    	}
    	System.out.print(" Edge "+src+"-"+dest+" removed.\n");
    	if(flag)
    		System.out.print(" Edge "+dest+"-"+src+" removed.\n");
    }

    public void options(Scanner sc)
    {
    	int c=1;
    	while(c!=0){
	    	System.out.println("\n Menu : \n");
	    	System.out.println("1: Display");
	    	System.out.println("2: Add Edge");
	    	System.out.println("3: Remove Edge");
	    	System.out.println("4: Get Edge List");
	    	System.out.print("0: Exit  ");
	    	c=sc.nextInt();
	    	switch(c){
	    		case 1:display(null);	break;
	    		case 2:System.out.print("\n Enter edge directions to add: ");
	    			   addEdge(sc.nextInt(),sc.nextInt());
	    			   break;
	    		case 3:System.out.print("\n Enter edge directions to remove: ");
	    			   removeEdge(sc.nextInt(),sc.nextInt());
	    			   break;
	    		case 4:System.out.print("\n Enter source for the edge list: ");
	    			   List<Integer>l=getEdgeList(sc.nextInt());
	    			   display(l);
	    			   break;
	    		case 0:System.out.println("\t Exiting");
	    		default:
	    		}
	    	}
    }

	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		Graph g;
		int num,nature,choice=0,src,dest;

		try{
			System.out.print("\n Enter number of nodes in the graph: ");
			num=sc.nextInt();

			System.out.print(" Graph is directed(1) or undirected(-1): ");
			nature=sc.nextInt();

			g=new Graph(num,nature);
			while(choice!=-1)
			{
				System.out.print("\n\n Enter edge directions(-1 to quit adding): ");
					src=sc.nextInt();
				   dest=sc.nextInt();
				if((src==-1 || dest==-1) || (src<-1 || dest<-1))
					choice=-1;
				else
				 g.addEdge(src,dest);
			}
			g.options(sc);
		}
		catch(Exception e)
		{System.out.println(" Error:  "+e);}

		sc.close();
	}
}