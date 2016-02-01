#include<stdio.h>		 
#include"../list.h"

void options(node *head)
{
   do{
   	
   
  printf("\n Following are available \n");
  printf(" \n 1:  Display ");
  printf(" \n 2:  Insert ");
  printf(" \n 3:  Delete ");
  printf(" \n 4:  Reverse the list");
  printf(" \n 5:  Concatenate list ");
  printf(" \n 6:  Sort the list");
  printf(" \n 7:  Remove duplicates");
  printf(" \n 8:  Insert T-Joint");
  printf(" \n 0:  Back ");
  
  scanf(" %d",&c);
  system("clear");
  
    switch(c)
  {
     case 1:  display_l(head);     break;
     case 2:  head=insert(head);   break;
     case 3:  head=del(head);      break;
     case 4:  head=rev(head);      break;
     case 5:  concat(head); 	   break;
     case 6:  sort(head);          break;
     case 7:  rmdup(head);         break;
     
     case 8:  {
     	      printf("\n Do you want to insert  a T-joint 1/0? ");	
		  scanf("%d",&c);
		
		if(c==1) instj(head);
	       		 
	        else options(head);		 
	       }		   break;
     
     case 0:    printf("\n Are you sure to go back : ");
     		scanf(" %d",&z);
     		if(z==1)
     		{
     		  system("clear");
     		  printf("\n\n Returning from the singly linked lists menu ");
     		  printf("\n (Expected wait time - 2 secs) \n");
     		  system("sleep 2");
     		  return;
     		}
  		else options(head);
   }
    
   
   }while(c!=0);
 }
   
