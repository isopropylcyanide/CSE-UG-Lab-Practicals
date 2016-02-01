w#include<iostream>
#include<cstdlib>
#include<algorithm>
#define endl cout<<endl;
using namespace std;

class mytree
{
  public:
   int data;
   mytree *left,*right;

   mytree():data(0),left(NULL),right(NULL){}
   mytree(int k):data(k),left(NULL),right(NULL){}
};

class bst : private mytree
{
     typedef mytree* tree;
     tree root;
     void inor(tree)const;
     void insert(tree &,int);

  public:
	bst(){
	root=NULL;}

	void delbst(const int);
	void ins(const int k){insert(root,k);};
	void inord(){inor(root);}
	int search(const int);
	void options();
	void new_search(const int,int&,tree&,tree&);
};

void bst::inor(tree root) const
{
   if(root!=NULL)
  {
    inor(root->left);
    cout<<" "<<root->data<<" ";
    inor(root->right);
   }

}

int bst::search(const int k)
{
   int flag=0;

   tree temp=root;

   while(!flag && temp!=NULL)
  {
   if(k==temp->data) flag=1;
   if(k>temp->data) temp=temp->right;
   else		 temp=temp->left;
  }

   return flag;
}

void bst::insert(tree &t,const int k)			//insertion into tree
{
  if (t==NULL)
	t= new mytree(k);
  else if (k<t->data)
	insert(t->left,k);
  else if (k>t->data)
	insert(t->right,k);
  else
	cerr<<"\n Item already in the tree\n";
}

void bst::new_search(const int k,int &flag,tree &t,tree &par)
{

  t=root;
  par=NULL;
  flag=0;

  while(!flag && t!=NULL)
  {
    if (k<t->data){
        par=t;
	t=t->left; }

    else if (k>t->data){
	par=t;
	t=t->right; }
    else flag=1;
  }
}

void bst:: delbst(const int k)
{
   int flag=0;
   tree t,par;

   new_search(k,flag,t,par);

  if(!flag)
  	cerr<<"\n Element doesn't exist in the tree \n";

  else
  {
     if((t->left!=NULL && t->right!=NULL))
     {
	cout<<"\n Given node has both children \n";

	tree succ=t->right;
	par=t;

        while(succ->left)
	 {
	  par=succ;
	  succ=succ->left;
	 }

 	cout<<" Successor is "<<succ->data;endl;
 	cout<<" Parent of successor is "<<par->data;endl;

        t->data=succ->data;
	t=succ;

    }

      tree sub=t->left;
      if(sub==NULL)
      sub=t->right;

      if(par==NULL)
      root=sub;

      else if (par->left==t)
	  par->left=sub;
      else
	  par->right=sub;
      delete t;
      cout<<"\n Node Deleted : "<<k; endl
 }
}


int i,k,m,c=0;

void bst::options()
{
 do{
  cout<<"\n MENU : ";

  cout<<"\n 1: Search ";
  cout<<"\n 2: Display ";
  cout<<"\n 3: Insert ";
  cout<<"\n 4: Delete in tree ";
  cout<<"\n 0: Exit    ";
  cin>>c;

 switch(c)
{
  case 1: cout<<"\n Search for what in tree ? ";
	  cin>>k;
	  if(search(k))
	    cout<<"\n Element is found\n ";
	  else
	    cout<<"\n Element doesn't exist \n";


	break;
  case 2: if(root==NULL)
	  cout<<"\nEmpty tree \n";
	  else
	  {endl inord(); endl}	break;
  case 3: cout<<"\n Enter data :  ";

  	  int x; cin>>x;
    	  ins(x);		break;

  case 4: cout<<"\n Enter the element you wish to delete ";
          cin>>m;
 	  delbst(m);		break;
  case 0: exit(1);		break;

 }}while(c!=0);
}

int main()
{
  printf("\n BINARY SEARCH TREE PROGRAM \n");

  bst new_tree;
  new_tree.options();
  return 0;
}
