#include"../list.h"

void display_dl(node * head)		//*using doubly
{
  int count=1; 
  node *p;

   p=head;
 
printf("\n Displaying using next :");

  if(p==NULL) 
   { printf("\n No element exits in the list "); return;  }
  while(p!=NULL)
 {
     printf(" \n Node %d : rno : %d  name : %s marks : %d",count,p->rno,p->name,p->marks);
       p=p->next;
       count++;
  } 

 p=head;  count=1;

 printf("\n\n Displaying using previous ");

  if(p==NULL)

 { printf("\n No element exits in the list \n");  options_dl(head); }

 while(p->next!=NULL)
   p=p->next ;			//reached end			

   while(p!=NULL)
 {
     printf(" \n Node %d : rno : %d  name : %s marks : %d",count,p->rno,p->name,p->marks);
       p=p->prev;
       count++;
  }  


 printf("\n");
 
}

