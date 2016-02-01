#include<malloc.h> 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define endl printf("\n")

typedef struct avl 
{
   int data;
   struct avl* left,*right;
   int height;
}tree;

int c,count=0,k,flag=0;

void inor(tree *);		void search(tree *);
tree * delavl(tree *);		void balance(tree *);
tree * insavl(tree *,int);	void options_av(tree *);
tree * rotateWithLeft(tree *);  tree *rebal(tree *,tree *);
tree * rotateWithRight(tree *); tree *lca(tree *,int,int);
tree * doubleWithLeft(tree *);
tree * doubleWithRight(tree *);

tree *parent(tree* root,int k)
{ 
   tree *temp=root,*parent=temp;

   while(temp!=NULL)
  {  
    tree * savet=temp;
       if(temp->data==k) 	break; 

     if(k>temp->data) temp=temp->right;

     else temp=temp->left;

	parent=savet;
  } 
  
   return parent;
}

int height(tree *t)
{
 return (t==NULL)?-1:t->height ;
}

int max(int l,int r)
{
  return l>r?l:r;
}	


int main()
{
  printf("\n AVL TREE PROGRAM \n");
  printf(" Enter (-1) wherever null \n\n");
   tree *root=NULL;

     options_av(root);
  return 0;
}

void options_av(tree *t)
{ 
 do{
  printf("\n MENU : ");
  
  printf("\n 1: Balance Factor  ");
  printf("\n 2: Inorder ");
  printf("\n 3: Search ");
  printf("\n 4: Insert ");
  printf("\n 5: Delete in AVL ");
  printf("\n 0: Exit    ");
  scanf(" %d",&c);

	 switch(c) 
  	{
  case 1: balance(t);	endl;	break;
  case 2: endl; inor(t); endl;	break;
  case 3: search(t);		break;

  case 4: {
	    printf("\n What do you want to insert ? "); 
	    scanf("%d",&k);	
	    t=insavl(t,k);  	break; }

  case 5: t=delavl(t);		break;  
 
  
  case 0: exit(1);		break;
  	}
     }
while(c!=0);
 }

void balance(tree *t)
{
     if(t==NULL)
  	return ;
  
    if(t!=NULL)
  { 
   printf("\n Balance factor of node %d is %d",t->data,height(t->left)-height(t->right));
   if(t->left)  balance(t->left);
   if(t->right) balance(t->right);
    return;
  } 
	endl;
  }


tree * insavl(tree *t,int k)
{
   if(t==NULL)
   {
     t=(tree *)malloc(sizeof(tree));
     t->height=0;   
     t->data=k; 
     t->left=NULL ; t->right=NULL;
  }

   else if(k<t->data)
   {
     t->left=insavl(t->left,k);
     
     if(height(t->left)-height(t->right)==2 || height(t->left)-height(t->right)==-2)
      {
	if(k<t->data && k<t->left->data) 

		    {printf("\n Single rot with left about %d\n",t->data);	t=rotateWithLeft(t);}
			
	else 
	    {printf("\n Double rot with left about %d\n",t->data);      t=doubleWithLeft(t); }
      }
	else printf("\n No rotation required wrt left of %d \n",t->data);
    }

  else if(k>t->data)	
   {	
	t->right=insavl(t->right,k);

	if(height(t->left)-height(t->right)==2 || height(t->left)-height(t->right)==-2)
      {
	if(k>t->data && k>t->right->data) 

		 {printf("\n Single rot with right about %d\n",t->data);	t=rotateWithRight(t);}
			
	else 
	 {printf("\n Double rot with right about %d\n",t->data); 	t=doubleWithRight(t); }
      }
	else printf("\n No rotation required wrt right of %d \n",t->data);
    }
	
 	t->height=max(height(t->left),height(t->right))+1;	
	return t;
  }


tree * rotateWithLeft(tree *t)
{
   tree * temp;
   temp=t->left;
   t->left=temp->right;
   temp->right=t;

  t->height=max(height(t->left),height(t->right))+1;
  temp->height=max(height(temp->left),height(temp->right))+1;

   return temp;
}


