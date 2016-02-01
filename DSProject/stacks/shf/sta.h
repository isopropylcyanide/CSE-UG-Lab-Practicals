#ifndef STA_H
#define STA_H

#include<stdio.h>
#include<stdlib.h>
#define maxi 4
int c; 

struct sta 
{
  int st[maxi];
  int top;
};
typedef struct sta stack_a;



void options_sa(stack_a *);
void pusha(stack_a *);
void popa(stack_a *);
void display_sa(stack_a *);




#endif
