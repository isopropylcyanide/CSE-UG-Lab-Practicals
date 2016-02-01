#include<stdio.h>
#include<stdlib.h>


 char src='A',tmp='C',dest='B' ;

void TOH(int,char,char,char);

 int main(int argc,char *argv[])
 {
    int i,count=0;
	
  	//sscanf(argv[1],"%d",&i);
   
  FILE *fp=fopen(argv[1] ,"r");

 if(fp==NULL)
 {
   printf("\n File couldn't be opened \n");
  exit(1);
  }
   
char ch=fgetc(fp);
i=ch-48;

printf(" i is : %d ",i); 

  if(i==0)

   {
       printf("\n Disks cannot be zero \n");
      exit(1);
   }
	printf("\n Loading disks \n\n");
  
 TOH(i,src,tmp,dest);

  fclose(fp);
 }


  void TOH(int i,char src,char tmp,char dest)
 {
      if(i==1)
     {
        printf("\n Disc moved from %c to %c \n",src,dest);
      return ;
    }
 

   else
          {
             TOH(i-1,src,dest,tmp);
    printf("\n Disc moved from %c to %c ",src,dest);


   TOH(i-1,tmp,src,dest);
 }
}







   



