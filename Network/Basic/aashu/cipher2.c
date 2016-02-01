#include<stdio.h>
int main()
{
FILE *fp , *fq;
char o,a;
int i,j;
char b[5][5]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','c','v','b','n','m'}; 
 
fp = fopen("1.txt", "r");
fq =fopen("2.txt","w");
char ch;

char str1[4], str2[8];
int s,d,i1,i2,i3;
float t, f1, f2;
for(i=0;i<5;i++)
{printf("\n");
for(j=0;j<5;j++)
{
printf("%c", b[i][j]);
printf(" ");}
}
printf("\n");
while(!feof(fp))
{
fscanf(fp,"%c%c",&a, &o);


for(i=0;i<5;i++)
for(j=0;j<5;j++)
{while(b[i][j]==a)
  int r1=i;
  int c2=j;
 while (b[i][j]==o)
{
 int r2=i;
 int c2=j;
}


}


printf("%c%c\n",a,o );
}
fclose(fp);

return 0;
}

