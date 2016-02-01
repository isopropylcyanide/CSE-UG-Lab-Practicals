#include<stdio.h>
#include"../sort_main.h"

void options_s(int a[20])
 {
  do{
   printf("\n\n Following are available \n");

   printf("\n 1: Binary search ");
   printf("\n 2: Bubble sort ");
   printf("\n 3: Quick sort ");
   printf("\n 4: Selection sort ");
   printf("\n 5: Insertion sort "); 
   printf("\n 0: Back "); 
 		           scanf(" %d",&c);
   system("clear");		           
 		           
   switch(c) {
   
    case 1: bins(a); 				break;
    case 2: bubs(a);				break;  
    case 3: quick(a,0,n-1); display_s(a);	break;
    case 4: sels(a);				break;
    case 5: inss(a);				break;
    case 0: printf("\n Are you sure to go back : ");
     		scanf(" %d",&c);
     		if(c==1)
     		{
     		  system("clear");
     		  printf("\n\n Returning from the sorting menu ");
     		  printf("\n (Expected wait time - 2 secs) \n");
     		  system("sleep 2");
     		  return;
     		}
     		
  		else options_s(a);				
    }}while(c!=0);
 }
