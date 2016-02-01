#include"../tree.h"
  
tree * doubleWithRight(tree *t)
{
  t->right=rotateWithLeft(t->right);
  
  return rotateWithRight(t);
}
