#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct trees
{
  int data;
  struct trees *left,*right;
};
typedef struct trees tree;
 
tree* st[20]; int top=-1,front=-1,rear=-1; 
tree* sq[20];		

int i,j=0,c=0,k=0,l=0,m=0; 
int a,flag=0,count=0;
int ina[20],posa[20],prea[20];

int  size(tree *);	void pre(tree *);	void lorder(tree *);
void delete(tree *);	void inor(tree *);	void inorit(tree *);
void search(tree *);	void post(tree *);	void delbst(tree *);
void delete(tree *);	void delete(tree *);
void options(tree *);	void depth(tree *);
void insbst(tree *);	void display(tree *);
void thread(tree *);    void maketh(tree *,int []);
void findleaf(tree *,int *,int[]);
void leaves(tree *);	

tree *create()
{ 
  tree *temp;    
 printf("\n Enter data :  "); 
  
   int x;
    scanf("%d",&x);
  
  if(x==-1)
    return NULL;
  

  temp=(tree *)malloc(sizeof(tree));
    temp->data=x; ++ count;
   
 
   printf("\n For left child of %d ",x);
   temp->left=create();

   printf("\n For right child of %d ",x);
   temp->right=create();

 	return temp;
}
 
  
void push(tree *t)
{
	 st[top++]=t;
}



tree* pop()
{   
 	tree* temp;
        temp=st[top--];
	
	return temp; 
}

void enqueue(tree *t)
{   
    if(front==-1)	
     {					
        front=0;
        rear=0;
     }

 else
       rear++;
           sq[rear]=t;
        
}

tree * deque()
{ 
   tree *temp;

 if(front<=rear)
   {
  	temp=sq[front++];
 	return temp;
  } 

} 

int main()
{
  printf("\n BINARY TREE PROGRAM \n");
  printf(" Enter (-1) wherever null \n\n");
   tree *root;
   root=create();
     options(root);
}


void options(tree *t)
{
 do{
  printf("\n MENU : ");
  
  printf("\n 1: Size ");
  printf("\n 2: Display ");
  printf("\n 3: Search ");
  printf("\n 4: Insert ");
  printf("\n 5: Delete in BST ");
  printf("\n 6: Depth ");
  printf("\n 7: Leaves ");
  printf("\n 8: Delete Tree  ");
  printf("\n 9: Thread ");  
  printf("\n 0: Exit    ");
  scanf(" %d",&c);

 switch(c) 
{
  case 1: printf("\n Size of tree is : %d",size(t));	break;
  case 2: display(t);	break;
  case 3: search(t);	break;
  case 5: delbst(t);	break;
  case 6: depth(t);	break;
  case 7: leaves(t);	break;
  case 8: delete(t);	break;
  case 9: thread(t);    break;
  case 4: insbst(t);    break;
  case 0: exit(1);	break;
 }}while(c!=0);
}

int size(tree *t)
{
   if (t==NULL) 
    return 0;
  else     
    return(size(t->left) + 1 + size(t->right));  
  }

void thread(tree *t)
{
   printf("\n 1: Preorder BTT ");
   printf("\n 2: Inorder BTT ");
   printf("\n 3: Postorder BTT "); 
   printf("\n 0: Back to menu ");
   scanf(" %d",&c);
  
   if(c==1)
       { 
          printf("\n The preorder : "); 
            pre(t);    
               maketh(t,prea);
                 return;
          }    
     if(c==2)
        { 
          printf("\n The inorder : "); 
            inor(t);    
            printf(" %d ",ina[i]) ;
               maketh(t,ina);
                 return;
          }   
      if(c==3)
       { 
          printf("\n The postorder : "); 
               post(t); 
               maketh(t,posa);
                 return;
          }   
 }

