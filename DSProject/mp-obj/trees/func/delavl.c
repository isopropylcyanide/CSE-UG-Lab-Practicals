#include"../tree.h"
  
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

