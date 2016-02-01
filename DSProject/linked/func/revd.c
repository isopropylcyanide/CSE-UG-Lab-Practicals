#include"../list.h"


node * revd(node *head)         //reversing using iteration
{
   node * temp,*p,*q;
   temp=NULL;
   p=head;
   if(p==NULL || p->next==NULL) 
   { 
	 printf("\n No elements to reverse \n");
        return p; 
   }
  
    while(p!=NULL)
 {   
   q=p->next ;
   p->next=temp;   
   temp=p;
   temp->prev=q;		//important
   p=q;
   }
  temp->prev=NULL;
  head=temp;

  printf("\n List Reversed using iterative method \n");
  display_dl(head);
  return head;
  }
 

