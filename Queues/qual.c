#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct qu 
{
  int data;
  struct qu *next;
};

typedef struct qu queue ;

queue *front,*rear ;
int i,count=0,j;

void createq();		int peek();
void options();		void enqueue();
int isEmpty();		void dequeue();
void isempty();		void display();


int main()
{
  queue *q;
  createq(); 
   options();
}

void createq()
{
 front=NULL;
 rear=NULL;  

  }

void options()
{
  
  printf("\n Queue size : %d",count);

if(isEmpty()!=1) 
  printf("\n Top of the queue is : %d",peek());
  printf("\n\n 1: Enqueue ");
  printf("\n 2: Dequeue ");
  printf("\n 3: isEmpty ");
  printf("\n 4: Display ");
  printf("\n 0: Exit \t");
			  scanf(" %d",&i);
  switch(i) {

  case 1: enqueue();	break;
  case 2: dequeue();	break; 
  case 3: isempty();	break;
  case 4: display();	break;
  case 0: exit(1);
 default: printf("\n Wrong char ");
 }
}

int isEmpty()
{
  if(front==NULL && rear==NULL) 
      return 1;
else return 0;

 }

void isempty()
{
   if(isEmpty()!=1)
   {
      printf("\n Queue is not empty ");
       options();
     }
   else
  {
      printf("\n Queue is empty ");
       options();
     }

 }

void display()
{
    queue *p=front;
    
   if(p==NULL && rear==NULL)
    { 
      printf("\n Queue is empty.Nothing to display ");
       options();
     }
 
  printf("\n Displaying queue : ");
 while(p!=rear) {
    
      printf("\n %d",p->data); 
      p=p->next;
       }
 
   if(p==rear)
   {
      printf("\n %d",p->data);
 }
   options();
}


void enqueue()
{ 
   if(rear==NULL)
  {
   rear=(queue *)malloc(sizeof(queue));
	rear->next=NULL; 
 
     printf("\n Enter the element : "); scanf(" %d",&rear->data);
	
	front=rear;
  }
    else {
            queue *temp;
   temp=(queue *)malloc(sizeof(queue));
  	rear->next=temp;

     printf("\n Enter the element : "); scanf(" %d",&temp->data);

         temp->next=NULL ;
    	 rear=temp;
   }
  count++;
   options();
 }

void dequeue()
{
     queue * p=front;

   if(p==NULL)
      {
  	printf("\n Queue is empty. Can't deque ");
    	options();
      }
 
    if(p->next!=NULL)
     {
        printf("\n Dequeued value : %d ",p->data);
       p=p->next;
        
        free(front);
       front=p;
        count--;
        options();
      }

     else 
       {
         printf("\n Dequeued value : %d ",p->data);
         
        free(front);
        front=rear=NULL ;
         count--;
        options();
        }
     
  }


int peek()
{
   if(isEmpty()!=1)
   { 
        return front->data ;
      }
   
     else return -100;
  }












