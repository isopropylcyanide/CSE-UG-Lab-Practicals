#include"../stacks.h"

void copos(stack *s)
{
  printf("\n Original type : Postfix ");
   printf("\n 1: Prefix ");
   printf("\n 0: Back ");
  
   scanf(" \t %d",&i) ;
  
  switch(i)
 {
   case 1:   copospre(s);      break;
   case 0:   options_p(s);
  }
 } 
