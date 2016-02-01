#include<iostream>
using namespace std;

class node{
public:
	int data;
	node *left;
	node* right;
};

int getleftmax(node* t){
	node *x=t;
	x=x->left;
	while(x->right)x=x->right;
	return x->data;
  }

int getrightmin(node *t){
	node *x=t;
		x=x->right;
	while(x->left)x=x->left;
	return x->data;
  }

class bst : private node
{
	node *t;
	void postorder(node *);

public:

	bst(){t=NULL;}
	friend int getleftmax(node *t);
	friend int getrightmin(node *t);

	node *create(int d=0){
		node *t1=new bst();
		t1->data=d;
		t1->left=NULL;
		t1->right=NULL;
		return t1;
	}

	void find_l_bst()
	{
		if(!t)return;
		bool bst_status=false;
		int min=0,max=0;
		node*temp=t;
		int size=0;
		cout<<"\n Size of largest binary tree: "<<find_l_bst_rec(temp,&size,&bst_status,&min,&max);
	}

	int find_l_bst_rec(node* t,int *size,bool *bst_status,int *min,int *max){	
	
		if(t->left)  find_l_bst_rec(t->left,size,bst_status,min,max);
		if(t->right) find_l_bst_rec(t->right,size,bst_status,min,max);

		cout<<"\n\n Main node: "<<t->data<<" BST: "<<*bst_status<<" Size: "<<*size<<" Min: "<<*min<<" Max: "<<*max;

		if(t->left==NULL && t->right==NULL){		//A leaf node
			cout<<"\n I'm at (leaf) node: "<<t->data;
			if(*bst_status==true && *max<t->data){
					*min=*max;
					*max=t->data;
					*size+=1;
				}
				else {
					*size=1;
					*min=*max=t->data;
			}
			*bst_status=true;
			cout<<"\n After method: "<<t->data<<" BST: "<<*bst_status<<" Size: "<<*size<<" Min: "<<*min<<" Max: "<<*max;
		}

		else if(!t->left && t->right){							//Only right child exists
			cout<<"\n I'm at (only right) node: "<<t->data;
			if(*bst_status==true){				
				if(t->data<*min){
					*min=t->data;
					*size+=1;
				}
				else {
					*bst_status=false;
					*min=*max=*size=0;
				}
				cout<<"\n After method: "<<t->data<<" BST: "<<*bst_status<<" Size: "<<*size<<" Min: "<<*min<<" Max: "<<*max;
			}	
		}

		else if(!t->right && t->left){							//Only left child exists
		cout<<"\n I'm at (only left) node: "<<t->data;

			if(*bst_status==true){
				if(t->data>*max){
					*max=t->data;
					*size+=1;
				}
				else {
					*bst_status=false;
					*min=*max=*size=0;
				}
				cout<<"\n After method: "<<t->data<<" BST: "<<*bst_status<<" Size: "<<*size<<" Min: "<<*min<<" Max: "<<*max;
			}
		}

		else{
			cout<<"\n I have both children ";
			int prev_best_size=*size;

			if(*bst_status)	
				prev_best_size=*size;	

			if(getleftmax(t)<t->data && t->data<getrightmin(t))
			{
				*size=*size+1;
				*min=getleftmax(t);
				*max=getrightmin(t);
				*bst_status=true;
			}
			else{
				*size=prev_best_size;
				*bst_status=false;
				cout<<"\n Not a BST. Selecting previous best size: "<<*size;
			}
			cout<<"\n After method: "<<t->data<<" BST: "<<*bst_status<<" Size: "<<*size<<" Min: "<<*min<<" Max: "<<*max;
		}
		
		return *size;	
	}

	void create_bst(){
		if(!t)	{
			t=create(25);
			t->left=create(18);
			t->left->left=create(19);
			t->left->left->right=create(15);
			t->left->right=create(20);
			t->left->right->left=create(18);
			t->left->right->right=create(25);

			t->right=create(50);
			t->right->left=create(35);
			t->right->left->left=create(20);
			t->right->left->left->right=create(25);
			t->right->left->right=create(40);
			t->right->right=create(60);
			t->right->right->left=create(55);
			t->right->right->right=create(70);
		}
	  }

	void display(){
		if(!t){
			cout<<"\n Empty Tree";
			return;
		}
		cout<<"\n Displaying Tree: ";
		node *x=t;
		postorder(x);
		cout<<endl;
	}
};

	void  bst:: postorder(node *t)
	{
		if(!t)return;
		postorder(t->left);
		postorder(t->right);
			cout<<" "<<t->data;
	}

int main()
{
	bst *b1=new bst();
	b1->create_bst();
	b1->display();
	b1->find_l_bst();
	cout<<endl;
}