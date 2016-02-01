#include"../stacks.h"

void options_p(stack *s)
 {
   printf("\n Following are available ");
   printf("\n 1: Evaluate postfix ");
   printf("\n 2: Evaluate prefix ");
   printf("\n 3: Convert ");
   printf("\n 0: Back ");
   scanf(" \t %d",&i) ;
   
   system("clear");
   
  switch(i)
 {
   case 1:   evalpo(s);      break;
   case 2:   evalpre(s);     break;
   case 3:   convert_p(s);     break;
   case 0:   printf("\n Are you sure to go back : ");
     		scanf(" %d",&z);
     		if(z==1) 
     		{
     		  system("clear");
     		  printf("\n\n Returning from the stacks- polish menu ");
     		  printf("\n (Expected wait time - 2 secs) \n");
     		  system("sleep 2");
     		  return;
     		}
  		else options_p(s);
  }
 }
