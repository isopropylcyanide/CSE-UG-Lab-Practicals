#include"../tree.h"


void display_bt(tree *t)
{
 do{
  printf("\n\n Display : ");
  
  printf("\n 1: Preorder " );
  printf("\n 2: Inorder "  );
  printf("\n 3: Postorder ");
  printf("\n 4: Level order "  );
  printf("\n 5: Inorder(iter) "  );
  printf("\n 0: Back to menu ");
  scanf(" %d",&l);
  
  system("clear");
 
 switch(l) 
{
  case 1: printf("\nPreorder : ");    		 pre(t);  	break;
  case 2: printf("\nInorder : ");     		 inor(t);	break;
  case 3: printf("\nPostorder : ");   		 post(t);	break;
  case 4: printf("\nLevel order : ");		 lorder(t);	break;
  case 5: printf("\nInorder (iterative) : ");    inorit(t);	break;
  case 0: return;
  }} while(l!=0);
}

