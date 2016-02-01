#include"../tree.h"


void depth(tree *t)
{
	int d1=0,d2=0; tree*p=t;
	
	while(t->left!=NULL || t->right!=NULL)
	{
	   d1++;

	   if(t->left==NULL) t=t->right;	
	   else t=t->left;
	}
	t=p;
	
	while(t->left!=NULL || t->right!=NULL)
	{
	   d2++;

	   if(t->right==NULL) t=t->left;	
	   else t=t->right;
	}t=p;

	if(d1>d2) { printf("\n Depth and height of tree is %d ",d1); return; }
	else	  { printf("\n Depth and height of tree is %d ",d2); return; }
  }

