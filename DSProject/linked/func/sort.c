#include<stdio.h>		 
#include"../list.h"

void sort(node *head)
{
   if(head==NULL) 
  {
      printf("\n Error while sorting. No list\n"); return ; }
 
else {
             int count=1; int k,temp;
             node *p,*q,*r;  p=head; q=p->next;
 
  r=head;					//using bubble sort. first counting
    while(r->next!=NULL)
  {
    count++; 
    r=r->next;
   }
     printf("\n Enter sorting criterion : rno 1 : marks 2 : ");
   scanf(" %d",&c);

 if(c==1) {
                   
   
  for(k=0; k<=count; k++)    //and swapping for rno. whole nodes should move not their data
 {
    while(q!=NULL)
    {
       if(p->rno>q->rno) 
        {
           temp=p->rno;
    	   p->rno=q->rno ;
 	   q->rno=temp;
  
     } p=p->next;
       q=p->next;
    
     }
      p=head; q=p->next;
  }
   printf("\n Sorted according to Rno \n"); display_l(head);
 }

 if(c==2) {
                   
   
   for(k=0; k<=count; k++)    //and swapping for marks 
 {
    while(q!=NULL)
    {
       if(p->marks>q->marks) 
        {
           temp=p->marks;
    	   p->marks=q->marks ;
 	   q->marks=temp;
         }
       q=q->next ; p=p->next;
     }
       p=head; q=p->next;
  }
   printf("\n Sorted according to Marks \n"); display_l(head);
 }  
 }
 } 						//sort ends

