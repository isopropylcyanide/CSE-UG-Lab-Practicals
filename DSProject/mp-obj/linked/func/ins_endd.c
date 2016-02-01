#include"../list.h"


node* ins_endd(node *head)		//*doubly
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
  temp->next=NULL;	temp->prev=p;
  display_dl(head);
  return head;
}
