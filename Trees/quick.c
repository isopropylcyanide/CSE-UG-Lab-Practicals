#include<stdio.h>
#include<stdlib.h>

 void quick(int x[10],int l,int r)
 {
   int par,i,j,temp;
  
   if(l<r)
 {
    par=l;
    i=l; j=r;
  
    while(i<j)
   {
      while(x[i]<=x[par] && i<r)  
 	i++;
  
       while(x[j]>x[par] && j>l)  
 	j--;
 
     if(i<j)
    {
      temp=x[i];
	x[i]=x[j];
      x[j]=temp;
    }
   }
 
   temp=x[par];
   x[par]=x[j];	  
   x[j]=temp;

   quick(x,l,j-1);
   quick(x,j+1,r);
  
  }
}

int main(int argc,char * argv[])
{

  if(argc<4)
  {
    printf("\n Not enough arguments \n\n");
    exit(1);
  }
    int a[(argc-1)],i;
 printf("\n  size of array is %d ",argc-1);  

  for(i=0; i<argc-1; i++)
    a[i]=atoi(argv[i+1]);

  printf("\n The entered list : "); 
 
  for(i=0; i<argc-1; i++) printf(" %d ",a[i]);
 
  quick(a,0,argc-2);

  printf("\n The sorted list : "); 
 
  for(i=0; i<argc-1; i++) printf(" %d ",a[i]);
   printf("\n\n");
}









