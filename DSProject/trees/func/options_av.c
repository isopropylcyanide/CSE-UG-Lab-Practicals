#include"../tree.h"
  
void options_av(tree *t)
{ 
 do{
  printf("\n MENU : ");
  
  printf("\n 1: Balance Factor  ");
  printf("\n 2: Inorder ");
  printf("\n 3: Search ");
  printf("\n 4: Insert ");
  printf("\n 5: Delete in AVL ");
  printf("\n 6: Other Displays ");
  printf("\n 7: Lowest Common Ancestor ");
  printf("\n 0: Back    ");
  scanf(" %d",&c);

   system("clear");
   
	 switch(c) 
  	{
  case 1: balance(t);	end;	break;
  case 2: end; inor(t); end;	break;
  case 3: searchbst(t);		break;

  case 4: {
	    printf("\n What do you want to insert ? "); 
	    scanf("%d",&k);	
	    t=insavl(t,k); 
	  }   			break;

  case 5: t=delavl(t);		break;  
  case 6: display_bt(t);	break;
  
  case 7: { int a1,a2; 
  		end; inor(t); end;
  		
  	   printf("\n Enter First  key : "); scanf("%d",&a1);
  	   printf("\n Enter Second key : "); scanf("%d",&a2); end; end;
  	   printf("\n The ancestor is found out to be : \n\n%d ",lca(t,a1,a2)->data);
  	   system("sleep 2");
  	   system("clear");
  	  }			break;
  
  case 0: {
  	 printf("\n Are you sure to go back : ");
     	 scanf(" %d",&z);
     	 if(z==1)
     	 {
     		  system("clear");
     		  printf("\n\n Returning from the AVL Tree menu ");
     		  printf("\n (Expected wait time - 2 secs) \n");
     		  system("sleep 2");
     		  return;
     		}
     	 
  	 else options_av(t);
  	 }	
  
  
  	}
     }
while(c!=0);
 }
