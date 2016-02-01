#include<stdio.h>		 
#include"../list.h"

void rmdup(node *head)
 {
      if(head==NULL)
  {
      printf("\n Error. Add entries first \n"); return ; }
  node *p=head,*temp,*q,*r; 
                           		//useful for deletion
              
   for(p=head; p!=NULL ; p=p->next)
  {
   
    for(r=p,q=p->next; q!=NULL; q=q->next) 
   { 
     
     if(p->rno==q->rno)
    {  
         d++; 				               //static int 
       printf("\n Duplicate found :%d \n",d);
       printf(" \n Duplicate Node: rno : %d name : %s marks : %d \n",q->rno,q->name,q->marks); 
       printf(" Original Node: rno : %d name : %s marks : %d ",p->rno,p->name,p->marks);
       printf(" \n Deleting dup : %d \n\n",d);
          temp=q;
    
        r->next=temp->next;
           free(temp);
    } 
     r=q;
   }
  }
    printf("\n Searching for duplicates completed \n");
    display_l(head);  

}

