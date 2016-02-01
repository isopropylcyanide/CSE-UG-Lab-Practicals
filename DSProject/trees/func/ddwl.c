#include"../tree.h"
  
tree * doubleWithLeft(tree *t)
{
  t->left=rotateWithRight(t->left);
  
  return rotateWithLeft(t);
}
