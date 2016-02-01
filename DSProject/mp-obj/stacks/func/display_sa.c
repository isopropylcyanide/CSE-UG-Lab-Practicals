#include"../stacks.h"


void display_sa(stack_a *s)
{
  if(s->top==-1)
   {
     printf("\n No elements in stack\n  "); options_sa(s);
   }
 else
  {  printf("\n Displaying stack ");
    
    int x=s->top;  
   while(x!=-1)
   {
     printf("\n Element %d : %d",x+1,s->st[x]);
     x--;
   }
 printf("\n");
}
  options_sa(s);
}
  

