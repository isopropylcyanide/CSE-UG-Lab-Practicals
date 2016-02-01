#include<stdio.h>

int main()
{
FILE *fp;
fp = fopen("trace1.tr", "r");
char ch;

char str1[4], str2[8];
int s,d,i1,i2,i3,count=0,i4,count1=0;
float t, f1, f2;
while(!feof(fp))
{
fscanf(fp,"%c %f %d %d %s %d %s %d %f %f %d %d",&ch,&t,&s,&d,str1,&i1,str2,&i2,&f1,&f2,&i3,&i4);
if(ch == 'r')
{
	if(s==2 && d==3)
        {
		if(i2==1)
			count++;
		if(i2==2)
			count1++;
	}
}
}
fclose(fp);
printf("\n%d packets send by 0\n",count);
printf("\n%d packets send by 1\n",count1);
return 0;
}
