#include<stdio.h>		 
#include"../list.h"

void display_l(node * head)
{  
 
      int count=1; 
  node *p;

   p=head; 
    
  if(p==NULL) 
    {
    	printf("\n No element exits in the list \n");
    	return;
    }
    
  while(p!=NULL)
 {
     printf(" \n Node %d : rno : %d  name : %s marks : %d",count,p->rno,p->name,p->marks);
          p=p->next;
          count++;
 }

 endl;
 
}

