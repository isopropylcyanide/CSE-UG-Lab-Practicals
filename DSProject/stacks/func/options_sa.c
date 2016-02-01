#include"../stacks.h"

void options_sa(stack_a *s)
 {
 do{
   printf("\n Top = %d ",s->top);
 
  printf("\n 1: Push ");
  printf("\n 2: Pop  ");
  printf("\n 3: Display ");
  printf("\n 0: Back\t");
  scanf(" %d",&c);
  
  system("clear");
  switch(c) {
  

   case 1: pusha(s);     break;
   case 2: popa(s);    break;
   case 3: display_sa(s);  break;
   
   case 0: printf("\n Are you sure to go back : ");
     		scanf(" %d",&z);
     		if(z==1)
     		{
     		  system("clear");
     		  printf("\n\n Returning from the stacks- arrays menu ");
     		  printf("\n (Expected wait time - 2 secs) \n");
     		  system("sleep 2");
     		  return;
     		}
  		else options_sa(s);
  		
   default: printf("\n Enter correct value in main\n");
  }
   }while(c!=0);
}
