#include"../stacks.h"

void pop(stack_l *top)
{
   int t; stack_l* p;
   
   if(top==NULL)
     {
        printf("\n Stack Underflow ");
         options_sl(top);
     }
     
else {
  t=top->data;
  p=top;
  top=top->next;
  free(p);
 printf("\n Element popped : %d",t);
 options_sl(top);
}
  }  


