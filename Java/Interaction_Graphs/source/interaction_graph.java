import java.lang.*;
import java.util.*;
import java.io.*;
import java.text.DecimalFormat;									/*For Displaying 01 as 01*/


class int_to_binary_stack{
	private Stack<String>st=new Stack<String>();				/*Stack for String elements*/
	private Stack<Integer>st_int=new Stack<Integer>();			/*Stack for Integer elements*/
	private String result,temp;

	protected String binary_convert(int number,int times){
		/*Takes a number and returns its binary representation
		  as a string with a minimum of 'times' characters */

		int x=number%2;
		result=new String();
		temp=new String();

		while(times>0){
			if (x==1)st.push("1");
				else st.push("0");
			number/=2;
			x=number%2;
			times-=1;
		}
		while(st.empty()==false){
			temp=result.concat(st.pop());
			result=temp;
		}
		return result;
	}

	protected void explicit_push(int x){
		/*Pushes an int into stack*/
		st_int.push(new Integer(x));
	}

	protected String explicit_pop(){
		/*Returns the string formed as a result
		  of popping the stack until empty*/

		result=new String();
		temp=new String();

		while(st_int.empty()==false){
			temp=result.concat(st_int.pop().toString());
			result=temp;
		}
		return result;
	}

}

class interaction_graph extends int_to_binary_stack {

	private int[][] permute;									/*2D Array for Original Table*/
	private int[][] fd_table;									/*2D Array for FD Table */
	private int nodes,max_var,boolean_func,fd_comb;
	private Map<Integer,String>fd_map;							/*Map to match FD with a two digit string*/
	private Map<Integer,HashSet<String>>dominant_in_fd;			/*Map to store all dominant edges in FD*/
	private Map<Integer,Integer>fd_graph_pos,fd_graph_neg;		/*Map to store all positive and negative from FD Table*/

	private static final int positive=1;						/*FD is positive for 01*/
	private static final int negative=10;						/*FD is negative for 10*/
	public static int current_object=0;							/*Finds current node*/

	public interaction_graph(int n,int node){
		/*Constructor for each node's properties*/

		this.boolean_func=n;
		this.nodes=node;
		this.max_var=1<<nodes;									/*Maximum states 2^(nodes)*/
		current_object+=1;
		fd_comb=1<<(nodes-1);
		permute=new int[max_var][nodes+1];
		fd_table =new int[fd_comb*fd_comb][fd_comb*fd_comb];

		fd_map=new HashMap<Integer,String>();					/*Create a map for each node's FD*/
		set_fd_map(fd_map,nodes);

		dominant_in_fd=new HashMap<Integer,HashSet<String>>();
		fd_graph_pos=new HashMap<Integer,Integer>();
		fd_graph_neg=new HashMap<Integer,Integer>();
		continue_work();
	}

	private void set_fd_map(Map<Integer,String>fd_map,int nodes){
		switch(nodes){
			case 2:
				fd_map.put(1,"1");
				fd_map.put(2,"2");
				break;
			case 3:
				fd_map.put(1,"12");
				fd_map.put(2,"13");
				fd_map.put(3,"23");
				break;
			case 4:
				fd_map.put(1,"123");
				fd_map.put(2,"124");
				fd_map.put(3,"134");
				fd_map.put(4,"234");
				break;

			case 5:
				fd_map.put(1,"1234");
				fd_map.put(2,"1235");
				fd_map.put(3,"1245");
				fd_map.put(4,"1345");
				fd_map.put(5,"2345");
		}
	}

	private void continue_work(){
		/*Depicts flow of work to be done for each node*/

		//System.out.println("In for : "+boolean_func+"\n");
		fill_table();
		// show_table();
		create_fd();
		// show_fd_table();
		get_dominant_from_fd_table();
		create_fd_graph();
	}

	private void fill_table(){
		/*Create the Permute table for calculations*/

		for(int i=0; i<max_var; i++){
			String bin=binary_convert(i,nodes);
			for(int j=0; j<nodes; j++)
				permute[i][j]=bin.charAt(j)-'0';
		}

		String val=binary_convert(boolean_func,max_var);
		StringBuffer sb = new StringBuffer(val);
		// sb = sb.reverse();
		for(int i=0;i<max_var; i++)
			permute[i][nodes]=sb.charAt(i)-'0';
	}

