#include"../list.h"


node* iith_begd(node *head)		//*doubly	
{ 
                                              
 
   node *p,*q,*temp;  int pos;

   printf("\n Enter position from beginning : "); scanf(" %d",&pos);
   temp=(node *)malloc(sizeof(node));
   
  printf("\n Enter rno: name: marks: "); scanf(" %d %s %d",&temp->rno,temp->name,&temp->marks);
  
  p=head;
   for(c=0; c<pos-1; c++)
  {
   p=p->next;
  }
    q=p->next; 
    p->next=temp;  temp->prev=p;   temp->next=q;  q->prev=temp;
  
  printf("\n Node inserted at the specified position \n");
  display_dl(head);
  return head;
  }

