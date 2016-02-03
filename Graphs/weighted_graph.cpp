#include <iostream>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
#include <list>
#define max 100000
using namespace std; int src,dest,i=1;


class node
{
public:
int wt;
int wt_from;
node *next;
int data;
};

class nodelist
{
public: node *head;
};

class WG : protected node, protected nodelist
{
        int numV;
        int nature;
        nodelist *arr,*mst;
        static int numE;

public:
        WG(){
        }
        WG(int v,int nature)
        {
                this->numV=v;
                this->nature=nature;

                arr= new nodelist[numV+1];
                mst= new nodelist[numV+1];

                for(i=0; i<=numV; i++) {
                        arr[i].head=NULL;
                        mst[i].head=NULL;
                }
        }

        int  not_added(int,int);      void removeEdge();
        void options();           void remove(int,int);
        void print_Graph();           void minSpanTree();
        void addEdge(int,int,int);       bool isCyclic();
        node * newListNode(int,int,int);  void printMST();
        void addNewEdge();            void addMSTedge(int,int);
        friend bool inRange(WG *,int);    void removeMSTedge(int,int);
        bool isAdjacent(int,int);     bool isCyclicRec(int,bool*,bool*);
};

int WG:: numE=0;

bool inRange(WG *g,int x)
{
        return (x<=g->numV) ? 1 : 0;
}

bool WG:: isAdjacent(int s,int d)
{
        if (!arr[s].head || s==d || !arr[d].head) return false;

        node *temp=arr[s].head;
        while(temp->next)
        {
                temp=temp->next;
                if (temp->data==d) return true;
        }
        return false;
}

int WG:: not_added(int src,int dest)
{
        int s=src;
        int d=dest;

        if(!inRange(this,s) || !inRange(this,d)) {
                cout<<"\t\tEDGE: "<<src<<"-"<<dest<<" OUT OF RANGE\n";
                return -1;
        }

        node *temp=arr[s].head;
        while(temp)
        {
                if(temp->data==dest)
                        return 0;
                temp=temp->next;
        }
        return 1;
}


node* WG :: newListNode(int dest,int weight,int from)
{
        node * p=new node;
        p->data=dest;
        p->next=NULL;
        p->wt=weight;
        p->wt_from=from;
        return p;
}

void WG :: addEdge(int s, int d,int wt)
{
        if (!inRange(this,s) || !inRange(this,d))
                cout<<"\t\tEDGE: "<<src<<"-"<<dest<<" OUT OF RANGE\n";

        else{
                node *p,*q;

                if(!arr[s].head) //if source is not created,create it
                {
                        q=newListNode(s,0,s);
                        arr[s].head=q;
                }

                if(!arr[d].head) //if dest is not created,create it
                {
                        q=newListNode(d,0,d);
                        arr[d].head=q;
                }
                //else just attach d to s
                q=arr[s].head;
                p=newListNode(d,wt,s);

                while(q->next) q=q->next;
                q->next=p;

                if(this->nature==0) { //if an undirected graph, attach s to d too

                        q=arr[d].head;
                        p=newListNode(s,wt,d);

                        while(q->next) q=q->next;
                        q->next=p;

                        cout<<"\t\tEDGE: "<<s<<"-"<<d<<" AND "<<d<<"-"<<s<<" ADDED \n";
                }
                else cout<<"\t\tEDGE: "<<s<<"-"<<d<<" ADDED \n";
        }
        numE++;
}

void WG:: addNewEdge()
{
        cout<<"\n Enter source and destination: "; int src,dest,weight;
        cin>>src>>dest>>weight;

        if(!inRange(this,src) || !inRange(this,dest))
                cout<<"\t\tEDGE: "<<src<<"-"<<dest<<" OUT OF RANGE\n";

        else if(not_added(src,dest))
                addEdge(src,dest,wt);
        else
                cout<<"\n EDGE: "<<src<<"-"<<dest<<" ALREADY ADDED\n";
}

void WG:: removeEdge()
{
        cout<<"\n Enter source and destination: ";
        cin>>src>>dest;

        if(not_added(src,dest))
                cout<<"\n EDGE: "<<src<<"-"<<dest<<" NOT PRESENT TO DELETE\n";
        else
        {
                remove(src,dest);
                cout<<"\n\t\t EDGE: "<<src<<"-"<<dest<<" REMOVED\n";

                if(this->nature==0) {
                        remove(dest,src);
                        cout<<"\t\t EDGE: "<<dest<<"-"<<src<<" REMOVED\n";
                }
        }
}

