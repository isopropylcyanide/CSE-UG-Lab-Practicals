#include"../list.h"



node* dith_begd(node *head)			//*doubly
{
   node *p,*q;  int pos;
   printf("\n Enter position from beginning : "); scanf(" %d",&pos);
   p=head; 
 
   
   if(p==NULL) 
 {
   printf("\n No element to be deleted :");
   return head;
  }

  for(c=0; c<pos; c++)
 {
      p=p->next;
  }

  q=p;
  p->prev->next=p->next;
  p->next->prev=p->prev;
  free(q);
 
  printf("\n Node deleted at the specified position \n");
  display_dl(head);
  return head;
  }
