#include"../tree.h"
  
tree * rotateWithRight(tree *t)
{
   tree * temp;
   temp=t->right;
   t->right=temp->left;
   temp->left=t;

  t->height=max(height(t->left),height(t->right))+1;
  temp->height=max(height(temp->left),height(temp->right))+1;
 
   return temp;
}
