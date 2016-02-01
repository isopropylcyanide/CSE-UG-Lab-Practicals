#include"../queue.h"

void options_ql()
{
  do
      {
  printf("\n Queue size : %d",count);

  if(isEmpty_p()!=1)  
  printf("\n Top of the queue is : %d",peek());
  printf("\n\n 1: Enqueue ");
  printf("\n 2: Dequeue ");
  printf("\n 3: isEmpty ");
  printf("\n 4: Display ");
  printf("\n 0: Back \t");
			  scanf("%d",&i);
  system("clear"); 
			 
  switch(i) {

  case 1: enqueuep();	break;
  case 2: dequeuep();	break; 
  case 3: isempty_p();	break;
  case 4: display_ql();	break;
  case 0: printf("\n Are you sure to go back : ");
     		scanf(" %d",&z);
     		if(z==1)
     		{
     		  system("clear");
     		  printf("\n\n Returning from the queues-lists menu ");
     		  printf("\n (Expected wait time - 2 secs) \n");
     		  system("sleep 2");
     		  return;
     		}
  		else options_ql();
  
  
  default: printf("\n Wrong char ");
  }
 }while(i!=0);
}

