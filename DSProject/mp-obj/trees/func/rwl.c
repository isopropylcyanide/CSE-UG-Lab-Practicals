#include"../tree.h"
  
tree * rotateWithLeft(tree *t)
{
   tree * temp;
   temp=t->left;
   t->left=temp->right;
   temp->right=t;

  t->height=max(height(t->left),height(t->right))+1;
  temp->height=max(height(temp->left),height(temp->right))+1;

   return temp;
}
