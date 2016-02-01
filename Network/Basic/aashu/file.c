#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main ()
{
  	FILE *fp;
	int c=0,i;
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
			}
		}
	}
	}
	printf("total packet %d\n", c);  	
	//if(fclose(fp)!=0)
	//	printf("\nError in closing");
  	
	return 0;
}
