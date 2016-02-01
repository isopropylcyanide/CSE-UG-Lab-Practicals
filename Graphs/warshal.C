#include<iostream>
#include<vector>
using namespace std;
int i,j,k,temp; char tp;

class node
{
  public: int to[5];
	  node(){}
};

class nodelist: public node
{
  public: node *list;
};

class Warshall: public nodelist
{
  int n;
  nodelist *array;
  public:
	Warshall (int k)
	 { 
	   n=k;
	   array=new nodelist[n];
	 }
 	Warshall(){}
	void initiate_action();
	void printGraph();
	void updateGraph();
	void readGraph();
};
	
void Warshall::readGraph()
{
  cout<<"\n ADJACENCY MATRIX : \n";
  for(i=0; i<n; i++)
   {
    for(j=0; j<n; j++)
    {
	cin>>temp;
	this->array[i].to[j]=temp;
    }
  }
}

void Warshall::printGraph()
{
 cout<<"\n PRINTING GRAPH...\n\n";
 for(i=0; i<n; i++)
   {
    cout<<"\n\n For node : "<<i+1;
    for(j=0; j<n; j++)
     { 
      cout<<"\n From "<<j+1<<" : "<<this->array[i].to[j];
     }
   }
}

void Warshall:: updateGraph()
{
   cout<<"\n UPDATING GRAPH TO THE SHORTEST VALUES : \n";
  for(i=0; i<n; i++)
   {
    for(j=0; j<n; j++)
    { 
     for(k=0; k<n; k++)
      {	
	if (this->array[i].to[j]>(this->array[i].to[k] + this->array[k].to[j]))
	 this->array[i].to[j]= this->array[i].to[k] + this->array[k].to[j];
      }
    }
  }
}


void Warshall:: initiate_action()
{
  readGraph();
  updateGraph();
  printGraph();
}

int main()
{

  Warshall w(5);
  w.initiate_action();
  return 0;
}




















































