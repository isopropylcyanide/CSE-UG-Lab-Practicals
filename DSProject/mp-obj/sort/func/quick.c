#include"../sort_main.h"
#include<stdio.h>


  void quick(int x[],int l,int r)		//quick sort
 {
   
  
   int par,i,j,temp;
  
   if(l<r)
 {
    par=l;
    i=l; j=r;
  
    while(i<j)			//partitioning
   {

      while(x[i]<=x[par] && i<r)  
 	i++;
  
       while(x[j]>x[par] && j>l)  
 	j--;
 
     if(i<j)
    {
      temp=x[i];
	x[i]=x[j];
      x[j]=temp;
    }
   }
 				//swapping partitioned with last
   temp=x[par];
   x[par]=x[j];	  
   x[j]=temp;

   quick(x,l,j-1);
   quick(x,j+1,r);
  
  }
     
 
}

