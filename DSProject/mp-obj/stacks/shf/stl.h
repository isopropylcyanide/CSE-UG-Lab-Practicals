#ifndef STL_H
#define STL_H
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct stal
{
  int data;
   struct stal* next;
};
typedef struct stal stack_l;
int c;

void options_sl(stack_l *);
void push(stack_l *);
void pop(stack_l *);
void display_sl(stack_l *);
void create(stack_l *);


#endif
