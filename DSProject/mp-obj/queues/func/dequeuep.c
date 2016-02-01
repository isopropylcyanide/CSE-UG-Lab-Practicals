#include"../queue.h"

void dequeuep()
{
     queue * p=front;

   if(p==NULL)
      {
  	printf("\n Queue is empty. Can't deque ");
    	return;
      }
 
    if(p->next!=NULL)
     {
        printf("\n Dequeued value : %d ",p->data);
       p=p->next;
        
        free(front);
       front=p;
        count--;
        return;
      }

     else 
       {
         printf("\n Dequeued value : %d ",p->data);
         
        free(front);
        front=rear=NULL ;
         count--;
         return;
        }
     
  }

