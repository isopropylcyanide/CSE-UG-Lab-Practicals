#include<stdio.h>
#include<string.h>
void display(char mat[5][5])
{	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%c ",mat[i][j]);
		}
		printf("\n");
	}
}
typedef struct charlist
{
	int x;
	int y;
	char ch;
}charlist;
int main()
{	void display(char mat[5][5]);
	char mat[5][5];
	char key[25];
	int iindex,jindex;//variables to keep track of cell having two characters
	printf("Enter the key:-");
	scanf("%s",key);
	/* matrix generation started*/
	int i,j,keytemp;
	char ch;
	int keylen=strlen(key);
	i=0;keytemp=keylen;
	j=0;
	int inckey=0;
	while(keylen--)
	{	
		if(j==5)
		{j=0;
		i++;
		}
		ch=key[inckey];
		mat[i][j]=ch;
		j++;
		inckey++;
	}
	int i2,j2,index;
	char ascii=97;
	int first=0;
	for(i2=i;i2<5&&ascii<=122;i2++)
	{	if(first==0)
		{ first=1;
		for(j2=j;j2<5&&ascii<=122;ascii++)
		{	

			for(index=0;index<keytemp&&ascii<=122;index++)
			{
				if(ascii==key[index])
				break;
			}
			if(index==keytemp)
			{ mat[i2][j2]=ascii;
				if(ascii=='i')
				{iindex=i2;
				jindex=j2;
				ascii++;
				}
			j2++;
			}
			 
		}
		}
		else
		{
			for(j2=0;j2<5&&ascii<=122;ascii++)
		{	

			for(index=0;index<keytemp&&ascii<=122;index++)
			{
				if(ascii==key[index])
				break;
			}
			if(index==keytemp)
			{	mat[i2][j2]=ascii;
				if(ascii=='i')
				{iindex=i2;
				jindex=j2;
				ascii++;
				}
				j2++;
			}
			 
		}
		}
	}
	//encryption started opening files for input and output
	FILE * fi=fopen("playfair_input","r");
	FILE * feo=fopen("playfair_eoutput","w+");
	char plain1,plain2,enc1,enc2;
	char special='z'; //special character set to z
	//generating mapping list
	int count=0;
	charlist clist[25];
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			clist[count].ch=mat[i][j];
			clist[count].x=i;
			clist[count].y=j;
			count++;
		}
	}
	
	/*printf("\nlist is----->");
	for(count=0;count<25;count++)
	{
		printf("ch=%c i=%d j=%d\n",clist[count].ch,clist[count].x,clist[count].y);
	}*/
	char flagdummy;
	while(fscanf(fi,"%c",&ch)!=EOF)
	{
		if(ch<97||ch>122)
		{ fprintf(feo,"%c",ch);
			continue;
		}
		int flag2=0;//flag to correctly manage spaces
		plain1=ch;
		fscanf(fi,"%c",&ch);
		if(ch<97||ch>122)
		{
			flag2=1;
			flagdummy=ch;
			fscanf(fi,"%c",&ch);
		}
		plain2=ch;
		int i1,j1;
		for(i=0;i<25;i++)
		{
			if(plain1==clist[i].ch)
			{
				i1=clist[i].x;
				j1=clist[i].y;
			}
			if(plain2==clist[i].ch)
			{
				i2=clist[i].x;
				j2=clist[i].y;
			}
		}
	if(i1==i2||j1==j2) //if the characters are either in same row or column
	{
		if(i1==i2)
		{
			i1=(i1+1)%5;
			i2=(i2+1)%5;
			for(i=0;i<25;i++)
			{
				if(i1==clist[i].x&&j1==clist[i].y)
				enc1=clist[i].ch;
				if(i2==clist[i].x&&j2==clist[i].y)
				enc1=clist[i].ch;
			}
		if(flag2==1)
		{
			fprintf(feo,"%c",enc1);
			fprintf(feo,"%c",flagdummy); //output the result taking care of flag2
			fprintf(feo,"%c",enc2);
		}
		else
		{	fprintf(feo,"%c%c",enc1,enc2);
		}
		}
		if(j1==j2)
		{
			j1=(j1+1)%5;
			j2=(j2+1)%5;
			for(i=0;i<25;i++)
			{
				if(i1==clist[i].x&&j1==clist[i].y)
				enc1=clist[i].ch;
				if(i2==clist[i].x&&j2==clist[i].y)
				enc1=clist[i].ch;
			}
		if(flag2==1)
		{
			fprintf(feo,"%c",enc1);
			fprintf(feo,"%c",flagdummy); //output the result taking care of flag2
			fprintf(feo,"%c",enc2);
		}
		else
		{	fprintf(feo,"%c%c",enc1,enc2);
		}
		}
			
	}
	else
		{
			int tempj1;
			tempj1=j1;
			j1=j2;
			j2=tempj1;
			for(i=0;i<25;i++)
			{
				if(i1==clist[i].x&&j1==clist[i].y)
				enc1=clist[i].ch;
				if(i2==clist[i].x&&j2==clist[i].y)
				enc1=clist[i].ch;
			}
		if(flag2==1)
		{
			fprintf(feo,"%c",enc1);
			fprintf(feo,"%c",flagdummy); //output the result taking care of flag2
			fprintf(feo,"%c",enc2);
		}
		else
		{	fprintf(feo,"%c%c",enc1,enc2);
		}
		}
	}
		



}

		
		
			
