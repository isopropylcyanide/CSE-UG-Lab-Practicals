#include<stdio.h>		 
#include"../list.h"

node* iith_end(node *head)
{ 
                                         //Approach 1: count the nodes and apply for loop from behind with two pointers differencing in their position by 1
                
   node *p,*q,*r,*temp;  int pos,count=1;
   printf("\n Enter position from end : "); scanf(" %d",&pos);
   temp=(node *)malloc(sizeof(node));
   
   printf("\n Enter rno: name: marks: "); scanf(" %d %s %d",&temp->rno,temp->name,&temp->marks);
   
                                           //firstly counting no of elements
   r=head;
    while(r->next!=NULL)
  {
    count++; 
    r=r->next;
   }
                                               //now using formula count-pos-1 from starting 
  p=head;  q=p->next; 
   for(c=0; c<(count-pos-1) ; c++)
  {
    p=p->next;
    q=q->next;
  }
     p->next=temp;
     temp->next=q;
   printf("\n Node inserted at the specified position \n");
  display_l(head);
  return head;
}
