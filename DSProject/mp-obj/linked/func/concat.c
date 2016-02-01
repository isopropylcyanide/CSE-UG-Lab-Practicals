#include<stdio.h>		 
#include"../list.h"

void concat(node *head)
{
   if(head==NULL)
  {
      printf("\n Error. Add a default linked list first \n"); return ; }
 else
{ 
  printf("\n No new list added yet. Would you like to add another list to current 1/0: ");
   scanf(" %d",&c);                                                 
    if(c==0) options(head);
 else if(c==1)
 {
      node *head2;
     head2=createlists();

       printf("\n \n Concatenating lists. Wait ...\n");
  node *p,*q;
  
      //to first list's last point new lists first 

   p=head;  q=head2;
   while(p->next!=NULL) { p=p->next; };

    p->next=q;      
  printf("\n Concatenation complete. \n \n");
  display_l(head);
  }
 }
}

