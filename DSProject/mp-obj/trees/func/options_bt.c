#include"../tree.h"


void options_bt(tree *t)
{
 do{
  printf("\n MENU : ");
  
  printf("\n 1: Size ");
  printf("\n 2: Display ");
  printf("\n 3: Search ");
  printf("\n 4: Depth of tree ");
  printf("\n 5: Leaves ");
  printf("\n 6: Delete Tree  "); 
  printf("\n 0: Back   ");
  scanf(" %d",&c);

   system("clear");
 
 switch(c) 
  {
  case 1: printf("\n Size of tree is : %d",size(t));	break;
  case 2: display_bt(t);				break;
  case 3: { printf("\n Search for what in BST ? "); 
  		scanf("%d",&k);
	    if(search(t,k)==1)
 
 	        	 printf("\n Element is found\n "); 
  	    else 	 printf("\n Element doesn't exist \n");
	  } break;  
	  
  case 4: depth(t);		break;
  case 5: leaves(t);		break;
  case 6: t=delete_bt(t);	break;
  
  case 0: 
  	  {
  	  printf("\n Are you sure to go back : ");
     	  scanf(" %d",&z);
     	  if(z==1) 
     	  {
     		  system("clear");
     		  printf("\n\n Returning from the Binary Tree menu ");
     		  printf("\n (Expected wait time - 2 secs) \n");
     		  system("sleep 2");
     		  return;
     		}
     	  
  	  else options_bt(t);
  	  }
  	 
 	}
  
  }
   while(c!=0);
   
  
}







