#include"../tree.h"

int search(tree *t,int k)
{
   if(t)
  { 
   if(k==t->data) { return 1; }
   search(t->right,k);
   search(t->left,k); 
  } 
  return 0;
}


