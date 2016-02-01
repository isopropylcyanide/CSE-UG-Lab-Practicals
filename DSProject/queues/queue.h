#ifndef QUA_H
#define QUA_H
#define maxim 4

#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

int i,c,j,j,z;
int front_a,rear_a;
int count;

struct qu {

int qu[maxim]; 
int data;
  struct qu *next;

};

typedef struct qu queue;

queue *front,*rear ;

queue q;

void options_qa(queue *);
void display_qa(queue *);
void enqueue(queue *);
void dequeue(queue *);

void options_ql();
void dequeuep();
void enqueuep();
int isEmpty_p();
void isempty_p();
void display_ql();
int peek();



#endif
