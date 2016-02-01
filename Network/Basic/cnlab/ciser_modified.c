#include<stdio.h>
int main()
{	FILE * fi=fopen("ciser_input","r");
	FILE * feo=fopen("ciser_encrypt_output","w");
	FILE * fpo=fopen("ciser_plain_output","w");
	int key;
	printf("enter the key:-");
	scanf("%d",&key);
	char ch;
	char che;
	while(fscanf(fi,"%c",&ch)!=EOF)
	{	
		if((ch>=97&&ch<=122)||(ch>=65&&ch<=90)||(ch>=48&&ch<=57))
		{	che=ch+key;
			if(ch>=97&&ch<=122)
			{
			if(che>122)
			{int temp=che-122;
			che=97+temp-1;}
			}
			if(ch>=65&&ch<=90)
			{
			if(che>90)
			{int temp=che-90;
			che=65+temp-1;}
			}
			if(ch>=48&&ch<=57)
			{
			if(che>57)
			{int temp=che-57;
			che=48+temp-1;}
			}
		fprintf(feo,"%c",che);
		}
		else
		fprintf(feo,"%c",ch);
		
		
	}
	fclose(feo);
	 feo=fopen("ciser_encrypt_output","r");
	while(fscanf(feo,"%c",&che)!=EOF)
	{	if(che==' '||che=='.')
		{fprintf(fpo,"%c",che);
			continue;
		}
		ch=che-key;
		if((ch>=97&&ch<=122)||(ch>=65&&ch<=90)||(ch>=48&&ch<=57))
		{	
		fprintf(fpo,"%c",ch);
		continue;
		}	
		if(che>=48&&che<=57)
		{			
			if(ch<48)
			{int temp=48-ch;
			ch=57-temp+1;
			fprintf(fpo,"%c",ch);
			continue;
			}
		}
			if(che>=65&&che<=90)
		{			
			if(ch<65)
			{int temp=65-ch;
			ch=90-temp+1;
			fprintf(fpo,"%c",ch);
			continue;
			}
		}
			if(che>=97&&che<=122)
		{			
			if(ch<97)
			{int temp=97-ch;
			ch=122-temp+1;
			fprintf(fpo,"%c",ch);
			continue;
			}
		}
		}
	fclose(fi);
	fclose(feo);
	fclose(fpo);
}
