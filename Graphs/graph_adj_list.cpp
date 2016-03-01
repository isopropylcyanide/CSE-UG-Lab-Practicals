#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
using namespace std;

class node{
 public:
  char data;
  node * next;
  char repr;
};

class nodeList
{
  public: node *head;
};

class Graph: private node,private nodeList {
  int numV;
  int nature;

  nodeList *array;

  public:
    Graph(){}
    Graph(int numV,int nature)
     {
      this->numV=numV;
      this->nature=nature;

      array=new nodeList[numV];

      for(int i=0; i<numV; i++)
       array[i].head=NULL;
     }
     void dfs_rev(int,vector<bool>&);	node * newListNode(char);	void addEdge(char,char);
     void printGraph();			int not_added(char,char);	void options();
     void addNewEdge();			bool hasEdge();			void RemoveEdge();
     void remove(int,int,char);		void dfs(); void bfs();		void isConnected();
     bool inRange(int);			void shortestPath();		void makeSet();
};

bool Graph:: inRange(int i){
  return i<this->numV?1:0;
 }

char src,dest;

int main()
{
   cout<<"\n Enter number of vertices : ";
   int numV;  int nature;
   cin>>numV;

   cout<<" Is the graph a digraph(1) or graph(0)? ";
   cin>>nature;

   Graph g(numV,nature);

   cout<<"\n Enter new edges (source , destination)";
   cout<<"\n Enter 0 0 to quit adding edges \n\n";

     while(1)
     {
  	cout<<" Add Edge : ";
	cin>>src>>dest;
	cin.ignore();
	if(src=='0' && dest=='0')
	break;

        if(g.not_added(src,dest)==1)
        g.addEdge(src,dest);
        else if (g.not_added(src,dest)==-1) ;
        else cout<<"\t\t EDGE: "<<src<<"-"<<dest<<" ALREADY ADDED\n";
     } 	g.options();

  return 0;
}

void Graph:: options()
{
  int i; while(1){

  cout<<"\n MENU: \n\n";
  cout<<"1: PRINT GRAPH\n";
  cout<<"2: DEPTH SEARCH\n";
  cout<<"3: BREADTH SEARCH\n";
  cout<<"4: IS CONNECTED\n";
  cout<<"5: HAS EDGE\n";
  cout<<"6: SHORTEST PATH\n";
  cout<<"7: ADD EDGE\n";
  cout<<"8: REMOVE EDGE\n";
  cout<<"9: MAKE SETS\n";
  cout<<"0: EXIT \t";
  cin>>i;
  switch(i){

  case 1: system("clear");	printGraph();	system("sleep 1");	break;
  case 2: system("clear");	dfs();		system("sleep 1");	break;
  case 3: system("clear");	bfs();		system("sleep 1");	break;
  case 4: system("clear");	isConnected();	system("sleep 1");	break;
  case 5: system("clear");	hasEdge();	system("sleep 1");	break;
  case 6: system("clear");	shortestPath();	system("sleep 1");	break;
  case 7: system("clear");	addNewEdge();	system("sleep 1");	break;
  case 8: system("clear");	RemoveEdge();	system("sleep 1");	break;
  case 9: system("clear");	makeSet();	system("sleep 1");	break;
  case 0: exit(1);
  default: cout<<"\n Enter correct choice in MENU: \n";
   }
 }
}

int Graph:: not_added(char src,char dest)
{
   int s=int(src)-65;
   int d=int(dest)-65;

   if(!inRange(s) || !inRange(d)){
     cout<<"\t\tEDGE: "<<src<<"-"<<dest<<" OUT OF RANGE\n";
     return -1;}

   node *temp=array[s].head;
   while(temp)
     {
 	if(temp->data==dest)
         return 0;
	temp=temp->next;
     }
  return 1;
}


node* Graph :: newListNode(char dest)
{
 node * p=new node;
 p->data=dest;
 p->next=NULL;
 return p;
}

