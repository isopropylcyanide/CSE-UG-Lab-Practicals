#include"../stacks.h"

void coin(stack *s)
{
  printf("\n Original type : Infix ");
   printf("\n 1: Postfix ");
   printf("\n 2: Prefix ");
   printf("\n 0: Back ");
  
   scanf(" \t %d",&i) ;
  
  switch(i)
 {
   case 1:   coinpos(s);      break;
   case 2:   coinpre(s);      break;
   case 0:   options_p(s);
  }
 }  

