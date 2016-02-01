#include"../tree.h"

void leaves(tree *t)
{
   if(t!=NULL)
  {
     if(t->left==NULL && t->right==NULL)
        {
          printf("\n Leaf found : %d ",t->data);

         }
        leaves(t->left);
        leaves(t->right);
 }
}


