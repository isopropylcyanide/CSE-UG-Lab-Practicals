#include"../tree.h"

void inorit(tree *t)
{ 
  while(1)
  
 {
   if(t)
	{ 
	  push_bt(t);
	  t=t->left ;
	}
  
   
   else
    {
    
       if(tos>-1)
      {
       t=pop_bt();
       if(t)printf(" %d ",t->data);
       
       t=t->right;
      }
      else break;
    }
   
 }      
	
}

