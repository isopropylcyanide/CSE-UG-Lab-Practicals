#include<stdio.h>
#include<stdlib.h>


void caesar_encrypt(int key,FILE *fp,FILE *fp1){
	int character,fchar;
	while(!feof(fp)){
		character=fgetc(fp);
		if(character>=48&&character<=57)
		{
			fchar=character+key;
			while(!(fchar>=48&&fchar<=57)){
				fchar-=10;
			}
			
			

		}
		else if (character>=65&&character<=90||character>=97&&character<=122)
		{
			fchar=character+key;
			while(!(fchar>=65&&fchar<=90||fchar>=97&&fchar<=122)){
				fchar-=26;
			}
			
		}
		else
			fchar=character;
		if(fchar!=EOF)
		fputc(fchar,fp1);
	}
}

void caesar_decrypt(int key,FILE *fp,FILE *fp1){
	int character,fchar;
	while(!feof(fp)){
		character=fgetc(fp);
		if(character>=48&&character<=57)
		{
			fchar=character-key;
			while(!(fchar>=48&&fchar<=57)){
				fchar+=10;
			}
			
		}
		else if (character>=65&&character<=90||character>=97&&character<=122)
		{
			fchar=character-key;
			while(!(fchar>=65&&fchar<=90||fchar>=97&&fchar<=122)){
				fchar+=26;
			}
			
		}
		else
			fchar=character;
		if(fchar!=EOF)
		fputc(fchar,fp1);
	}

}


int main(int argc, char *argv[])
{
	int key;
	FILE *fp,*fp1;
	printf("Enter the key\n");
	scanf("%d",&key);
	fp=fopen(argv[1],"r");
	fp1=fopen(argv[2],"w");
	caesar_decrypt(key,fp,fp1);
	return 0;
}