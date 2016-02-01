#include"../stacks.h"


void evalpo(stack *s)

{  
   printf("\n Enter the postfix expression : ");
  scanf(" %s",aa);
 
  int len=strlen(aa);
   printf("\n Length of above expression is : %d \n",len);

    for(i=0; i<len ; i++)
     { 
         if(check(aa[i])==0)			//meaning its an operand
        {
          
           pushe(s,aa[i]-48);
         }
 
      if(check(aa[i])==1)			//meaning its an operator
     {
        printf("\n Popping the top two \n");
         p1=pope(s); 
         p2=pope(s);
         p0=op(p2,p1,aa[i]);			//top ke neeche waala ka operation with top

        pushe(s,p0);
      }
   }
	
 printf("\n Evaluating postfix exp = %d \n",s->st[s->top]);
   options_p(s);
 }

