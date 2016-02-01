#include<stdio.h>		 
#include"../list.h"


void instj(node * head)
 {
   head2=createlists();	
   int count=1; 
   node *s,*r=head;
		
   printf("\n Enter element of the first list which is the joint : ");
 	scanf("%d",&i);

 	while(r->next!=NULL)
	{
	  r=r->next;   
	  count++;

  	 if(count==i)
  	    break ;
	}
 
   s=head2;

  while(s->next!=NULL) 		
  s=s->next;
                                  
   s->next=r;
  printf("\n Displaying list with the joint \n\n");

  count=1; 
  node *p;

   p=head2; 
    
  while(p!=NULL)
 {
     printf(" \n Node %d : rno : %d  name : %s marks : %d",count,p->rno,p->name,p->marks);
          p=p->next;
          count++;
 }
 endl;
 
 options(head);
}