void Graph :: addEdge(char src, char dest)
{
  int s=int(src)-65;
  int d=int(dest)-65;
  int flag=0;

  if(!inRange(s) || !inRange(d))
  cout<<"\t\tEDGE: "<<src<<"-"<<dest<<" OUT OF RANGE\n";

  else{
  node *p,*q;

  if(!array[s].head)
  {
     q=newListNode(src);
     array[s].head=q;
  }

   if(!array[d].head)
  {
     q=newListNode(dest);
     array[d].head=q;
  }

  q=array[s].head;
  p=newListNode(dest);

  while(q->next) q=q->next;
  q->next=p;

  if(this->nature==0){

  q=array[d].head;
  p=newListNode(src);

  while(q->next) q=q->next;
  q->next=p;

  cout<<"\t\tEDGE: "<<src<<"-"<<dest<<" AND "<<dest<<"-"<<src<<" ADDED \n";
   }
  else cout<<"\t\tEDGE: "<<src<<"-"<<dest<<" ADDED \n";
 }
}


bool Graph:: hasEdge()
{
  cout<<"\n Enter source and destination: ";
  cin>>src>>dest;

   if(!inRange(int(src)-65) || !inRange(int(dest)-65))
  cout<<"\t\tEDGE: "<<src<<"-"<<dest<<" OUT OF RANGE\n";

  else if(not_added(src,dest)) {cout<<"\n EDGE: "<<src<<"-"<<dest<<" NOT PRESENT\n"; return 0;}
  else	{cout<<"\n EDGE: "<<src<<"-"<<dest<<" PRESENT\n"; return 1;}
}


void Graph:: addNewEdge()
{
  cout<<"\n Enter source and destination: ";
  cin>>src>>dest;

  if(!inRange(int(src)-65) || !inRange(int(dest)-65))
  cout<<"\t\tEDGE: "<<src<<"-"<<dest<<" OUT OF RANGE\n";

  else if(not_added(src,dest))
        addEdge(src,dest);
  else
	cout<<"\n EDGE: "<<src<<"-"<<dest<<" ALREADY ADDED\n";
}

void Graph:: RemoveEdge()
{
  cout<<"\n Enter source and destination: ";
  cin>>src>>dest;

  if(not_added(src,dest))
	cout<<"\n EDGE: "<<src<<"-"<<dest<<" NOT PRESENT TO DELETE\n";
  else
  {
    int s=int(src)-65;
    int d=int(dest)-65;

    remove(s,d,dest);
    cout<<"\n\t\t EDGE: "<<src<<"-"<<dest<<" REMOVED\n";

    if(this->nature==0){
    remove(d,s,src);
    cout<<"\t\t EDGE: "<<dest<<"-"<<src<<" REMOVED\n";
    }
  }
}

void Graph:: remove(int s,int d,char dest)
{
  node *temp=array[s].head,*temp2,*del;

  if(temp->data==dest)
  {
   if(temp->next)
   array[s].head=temp->next;

   else
   array[s].head=NULL;
   delete temp;
  }

  else{

  while(temp->next->data!=dest && temp->next!=NULL && temp!=NULL)
   temp=temp->next;

  if(temp->next->next &&temp->next)
   {
     temp2=temp->next->next;
     del=temp->next;
     temp->next=temp2;
     delete del;
   }
   else if(temp->next)
   {
     del=temp->next;
     temp->next=NULL;
     delete del;
  }
 }
}

