#include"../stacks.h"

int prec(char x)					//to check precedence of the operators
{
  if(x == '(' || x == ')')
 return 0;
   if(x == '+' || x == '-')
 return 1;
   if(x == '*' || x == '/' || x == '%')
 return 2;
   return 3;
  
}