	private void create_fd(){
		/*Create FD table for each node For each index(0-3) in binary
		  Get two indices which determine the two values in permute[][] to
		  be checked. For each FD in node 1
		  FD 1=FD11
		  FD 2=FD13
		  FD 3=FD23, get the map values ,scan all rows for these values and
		  append the results in the FD Table*/

	 for(int fd=1; fd<=nodes; fd++){
	 	for(int i=0; i<fd_comb; i++){

			if (nodes==3){
			String ans=binary_convert(i,2);
			int index1=ans.charAt(0)-'0';
			int index2=ans.charAt(1)-'0';

			int left =fd_map.get(fd).charAt(0) -'0' -1;
			int right=fd_map.get(fd).charAt(1) -'0' -1;

			String res=new String();
			for(int row=0; row<max_var; row++)
				if (permute[row][left]==index1 && permute[row][right]==index2)
					explicit_push(permute[row][nodes]);

			res=explicit_pop();
			fd_table[i][fd]=Integer.parseInt(res);
			}

		else if (nodes==2){
				String ans=binary_convert(i,1);
				int index=ans.charAt(0)-'0';

				int left =fd_map.get(fd).charAt(0) -'0' -1;
				String res=new String();
				for(int row=0; row<max_var; row++)
					if (permute[row][left]==index)
						explicit_push(permute[row][nodes]);

				res=explicit_pop();
				fd_table[i][fd]=Integer.parseInt(res);
			}
		else if (nodes==4){
				String ans=binary_convert(i,3);
				int index1=ans.charAt(0)-'0';
				int index2=ans.charAt(1)-'0';
				int index3=ans.charAt(2)-'0';

				int left  =fd_map.get(fd).charAt(0) -'0' -1;
				int mid   =fd_map.get(fd).charAt(1) -'0' -1;
				int right =fd_map.get(fd).charAt(2) -'0' -1;

				String res=new String();
				for(int row=0; row<max_var; row++)
					if (permute[row][left]==index1 && permute[row][mid]==index2 && permute[row][right]==index3)
						explicit_push(permute[row][nodes]);

				res=explicit_pop();
				fd_table[i][fd]=Integer.parseInt(res);
			}

		else if (nodes==5){
				String ans=binary_convert(i,4);
				int index1=ans.charAt(0)-'0';
				int index2=ans.charAt(1)-'0';
				int index3=ans.charAt(2)-'0';
				int index4=ans.charAt(3)-'0';

				int left_1  =fd_map.get(fd).charAt(0) -'0' -1;
				int left_2  =fd_map.get(fd).charAt(1) -'0' -1;
				int right_1 =fd_map.get(fd).charAt(2) -'0' -1;
				int right_2 =fd_map.get(fd).charAt(3) -'0' -1;

				String res=new String();
				for(int row=0; row<max_var; row++)
					if (permute[row][left_1]==index1 && permute[row][left_2]==index2 && permute[row][right_1]==index3 && permute[row][right_2]==index4)
						explicit_push(permute[row][nodes]);
				res=explicit_pop();
				fd_table[i][fd]=Integer.parseInt(res);
			}
		}
	 }

	}

	private void show_table(){
		/*Show Permute table for verification*/

		System.out.println("\n PERMUT TABLE");
		System.out.println();
		for(int i=0; i<max_var; i++){
			for(int j=0; j<=nodes; j++)
				System.out.print(" "+permute[i][j]);
			System.out.println();
		}
	}

	private void show_fd_table(){
		/*Show FD Table for given node*/

		System.out.println("\n FD TABLE");
		DecimalFormat twodigits = new DecimalFormat("00");
		for(int j=0; j<fd_comb; j++){
			System.out.print(" "+twodigits.format(j)+"->");
			for(int i=1; i<=nodes; i++)
				System.out.print(" "+twodigits.format(fd_table[j][i]));
			System.out.println();
		}
	}

	private void get_dominant_from_fd_table(){
		/*Extract dominant edges from the FD*/

		for(int fd=1; fd<=nodes; fd++){
			HashSet<String> temp=new HashSet<String>();

			for (int row=0; row<fd_comb; row++){
				if (fd_table[row][fd]==10 )    temp.add("N");
				else if (fd_table[row][fd]==1) temp.add("P");
			}
			dominant_in_fd.put(fd,temp);
			//System.out.println(" Dominant for FD: "+fd+": "+dominant_in_fd.get(fd));
		}
	}

