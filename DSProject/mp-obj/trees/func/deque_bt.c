#include"../tree.h"

tree * deque_bt()
{ 
   tree *temp;

 if(fr<=rr)
   {
  	temp=sq[fr++];
 	return temp;
  } 
	return NULL;
} 
