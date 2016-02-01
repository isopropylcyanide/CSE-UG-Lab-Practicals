#include<iostream>
#include<cstring>
#include<cstdlib>
#include<map>
#include<vector>
 using namespace std;

class node
{
  public:
  int color;
  node *next;
  int data;
};

class nodelist
{ 
  public:node *head;
};

class Graph_color: protected node, protected nodelist
{
  int numV;
  int nature;
  nodelist *arr;

  public:
  Graph_color(){}
  Graph_color(int a,int nat)
    {
	this->numV=a;
	this->nature=nat;
  
        arr= new nodelist[numV+1];

        for(int i=0; i<=numV; i++)     
 	  arr[i].head=NULL;	 
    }
 
  int  not_added(int,int);
  void options();
  void printGraph_color();
  void addEdge(int ,int);	
  void coloring();
  node * newListNode(int);
  void addNewEdge();
  friend bool inRange(Graph_color *,int);
  bool isAdjacent(int,int);
};


bool inRange(Graph_color *g,int x)
{ return (x<=g->numV)?1:0; }

bool Graph_color:: isAdjacent(int s,int d)
{
   if (!arr[s].head || s==d || !arr[d].head)return false;
  
   node *temp=arr[s].head;
   while(temp->next)
    {
     temp=temp->next;
     if (temp->data==d)return true;
    }
  return false;
} 

int Graph_color:: not_added(int src,int dest)
{
   int s=src;
   int d=dest;

   if(!inRange(this,s) || !inRange(this,d)){
     cout<<"\t\tEDGE: "<<src<<"-"<<dest<<" OUT OF RANGE\n";
     return -1;}

   node *temp=arr[s].head;
   while(temp)
     {
 	if(temp->data==dest)
         return 0;
	temp=temp->next;
     }
  return 1;
}


node* Graph_color :: newListNode(int dest)
{
 node * p=new node;
 p->data=dest;
 p->next=NULL;
 p->color=0;
 return p;
}
   
void Graph_color :: addEdge(int src, int dest)
{ 
  int s=src;
  int d=dest;
  int flag=0;

  if (!inRange(this,s) || !inRange(this,d))
 	cout<<"\t\tEDGE: "<<src<<"-"<<dest<<" OUT OF RANGE\n";

  else{
  node *p,*q;

  if(!arr[s].head)
  { 
     q=newListNode(src);
     arr[s].head=q;
  }

   if(!arr[d].head)
  { 
     q=newListNode(dest);
     arr[d].head=q;
  }

  q=arr[s].head;
  p=newListNode(dest);

  while(q->next) q=q->next;
  q->next=p;

  if(this->nature==0){

  q=arr[d].head;
  p=newListNode(src);

  while(q->next) q=q->next;
  q->next=p;  

  cout<<"\t\tEDGE: "<<src<<"-"<<dest<<" AND "<<dest<<"-"<<src<<" ADDED \n";
   }
  else cout<<"\t\tEDGE: "<<src<<"-"<<dest<<" ADDED \n";
  }
}

void Graph_color:: addNewEdge()			
{
  cout<<"\n Enter source and destination: "; int src,dest;
  cin>>src>>dest;
    
  if(!inRange(this,src) || !inRange(this,dest))
  cout<<"\t\tEDGE: "<<src<<"-"<<dest<<" OUT OF RANGE\n";
 
  else if(not_added(src,dest))
        addEdge(src,dest); 	
  else
	cout<<"\n EDGE: "<<src<<"-"<<dest<<" ALREADY ADDED\n";
}



void Graph_color:: printGraph_color()
{
 cout<<"\n Printing the adjacency lists. ";
 string s1;  

 if(this->nature==1) s1="DIRECTED";
 else	s1="UNDIRECTED  ";

 cout<<"\n Please note that the given Graph_color is: "<<s1<<endl;
 
 for(int i=1; i<=numV; i++)
 {
   node * temp=arr[i].head;
   cout<<"\n List for "<<i<<":";
   while (temp)
   {
     cout<<"->"<<temp->data;
     temp=temp->next;
   }
 }
 cout<<endl;
}  


void Graph_color::coloring()
{
   //Step 1: Order the nodes on the basis of their degree.
       //  Create a map which holds the node: degree heads of the numV number of adjaceny lists    
   
   map<int,int>order;
   vector<int>fo(numV,0);
   int count;

      //For each node the degree is the number of links in its adjacency list from head till null

   for(int i=1;i<=numV;i++)
    {
      if (!arr[i].head)return;

      node *p=arr[i].head;
      count=0;
      
      while(p->next)
       {
        ++count;
        p=p->next;
       }
     order[i]=count;
    }
        	//Sort the map values in decreasing order and store corresponding keys in another vector
 			
    vector<bool>valid(numV+1); 
    fill(valid.begin(),valid.end(),1);
   
   for(int j=1;j<=numV;j++)
    {
      int kmax=0,val_max=0;
      for(int i=1;i<=numV;i++)
       {
          if (order[i]>val_max && valid[i])
           {
	    val_max=order[i];
	    kmax=i;
           }
       }
      fo[j]=kmax;
      valid[kmax]=0;
    }

    cout<<"\n The nodes with sorted degrees (desc): ";
    for(int i=1;i<=numV;i++)cout<<fo[i]<<" ";
	
    fill(valid.begin(),valid.end(),1);
    count=0;					//1: Unmarked 0: Marked

    for(int i=1; i<=numV; ++i)
     { 
       if (valid[fo[i]])
         {
           arr[fo[i]].head->color=count;
           cout<<"\n Coloured node: "<<fo[i]<<" : "<<++count;
	   valid[fo[i]]=0;
         }

      for(int j=1; j<=numV; ++j)
       { 
         if (valid[fo[j]] && !isAdjacent(fo[i],fo[j]))
          {
           arr[fo[j]].head->color=count;
           cout<<"\n Coloured node: "<<fo[j]<<" : "<<count;
	   valid[fo[j]]=0;
         }
      }
     }	
  cout<<"\n The chromatic number of the given graph : "<<count<<endl;
} 


void Graph_color:: options()
{ 
  int i; while(1){

  cout<<"\n\n MENU: \n\n";
  cout<<"1: PRINT Graph\n";
  cout<<"2: Color Graph\n";
  cout<<"3: Add Edge\n";
  cout<<"0: EXIT \t";
  cin>>i;
  switch(i){
 
  case 1: printGraph_color();	break;
  case 2: coloring();		break;	
  case 3: addNewEdge();		break;
  case 0: exit(1);
  default: cout<<"\n Enter correct choice in MENU: \n";
   }
 }
}


int main()
{
  cout<<"\n Enter number of vertices : ";
   int numV,nature,src,dest;
   cin>>numV;
   
   cout<<" Is the Graph a Directed(1) or Undirected(0)? ";
   cin>>nature;
   
   Graph_color g(numV,nature);

   cout<<"\n Enter new edges (source , destination)";
   cout<<"\n Enter 0 0 to quit adding edges \n\n";

   while(1)
     {
  	cout<<" Add Edge : ";
	cin>>src>>dest;
	cin.ignore();
	if(src==0 && dest==0)
	break;

        if(g.not_added(src,dest)==1)
        g.addEdge(src,dest);
        else if (g.not_added(src,dest)==-1) ;
        else cout<<"\t\t EDGE: "<<src<<"-"<<dest<<" ALREADY ADDED\n";
     } 	
     g.options();

  return 0;
}








































