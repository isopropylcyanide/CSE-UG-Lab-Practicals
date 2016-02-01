#include"../stacks.h"

void pushe(stack *s,char x)
{ 
 
   if(s->top==39) printf("\n Stack Overflow \n");
 
 else { 
      s->top++;
      s->st[s->top]=x ;
      printf("\n Element pushed : %d",x);
}
	
}
