#include"../stacks.h"

int check(char k)						//distinguishing between an operand and an operator and parenthesis
{
   if ( k=='+' || k=='-'  || k=='*' || k=='/' || k=='^') return 1;
  
  else if(  k=='(') return 2;
  else if(  k==')') return 3;
   else
       return 0;
 }
