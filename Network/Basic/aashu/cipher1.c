#include<stdio.h>
int main()
{
FILE *fp , *fq;
char a,i;
char b[100]; int key=3; 
fp = fopen("1.txt", "r");
fq =fopen("2.txt","w");
char ch;

char str1[4], str2[8];
int s,d,i1,i2,i3;
float t, f1, f2;
while(!feof(fp))
{int j=0;
fscanf(fp,"%c",&a);
printf("%c-",a );
if(a>=48 && a<=(122-key))
{printf("%c \n",a+key);
}

}
fclose(fp);

return 0;
}

