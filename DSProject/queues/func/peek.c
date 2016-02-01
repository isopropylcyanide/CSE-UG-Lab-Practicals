#include"../queue.h"

int peek()
{
   if(isEmpty_p()!=1)
   { 
        return front->data ;
      }
   
     else return -100;
  }
