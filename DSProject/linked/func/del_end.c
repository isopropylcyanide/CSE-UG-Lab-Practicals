#include<stdio.h>		 
#include"../list.h"

node* del_end(node *head)
{
     node *p,*temp; 

       p=head; 
  
    if(p==NULL) 
 {
   printf("\n No element to be deleted :");
   return head;
  }
  temp=p->next;
   while(temp->next!=NULL)
  { 
    temp=temp->next;
    p=p->next ;
   }
  
   free(temp);
   p->next=NULL ;
  
  printf("\n Node deleted at the end \n");
  display_l(head);
  return head;
}
