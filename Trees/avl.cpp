#include<iostream>
#include<cstdlib>
#include<algorithm>
#define endl cout<<endl;
using namespace std;

class mytree
{
  public: 
   int data,height;
   mytree *left,*right;

   mytree():data(0),left(NULL),right(NULL),height(0){}
   mytree(int k):data(k),left(NULL),right(NULL),height(0){}
};	

class avl : private mytree
{
     typedef mytree* tree;
     tree root;
     void inor(tree)const;
     void insavl(tree &,int);
     void balance(tree &);
     void rotateWithLeft(tree &);  
     void rebal(tree &);
     void rotateWithRight(tree &); 
     void doubleWithLeft(tree &);
     void doubleWithRight(tree &);
     void get_parent(tree &,const int);
     int height(tree &);	     

  public:
	avl(){
	root=NULL;}

	void delavl(const int);
	void ins(const int k){insavl(root,k);};
	void inord(){inor(root);};
	int  search(const int);
	void options_av();
	void new_search(const int,int&,tree&,tree&);
	void showBal(){balance(root);}
};

int avl:: height(tree &t)
{
 return (t==NULL)?-1:t->height ;
}

void avl::balance(tree &t)
{
  if(t!=NULL)
  { 
   cout<<"\n Balance factor of node "<<t->data<<" is : "<<height(t->left)-height(t->right);
   if(t->left)  balance(t->left);
   if(t->right) balance(t->right);
    return;
 } 
	endl;
}

void avl:: insavl(tree &t,int k)
{
   if(t==NULL)
   t=new mytree(k);

   else if(k<t->data)
   {
     insavl(t->left,k);
     
     if(height(t->left)-height(t->right)==2 || height(t->left)-height(t->right)==-2)
      {
	if(k<t->data && k<t->left->data) 

		    {cout<<"\n Single rot with left about "<<t->data<<"\n";	rotateWithLeft(t);}
			
	else 
	    {cout<<"\n Double rot with left about "<<t->data<<"\n";     doubleWithLeft(t); }
      }
	else cout<<"\n No rot wrt left of "<<t->data<<"\n";
    }

  else if(k>t->data)	
   {	
	insavl(t->right,k);

	if(height(t->left)-height(t->right)==2 || height(t->left)-height(t->right)==-2)
      {
	if(k>t->data && k>t->right->data) 

		 {cout<<"\n Single rot with right about "<<t->data<"\n"; rotateWithRight(t);}
			
	else 
	 {cout<<"\n Double rot with right about "<<t->data<"\n"; 	doubleWithRight(t); }
      }
	else cout<<"\n No rot required wrt right of "<<t->data<"\n";
    }
  else 
	cerr<<"\n Item already in the tree\n";

 	t->height=max(height(t->left),height(t->right))+1;	
}

void avl::rotateWithLeft(tree &t)
{
   tree temp;
   temp=t->left;
   t->left=temp->right;
   temp->right=t;

  t->height=max(height(t->left),height(t->right))+1;
  temp->height=max(height(temp->left),height(temp->right))+1;
  t=temp;
}

void avl::rotateWithRight(tree &t)
{
   tree  temp;
   temp=t->right;
   t->right=temp->left;
   temp->left=t;

  t->height=max(height(t->left),height(t->right))+1;
  temp->height=max(height(temp->left),height(temp->right))+1;
  t=temp;
}

void avl::doubleWithLeft(tree &t)
{
  rotateWithRight(t->left);
  rotateWithLeft(t);
}

void avl::doubleWithRight(tree &t)
{
  rotateWithLeft(t->right);
  rotateWithRight(t);
}

void avl:: get_parent(tree& parent,const int k)
{ 
   tree temp=root;
   parent=temp;

   while(temp!=NULL)
  {  
    tree savet=temp;
    if(temp->data==k) 	break; 

    if(k>temp->data) temp=temp->right;
    else temp=temp->left;
    parent=savet;
  } 
}




