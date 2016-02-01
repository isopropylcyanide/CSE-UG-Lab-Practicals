#include"../queue.h"

void enqueue(queue *q)
{
 
 if((front_a==0 && rear_a==maxim-1)|| front_a==rear_a+1) 
   {
      printf("\n Queue overflow. Dequeue first ");
      return;
    }
  
       
     if(front_a==-1)		//queue is empty
     {					
        front_a=0;
        rear_a=0;
     }
  else if(rear_a==maxim-1) rear_a=0;
 else
       rear_a++;

	   printf("\n Enter the element : "); 
          scanf(" %d",&j);
           q->qu[rear_a]=j;
       printf("\n Element in queue: %d ",j);
         return;
      }
  

