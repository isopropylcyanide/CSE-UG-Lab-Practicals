#include"../tree.h"
  
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
	end;
  }

