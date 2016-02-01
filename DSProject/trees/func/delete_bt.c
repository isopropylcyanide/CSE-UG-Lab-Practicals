#include"../tree.h"

tree* delete_bt(tree *t)
{
	if(t==NULL) return t;

	delete_bt(t->left);
	delete_bt(t->right);
	printf("\n Deleting node : %d ",t->data);
	free(t);
	return NULL;
	printf("\n");
  }
