#include<stdio.h>
#include<stdlib.h>

#define max 4
int c; 

struct sta 
{
  int st[max];
  int top;
};
typedef struct sta stack;


void options(stack *);
void push(stack *);
void pop(stack *);
void display(stack *);

int main()
{
  stack *s;
   s->top=-1;
  options(s);
  
 }
 
 void options(stack *s)
 {
 do{
   printf("\n Top = %d ",s->top);
 
  printf("\n 1: Push ");
  printf("\n 2: Pop  ");
  printf("\n 3: Display ");
  scanf(" %d",&c);
  
  switch(c) {
  

   case 1: push(s);     break;
   case 2: pop(s);    break;
   case 3: display(s);  break;
   case 0: exit(1);
   default: printf("\n Enter correct value in main\n");
  }
   }while(c!=0);
}


void display(stack *s)
{
  if(s->top==-1)
   {
     printf("\n No elements in stack\n  "); options(s);
   }
 else
  {  printf("\n Displaying stack ");
    
    int x=s->top;  
   while(x!=-1)
   {
     printf("\n Element %d : %d",x+1,s->st[x]);
     x--;
   }
 printf("\n");
}
  options(s);
}
  



void push(stack *s)
{ int k;
 
   if(s->top==max-1) printf("\n Stack Overflow \n");
 
 else { printf("\n Enter element : ");
  scanf(" %d",&k);
      s->top++;
      s->st[s->top]=k ;
      printf("\n Element pushed\n");
} }
			

void pop(stack *s)
{
   
    if(s->top==-1) { printf("\n Stack Underflow \n"); options(s); }
 else 
    printf("\nElement %d : %d\n",s->top+2,(s->st[s->top--])) ;
   
}