void Graph::bfs()
{
  vector<bool>visited(numV,false); char x;
  cout<<"\n Start BFS from which node : ";
  cin>>x;

  int no=int(x)-65,y;

  cout<<" THE BFS FROM "<<x<<": ";

  if(!inRange(no)){
	cout<<" IS NOT IN RANGE \n";
	return;}

  list<node*> q;
  node *it;
  visited[no]=true;

  if(array[no].head==NULL)
	{ cout<<" DOESN'T EXIST "<<endl; return;}

  q.push_back(array[no].head);

  while (!q.empty())
  {
    cout<<q.front()->data<<" ";
    no=int(q.front()->data)-65;

    q.pop_front();

        for(it = array[no].head; it !=NULL; it=it->next)
        {
 	   y=int(it->data)-65;
            if(!visited[y])
            {
              visited[y] = true;
	      q.push_back(array[y].head);
            }
        }
    }
 cout<<endl;
}

void Graph::dfs_rev(int no,vector<bool>&visited)
{
  visited[no]=true;
  cout<<char(no+65)<<" ";

  node *p;

  for(p=array[no].head; p!=NULL ; p=p->next)
  {
   no=int(p->data)-65;
   if(!visited[no])
   dfs_rev(no,visited);
  }
}

void Graph::dfs()
{
   vector<bool>visited(numV,false); char x;
   cout<<"\n Start DFS from which node : ";
   cin>>x;

   int no=int(x)-65;
   cout<<" THE DFS FROM "<<x<<": ";

   if(!inRange(no))
	cout<<" IS NOT IN RANGE ";
   else if(array[no].head==NULL)
	cout<<" DOESN'T EXIST ";
   else
   dfs_rev(no,visited);
   cout<<endl;
}

void Graph::isConnected()
{
   int flag=0;
   vector<bool>visited(numV,false);
   cout<<"\n\n Starting DFS from first node : ";
   dfs_rev(0,visited);

   for(int i=0; i<visited.size(); i++)
   	if(!visited[i])	{flag=1; break;}
	else flag=0;

  if(flag==1)
   	cout<<"\n NOT CONNECTED. ALL VERTICES AREN'T REACHABLE "<<endl;
  else
	cout<<"\n CONNECTED. ALL VERTICES ARE REACHABLE "<<endl;
}

void Graph:: shortestPath()
{
 cout<<"\n Enter source and destination: ";
  cin>>src>>dest;

  int s=int(src)-65;
    int d=int(dest)-65;

   if(!inRange(s) || !inRange(d))
  cout<<"\t\tPATH: "<<src<<"-->"<<dest<<" OUT OF RANGE\n";

}

void Graph:: makeSet()
{
 node *set[numV];

 for(int i=0; i<numV; i++)
 {
   char dt=char(i+65);
   set[i]=newListNode(dt);
   set[i]->repr=dt;
 }

 for(int i=0; i<numV; i++)
 {
  node * temp=array[i].head;
  if(!temp) continue;

  char rep_store=char(i+65);
  int set_link=0;

  if(set[i]->repr==rep_store)
  {
    while(temp->next)
     {
      	temp=temp->next;
      	set_link=int(temp->data)-65;

      	if (set[set_link]->repr!=temp->data)
	   set[i]->repr=set[set_link]->repr;

	else
	 set[set_link]->repr=set[i]->repr;
       }
    }
 }

cout<<"\n The Sets formed by the above graph are \n\n"<<"{ ";

for(int j=0; j<numV; j++)
 {
  char rep=char(j+65);
  cout<<" (";

 for(int i=0; i<numV; i++)
 {
   node * temp=set[i];

  if(temp->repr==rep)
	 cout<<temp->data<<" ";
  }
   cout<<")";
 }

 cout<<" }"<<endl<<endl;
}


void Graph:: printGraph()
{
 cout<<"\n Printing the adjacency lists. ";
 string s1;

 if(this->nature==1) s1="DIRECTED";
 else	s1="UNDIRECTED  ";

 cout<<"\n Please note that the given graph is: "<<s1<<endl;

 for(int i=0; i<numV; i++)
 {
   node * temp=array[i].head;
   cout<<"\n List for "<<char(i+65)<<":";
   while (temp)
   {
     cout<<"->"<<temp->data;
     temp=temp->next;
   }
 }
 cout<<endl;
}
