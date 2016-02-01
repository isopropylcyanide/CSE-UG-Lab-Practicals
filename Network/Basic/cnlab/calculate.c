#include<stdio.h>
int main()
{	int count=0;
	FILE *fp;
	fp=fopen("1308.tr","r");
	char ch=getc(fp);
	while(ch!=EOF)
	{
		if(ch=='r')
		{
			count++;
		}
	}
	printf("count=%d",count);
	fclose(fp);
}
