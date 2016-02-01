#include"../tree.h"
  
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

