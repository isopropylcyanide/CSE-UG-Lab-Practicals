#include<stdio.h>
int main()
{
FILE *fp,*fd;
fp=fopen("trace2.tr","r");
if(fp==NULL)
{printf("Sorry couldn't open file1\n");return 0;}
fd=fopen("output.txt","w");
if(fd==NULL)
{printf("Sorry couldn't open file2\n");return 0;}
char c1,c2[5],c3[10];
double d1,d2,d3,d4,d5,d6,d7;
int e1,e2,r2,r3,r4;
double ff=1.5;
int count=0,cc1;
while(!feof(fp))
{
	fscanf(fp," %c %lf %d %d %s %d %s %lf %lf %lf %d %d",&c1,&d1,&r2,&r3,c2,&r4,c3,&d5,&d6,&d7,&e1,&e2);
	if(c1=='r' && r2==3 && r3==5)
	{
		if(d1<=ff)
			count++;
		else
		{
			fprintf(fd,"%lf",ff);
			fprintf(fd," %d\n",count);
			count++;
			ff+=0.5;
		}
	}
}
return 0;
}
