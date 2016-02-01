#include<stdio.h>		 
#include"../list.h"

node* ins_beg(node *head)
{
   node *p,*temp; 
    temp=(node *)malloc(sizeof(node));
    printf("\n Enter rno: name: marks: "); scanf(" %d %s %d",&temp->rno,temp->name,&temp->marks);
  
   p=head;
  temp->next=p;
  head=temp;
  printf("\n Node entered. \n");
  display_l(head);
  return head;
 }

