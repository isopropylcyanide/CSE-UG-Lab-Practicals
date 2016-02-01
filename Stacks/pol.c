#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>



struct sta 
{
  int st[40];
  int top;
};
typedef struct sta stack;

void create(stack *);    	void evalpre(stack *);		void coinpre(stack *);		int pope(stack *);
void push(stack *,char); 	void options(stack *);		void coposin(stack *);		char top(stack *);
char  pop(stack *);		void convert(stack *);		void copospre(stack *);		int empty(stack *);
void display(stack *);		void coin(stack *);		void coprein(stack *);		
void evalpo(stack *);		void copos(stack *);		void coprepos(stack *);		
int  check(char );		void copre(stack *);		int  prec(char);
int  op(int,int,char);		void coinpos(stack *);		void pushe(stack *,char);

char a[40];  int i,j,p1,p2,p0 ; 	char q1,x;  
char b[40];


int main()
{
  stack s; create(&s); 
  options(&s);
 }

 void options(stack *s)
 {
   printf("\n Following are available ");
   printf("\n 1: Evaluate postfix ");
   printf("\n 2: Evaluate prefix ");
   printf("\n 3: Convert ");
   printf("\n 0: Exit ");
   scanf(" \t %d",&i) ;
  
  switch(i)
 {
   case 1:   evalpo(s);      break;
   case 2:   evalpre(s);     break;
   case 3:   convert(s);     break;
   case 0:   exit(1);
  }
 }

int check(char k)						//distinguishing between an operand and an operator and parenthesis
{
   if ( k=='+' || k=='-'  || k=='*' || k=='/' || k=='^') return 1;
  
  else if(  k=='(') return 2;
  else if(  k==')') return 3;
   else
       return 0;
 }

int op(int a,int b,char c)				//What happens during evaluation
{
   switch(c)
   {
     case '+' : return a+b; 	 break;
     case '-' : return a-b; 	 break;
     case '*' : return a*b; 	 break;
     case '/' : return a/b; 	 break;
     
  default: printf("\n Wrong char entered under operation check ");
  }
 }

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



void evalpo(stack *s)

{  
   printf("\n Enter the postfix expression : ");
  scanf(" %s",a);
 
  int len=strlen(a);
   printf("\n Length of above expression is : %d \n",len);

    for(i=0; i<len ; i++)
     { 
         if(check(a[i])==0)			//meaning its an operand
        {
          
           pushe(s,a[i]-48);
         }
 
      if(check(a[i])==1)			//meaning its an operator
     {
        printf("\n Popping the top two \n");
         p1=pope(s); 
         p2=pope(s);
         p0=op(p2,p1,a[i]);			//top ke neeche waala ka operation with top

        pushe(s,p0);
      }
   }
	
 printf("\n Evaluating postfix exp = %d \n",s->st[s->top]);
   options(s);
 }

void evalpre(stack *s)

{  
   printf("\n Enter the prefix expression : ");
  scanf(" %s",a);
 
  int len=strlen(a);
   printf("\n Length of above expression is : %d \n",len);

    for(i=len-1; i>=0 ; i--)
     { 
         if(check(a[i])==0)			//meaning its an operand
        {
          
           pushe(s,a[i]-48);
         }
 
      if(check(a[i])==1)			//meaning its an operator
     {
        printf("\n Popping the top two \n");
         p1=pope(s);
         p2=pope(s);
         p0=op(p1,p2,a[i]);				//top ka top ke neeche waale se operation

        pushe(s,p0);
      }
   }

 printf("\n Evaluating prefix exp = %d \n",s->st[s->top]);
  options(s);
 }

void convert(stack *s)
{
   printf("\n 1: Infix ");
   printf("\n 2: Postfix ");
   printf("\n 3: Prefix ");
   printf("\n 0: Back ");

  scanf(" \t %d",&i) ;
  
  switch(i)
 {
   case 1:   coin(s);      break;
   case 2:   copos(s);     break;
   case 3:   copre(s);     break;
   case 0:   options(s);
  }
 }  

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
   case 0:   options(s);
  }
 }  

void copos(stack *s)
{
  printf("\n Original type : Postfix ");
   printf("\n 1: Infix ");
   printf("\n 2: Prefix ");
   printf("\n 0: Back ");
  
   scanf(" \t %d",&i) ;
  
  switch(i)
 {
   case 1:   coposin(s);      break;
   case 2:   copospre(s);   break;
   case 0:   options(s);
  }
 } 

void copre(stack *s)
{
  printf("\n Original type : Prefix ");
   printf("\n 1: Infix ");
   printf("\n 2: Postfix ");
   printf("\n 0: Back ");
  
   scanf(" \t %d",&i) ;
  
  switch(i)
 {
   case 1:   coprein(s);      break;
   case 2:   coprepos(s);   break;
   case 0:   options(s);
  }
 } 
 

