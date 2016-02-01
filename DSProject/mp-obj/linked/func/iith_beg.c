#include<stdio.h>		 
#include"../list.h"

node* iith_beg(node *head)
{ 
                                             //logic: two pointers with one difference around the required position 
 
   node *p,*q,*temp;  int pos;
   printf("\n Enter position from beginning : "); scanf(" %d",&pos);
   temp=(node *)malloc(sizeof(node));
   
   printf("\n Enter rno: name: marks: "); scanf(" %d %s %d",&temp->rno,temp->name,&temp->marks);
   
   p=head; q=p->next;
   for(c=0; c<pos-1; c++)
{ 
   p=p->next;
   q=q->next;
   
 } 
  p->next=temp;  temp->next=q;
  printf("\n Node inserted at the specified position \n");
  display_l(head);
  return head;
  }
