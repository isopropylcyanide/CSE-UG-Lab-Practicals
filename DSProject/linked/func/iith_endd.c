#include"../list.h"

node* iith_endd(node *head)		//*doubly
{               
   node *p,*temp;  int pos,count=1;

   printf("\n Enter position from end : "); scanf(" %d",&pos);
   temp=(node *)malloc(sizeof(node));
   
   printf("\n Enter rno: name: marks: "); scanf(" %d %s %d",&temp->rno,temp->name,&temp->marks);
   
                                           
  p=head;
    while(p->next!=NULL)
  {
    count++; 
    p=p->next;
   }
                                              
  p=head; 
                                        
   for(c=0; c<(count-pos-1) ; c++)
  {
    p=p->next;
  
  }
     temp->next=p->next;
     p->next->prev=temp;
     p->next=temp;   temp->prev=p; 
     
   printf("\n Node inserted at the specified position \n");
  display_dl(head);
  return head;
}
