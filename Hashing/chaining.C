#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

class node{
 public:
 	int data;
	node* next;

	node* new_head(int d=0)
	{
		node *x=new node();
		x->data=d;
		x->next=NULL;
		return x;
	}
};

class chaining: private node
{
	vector<node* >hash;
	int n;

 public:
 	chaining(int x=0)
 	{
 		vector<node* >hash_temp(n);
 		hash=hash_temp;
		n=x;

 		for(int i=0; i<n; i++)
 			hash.push_back(new_head()); 		
 	}

 	int hash_func(int x)
 	{
 		return x%n;
 	}

 	void fill_hash(int x)
 	{
 		int pos=hash_func(x);
 		if(!hash[pos])	
 			hash[pos]=new_head(x);

 		else{
 			node *p=hash[pos];
 				while(p->next!=NULL){
 					p=p->next;
 				}
 			p->next=new_head(x); 	
 		}
 		print_hash();
 	}

 	void print_hash()
 	{
 		cout<<endl;
 		for(int i=0; i<n; i++)
 		{
 			cout<<i<<" :";
 			if (hash[i])
 				{
 				node *p=hash[i];
 				while(p!=NULL){
 					cout<<" "<<p->data;
 					p=p->next;
 				}
 			}
 			cout<<endl;	
 		}
 	}	
 
 	bool search_hash(int key)
 	{
 		int index=hash_func(key);
 		
 		if (hash[index])
 		{
 				node *p=hash[index];
 				while(p!=NULL){
 					if(p->data==key) return true;
 					p=p->next;
 				}
		}
		return false;
	}
};

int main()
{
	int num;
	cout<<"\n Enter size of the hash function : "; cin>>num;

	assert(num>0);
	chaining c1(num);

	while(1)
	{
		cout<<"\n Enter new key (-1 to stop): "; cin>>num;
		if(num==-1) break;
		c1.fill_hash(num);
	}
	
	while(1)
	{
		cout<<"\n Enter search key (-1 to stop) : "; cin>>num;
		if(num==-1) break;	
		if(c1.search_hash(num))
			 cout<<" Found\n";
		else cout<<" Not Found\n";
	}
	return 0;
}