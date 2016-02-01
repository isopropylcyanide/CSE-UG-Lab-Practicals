#include"../tree.h"

void lorder(tree *t)
{   
    if(!t) return ;

    enqueue_bt(t);

    while(fr!=rr+1)
   {
    t=deque_bt();
   
    if(t) printf(" %d ",t->data);
     
     if(t->left)  enqueue_bt(t->left);
     if(t->right) enqueue_bt(t->right);

  }
 
}

