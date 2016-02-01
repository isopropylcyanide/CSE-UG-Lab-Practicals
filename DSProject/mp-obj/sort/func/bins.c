#include"../sort_main.h"
#include<stdio.h>


 void bins(int a[])				//binary search
 { 
     quick(a,0,n-1);
     int first,mid,last,l;  

      printf("\n Enter value to find ");
      scanf("%d",&l); 
          
     first=0; 	last=n-1; mid=(first+last)/2 ;
    
     while(first<=last ) 
      {
         if (a[mid]<l) first=mid+1; 
   		    
         else if (a[mid]==l) 
      {
         printf(" %d found at location %d.\n",l,mid+1);
     	 break;
      }
 	else	last=mid-1;
    	 
        mid=(first + last)/2;
         
   	}
  	 if (first>last)
    	 printf(" Not found \n ");
 
 	return ;
     }

