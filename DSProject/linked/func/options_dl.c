#include"../list.h"


void options_dl(node *head)
{
   do 
   {
  
  printf("\n Following are available \n");
  printf(" \n 1:  Display ");
  printf(" \n 2:  Insert ");
  printf(" \n 3:  Delete ");
  printf(" \n 4:  Reverse ");
  printf(" \n 0:  Back ");
  scanf(" %d",&c);
  system("clear");
    switch(c)
  {
     case 1:  display_dl(head);       break;
     case 2:  head=insertd(head);        break;
     case 3:  head=deld(head);           break;
     case 4:  head=revd(head);           break;
     
     case 0:  printf("\n Are you sure to go back : ");
     		scanf(" %d",&z);
     		if(z==1) 
     		{
     		  system("clear");
     		  printf("\n\n Returning from the doubly linked list menu ");
     		  printf("\n (Expected wait time - 2 secs) \n");
     		  system("sleep 2");
     		  return;
     		}
  		else options_dl(head);
    }
     
   }while(c!=0); 
}
