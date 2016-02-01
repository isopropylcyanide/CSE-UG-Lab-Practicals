#include<stdio.h>
#include<stdlib.h>
#define endl printf("\n")

typedef struct trees
{
  int data;
  struct trees *left,*right,*parent;
 
}tree;	

int i,k,c=0,k;

tree* delbst(tree *);
tree* insert(tree *,int);
void inor(tree *);
void search(tree *);
tree *parent(tree *,int);

void options(tree *t)
{
 do{
  printf("\n MENU : ");
  
  printf("\n 1: Search ");
  printf("\n 2: Display ");
  printf("\n 3: Insert ");
  printf("\n 4: Delete in BST ");
  printf("\n 0: Exit    ");
  scanf(" %d",&c);

 switch(c) 
{
  case 1: search(t);		break;
  case 2: endl; inor(t); endl;	break;
  case 3: printf("\n Enter data :  "); 
  
  	 int x;
    	 scanf("%d",&x); t=insert(t,x);	break;

  case 4: t=delbst(t);		break;
  case 0: exit(1);		break;

 }}while(c!=0);
}


int main()
{
  printf("\n BINARY SEARCH TREE PROGRAM \n");
  printf(" Enter (-1) wherever null \n\n");
     tree *root;
     options(root);
}


tree *parent(tree* root,int k)
{ 
   tree *temp=root,*parent=temp;

   while(temp!=NULL)
  {  
    tree * savet=temp;
       if(temp->data==k)	break;

     if(k>temp->data) temp=temp->right;

     else temp=temp->left;

	parent=savet;
  } 
   return parent;
}



void inor(tree *t )			//inorder displaying and storing the values in an array
{
   if(t!=NULL)
  { 
    inor(t->left); 
    printf(" %d ",t->data);
    inor(t->right); 
   } 

}


void search(tree *t)
{
   int k,flag=0;
   printf("\n Search for what in BST ? "); scanf(" %d",&k);

   while(t)
  { 
   if(k==t->data) flag=1;
   if(k>t->data) t=t->right;
   else		 t=t->left; 
  } 
 
  if(flag==1){ printf("\n Element is found\n "); flag=0; }

  else 	 printf("\n Element doesn't exist \n");
}

tree* insert(tree *t,int k)			//insertion into BST	
{
    if(t==NULL)
   {
     t=(tree *)malloc(sizeof(tree));  
     t->data=k; 
     t->left=NULL ; t->right=NULL;
  }

   else if(k<t->data)
   {
     t->left=insert(t->left,k);
      }

  else if(k>t->data)	
   {	
	t->right=insert(t->right,k);
    }
	
 		
	return t;
}


tree* delbst(tree *t)	
{
   int k,flag=0;

   printf("\n Enter the element you wish to delete ");
   scanf(" %d",&k);

   tree *root=t;

   while(t)					//element exists
  { 
   if(k==t->data) {flag=1; break; }
   if(k>t->data) t=t->right;
   else		 t=t->left; 
  } 
 
  if(flag!=1)
  { printf("\n Element doesn't exist in the tree \n"); return ; }

  else
  {

     if((t->left!=NULL && t->right!=NULL))
     {
	printf("\n Given node has both children \n");

	tree * succ,*sucpar=t;				//to find successors

 	        
	succ=t->right;

        while(succ->left) 
	 {
	  sucpar=succ;
	  succ=succ->left;
	 }	

 	printf(" Successor is %d\n",succ->data);
 	printf(" Parent of successor is %d",sucpar->data);

        t->data=succ->data; 
							
	if(succ->right)	
	{
	  if(sucpar->left) sucpar->right=succ->right;
	  else sucpar->left=succ->right;
	}

	else 
	{
	  if(sucpar->left) {sucpar->left=t->left; sucpar->right=NULL;}
	  else sucpar->left=NULL;
	}

	free(succ);  	


	printf("\n Node Deleted : %d \n",k);
	return root;
    }
 

   if(t->left==NULL && t->right==NULL) 			//given node is  leaf node
   { 
      printf("\n Given node is a leaf node \n"); 
      printf(" Node Deleted : %d \n",k);
	
      tree *par=parent(root,k);

	if(t->data==par->data)
	  	{printf("\n Removing the root node \n");free(t); return NULL;}
		
	
          if(par->left->data==t->data)  {par->left=NULL;  free(t);  }
     	  else if(par->right->data==t->data) {par->right=NULL; free(t);  }
       
 
     return root;
   }
     
     if(t->right==NULL && t->left!=NULL)		//given node has one left child
  {  
      printf("\n Given node has one left child \n");
      printf(" Node Deleted : %d\n ",k);
      
      tree * del=t; 
      tree *par=parent(root,k);
	
	
	if(t==par)
	  {
		t=t->left;
		free(del);
		return t;
	 }

   	  else  if(t->data>par->data)  {par->right=t->left ; free(t);  }
   	  else 		{par->left=t->left; free(t);  }
	
      return root;
   }
 
    if(t->left==NULL && t->right!=NULL)			//given node has one right child
  {  
      printf("\n Given node has one right child \n");
      printf(" Node Deleted : %d \n",k);
	
	tree * del=t;
	tree *par=parent(root,k);

	if(t==par)
	  {
		t=t->right;
		free(del);
		return t;
	 }	

    	  else if(t->data>par->data)  {par->right=t->right ; free(t);  }
   	  else 		{par->left=t->right; free(t);  }

      return root ;
   }	
 }
}

