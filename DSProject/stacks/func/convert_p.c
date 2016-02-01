#include"../stacks.h"
void convert_p(stack *s)
{
   printf("\n 1: Infix ");
   printf("\n 2: Postfix ");
   printf("\n 0: Back ");

  scanf(" \t %d",&i) ;
  
  switch(i)
 {
   case 1:   coin(s);      break;
   case 2:   copos(s);     break;
   case 0:   options_p(s);
  }
 }  