	private void create_fd_graph(){
		/*Adds pairs to positive or negative list*/

		for(int fd=1; fd<=nodes; fd++){

			if (dominant_in_fd.get(fd).contains("P"))
				fd_graph_pos.put(fd,current_object);

		    if (dominant_in_fd.get(fd).contains("N"))
				fd_graph_neg.put(fd,current_object);
		}
	}

	public Map<Integer,Integer> getPositiveGraph(){
		/*Returns the positive graph list for each node*/
		return fd_graph_pos;
	}

	public Map<Integer,Integer> getNegativeGraph(){
		/*Returns the negative graph list for each node*/
		return fd_graph_neg;
	}
}


class Graph {
	private List<Map<Integer,Integer>> pos;
	private Map<Integer,List<Integer>>adjList;
	private int num_nodes;
	private int total_edges;
	private int cycle_length;
	private int max_cycle_length;
	private boolean has_cycle;
    private int visited[];
	private String type;

 	public Graph(int num,List<Map<Integer,Integer>>pos, String type){
        this.type = type;
 		this.pos=pos;
 		this.num_nodes=num;
 		this.total_edges=0;
 		this.has_cycle=false;
 		this.cycle_length=0;
 		this.max_cycle_length=0;

 		visited=new int[num_nodes];
 		for(int i=0; i<num_nodes; i++)visited[i]=0;

 		adjList=new HashMap<Integer,List<Integer>>();

 		for(int i=1; i<=num_nodes; i++)
			adjList.put(i,new LinkedList<Integer>());
		create_final_graph();
		// print_final_graph();
 	}

 	private void create_final_graph(){
 		for(int i=1; i<=num_nodes; i++){
 			List<Integer>adder=adjList.get(i);

 			for(int j=1; j<=num_nodes; j++){

 				if (pos.get(j-1).get(i)!=null){
 					adder.add(pos.get(j-1).get(i));
 					total_edges+=1;
 				}
 			}
 			adjList.put(i,adder);
 		}
 	}

    public void printGraphMatrix(PrintWriter out){
        // out.println("\nMatrix for Type: " + type);
        int [][] array = new int[num_nodes][num_nodes];

        for (int i = 0; i < num_nodes; i++){
            for (int j : adjList.get(i + 1))
                array[i][j -1] = (type == "Positive") ? 1 : -1;
        }

        for (int i = 0; i < num_nodes; i++){
            for (int j = 0; j < num_nodes; j++)
                out.print(array[i][j] + " ");
            out.println();
        }

    }

 	private void print_final_graph(){
        System.out.println("\nType: " + type);
 		for(int i=1; i<=num_nodes; i++)
 			System.out.println(" "+i+"-> "+adjList.get(i));
 	}

 	public int get_number_edges(){
		return total_edges;
 	}

 	public int has_alteast_one_cycle(){

 		for(int i=1; i<=num_nodes; i++){
 			for(int m=0; m<num_nodes; m++)visited[m]=0;
 			cycle_length=0;

 			if (dfs(i,adjList.get(i),visited)){
 				max_cycle_length=max(max_cycle_length,cycle_length);
 				return max_cycle_length;
 			}
 		}
 		return max_cycle_length;
 	}

 	private int max(int a,int b){
 		return a>b?a:b;
 	}

 	private boolean dfs(int i,List<Integer>curr,int[] visited){
 		visited[i-1]=1;

 		for(int l:curr)
 			if (visited[l-1]==1){
 				cycle_length+=1;
 				has_cycle=true;
 			}
 			else return dfs(l,adjList.get(l),visited);

 		return has_cycle;
 	}
}


class main_tester{
	static int matched_so_far=0;

