#include<stdio.h>
#include<stdlib.h>
#define max 4

struct sta {
int qu[max]; 

};

int front=-1,rear=-1;

typedef struct sta queue;
int i,c,j;

void display(queue *);
void options(queue *);		void enqueue(queue *);
void dequeue(queue *);


int main()
{
  queue q;
 
  options(&q);
}

void options(queue *q)
{
   
  printf("\n\n Currently front=%d & rear=%d ",front,rear);
  
  printf("\n 1: Enqueue ");
  printf("\n 2: Dequeue ");
  printf("\n 3: Display ");
  printf("\n 0: Exit \t");
			  scanf(" %d",&i);
  switch(i) {

  case 1: enqueue(q);	break;
  case 2: dequeue(q);	break; 
  case 3: display(q);	break;
  
  case 0: exit(1);
 default: printf("\n Wrong char ");
 }
}


void enqueue(queue *q)
{
 
 if((front==0 && rear==max-1)|| front==rear+1) 
   {
      printf("\n Queue overflow. Dequeue first ");
       options(q);
    }
  
       
     if(front==-1)		//queue is empty
     {					
        front=0;
        rear=0;
     }
  else if(rear==max-1) rear=0;
 else
       rear++;

	   printf("\n Enter the element : "); 
          scanf(" %d",&j);
           q->qu[rear]=j;
       printf("\n Element in queue: %d ",j);
         options(q);
      }
  

void dequeue(queue *q)
{
   if(front==-1)		//queue is empty
  {
      printf("\n Queue is empty. \n");
      options(q);
   }

  if(front==rear)
 {
    printf("\n Queue only has one element ");
  	
	printf("\n Element out of the queue is : %d \n",q->qu[front]);		
	
    front=-1; rear=-1;
	options(q);
  }
        

 if(front<rear)
   {
  	printf("\n Element out of the queue is .. %d \n",q->qu[front]);
 
        front++;
    options(q);
    }

   if(front==max-1)
 {
	printf("\n Element out of the queue is .. %d \n",q->qu[front]);
      front=0;
    options(q);
  }

 if(front>rear)
 {
   if(front<max)
    {
   	 printf("\n Element out of the queue is .. %d \n",q->qu[front]);
     		 front++ ; 
	options(q);
       }

  if(front==max-1)
 {
	printf("\n Element out of the queue is .. %d \n",q->qu[front]);
      front=0;
    options(q);
  }
 }
 
  
}





void display(queue *q)
{
  int f=front; int r=rear;

  if(front==-1)
 {
    printf("\n Nothing to display. Queue is empty ");
   options(q);
 }

 printf("\n Displaying queue");
 
 if(f<=r)

    while(f<=r)
   {
     printf("\n Data : %d ",q->qu[f]);
      f++;
   }
 

  else
{ 

     while(f<max)
    {
       printf("\n Data : %d ",q->qu[f]);
	f++; 
   }

 f=0;
  while(f<=rear)
  {
    printf("\n Data : %d :",q->qu[f]);
   f++;
   }
 }
   options(q);
} 
 
  
















































