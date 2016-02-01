#include"../sort_main.h"
#include<stdio.h>


void bubs(int a[])				//bubble sort
 { 
   int count=0,i; int csum=0;


 for(i=0; i<n; i++)
{   
  for(c=i;c<n-1;c++)
  {
    if(a[c]>a[c+1])   
   { 
      temp=a[c];
      a[c]=a[c+1];
      a[c+1]=temp;
    count++;  csum++;

   }
  }
    printf("\n Comparisons in %d pass : %d ",i+1,count);
     if(count==0)
   {
     printf("\n List sorted in %d passes ",i);
     break; }    
     count=0;
 }   
 printf("\n Total number of comparisons : %d ",csum);
  display_s(a); 
  return ;
}

