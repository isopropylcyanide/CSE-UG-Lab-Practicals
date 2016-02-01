#include"../tree.h"
  
int height(tree *t)
{
 return (t==NULL)?-1:t->height ;
}
