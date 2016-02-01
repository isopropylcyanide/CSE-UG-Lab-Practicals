#include<stdio.h>		 
#include"../list.h"

node* del_ithd(node *head)
{
   printf(" \n 1: ith from begining ");
   printf(" \n 2: ith from end ");
    scanf(" %d",&c); 
  switch(c)
{ 
   case 1: head=dith_begd(head); break;
   case 2: head=dith_endd(head); break;
  
   default: printf("\n Enter correct choice for ith menu");
 }return head;
}
