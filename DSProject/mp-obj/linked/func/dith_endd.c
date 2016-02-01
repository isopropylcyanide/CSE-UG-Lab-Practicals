#include"../list.h"


node* dith_endd(node *head)		//*doubly
{
    node *p,*q;  int pos,count=1;
   printf("\n Enter position from end : "); scanf(" %d",&pos);
  
 
            					//firstly counting no of elements
   p=head;
   
    if(p==NULL) 
 {
   printf("\n No element to be deleted :");
   return head;
  }
    while(p->next!=NULL)
  {
    count++; 
    p=p->next;
   }
           					 //now using formula count-pos-1 from starting 
  p=head; 
 
   for(c=0; c<(count-pos-1) ; c++)
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

