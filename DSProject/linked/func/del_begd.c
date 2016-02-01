#include"../list.h"


node* del_begd(node * head)		//*doubly
{
   node *p,*temp; 
    
       temp=head;
 if(temp==NULL) 
 {
   printf("\n No element to be deleted :");
   return head;
  }
    p=temp->next;
    p->prev=NULL;
    head=p;		
    free(temp);
    printf("\n Node deleted at the beginning \n");
  display_dl(head);
  return head;
  }
 
