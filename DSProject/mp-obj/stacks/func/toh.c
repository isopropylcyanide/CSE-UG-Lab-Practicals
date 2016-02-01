#include"../stacks.h"

void TOH(int i,char src,char tmp,char dest)
 {
      if(i==1)
     {
        printf("\n Disc moved from %c to %c \n",src,dest);
        return ;
    }
    else
      {
          TOH(i-1,src,dest,tmp);
    	  printf("\n Disc moved from %c to %c ",src,dest);

   TOH(i-1,tmp,src,dest);
 }
}
