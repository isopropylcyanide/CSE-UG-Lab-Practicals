#include<stdio.h>
#include<string.h>

int main()
{
	FILE *fp;
        char *ch;
        int count=0;
	fp=fopen("trace1.tr","r");
        ch=fscanf(fp,"%s");
         while(ch !=EOF)
	   
{             if(ch="r           2 3") 
                 {
                    count++;
}    
              printf("%d \n",count);
              ch=(fscan,"%s");
}
	fclose(fp);
	return 0;
}
