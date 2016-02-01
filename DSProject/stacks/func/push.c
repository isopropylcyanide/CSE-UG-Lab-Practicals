#include"../stacks.h"

void push(stack_l *top)
{  
   stack_l *p;
    p=(stack_l *)malloc(sizeof(stack_l));
   if(p==NULL) 					//stack_l overflow generally wont occur in linked lists.
  {
       printf("\n Stack is full ");
        options_sl(top);
    }

   printf("\n Enter element to be pushed :");
   scanf(" %d",&p->data);
   p->next=top;
   top=p;
   options_sl(top);  
}
