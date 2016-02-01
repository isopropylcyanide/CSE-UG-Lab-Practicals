#include"../stacks.h"

int pope(stack *s)
{
   int x=s->st[s->top];
   
    if(s->top==-1) {  return 0; }
 else 
    { printf("\n Popped : %d ",x);
     return s->st[s->top--] ;
   }
   
}
