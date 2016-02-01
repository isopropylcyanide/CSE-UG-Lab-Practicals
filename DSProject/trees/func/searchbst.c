#include"../tree.h"

void searchbst(tree *t)
{
   int k,flag=0;
   printf("\n Search for what in BST ? "); scanf(" %d",&k);

   while(t)
  { 
   if(k==t->data) flag=1;
   if(k>t->data) t=t->right;
   else		 t=t->left; 
  } 
 
  if(flag==1){ printf("\n Element is found\n "); flag=0; }

  else 	 printf("\n Element doesn't exist \n");
}

