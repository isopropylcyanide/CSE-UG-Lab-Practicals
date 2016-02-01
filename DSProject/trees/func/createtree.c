#include"../tree.h"

tree *createtree()
{ 
  tree *temp;    
 printf("\n Enter data :  "); 
  
   int x;
    scanf("%d",&x);
  
  if(x==-1)
    return NULL;
  

  temp=(tree *)malloc(sizeof(tree));
    temp->data=x;
   
 
   printf("\n For left child of %d ",x);
   temp->left=createtree();

   printf("\n For right child of %d ",x);
   temp->right=createtree();

 	return temp;
}
