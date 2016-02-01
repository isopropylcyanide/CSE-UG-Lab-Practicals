#include"../tree.h"

int size(tree *t)
{
   if (t==NULL) 
    return 0;
  else     
    return(size(t->left) + 1 + size(t->right));  
  }

