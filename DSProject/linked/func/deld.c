#include<stdio.h>		 
#include"../list.h"

node* deld(node *head)
{
  printf("\n Where do you want to delete :");
  printf("\n 1: Beginning ");
  printf("\n 2: End ");
  printf("\n 3: ith ");
  printf("\n 0: Back ");
  scanf(" %d",&c);
  

  switch(c)
{
   case 1: head=del_begd(head); break;
   case 2: head=del_endd(head); break;
   case 3: head=del_ithd(head); break;
   case 0: return head;
   default: printf("\n Enter correct choice for delete\n");
 }

 return head;
} 
