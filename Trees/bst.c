#include<stdio.h>
#include<stdlib.h>

typedef struct trees
{
  int data;
  struct trees *left,*right,*parent;
 
}tree;	

int i,k=0,c=0,ina[20];

void delbst(tree *);
void insert(tree *);
void inor(tree *);
void search(tree *);

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
  case 1: search(t);	break;
  case 2: inor(t);	break;
  case 3: insert(t);	break;
  case 4: delbst(t);	break;
  case 0: exit(1);	break;
 }}while(c!=0);
}


tree *create()
{ 
  tree *temp;    
 printf("\n Enter data :  "); 
  
   int x;
    scanf("%d",&x);
  
  if(x==-1)
    return NULL;
  

  temp=(tree *)malloc(sizeof(tree));
    temp->data=x;
 
   printf("\n For left child of %d ",x);
   temp->left=create();

   printf("\n For right child of %d ",x);
   temp->right=create();

 	return temp;
}



int main()
{
  printf("\n BINARY SEARCH TREE PROGRAM \n");
  printf(" Enter (-1) wherever null \n\n");
 
   tree * root;
   root=create();
     options(root);
}



void inor(tree *t )			//inorder displaying and storing the values in an array
{
   if(t!=NULL)
  { 
    inor(t->left); 
    ina[k++]=t->data ;
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

void insert(tree *t)			
{
   int k; tree *temp,*p=t;
   printf("\n Insert what in BST ? "); scanf(" %d",&k);
 
   temp=(tree *)malloc(sizeof(tree));
   temp->data=k;
   temp->left=NULL; temp->right=NULL;
   
   tree*parent;
   int child_from ;
  
  while(t)
  {
   if(k>t->data) 
    {
      if(t->right==NULL)
       {
	 t->right=temp;
 	 parent=t; child_from=1;
	 break;
       }
         t=t->right;
    }
   if(k<t->data)  
     {
      if(t->left==NULL)
       {
	 t->left=temp;
	 parent=t; child_from=0;
	 break;
       }
         t=t->left;
    }
  }
   printf("\n Element %d inserted in BST and is %d's %s child \n\n",k,parent->data,(child_from==1)?"right":"left");
   inor(p);
}


void delbst(tree *t)	
{
   int k,flag=0;

   printf("\n Enter the element you wish to delete ");
   scanf(" %d",&k);

   tree * temp=t;	
   tree * parent=temp;	
   tree* succ=t; 
   tree * temp2=t;
   tree *sucpar=temp2;
    
   while(t)			//element exists
  { 
   if(k==t->data) {flag=1; break; }
   if(k>t->data) t=t->right;
   else		 t=t->left; 
  } 
 
  if(flag!=1)
  { printf("\n Element doesn't exist in the tree \n"); return ; }
  else
  {

   				//finding its parent
  while(temp!=NULL)
  {  
    tree * savet=temp;
      
     if(temp->data==k)
	break;

     if(k>temp->data)
	 temp=temp->right;

     else
	 temp=temp->left;

	parent=savet;
  }
  }
 
     if((t->left!=NULL && t->right!=NULL))
     {
	tree * del=t;

	 printf("\n Given node has both children \n");

         for(i=0; ; i++)	
	 if(ina[i]==k) break; 

	while(succ)			
    { 
        if(succ->data==ina[i+1])  break; 
	if(succ->data<ina[i+1]) succ=succ->right;
   	else	 succ=succ->left; 
  } 
	 			//now find parent of successor

	while(temp2!=NULL)
  {  
     tree *save=temp2;
      
     if(temp2->data==ina[i+1])
	break;

     if(ina[i+1]>temp2->data)
	 temp2=temp2->right;

     else
	 temp2=temp2->left;

	sucpar=save;
  }
 	printf(" Successor is %d\n",succ->data);
 	printf(" Parent of successor is %d",sucpar->data);

        t->data=ina[i+1]; 
							//finding which side the successor lies on its parent

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
	return;
    }
 

   if(t->left==NULL && t->right==NULL) 			//given node is  leaf node
   { 
      printf("\n Given node is a leaf node \n"); 
      printf(" Node Deleted : %d \n",k);
	
	if(t->data==parent->data)
	  	{printf("\n Removing the root node \n");free(t);}
		
	
          if(parent->left)  {parent->left=NULL;  free(t);  }
     	  if(parent->right) {parent->right=NULL; free(t);  }
       
 
     return;
   }
     
     if(t->right==NULL && t->left!=NULL)		//given node has one left child
  {  
      printf("\n Given node has one left child \n");
      printf(" Node Deleted : %d\n ",k);
      tree * del=t;
	
	if(t==parent)
	  {
		t=t->left;
		free(del);
	 }

   	  else  if(t->data>parent->data)  {parent->right=t->left ; free(t);  }
   	  else 		{parent->left=t->left; free(t);  }
	
      return;
   }
 
    if(t->left==NULL && t->right!=NULL)			//given node has one right child
  {  
      printf("\n Given node has one right child \n");
      printf(" Node Deleted : %d \n",k);
	
	tree * del=t;
	
	if(t==parent)
	  {
		t=t->right;
		free(del);
	 }	

    	  else if(t->data>parent->data)  {parent->right=t->right ; free(t);  }
   	  else 		{parent->left=t->right; free(t);  }

      return;
   }	

}




