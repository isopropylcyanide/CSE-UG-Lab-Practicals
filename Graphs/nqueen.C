#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>

using namespace std;

int n,m,i,l,j,k,flag=0;
int M[10][10]; vector<int>pos(10,-1);

void placement(int,int);
void print();
void clear();

int main()
{ 
  cout<<"\n Enter the order of the chessboard matrix : "; cin>>n;

  for(i=0; i<n; i++)
  for(j=0; j<n; j++)
	M[i][j]=0;

  int Qstatus=0;
  
  for(k=0; k<n; k++)
   {
     cout<<"\n INITIALLY AT LOCATION : "<<k<<endl;
     placement(Qstatus,k);
     print();
   }
  return 0;
} 

void clear()
{
 for(i=0; i<n; i++)
  for(j=0; j<n; j++) M[i][j]=0;
 for(i=0; i<n; i++) pos[i]=0;
}

void print()
{
 cout<<endl;
 for(i=0; i<n; i++){
  for(j=0; j<n; j++)
   cout<<" "<<M[i][j];
  cout<<endl; }
 cout<<" Position : ";
 for(vector<int>::iterator it=pos.begin(); it!=pos.end(); it++)
   cout<<" "<<*it;
 cout<<endl;
}


bool isSafe(int Qstatus,int l)
{
  for(j=0; j<Qstatus; j++)
   {
    if((pos[j]==l) || (abs(j+pos[j])==abs(Qstatus+l) || abs(j-pos[j])==abs(Qstatus-l) ))
      { flag=1;break; }
     else flag=0;
   }
  
  return (flag==0)?true:false;
}


void placement(int Qstatus,int init)
{
  if(Qstatus==n) return;
  if(Qstatus==0)
   {
     clear();
     pos[0]=init;
     M[0][pos[0]]=1;
  }
  else
   { 

     for(l=0; l<n; l++)
      {
	if(isSafe(Qstatus,l))
	{
	 pos[Qstatus]=l;
	 M[Qstatus][l]=1;
	 break;
	}
      }
    }	
    placement(Qstatus+1,init);
}













	
 
