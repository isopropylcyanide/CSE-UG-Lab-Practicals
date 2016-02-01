#include"../stacks.h"

void coinpos(stack *s)
{					//infix to postfix 
 		
	printf("\n Enter the infix expression : ");
 	  scanf(" %s",aa);
 
  int len=strlen(aa);
   printf("\n Length of above expression is : %d \n",len);

 printf("\n The postfix expression is :\t"); 
    for(i=0; i<len ; i++)
 {
	if(check(aa[i])==0)		//operand		
       printf("%c",aa[i]);

    else
       if(aa[i]=='(')
           pushp(s,'(');
       else
       {
         if(aa[i]==')')
             while((xx=popp(s))!='(')
             printf("%c",xx);
         else
         {
         while(prec(aa[i])<=prec(top_p(s)) && !empty(s))
             {
             xx=popp(s);
             }
         pushp(s,aa[i]);
             printf("%c",xx);
         }
       }

  }
   while(!empty(s))
{ 
  
   xx=popp(s);
   printf("%c",xx);
 }

 printf("\n\n");
 options_p(s);

 }

