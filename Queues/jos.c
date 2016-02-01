#include<stdio.h>

int main()
{
   int n,k,s,ans;

  printf("\n Enter the number of players ");
   scanf(" %d",&n);
  
  printf("\n Enter the number of shifts ");
   scanf(" %d",&k);

  printf("\n Enter the starting position ");
   scanf(" %d",&s);
 
   ans=josephus(n,k,s);
 
  printf("\n The last known survivor would be : %d \n\n ",ans);
  
}

int josephus(int n,int k,int s)
 {
    if(n==1) 
      return 1;
 
   int sp=(s+k-1)%n +1;
 
   int surv=josephus(n-1,k,sp);
  if(surv<sp)
    return surv;

  else
    return surv+1;
 }
