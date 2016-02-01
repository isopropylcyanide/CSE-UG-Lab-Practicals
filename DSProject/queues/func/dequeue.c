#include"../queue.h"

void dequeue(queue *q)
{
   if(front_a==-1)		//queue is empty
  {
      printf("\n Queue is empty. \n");
      return;
   }

  if(front_a==rear_a)
 {
    printf("\n Queue only has one element ");
  	
	printf("\n Element out of the queue is : %d \n",q->qu[front_a]);		
	
    front_a=-1; rear_a=-1;
	return;
  }
        

 if(front_a<rear_a)
   {
  	printf("\n Element out of the queue is .. %d \n",q->qu[front_a]);
 
        front_a++;
    return;
    }

   if(front_a==maxim-1)
 {
	printf("\n Element out of the queue is .. %d \n",q->qu[front_a]);
      front_a=0;
   return;
  }

 if(front_a>rear_a)
 {
   if(front_a<maxim)
    {
   	 printf("\n Element out of the queue is .. %d \n",q->qu[front_a]);
     		 front_a++ ; 
       }

  if(front_a==maxim-1)
 {
	printf("\n Element out of the queue is .. %d \n",q->qu[front_a]);
      front_a=0;
    return;
  }
 }
 
  
}



