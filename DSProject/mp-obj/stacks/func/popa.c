#include"../stacks.h"

void popa(stack_a *s)
{
   
    if(s->top==-1) { printf("\n Stack Underflow \n"); options_sa(s); }
 else 
    printf("\nElement %d : %d\n",s->top+2,(s->st[s->top])) ;
    s->top--;
}



