#include"../sort_main.h"
#include<stdio.h>


 void inss(int a[])				//insertion sort
 {
   int count=0,i,bar,j;

  
  for(i=0; i<n; i++)
{   
  bar=i;
 
   for(c=i+1;c<n;c++)
   {
     for(j=0; j<=bar; j++)
     {
  	   if(a[j]>a[c])	//if sorted group has an element larger
         {
 	  temp=a[c];
	  a[c]=a[j];
	  a[j]=temp;
          count++;
          }
      }
    }
     printf("\n Comparisons in %d pass : %d ",i+1,count); 
  }
 display_s(a);
 return ;
}
