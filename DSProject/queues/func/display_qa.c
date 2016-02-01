#include"../queue.h"


void display_qa(queue *q)
{
  int f=front_a; int r=rear_a;

  if(front_a==-1)
 {
    printf("\n Nothing to display. Queue is empty ");
    return;
 }

 printf("\n Displaying queue");
 
 if(f<=r)

    while(f<=r)
   {
     printf("\n Data : %d ",q->qu[f]);
      f++;
   }
 

  else
{ 

     while(f<maxim)
    {
       printf("\n Data : %d ",q->qu[f]);
	f++; 
   }

 f=0;
  while(f<=rear_a)
  {
    printf("\n Data : %d :",q->qu[f]);
   f++;
   }
 }
   return;
} 
 

