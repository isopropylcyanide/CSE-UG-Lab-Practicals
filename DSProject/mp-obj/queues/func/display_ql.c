#include"../queue.h"

void display_ql()
{
    queue *p=front;
    
   if(p==NULL && rear==NULL)
    { 
      printf("\n Queue is empty.Nothing to display ");
       options_ql();
     }
 
  printf("\n Displaying queue : ");
 while(p!=rear) {
    
      printf("\n %d",p->data); 
      p=p->next;
       }
 
   if(p==rear)
   {
      printf("\n %d",p->data);
 }
   options_ql();
}
