#include<stdio.h>		 
#include"../list.h"

node * createlists()
{
   int i,n;
  node *p, *head;

   
  printf("\n How many elements to enter ?: ");
  scanf(" %d",&n); endl;
  endl;
  
  if(n==0)
  {
    printf("\n List can't be empty \n");
    return NULL;
   }
 
 for(i=0; i<n; i++)
 {
    if(i==0)
   {
      head=(node *)malloc(sizeof(node)) ;
      p=head;	
    }
  
   else
  {  

     p->next=(node *)malloc(sizeof(node));
      p=p->next ;
   }
  printf(" Enter rno : name : marks : ");
  scanf(" %d %s %d",&p->rno,p->name,&p->marks);
  printf(" \n");

  }
      p->next=NULL;
      printf("\n Elements have been entered \n");

      return head;
   }


