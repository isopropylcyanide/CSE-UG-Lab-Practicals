#include"../tree.h"


tree * pop_bt()
{   
 	tree* temp;
        temp=st[tos--];
	
	return temp; 
}