tree * rotateWithRight(tree *t)
{
   tree * temp;
   temp=t->right;
   t->right=temp->left;
   temp->left=t;

  t->height=max(height(t->left),height(t->right))+1;
  temp->height=max(height(temp->left),height(temp->right))+1;
 
   return temp;
}



tree * doubleWithLeft(tree *t)
{
  t->left=rotateWithRight(t->left);
  
  return rotateWithLeft(t);
}



tree * doubleWithRight(tree *t)
{
  t->right=rotateWithLeft(t->right);
  
  return rotateWithRight(t);
}


tree * rebal(tree *root,tree *t)
{							//this will check for the first imbalanced node uptill root
   
  t->height=max(height(t->left),height(t->right))+1;	//update height of returned node after deletion
  
   tree *temp_parent;

  do
   {
     printf("\n Initial node : %d \n",t->data);
   
     temp_parent=parent(root,t->data);
      printf("\n Initial parent of %d found : %d \n",t->data,temp_parent->data);
   
     if(height(t->left)-height(t->right)==2)		
      {
         if(height(t->left->left)-height(t->left->right)>=0)					//left left
            
             {printf("\n Single rot with left about %d\n",t->data);	t=rotateWithLeft(t); }
           
         else if(height(t->left->left)-height(t->left->right)<0)				//left right
        
          {printf("\n Double rot with left about %d\n",t->data);      t=doubleWithLeft(t); }
          
         else printf("\n No rotation required wrt left of %d \n",t->data); 
          
       }
       
       else if(height(t->left)-height(t->right)==-2)		
        {
          if(height(t->right->left)-height(t->right->right)<=0)					//right right
           
             {printf("\n Single rot with right about %d\n",t->data);	t=rotateWithRight(t);}
           
         else if(height(t->right->left)-height(t->right->right)>0)				//right left
          
           {printf("\n Double rot with right about %d\n",t->data); 	t=doubleWithRight(t); }
           
           else printf("\n No rotation required wrt right of %d \n",t->data);
        }
    
     if(temp_parent==root)
      {
        printf("\n Parent reached \n\n");
        break;
       } 
     	
    t=temp_parent;
   printf("\n Now finding parent : %d \n",t->data);
  
  }
   while(t!=root);
  
  
  
   return t;
}


tree* delavl(tree *t)
{  
  if(t==NULL)
     {printf("\n Tree is empty\n ");	return t;}
 
  printf("\n Enter the element you wish to delete ");
   int k; scanf(" %d",&k);


  int flag=0;

   tree *root=t;

   while(t)					//element exists
  { 
   if(k==t->data) {flag=1; break; }
   if(k>t->data) t=t->right;
   else		 t=t->left; 
  } 
 
  if(flag!=1)
  { printf("\n Element doesn't exist in the tree \n"); return root; flag=1; }

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
	
	return rebal(root,t);
    }
 

   if(t->left==NULL && t->right==NULL) 			//given node is  leaf node
   { 
      printf("\n Given node is a leaf node \n"); 
      printf(" Node Deleted : %d \n",k);
	
      tree *par=parent(root,k);

	if(t->data==par->data)
	  	{printf("\n Removing the root node \n");free(t); return NULL;}
		
	
         if(par->left->data==t->data)  {par->left=NULL;  free(t);  }
     	 if(par->right->data==t->data) {par->right=NULL; free(t);  }
       
 	return rebal(root,par);
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
	
     return rebal(root,par);
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

      return rebal(root,par);
   }	
 }
  return root;

  
}


void search(tree *t)
{
   int k,flag=0;
   printf("\n Search for what in AVL ? "); scanf(" %d",&k);

   while(t)
  { 
   if(k==t->data) flag=1;
   if(k>t->data) t=t->right;
   else		 t=t->left; 
  } 
 
  if(flag==1){ printf("\n Element is found\n "); flag=0; }
  else 	 printf("\n Element doesn't exist \n");
}


void inor(tree *t )
{
   if(t)
  { 
    inor(t->left); 
    printf(" %d ",t->data);
    inor(t->right); 
   } 
}


















