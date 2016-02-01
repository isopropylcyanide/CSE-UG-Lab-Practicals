#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int n;
  cout<<"\n Enter the number of items : ";
  cin>>n;

  int wt[n],val[n],V[n+1][n+2];
  
  cout<<"\n Enter the weight of each item : ";
  for(int i=0; i<n; i++)
   cin>>wt[i];

  cout<<"\n Enter the value of each item : ";
  for(int i=0; i<n; i++)
   cin>>val[i];
 
  for(int i=0; i<n+1; i++)   
     for(int j=0; j<n+2; j++)
	V[i][j]=0;

  for(int i=0; i<n+1; i++)   
   {
     for(int j=0; j<n+2; j++)
      {
	if (j>=wt[i])
	  V[i][j]=max(V[i-1][j],val[i]+V[i-1][j-wt[i]]);
	else
	  V[i][j]=V[i-1][j];
      }
   }
   cout<<"\n The maximum profit could be : "<<V[n][n+1];

 return 0;
}

































