#include"../queue.h"

void options_qa(queue *q)
{
   do{
  printf("\n\n Currently front=%d & rear=%d ",front_a,rear_a);
  
  printf("\n 1: Enqueue ");
  printf("\n 2: Dequeue ");
  printf("\n 3: Display ");
  printf("\n 0: Back \t");
			  scanf(" %d",&i);
  system("clear");			  
			  
  switch(i) {

  case 1: enqueue(q);	break;
  case 2: dequeue(q);	break; 
  case 3: display_qa(q);break;
  case 0: printf("\n Are you sure to go back : ");
     		scanf(" %d",&z);
     		if(z==1)
     		{
     		  system("clear");
     		  printf("\n\n Returning from the queues- arrays menu ");
     		  printf("\n (Expected wait time - 2 secs) \n");
     		  system("sleep 2");
     		  return;
     		}
  		else options_qa(q);
 
  default: printf("\n Wrong char ");
          }
   }
   while(i!=0);
}