void WG:: remove(int s,int d)
{
        node *temp=arr[s].head,*temp2,*del;

        if(temp->data==d)
        {
                if(temp->next)
                        arr[s].head=temp->next;

                else
                        arr[s].head=NULL;
                delete temp;
        }

        else{

                while(temp->next->data!=d && temp->next!=NULL && temp!=NULL)
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


void WG:: print_Graph()
{
        cout<<"\n Printing the adjacency lists. ";
        string s1;

        if(this->nature==1) s1="DIRECTED";
        else s1="UNDIRECTED  ";

        cout<<"\n Please note that the given WG is: "<<s1<<endl;

        for(i=1; i<=numV; i++)
        {
                node * temp=arr[i].head;
                cout<<"\n For "<<i<<":";
                while (temp)
                {
                        cout<<"->"<<temp->data<<"("<<temp->wt<<"-"<<temp->wt_from<<") ";
                        temp=temp->next;
                }
        }
        cout<<endl;
}

void WG:: addMSTedge(int s,int d)
{
        node *p,*q;

        if(!mst[s].head) //if source is not created,create it
        {
                q=newListNode(s,0,s);
                mst[s].head=q;
        }

        if(!mst[d].head) //if dest is not created,create it
        {
                q=newListNode(d,0,d);
                mst[d].head=q;
        }
        //else just attach d to s
        q=mst[s].head;
        p=newListNode(d,wt,s);

        while(q->next) q=q->next;
        q->next=p;

        cout<<"\t\tEDGE: "<<s<<"-"<<d<<" ADDED IN MST FUNCTION \n";
}

void WG:: removeMSTedge(int s,int d)
{
        node *temp=mst[s].head,*temp2,*del;

        if(temp->data==d)
        {
                if(temp->next)
                        mst[s].head=temp->next;

                else
                        mst[s].head=NULL;
                delete temp;
        }

        else{

                while(temp->next->data!=d && temp->next!=NULL && temp!=NULL)
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
        cout<<"\t\tEDGE: "<<s<<"-"<<d<<" REMOVED IN MST FUNCTION \n";
}

bool WG:: isCyclicRec(int v,bool *visited,bool* recStack)
{
        if(visited[v] == false)
        {
                // Mark the current node as visited and part of recursion stack
                visited[v] = true;
                recStack[v] = true;

                // Recur for all the vertices adjacent to this vertex
                node *p;
                for(p= mst[v].head; p!=NULL; p=p->next)
                {
                        if ( !visited[p->data] && isCyclicRec(p->data, visited, recStack) )
                                return true;
                        else if (recStack[p->data])
                                return true;
                }

        }
        recStack[v] = false; // remove the vertex from recursion stack
        return false;
}

bool WG:: isCyclic()
{
        // Mark all the vertices as not visited and not part of recursion
        // stack
        bool *visited = new bool[numV+1];
        bool *recStack = new bool[numV+1];
        for(int i =1; i <=numV; i++)
        {
                visited[i] = false;
                recStack[i] = false;
        }

        // Call the recursive helper function to detect cycle in different
        // DFS trees
        for(int i = 1; i <=numV; i++)
                if (isCyclicRec(i, visited, recStack))
                        return true;

        return false;

}


void WG:: printMST()
{
        for(i=1; i<=numV; i++)
        {
                node * temp=mst[i].head;
                cout<<"\n For "<<i<<":";
                while (temp)
                {
                        cout<<"->"<<temp->data;
                        temp=temp->next;
                }
        }
        cout<<endl;
}


void WG::minSpanTree()
{
        //arrange all nodes in the ascending order
        //find the best minimum node

        int cur_min=max,best_src,best_dest,j,count=0;

        vector<vector<bool> >valid(numV+1,vector<bool>(numV+1,1));

A:   for(i=1; i<=numV; i++)
        {
                node *temp=arr[i].head;
                while(temp->next)
                {
                        temp=temp->next;

                        if (temp->wt<cur_min && valid[i][temp->data])
                        {
                                cur_min=temp->wt,best_src=i,best_dest=temp->data;
                        }
                }
        }
        if (cur_min==max) {cout<<"\n The MST list is as follows ";  printMST(); return; }

        cout<<"\n Checking minimum edge: "<<best_src<<"-"<<best_dest<<" : "<<cur_min;

        while(count<=numE-1)
        {
                cur_min=max;
                valid[best_src][best_dest]=0;
                valid[best_dest][best_src]=0; cout<<endl;

                addMSTedge(best_src,best_dest);

                if (!isCyclic())
                {
                        cur_min=max;
                        vector<vector<bool> >valid(numV+1,vector<bool>(numV+1,1));
                        valid[best_src][best_dest]=0;
                        valid[best_dest][best_src]=0;
                        count+=1;
                        goto A;
                }
                else removeMSTedge(best_src,best_dest);
                goto A;
        }
}

void WG:: options()
{
        while(1) {

                cout<<"\n\n MENU: \n\n";
                cout<<" 1: Print Graph\n";
                cout<<" 2: Add Edge\n";
                cout<<" 3: Remove Edge\n";
                cout<<" 4: Minimum Spanning Tree\n";
                cout<<" 0: EXIT \t";
                cin>>i;
                switch(i) {

                case 1: print_Graph();    break;
                case 2: addNewEdge();     break;
                case 3: removeEdge();     break;
                case 4: minSpanTree();    break;
                case 0: exit(1);
                default: cout<<"\n Enter correct choice in MENU: \n";
                }
        }
}


int main()
{
        cout<<"\n Enter number of vertices : ";
        int numV,nature,src,dest,wt;
        cin>>numV;

        cout<<" Is the Graph a Directed(1) or Undirected(0)? ";
        cin>>nature;

        WG g(numV,nature);

        cout<<"\n Enter new edges (source , destination)";
        cout<<"\n Enter 0 0 to quit adding edges \n\n";

        while(1)
        {
                cout<<"\n Add Edge : weights: ";
                cin>>src>>dest>>wt;
                cin.ignore();
                if(src==0 && dest==0)
                        break;

                if(g.not_added(src,dest)==1)
                        g.addEdge(src,dest,wt);
                else if (g.not_added(src,dest)==-1) ;
                else cout<<"\t\t EDGE: "<<src<<"-"<<dest<<" ALREADY ADDED\n";
        }
        g.options();

        return 0;
}
