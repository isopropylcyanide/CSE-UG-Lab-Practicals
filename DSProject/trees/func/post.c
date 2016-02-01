#include"../tree.h"


void post(tree *t)
{
   if(t!=NULL)
  { 
    post(t->left); 
    post(t->right); 
    if(t) printf(" %d ",t->data);
     else printf(" NULL ");
   } 
 
}
