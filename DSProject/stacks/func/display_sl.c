#include"../stacks.h"

void display_sl(stack_l * top)
{
	if(top==NULL)
     {
        printf("\n No elements in stack\n ");
         options_sl(top);
     }
 else {
  printf("\n Displaying stack\n ");
  stack_l *p=top;
  
  while(p!=NULL)
  {
    printf("\n Element : %d ",p->data);
    p=p->next;
  }
 printf("\n");
}
options_sl(top);
}
 



