#include"../sort_main.h"
#include<stdio.h>



 void sels(int a[])				//selection sort
 {
  int count=0,i;


 for(i=0; i<n; i++)
{   
   for(c=i+1;c<n;c++)
   {
     if(a[c]<a[i])
	{   temp=a[c];
	   a[c]=a[i];
	   a[i]=temp;
 		count++;
        }
   }

 }

 printf("\n Total number of comparisons : %d ",count);
 display_s(a);
 return ; 
}
