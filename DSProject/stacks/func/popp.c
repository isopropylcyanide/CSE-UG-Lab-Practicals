#include"../stacks.h"

char popp(stack *s)
{ 
   char x;
   x=s->st[s->top];
   s->top--;
   return x;
   
}
