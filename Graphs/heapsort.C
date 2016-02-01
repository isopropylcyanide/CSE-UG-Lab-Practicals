#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class node
{
  public:
  int data;
  node * left,*right;

  node(){}
  node(int k):data(k),left(NULL),right(NULL){}
};
typedef node* tree;

class heapsorts: private node
{
  tree t;
  int front,rear;
  tree* store;
  void inor(tree) ;

  public:
	heapsorts(){}
	heapsorts(int n)
	{
	  store=new tree[n];
	  front=rear=-1;
	}
	  
        void basic(vector<int>&);
	
	void enqueue(tree);
  	tree dequeue();
	void inord(){inor(t);}
	~heapsorts()
	{
	  cout<<"\n Program ends.\n\n";
	}
};

int main()
{
  int n;
  cout<<"\n Enter the input size: "; cin>>n;
  cout<<"\n Enter the input array :   ";

  vector<int> A(n+1);

  for(int i=0; i<n; i++)
	cin>>A[i];

  heapsorts heap(n);
  heap.basic(A);
  heap.inord();
}

void heapsorts:: enqueue(tree t)
{
  if(front==-1)	
     {					
        front=0;
        rear=0;
     }

 else rear++;
           store[rear]=t;
}

tree heapsorts:: dequeue()
{
  tree temp;

 if(front<=rear)
   {
  	temp=store[front++];
 	return temp;
  } 

}

void heapsorts::inor(tree t)
{
   if(t!=NULL)
  { 
    inor(t->left); 
    cout<<" "<<t->data<<" ";
    inor(t->right); 
   } 
}

void heapsorts:: basic(vector<int> & A)
{
  tree root=t,temp;
 
  tree* nlist = new node*[A.size()];
   nlist[0] = new node();
   nlist[0]->data = A[0];

   for (int i = 0, j = 0; ; j++) {
      if (++i >=A.size()) return;

      nlist[i] = new node();
      nlist[i]->data = A[i];
      nlist[j]->left = nlist[i];

      if (++i >= A.size()) return;

      nlist[i] = new node();
      nlist[i]->data = A[i];
      nlist[j]->right = nlist[i];
   }
 inor(nlist[0]);
}


















































