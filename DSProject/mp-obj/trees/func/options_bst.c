#include"../tree.h"

void options_bst(tree *t)
{
 do{
  printf("\n MENU : ");
  
  printf("\n 1: Search ");
  printf("\n 2: Display ");
  printf("\n 3: Insert ");
  printf("\n 4: Delete in BST ");
  printf("\n 5: Other Displays ");
  printf("\n 6: Lowest Common Ancestor ");
  printf("\n 0: Back    ");
  scanf(" %d",&c);
 
  system("clear");
  
 switch(c) 
{
  case 1: searchbst(t);			break;
  case 2: end; inor(t); end;		break;
  case 3: printf("\n Enter data :  "); 
  
  	 int x;
    	 scanf("%d",&x); t=insbst(t,x);	break;

  case 4: t=delbst(t);		break;
  case 5: display_bt(t);	break;
  
  case 6: { int a1,a2; 
  		end; inor(t); end;
  		
  	   printf("\n Enter First  key : "); scanf("%d",&a1);
  	   printf("\n Enter Second key : "); scanf("%d",&a2); end; end;
  	   printf("\n The ancestor is found out to be : %d \n\n",lca(t,a1,a2)->data);
  	   system("sleep 2");
  	   system("clear");
  	   }			break;
  
  case 0: {
  		printf("\n Are you sure to go back : ");
     	 scanf(" %d",&z);
     	 if(z==1) 
     	 {
     		  system("clear");
     		  printf("\n\n Returning from the BST menu ");
     		  printf("\n (Expected wait time - 2 secs) \n");
     		  system("sleep 2");
     		  return;
     		}
     	 
  	 else options_bst(t);
  	 }		
    }
 }
 while(c!=0);
 
}




