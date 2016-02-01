#include"../tree.h"

tree * lca(tree *t,int a1,int a2)
{
  while(t)
  {
  
  if(t->data==a1 && t->data==a2)
   return t;
  
  if(t->data>a1 && t->data>a2)
   t=t->left;
   
   if(t->data<a1 && t->data<a2)
   t=t->right;
   
   if((t->data>=a1 && t->data<a2) || (t->data>=a2 && t->data<a1))
   return t;
   }
   return t;
 }
