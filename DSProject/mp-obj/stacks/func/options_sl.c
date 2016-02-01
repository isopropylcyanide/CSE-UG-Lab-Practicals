#include"../stacks.h"

void options_sl(stack_l *top)
 {
 do{
  
  printf("\n 1: Push element ");
  printf("\n 2: Pop element ");
  printf("\n 3: Display stack");
  printf("\n 0: Back\t");
  scanf(" %d",&c);
  
  system("clear");
  switch(c) {
  
   case 1: push(top);     break;
   case 2: pop(top);    break;
   case 3: display_sl(top);  break;
   case 0: printf("\n Are you sure to go back : ");
   
     		scanf(" %d",&z);
     		if(z==1) 
     		{
     		  system("clear");
     		  printf("\n\n Returning from the stacks- lists menu");
     		  printf("\n (Expected wait time - 2 secs) \n");
     		  system("sleep 2");
     		  return;
     		}
  		else options_sl(top);
   default: printf("\n Enter correct value in main\n");
  }
   }while(c!=0);
}
