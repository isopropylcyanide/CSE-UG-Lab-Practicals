#include"../queue.h"


void enqueuep()
{ 
   if(rear==NULL)
  {
   rear=(queue *)malloc(sizeof(queue));
	rear->next=NULL; 
 
     printf("\n Enter the element : "); scanf(" %d",&rear->data);
	
	front=rear;
  }
    else {
            queue *temp;
   temp=(queue *)malloc(sizeof(queue));
  	rear->next=temp;

     printf("\n Enter the element : "); scanf(" %d",&temp->data);

         temp->next=NULL ;
    	 rear=temp;
   }
  count++;
   return;
 }