void coinpos(stack *s)
{					//infix to postfix 
 		
	printf("\n Enter the infix expression : ");
 	  scanf(" %s",a);
 
  int len=strlen(a);
   printf("\n Length of above expression is : %d \n",len);

 printf("\n The postfix expression is :\t"); 
    for(i=0; i<len ; i++)
 {
	if(check(a[i])==0)		//operand		
       printf("%c",a[i]);

    else
       if(a[i]=='(')
           push(s,'(');
       else
       {
         if(a[i]==')')
             while((x=pop(s))!='(')
             printf("%c",x);
         else
         {
         while(prec(a[i])<=prec(top(s)) && !empty(s))
             {
             x=pop(s);
             }
         push(s,a[i]);
             printf("%c",x);
         }
       }

  }
   while(!empty(s))
{ 
  
   x=pop(s);
   printf("%c",x);
 }

 printf("\n\n");
 options(s);

 }

void coinpre(stack *s)
{
   						//infix to prefix
 printf("\n Enter the infix expression : ");
 	  scanf(" %s",a);
 
  int len=strlen(a); int c[30]; int j=0;	int count=0;
   printf("\n Length of above expression is : %d \n",len);
		
 printf("\n The prefix expression is :\t"); 

 for(i=len-1,p1=0; i>=0; i--)
  {
 	b[p1]=a[i]; p1++; 
	 }
  
    for(i=0; i<len; i++)
 {
    if(check(b[i])==0)
       c[j++]=b[i];	

    else
       if(b[i]==')')
        {   push(s,')'); count+=2; }
       else
       {
         if(b[i]=='(') 
		 while(top(s)!=')')
            c[j++]=pop(s); 
		
	 else 						//meaning operator
         {
         while(prec(b[i])<=prec(top(s)) && !empty(s))
             {
             x=pop(s); 
              c[j++]=x;
             }
         push(s,b[i]);
         }
       }

  }

   while(!empty(s))
{ 
   x=pop(s);
 c[j++]=x; 
 } 
 	if(count==2) p2=1; if(count==4) p2=2; if(count==6) p2=3;
 for(i=len-count-p2; i>=0; i--)
 {  
   if(c[i]!=')' || c[i]!='(')
   printf("%c",c[i]);
 }

 printf("\n\n");
 
 options(s);


 }

void coposin(stack *s)
{
	//not required
 }


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
	push(s,n[i]);
        count++;
      } 

	if(check(n[i])==1)			//meaning its an operator
    {
                  
       	x=pop(s);	
	y=pop(s);

     if(x=='z')
   {  
         count++;
        push(s,'z');
      c[m++]=y;         
      c[m++]=n[i];
   }
 
     if(y=='z')				//a little tricky
   {   count++;
      c[m++]=n[i];
      c[l--]=x;		
       ++app;
      push(s,'z');  
   }
     else { 
           push(s,'z');
	c[m++]=x;
        c[m++]=y;
        c[m++]=n[i];
			
          }
   }
 }
   while(!empty(s))	//just to clear the stack 
   { 
     q1=pop(s);
    }

 printf("\n The prefix expression is :\t"); 
    for(j=20+count; j>=20-app ; j--)
   {
       printf("%c",c[j]);
   }

   printf("\n\n");
   
   options(s);
 }

void coprein(stack *s)
{
	//not required
 }

void coprepos(stack *s)
{

 }




void push(stack *s,char x)
{ 
    s->top++;
      s->st[s->top]=x ;

}



void pushe(stack *s,char x)
{ 
 
   if(s->top==39) printf("\n Stack Overflow \n");
 
 else { 
      s->top++;
      s->st[s->top]=x ;
      printf("\n Element pushed : %d",x);
}
	
}

void create(stack *s)
{
  s->top=-1;
 
 } 

void display(stack *s)
{
  if(s->top==-1)
   {
     printf("\n No elements in stack\n  "); 
   }
 else
  {  
    int x=s->top;  printf("\n"); 
   while(x!=-1)
   {
     printf("%c",s->st[x]);
     x--;
   }
 printf("\n Displayed");
}
  
}
  

char pop(stack *s)
{ 
   char x;
   x=s->st[s->top];
   s->top--;
   return x;
   
}

int pope(stack *s)
{
   int x=s->st[s->top];
   
    if(s->top==-1) {  return 0; }
 else 
    { printf("\n Popped : %d ",x);
     return s->st[s->top--] ;
   }
   
}
char top(stack * s)
{
   return s->st[s->top];
}

int empty(stack *s)
{
    if(s->top==-1)
 return 1;
    else 
 return 0;
}
