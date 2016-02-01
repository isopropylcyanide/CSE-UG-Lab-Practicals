#include"../stacks.h"

void copospre(stack *s)
{					//postfix to prefix
		
   char c[40]; char n[40];
			
  printf("\n Enter the postfix expression : ");
 	  scanf("%s",n);
 
  int len=strlen(n);  

  int m=20; int l=19;  int count=0,app=0;
  char x,y;

   printf("\n Length of above expression is : %d \n",len);
		

   for(i=0; i<=len-1; i++)
 {
    if(check(n[i])==0)			//meaning its an operand
      {
	pushp(s,n[i]);
        count++;
      } 

	if(check(n[i])==1)			//meaning its an operator
    {
                  
       	x=popp(s);	
	y=popp(s);

     if(x=='z')
   {  
         count++;
        pushp(s,'z');
      c[m++]=y;         
      c[m++]=n[i];
   }
 
     if(y=='z')				//a little tricky
   {   count++;
      c[m++]=n[i];
      c[l--]=x;		
       ++app;
      pushp(s,'z');  
   }
     else { 
           pushp(s,'z');
	c[m++]=x;
        c[m++]=y;
        c[m++]=n[i];
			
          }
   }
 }
   while(!empty(s))	//just to clear the stack 
   { 
     q1=popp(s);
    }

 printf("\n The prefix expression is :\t"); 
    for(j=20+count; j>=20-app ; j--)
   {
       printf("%c",c[j]);
   }

   printf("\n\n");
   
   options_p(s);
 }


