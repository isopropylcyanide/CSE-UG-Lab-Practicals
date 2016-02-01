#include"../list.h"

node* del_endd(node *head)		//*doubly
{
     node *p,*temp; 

       p=head; 
  
    if(p==NULL) 
 {
   printf("\n No element to be deleted :");
   return head;
  }

   while(p->next!=NULL)
  { 
    p=p->next ;
   }
  
   temp=p; 
   p->prev->next=NULL;
   free(temp);
  
  printf("\n Node deleted at the end \n");
  display_dl(head);
  return head;
}
