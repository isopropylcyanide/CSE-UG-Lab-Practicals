#include"../tree.h"

tree* insbst(tree *t,int k)			//insertion into BST	
{
    if(t==NULL)
   {
     t=(tree *)malloc(sizeof(tree));  
     t->data=k; 
     t->left=NULL ; t->right=NULL;
  }

   else if(k<t->data)
   {
     t->left=insbst(t->left,k);
      }

  else if(k>t->data)	
   {	
	t->right=insbst(t->right,k);
    }
	
 		
	return t;
}
