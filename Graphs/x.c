#include<stdio.h>
int n,b,i,j;


void print2d(int par[][b+1])
{
 for(i=0; i<=n; i++){
   for(j=0; j<=b; j++)	
   printf(" %d ",par[i][j]);
   printf("\n");
  }
}


void getParity(int par[][b+1])
{
  int sum=0;
  for(i=0; i<n; i++)
   {
     sum=0;
     for(j=0; j<b; j++)
      sum+=par[i][j];	  
  
   if (sum&1) par[i][b]=1;
	else  par[i][b]=0;
   }
   printf("\n After row\n");
  print2d(par);

  for(i=0; i<b+1; i++)
   {
     sum=0;
     for(j=0; j<n; j++)
      sum+=par[j][i];	

   if (sum&1) par[n][i]=1;
	else  par[n][i]=0;   
   }
 printf("\n After col\n");
 print2d(par);
}


int main()
{

  printf("\n Enter the number of inputs: "); 
  scanf("%d",&n);

  printf("\n Enter the size of each input(bits): "); 
  scanf("%d",&b);
  
  printf("\n Creating a matrix of dim[%d][%d]\n",n+1,b+1);
  int parity[n+1][b+1];
  for(i=0; i<=n; i++)
   for(j=0; j<=b; j++)	
    parity[i][j]=0;
 
  printf("\n Enter the inputs: \n"); 
  for(i=0; i<n; i++)
   for(j=0; j<b; j++)	
    scanf("%d",&parity[i][j]);

  getParity(parity);
   return 0;
}




















