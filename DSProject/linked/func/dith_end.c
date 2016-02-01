#include<stdio.h>		 
#include"../list.h"

node* dith_end(node *head)
{
    node *p,*q,*r;  int pos,count=1;
   printf("\n Enter position from end : "); scanf(" %d",&pos);
  
 
            					//firstly counting no of elements
   r=head;
   
    if(r==NULL) 
 {
   printf("\n No element to be deleted :");
   return head;
  }
    while(r->next!=NULL)
  {
    count++; 
    r=r->next;
   }
           					 //now using formula count-pos-1 from starting 

  p=head;  q=p->next;
   for(c=0; c<(count-pos-2) ; c++)
 {
    q=q->next;
    p=p->next;
  }
 p->next=q->next;
 free(q);

printf("\n Node deleted at the specified position \n");
  display_l(head);
  return head;
}  
