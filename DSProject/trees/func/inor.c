#include"../tree.h"

void inor(tree *t )
{
   if(t!=NULL)
  { 
    inor(t->left); 
    if(t) printf(" %d ",t->data);
    inor(t->right); 
   } 

}


