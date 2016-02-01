#include"../stacks.h"

void pusha(stack_a *s)
{ int k;
 
   if(s->top==maxi-1) printf("\n Stack Overflow \n");
 
 else { printf("\n Enter element : ");
  scanf(" %d",&k);
      s->top++;
      s->st[s->top]=k ;
      printf("\n Element pushed\n");
} }
			

