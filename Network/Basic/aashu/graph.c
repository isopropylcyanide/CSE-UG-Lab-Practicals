#include<stdio.h>
void main()
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
	if(i1>=0)
	count++;
        else if(d==2)
        count1++;
}
}
printf("\n\n%d packets received by 3\n",count);

printf("\n\n%d packets received by 2\n",count1);


FILE *ft;
int x,y;
char z;
ft=fopen("g1.txt","r");
while(!feof(ft))
{
fscanf(ft,"%d %d", &x,&y);
}
printf("%d %d \n",x,y);

fclose(ft);
fclose(fp);




}

