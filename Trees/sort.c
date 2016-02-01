#include<stdio.h>
#include<stdlib.h>

void options(int []); int c,temp,arg;
void quick(int [],int,int);    void bubs(int []);
void bins(int []);    	      void inss(int []);
void sels(int []);            void display(int []);
void shels(int []);   	      void rads(int []);
void mers(int []);
   
int main(int argc, char * argv[])
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
  arg=argc-1;
  options(a);
 }
 
 void options(int a[])
 {

   printf("\n\n Following are available ");

   printf("\n 1: Binary search ");
   printf("\n 2: Bubble sort ");
   printf("\n 3: Quick sort ");
   printf("\n 4: Selection sort ");
   printf("\n 5: Insertion sort "); 
   printf("\n 6: Merge sort "); 
   printf("\n 7: Radix sort ");  
   printf("\n 8: Shell sort "); 
   printf("\n 0: Exit "); 
 		           scanf(" %d",&c);
   switch(c) {
   
    case 1: bins(a); 				break;
    case 2: bubs(a);				break;  
    case 3: quick(a,0,arg-1); display(a);	break;
    case 4: sels(a);				break;
    case 5: inss(a);				break;
    case 6: mers(a);				break;
    case 7: rads(a);				break;
    case 8: shels(a);	;			break;
    case 0: exit(1);
    }
 }

  void bins(int a[])				//binary search
 { 
    sels(a);
     

	
   }


  void quick(int x[],int l,int r)		//quick sort
 {
   
  
   int par,i,j,temp;
  
   if(l<r)
 {
    par=l;
    i=l; j=r;
  
    while(i<j)			//partitioning
   {
      printf("\n In part : "); display(x);
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
 				//swapping partitioned with last
  printf("\n end of partition ");
   temp=x[par];
   x[par]=x[j];	  
   x[j]=temp;

   quick(x,l,j-1);
   quick(x,j+1,r);
  
  }
     
 
}

 void bubs(int a[])				//bubble sort
 { 
   int count=0,i; int csum=0;


 for(i=0; i<arg; i++)
{   
  for(c=i;c<arg-1;c++)
  {
    if(a[c]>a[c+1])   
   { 
      temp=a[c];
      a[c]=a[c+1];
      a[c+1]=temp;
    count++;  csum++;

   }
  }
    printf("\n Comparisons in %d pass : %d ",i+1,count);
     if(count==0)
   {
     printf("\n List sorted in %d passes ",i);
     break; }    
	count=0;
 }   
 display(a); 
 printf("\n Total number of comparisons : %d ",csum);
 
}

 void sels(int a[])				//selection sort
 {
  int count=0,i;


 for(i=0; i<arg; i++)
{   
   for(c=i+1;c<arg;c++)
   {
     if(a[c]<a[i])
	{   temp=a[c];
	   a[c]=a[i];
	   a[i]=temp;
 		count++;
        }
   }
   printf("\n Smallest in %d pass : %d ",i+1,temp);

 }
 display(a); 
 printf("\n Total number of comparisons : %d ",count);

}


 void inss(int a[])				//insertion sort
 {
   int count=0,i,bar,j;

  
  for(i=0; i<arg; i++)
{   
  bar=i;
 
   for(c=i+1;c<arg;c++)
   {
     for(j=0; j<=bar; j++)
     {
  	   if(a[j]>a[c])	//if sorted group has an element larger
         {
 	  temp=a[c];
	  a[c]=a[j];
	  a[j]=temp;
          count++;
          }
      }
    }
     printf("\n Comparisons in %d pass : %d ",i+1,count); 
  }
   
 


}

 void display(int a[])
 {
   printf("\n\n Sorted array looks like ");
   for(c=0; c<arg; c++) printf(" %d ",a[c]);
   printf("\n");
 }

 
  void mers(int a[])				//merge sort
 {
   int x[arg/2],y[arg/2];  int i,j,count=0;

    for(i=0; i<arg/2; i++)
     x[i]=a[i];   
    
  for(i=0; i<arg/2; i++)
{   
  for(c=0;c<(arg/2)-1;c++)
  {
    if(x[c]>x[c+1])   
   { 
      temp=x[c];
      x[c]=x[c+1];
      x[c+1]=temp;
   }}}
 printf("\n Array 1: ");  for(c=0; c<sizeof(x)/sizeof(int); c++) printf(" %d ",x[c]);
  
  
 if(arg%2==0)   
 
   {for(i=0; i<arg/2; i++)
     y[i]=a[i+(arg/2)];


    for(i=0; i<arg/2; i++)
{   
  for(c=0;c<(arg/2)-1;c++)
  {
    if(y[c]>y[c+1])   
   { 
      temp=y[c];
      y[c]=y[c+1];
      y[c+1]=temp;
   }}}
 printf("\n Array 2: ");  for(c=0; c<sizeof(y)/sizeof(int); c++) printf(" %d ",y[c]);
	
    }

    else
 {
     for(i=0; i<(arg/2)+1; i++)
     y[i]=a[i+(arg/2)];	

   
    for(i=0; i<(arg/2)+1; i++)
{   
  for(c=0;c<(arg/2)-1;c++)
  {
    if(y[c]>y[c+1])   
   { 
      temp=y[c];
      y[c]=y[c+1];
      y[c+1]=temp;
   }}}
 printf("\n Array 2: ");  for(c=0; c<=sizeof(y)/sizeof(int); c++) printf(" %d ",y[c]);
	
 
   }
 
  int aux[arg]; int b1=0,b2=0; printf("\n");
  
 for(i=0; i<arg; i++)  
  {
   if(b2==arg/2) 
            {
              while(b1!=arg/2)
              { aux[i]=x[b1]; i++; b1++; }
           break; }

 if(b1==arg/2) 
            {
              while(b2!=arg/2)
              { aux[i]=y[b2]; i++; b2++; }
           break; }

 	 if(x[b1]<y[b2] && (b1<arg/2 || b2<arg/2))
    {
    		aux[i]=x[b1]; 	
             b1++;
   	}

   else if(y[b2]<x[b1] && (b1!=arg/2 || b2!=arg/2))
     {  
      	   aux[i]=y[b2];
		b2++;
          
   	}
     }


}




 void rads(int a[])				//radix sort
 {

   }

 void shels(int a[])				//shels sort
 {

   }