	public static void main(String[] args) throws FileNotFoundException,IOException {

		final int num_nodes=Integer.parseInt(args[0]);
		final int max_edges=num_nodes*num_nodes;
		int cyc_len=0;

		int total_matches=0;
		int positive_matches=0;
		int negative_matches=0;
		int positive_cycles=0;
		int negative_cycles=0;
		int positive_only=0;
		int negative_only=0;

		System.out.println("\n BOOLEAN NETWORK DECOMPOSITION("+num_nodes+" NODES) ");
		System.out.println(" ATTEMPT TO CREATE AN INTERACTION GRAPH \n");

		/*Creating a list of objects */
		ArrayList<interaction_graph>IG = new ArrayList<interaction_graph>();


		/* Initialise two lists for storing the function's graphs*/
		List<Map<Integer,Integer>>tpos=new LinkedList<Map<Integer,Integer>>();
		List<Map<Integer,Integer>>tneg=new LinkedList<Map<Integer,Integer>>();

		PrintWriter pos_all=new PrintWriter("../source/pos_all.txt");
		PrintWriter neg_all=new PrintWriter("../source/neg_all.txt");
		PrintWriter pos_cyc=new PrintWriter("../source/pos_cyc.txt");
		PrintWriter neg_cyc=new PrintWriter("../source/neg_cyc.txt");
		PrintWriter pos_only = new PrintWriter("../source/pos_only.txt");
		PrintWriter neg_only = new PrintWriter("../source/neg_only.txt");

        PrintWriter graph_maker = new PrintWriter("../source/graph_list.txt");

		String get_comb="python ../source/comb.py "+Integer.toString(num_nodes);
		Process python_process=Runtime.getRuntime().exec(get_comb);
		BufferedReader br=new BufferedReader(new InputStreamReader(python_process.getInputStream()));

		String []sp;
		String line;

		while((line=br.readLine())!=null){
            // System.out.println(line);

			matched_so_far+=1;
			sp=line.split(" ");

			interaction_graph.current_object=0;
			tpos.clear();
			tneg.clear();
			IG.clear();

			for(int i=1; i<=num_nodes; i++){
				// System.out.println("\n Currently : "+sp[i-1]);
				IG.add(new interaction_graph(Integer.parseInt(sp[i-1]),num_nodes));
				tpos.add(IG.get(i-1).getPositiveGraph());
				tneg.add(IG.get(i-1).getNegativeGraph());
			}

			Graph positiveGraph= new Graph(num_nodes,tpos, "Positive");
			Graph negativeGraph= new Graph(num_nodes,tneg, "Negative");

            graph_maker.println("Graph for: ");
            for(int i=1; i<=num_nodes; i++)
                graph_maker.print(sp[i-1]+ " ");

            positiveGraph.printGraphMatrix(graph_maker);
            negativeGraph.printGraphMatrix(graph_maker);

			int pos_edges = positiveGraph.get_number_edges();
			int neg_edges = negativeGraph.get_number_edges();


			if(pos_edges >0 && neg_edges==0){
				pos_only.println();
				for(int p=0; p<num_nodes; p++)
					pos_only.print(sp[p]+" ");
				positive_only+=1;
			}

			if(neg_edges >0 && pos_edges==0){
				neg_only.println();
				for(int p=0; p<num_nodes; p++)
					neg_only.print(sp[p]+" ");
				negative_only+=1;

			}

			if(pos_edges==max_edges){
				pos_all.println();
				for(int p=0; p<num_nodes; p++)
					pos_all.print(sp[p]+" ");
				positive_matches+=1;
			}

			if(neg_edges==max_edges){
				neg_all.println();
				for(int p=0; p<num_nodes; p++)
					neg_all.print(sp[p]+" ");
				negative_matches+=1;
			}

			if((cyc_len=positiveGraph.has_alteast_one_cycle())!=0){
				pos_cyc.print(cyc_len+" ");
				for(int p=0; p<num_nodes; p++)
					pos_cyc.print(sp[p]+" ");
				pos_cyc.println();
				positive_cycles+=1;
			}

			if((cyc_len=negativeGraph.has_alteast_one_cycle())!=0){
				neg_cyc.print(cyc_len+" ");
				for(int p=0; p<num_nodes; p++)
					neg_cyc.print(sp[p]+" ");
				neg_cyc.println();
				negative_cycles+=1;
			}

		// if (matched_so_far%10000==0)	//Statutory notifications on reaching a grand outputs
		// 	System.out.println("Matched: "+matched_so_far+" Current Set: "+line);
		}

		pos_all.close();
		neg_all.close();
		pos_cyc.close();
		neg_cyc.close();
		pos_only.close();
		neg_only.close();
        graph_maker.close();
		br.close();

		System.out.print("\n Complete positive matches: "+positive_matches);
		System.out.print("\n Complete negative matches: "+negative_matches);
		System.out.print("\n Only complete positive:    "+positive_only);
		System.out.print("\n Only complete negative:    "+negative_only);
		System.out.print("\n Atleast 1 positive  cycle: "+positive_cycles);
		System.out.print("\n Atleast 1 negative  cycle: "+negative_cycles+"\n\n");
	}
}
