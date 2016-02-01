#include"../stacks.h"

int op(int a,int b,char c)				//What happens during evaluation
{
   switch(c)
   {
     case '+' : return a+b; 	 break;
     case '-' : return a-b; 	 break;
     case '*' : return a*b; 	 break;
     case '/' : return a/b; 	 break;
     
  default: printf("\n Wrong char entered under operation check ");
  return 1;
  }
 }

