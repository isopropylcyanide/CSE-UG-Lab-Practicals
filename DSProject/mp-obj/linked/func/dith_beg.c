#include<stdio.h>		 
#include"../list.h"

node* dith_beg(node *head)
{
   node *p,*q;  int pos;
   printf("\n Enter position from beginning : "); scanf(" %d",&pos);
   p=head; 
 
   
   if(p==NULL) 
 {
   printf("\n No element to be deleted :");
   return head;
  }
  q=p->next;
  for(c=0; c<pos-1; c++)
 {
     q=q->next; p=p->next;
  }
 p->next=q->next ;
 free(q); 
  printf("\n Node deleted at the specified position \n");
  display_l(head);
  return head;
  }
