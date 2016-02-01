#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct sta
{
  int data;
   struct sta* next;
};
typedef struct sta stack;
int c;

void options(stack *);
void push(stack *);
void pop(stack *);
void display(stack *);

int main()
{
  stack * top;
  create(top);
 }

void options(stack *top)
 {
 do{
  
  printf("\n 1: Push element ");
  printf("\n 2: Pop element ");
  printf("\n 3: Display stack");
  printf("\n 0: Exit ");
  scanf(" %d",&c);
  
  switch(c) {
  
   case 1: push(top);     break;
   case 2: pop(top);    break;
   case 3: display(top);  break;
   case 0: 		exit(-1);
   default: printf("\n Enter correct value in main\n");
  }
   }while(c!=0);
}

void push(stack *top)
{  
   stack *p;
    p=(stack *)malloc(sizeof(stack));
   if(p==NULL) 					//stack overflow generally wont occur in linked lists.
  {
       printf("\n Stack is full ");
        options(top);
    }

   printf("\n Enter element to be pushed :");
   scanf(" %d",&p->data);
   p->next=top;
   top=p;
   options(top);  
}

void pop(stack *top)
{
   int t; stack* p;
   if(top==NULL)
     {
        printf("\n Stack Underflow ");
         options(top);
     }
else {
  t=top->data;
  p=top;
  top=top->next;
  free(p);
 printf("\n Element popped : %d",t);
 options(top);
}
  }  
  
void create(stack *top)
{
  top=NULL ; options(top);
 }

void display(stack * top)
{
	if(top==NULL)
     {
        printf("\n No elements in stack\n ");
         options(top);
     }
 else {
  printf("\n Displaying stack\n ");
  stack *p=top;
  while(p!=NULL)
  {
    printf("\n Element : %d ",p->data);
    p=p->next;
  }
 printf("\n");
}
options(top);
}
 