void maketh(tree * t,int arr[])
{  
   int lea[count];   
    int k=0;
   int *p= &k;


    findleaf(t,p,lea);
  printf("\n Leaves are : "); 
  
     for(i=0; i<(*p); i++) printf(" %d ",lea[i]);  
      
}

void leaves(tree *t)
{
   if(t!=NULL)
  {
     if(t->left==NULL && t->right==NULL)
        {
          printf("\n Leaf found : %d ",t->data);

         }
        leaves(t->left);
        leaves(t->right);
 }
}


void findleaf(tree *t,int *p,int lea[])
{
   if(t!=NULL)
  {
     if(t->left==NULL && t->right==NULL)
           lea[(*p)++]=t->data; 

        findleaf(t->left,p,lea);
        findleaf(t->right,p,lea);
  }
}

void delete(tree *t)
 {
	if(t==NULL) return;

	delete(t->left);
	delete(t->right);
	printf("\n Deleting node : %d ",t->data);
	free(t);
	printf("\n");
 }



void search(tree *t)
{
   int k;
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




void depth(tree *t)
{
	int d1=0,d2=0; tree*p=t;
	
	while(t->left!=NULL || t->right!=NULL)
	{
	   d1++;

	   if(t->left==NULL) t=t->right;	
	   else t=t->left;
	}
	t=p;
	
	while(t->left!=NULL || t->right!=NULL)
	{
	   d2++;

	   if(t->right==NULL) t=t->left;	
	   else t=t->right;
	}t=p;

	if(d1>d2) { printf("\n Depth and height of tree is %d ",d1); options(t); }
	else	  { printf("\n Depth and height of tree is %d ",d2); options(t); }
  }


void insbst(tree *t)			//Insert in BST
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

	 if(succ->right)  t->right=succ->right;
	else t->right=NULL;

	free(succ); 

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





void display(tree *t)
{
 do{
  printf("\n\n Display : ");
  
  printf("\n 1: Preorder " );
  printf("\n 2: Inorder "  );
  printf("\n 3: Postorder ");
  printf("\n 4: Level order "  );
  printf("\n 5: Inorder(iter) "  );
  printf("\n 0: Back to menu ");
  scanf(" %d",&c);

 switch(c) 
{
  case 1: printf("\nPreorder : ");    pre(t);  	break;
  case 2: printf("\nInorder : ");     inor(t);	break;
  case 3: printf("\nPostorder : ");   post(t);	break;
  case 4: printf("\nLevel order : ");lorder(t);	break;
  case 5: printf("\nInorder : ");    inorit(t);	break;
  case 0: options(t);			        break;
  }} while(c!=0);
}


void pre(tree *t)
{  
   if(t!=NULL)
  { 
    if(t) printf(" %d ",t->data);
     else printf(" NULL "); 
    prea[m++]=t->data ;
    pre(t->left); 
    pre(t->right); 
    
   } 

 }

void inor(tree *t )
{
   if(t!=NULL)
  { 
    inor(t->left); 
    ina[k++]=t->data ;
    if(t) printf(" %d ",t->data);
     else printf(" NULL ");
    inor(t->right); 
   } 

}


void post(tree *t)
{
   if(t!=NULL)
  { 
    post(t->left); 
    post(t->right); 
    if(t) printf(" %d ",t->data);
     else printf(" NULL ");
    posa[l++]=t->data;
   } 
 
}

void inorit(tree *t)
{ 
   while(t!=NULL)
	{ 
	  push(t);
	 t=t->left ;
	}

   while(top!=-2)
   { t=pop();
 
    
   if(t)	
   printf(" %d ",t->data);

   if(t->right) push(t->right);
    }
      
	
}
	
void lorder(tree *t)
{   
    if(!t) return ;

    enqueue(t);

    while(front!=rear+1)
   {
    t=deque();
   
    if(t) printf(" %d ",t->data);
     else printf(" NULL ");
     if(t->left)  enqueue(t->left);
     if(t->right) enqueue(t->right);

  }
 
}


 





