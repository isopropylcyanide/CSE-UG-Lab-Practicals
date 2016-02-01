#include"../stacks.h"

void coinpre(stack *s)
{
   						//infix to prefix
 printf("\n Enter the infix expression : ");
 	  scanf(" %s",aa);
 
  int len=strlen(aa); int c[30]; int j=0;	int count=0;
   printf("\n Length of above expression is : %d \n",len);
		
 printf("\n The prefix expression is :\t"); 

 for(i=len-1,p1=0; i>=0; i--)
  {
 	b[p1]=aa[i]; p1++; 
	 }
  
    for(i=0; i<len; i++)
 {
    if(check(b[i])==0)
       c[j++]=b[i];	

    else
       if(b[i]==')')
        {   pushp(s,')'); count+=2; }
       else
       {
         if(b[i]=='(') 
		 while(top_p(s)!=')')
            c[j++]=popp(s); 
		
	 else 						//meaning operator
         {
         while(prec(b[i])<=prec(top_p(s)) && !empty(s))
             {
             xx=popp(s); 
              c[j++]=xx;
             }
         pushp(s,b[i]);
         }
       }

  }

   while(!empty(s))
{ 
   xx=popp(s);
 c[j++]=xx; 
 } 
 	if(count==2) p2=1; if(count==4) p2=2; if(count==6) p2=3;
 for(i=len-count-p2; i>=0; i--)
 {  
   if(c[i]!=')' || c[i]!='(')
   printf("%c",c[i]);
 }

 printf("\n\n");
 
 options_p(s);


 }

