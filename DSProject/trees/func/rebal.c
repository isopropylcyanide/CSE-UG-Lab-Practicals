#include"../tree.h"
  
  tree * rebal(tree *root,tree *t)
{							//this will check for the first imbalanced node uptill root
   
  t->height=max(height(t->left),height(t->right))+1;	//update height of returned node after deletion
  
   tree *temp_parent;

  do
   {
     printf("\n Initial node : %d \n",t->data);
   
     temp_parent=parent(root,t->data);
      printf("\n Initial parent of %d found : %d \n",t->data,temp_parent->data);
   
     if(height(t->left)-height(t->right)==2)		
      {
         if(height(t->left->left)-height(t->left->right)>=0)					//left left
            
             {printf("\n Single rot with left about %d\n",t->data);	t=rotateWithLeft(t); }
           
         else if(height(t->left->left)-height(t->left->right)<0)				//left right
        
          {printf("\n Double rot with left about %d\n",t->data);      t=doubleWithLeft(t); }
          
         else printf("\n No rotation required wrt left of %d \n",t->data); 
          
       }
       
       else if(height(t->left)-height(t->right)==-2)		
        {
          if(height(t->right->left)-height(t->right->right)<=0)					//right right
           
             {printf("\n Single rot with right about %d\n",t->data);	t=rotateWithRight(t);}
           
         else if(height(t->right->left)-height(t->right->right)>0)				//right left
          
           {printf("\n Double rot with right about %d\n",t->data); 	t=doubleWithRight(t); }
           
           else printf("\n No rotation required wrt right of %d \n",t->data);
        }
    
     if(temp_parent==root)
      {
        printf("\n Parent reached \n\n");
        break;
       } 
     	
    t=temp_parent;
   printf("\n Now finding parent : %d \n",t->data);
  
  }
   while(t!=root);
  
  
  
   return t;
}

