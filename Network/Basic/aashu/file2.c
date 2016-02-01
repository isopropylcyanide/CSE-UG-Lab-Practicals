#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main ()
{
  	FILE *fp;
	int c=0,i,src1=0,src2=0;
	char* arr;
	arr=(char*)malloc(40*sizeof(char));
	fp = fopen("trace1.tr", "r");
	if(!fp)
	printf("Error in trace file\n");	 
	else	
	{
	while(fgets(arr,1024,fp))
	{
		if(arr[0]=='r')
		{
			
			i=3;
			if(arr[i]=='.')
			{
				do
				{
					i++;				
				}while((int)arr[i]!=32);			
			}
			
			if(arr[i+1]=='2' && arr[i+3]=='3')
			{
				c++;
				

				if(arr[i+20]=='1')
				{
					src1++;
					printf("%s\n",arr);			
				}
				else if(arr[i+21]=='2')
				{
					src2++;
					printf("%s\n",arr);			
				}
			}
			
		}
	}
	}
	printf("total packet recieved %d\n", c);  	
	printf("sent by node 0 is %d\n",src1);
	printf("sent by node 1 is %d",src2);	
	//if(fclose(fp)!=0)
	//	printf("\nError in closing");
  	
	return 0;
}
