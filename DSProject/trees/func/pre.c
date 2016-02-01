#include"../tree.h"

void pre(tree *t)
{  
   if(t!=NULL)
  { 
    if(t) printf(" %d ",t->data);
    
    pre(t->left); 
    pre(t->right); 
    
   } 

 }


