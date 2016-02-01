#include"../tree.h"

tree *parent(tree* root,int k)
{ 
   tree *temp=root,*parent=temp;

   while(temp!=NULL)
  {  
    tree * savet=temp;
       if(temp->data==k) 	break; 

     if(k>temp->data) temp=temp->right;

     else temp=temp->left;

	parent=savet;
  } 
  
   return parent;
}

