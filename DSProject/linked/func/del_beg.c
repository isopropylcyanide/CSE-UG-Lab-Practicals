#include<stdio.h>		 
#include"../list.h"

node* del_beg(node * head)
{
   node *p,*temp; 
    
       p=head;
 if(p==NULL) 
 {
   printf("\n No element to be deleted :");
   return head;
  }
    temp=p->next;
    head=temp;
    free(p);
    printf("\n Node deleted at the beginning \n");
  display_l(head);
  return head;
  
  }