void avl::rebal(tree &t)
{							//this will check for the first imbalanced node uptill root
   
  t->height=max(height(t->left),height(t->right))+1;	//update height of returned node after deletion
  
   tree temp_parent;
   int flag=0;

  do
   {
     cout<<"\n Initial node "<<t->data; endl;
   
     get_parent(temp_parent,t->data);

      cout<<"\n Initial parent of "<<t->data<<" found : "<<temp_parent->data; endl;
   
     if(height(t->left)-height(t->right)==2)		
      {
         if(height(t->left->left)-height(t->left->right)>=0)					//left left
            
             {cout<<"\n Single rot with left about "<<t->data<<"\n";	rotateWithLeft(t); }
           
         else if(height(t->left->left)-height(t->left->right)<0)				//left right
        
          {cout<<"\n Double rot with left about "<<t->data<<"\n";     doubleWithLeft(t);  }
          
         else cout<<"\n No rotation required wrt left of "<<t->data<<"\n";
          
       }
       
       else if(height(t->left)-height(t->right)==-2)		
        {
          if(height(t->right->left)-height(t->right->right)<=0)					//right right
           
             {cout<<"\n Single rot with right about "<<t->data<"\n"; rotateWithRight(t);}
           
         else if(height(t->right->left)-height(t->right->right)>0)				//right left
          
           {cout<<"\n Double rot with right about "<<t->data<<"\n";     doubleWithRight(t);  }
           
           else cout<<"\n No rotation required wrt right of "<<t->data<<"\n";
        }
    
     if(temp_parent==root)
      {
        cout<<"\n Balance complete uptill root ";
        root=t;
        break;
       } 
     	
    t=temp_parent;
   cout<<"\n Now finding parent : "<<t->data;
  
  }
   while(t!=root);
  
}

void avl:: delavl(const int k)	
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
      
      tree to_be_rebalanced,sub=t->left;
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
	
      if(par==NULL && sub==NULL)
       cout<<"\n There is no need for rebalancing. \n";

      else if(par==NULL && sub!=NULL){
       cout<<"\n Checking for balance starting from "<<sub->data;
       rebal(sub);}
  
       else if(par!=NULL){
       cout<<"\n Checking for balance starting from "<<par->data;
       rebal(par);}
  }
}

int avl::search(const int k)
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



void avl::new_search(const int k,int &flag,tree &t,tree &par)
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


int i,k,m,c=0;

int main()
{
   cout<<"\n AVL TREE PROGRAM \n";
   cout<<" Enter (-1) wherever null \n";
   avl new_tree;
   new_tree.options_av();
   
 return 0;
}

void avl::inor(tree root) const
{
   if(root!=NULL)
  { 
    inor(root->left); 
    cout<<" "<<root->data<<" ";
    inor(root->right); 
   } 
}

void avl:: options_av()
{ 
 do{
  cout<<"\n\n MENU : ";
  
  cout<<"\n 1: Balance Factor  ";
  cout<<"\n 2: Inorder ";
  cout<<"\n 3: Search ";
  cout<<"\n 4: Insert ";
  cout<<"\n 5: Delete in AVL ";
  cout<<"\n 0: Exit    ";
  cin>>c;

	 switch(c) 
  	{
  case 1: if(root==NULL)
	  cout<<"\nEmpty tree \n";
	  else
	  {showBal(); endl}	break;

  case 2: if(root==NULL)
	  cout<<"\nEmpty tree \n";
	  else
	  {endl inord(); endl}	break;
  
  case 3: cout<<"\n Search for what in tree ? ";
	  cin>>k;
	  if(search(k))
	   cout<<"\n Element is found\n "; 
	  else
	   cout<<"\n Element doesn't exist \n";
				break;

  case 4:  cout<<"\n What do you want to insert ? "; 
	   cin>>k;	
	   ins(k);  		break; 

  case 5: cout<<"\n Enter the element you wish to delete ";
          cin>>m;	  
 	  delavl(m);		break;  
 
  
  case 0: exit(1);		break;
  	}
     }
while(c!=0);
 }


