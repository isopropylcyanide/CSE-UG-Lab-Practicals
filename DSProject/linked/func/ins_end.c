#include<stdio.h>		 
#include"../list.h"

node* ins_end(node *head)
{
 node *p,*temp;
    temp=(node *)malloc(sizeof(node));
   
   printf("\n Enter rno: name: marks: "); scanf(" %d %s %d",&temp->rno,temp->name,&temp->marks);
   p=head;
  while(p->next!=NULL)
 {
   p=p->next ;
  }
  p->next=temp;
  temp->next=NULL;
  display_l(head);
  return head;
}
