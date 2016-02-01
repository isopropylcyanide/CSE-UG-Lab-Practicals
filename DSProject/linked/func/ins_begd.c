#include"../list.h"

node* ins_begd(node *head)		//*doubly
{
   node *p,*temp; 
    temp=(node *)malloc(sizeof(node));
    printf("\n Enter rno: name: marks: "); scanf(" %d %s %d",&temp->rno,temp->name,&temp->marks);
  
   p=head;
  temp->next=p; 
  p->prev=temp; 
  head=temp;	
  printf("\n Node entered. \n");
  display_dl(head);
  return head;
 }

