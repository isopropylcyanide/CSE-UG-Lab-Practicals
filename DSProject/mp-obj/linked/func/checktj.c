#include<stdio.h>		 
#include"../list.h"

void checktj(node * head)
{	
  node *p=head,*q=head,*save=head; int flag=0;
		
		 	
 if(p==NULL || p->next==NULL) 
  {
      printf("\n No elements.  Hence no T-joint possible \n\n");
      return;
  }
  
  if(head2==NULL) 
  {
    printf("\n No T-joint in the list \n"); 
    options(head);
   }

    while(q->next!=NULL) 
    q=q->next; 
	
    q->next=p;
    	
    q=p=head2;

    while(q && q->next)
     {
      p=p->next;
      q=q->next->next;

      if(p==q)
        { 
        printf("\n A T-joint has been detected \n");
	flag=1;  
	break;
        }	
   }
       
    if(flag==1)
     {
        printf("\n I am here ");
   	p=head;
   	
	while(p!=q)
  	{
	     p=p->next;
	     q=q->next;
   	}
   	
	printf(" \n T-joint found at  rno : %d \n\n",p->rno);
     }
     
     options(save);
  }











