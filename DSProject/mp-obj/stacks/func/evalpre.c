#include"../stacks.h"

void evalpre(stack *s)

{  
   printf("\n Enter the prefix expression : ");
  scanf(" %s",aa);
 
  int len=strlen(aa);
   printf("\n Length of above expression is : %d \n",len);

    for(i=len-1; i>=0 ; i--)
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
         p0=op(p1,p2,aa[i]);				//top ka top ke neeche waale se operation

        pushe(s,p0);
      }
   }

 printf("\n Evaluating prefix exp = %d \n",s->st[s->top]);
  options_p(s);
 }
