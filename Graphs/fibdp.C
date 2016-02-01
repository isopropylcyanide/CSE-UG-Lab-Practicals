#include<iostream>
#include<vector>
using namespace std;

int f=0;

int fib_dp(vector<int>k,int n) 
{
  if (n<=2)
	f=1;
  else  if (k[n]==0)
	{
	 f=fib_dp(k,n-1)+fib_dp(k,n-2);
	 k[n]=f;
 	} 
 else
	 f=k[n];
  return f;
}


int main()
{
  int n;
  vector<int>k(1,0);

  while(1){	
  cout<<"\n Enter the nth term: ";
  cin>>n; 

  k.resize(n+1);
  cout<<" Series:  "<<fib_dp(k,n)<<endl;

  k.clear(); 
  }
 return 0;
}

