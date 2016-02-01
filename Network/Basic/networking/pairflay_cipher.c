#include<stdio.h>
struct character_info
{
	int r,c;
};

int fchar,fchar1;

void printinfile(FILE *fp,FILE *fp1,int pos,int pos1)
{
	seek(fp1,pos,SEEK_SET);
	fputc(fp1,fchar);
	fseek(fp1,pos1,SEEK_SET);
	fputc(fp1,fchar1);
}

void encrypt(char key_matrix[][6],FILE *fp,FILE *fp1,struct character_info cinfo,int character,int character1,int x,int y)
{
	if(cinfo[character-x].r==cinfo[character1-y].r)   //if both are in same row
	{
		if(cinfo[character-x].c+1==6)                   //for setting the encrypted first character
			 fchar=key_matrix[cinfo[character-x].r][0];   
		else
			fchar=key_matrix[cinfo[character-x].r][cinfo[character-x].c+1];
		if(cinfo[character1-y].c+1==6)            //for the encryption of second character
			 fchar=key_matrix[cinfo[character1-y].r][0]; 
		else
			fchar=key_matrix[cinfo[character1-y].r][cinfo[character1-x].y+1];
	}
					else if(cinfo[character-x].c==cinfo[character1-y].c)  //for same column
					{
						if(cinfo[character-x].r+1==6)
						 fchar=key_matrix[0][cinfo[character-x].c]; 
						else
							fchar=key_matrix[cinfo[character-x].r+1][cinfo[character-x].c];

						if(cinfo[character1-y].r+1==6)
						 fchar=key_matrix[0][cinfo[character1-y].c]; 
						else
							fchar=key_matrix[cinfo[character1-y].r+1][cinfo[character1-y].c];
					}
					else
					{
						fchar=key_matrix[cinfo[character-x].r][cinfo[character1-y].c];
						fchar1=key_matrix[cinfo[character1-y].r][cinfo[character-x].c];
					}	
}



void playfair_cipher(char key_matrix[][6],FILE *fp,FILE *fp1,struct character_info cinfo){
	int character,character1,i=0,flagcharacter=0,flag1number=0,flagcharacter1=0,flag1number1=0;
	long int pos,pos1;
	while(!feof(fp)){
		while(i<2)                               //for selecting two charactre and if the character is not required
		{											//it is put at the same position in the encrypted file
			if(i==0)
			 character=fgetc(fp);                                     
			 pos=ftell(fp);
			if(character>=97&&character<=122||character>=48&&character<=57)
				{
					++i;
					if(character>=97&&character<=122)
						flagcharacter=1;
					else
						flag1number=1;
				}

			else
			{
				fseek(fp1,pos,SEEK_SET);
				fputc(fp1,character);
			}

			character1=fgetc(fp);
				pos1=ftell(fp);
			if(character1>=97&&character1<=122||character1>=48&&character1<=57)
			{
				i++;
				if(character1>=97&&character1<=122)
						flagcharacter1=1;
					else
						flag1number1=1;
			}
			else
			{
				fseek(fp1,pos1,SEEK_SET);
				fputc(fp1,character);
			}
		}
		if(flagcharacter)
			{
				if(flagcharacter1)
				{
					if(character!=character1)
					encrypt(key_matrix,fp,fp1,cinfo,character,character1,97,97);
				    else
				    	encrypt(key_matrix,fp,fp1,cinfo,character,122,97,97);


					
				}
				else
				{
					encrypt(key_matrix,fp,fp1,cinfo,character,character1,97,48);
					
				}
			}
			else
			{
				if(flagcharacter1)
				{
					encrypt(key_matrix,fp,fp1,cinfo,character,character1,48,97);
					
				}
				else
				{
					encrypt(key_matrix,fp,fp1,cinfo,character,character1,48,48);
					
				}
			}




	
}

int findChar(char c,char string[]){   ///for finding whether the caharcter is not present in the key
	int i=0;
	while(string[i]!='\0'){
		if(string[i]==c)
			return 1;
	++i;	
	}
	return 0;
}


int main(int argc, char const *argv[])
{
	char key_string[36];
	char key_matrix[6][6];
	int i=0;
	FILE *fp,*fp1;
	fp=fopen(argv[1],"r");
	fp1=fopen(argv[2],"w");
	struct character_info cinfo[36];
	printf("Enter the key String such that characters doesnot repeat\n");
	scanf("%s",key_string);
	while(key_string[i]!='\0'){
		for(j=0;j<6;j++){
			for (k = 0; k < 6; ++k){
				key_matrix[j][k]=key_string[i];
				if(key_string[i]>=48&&key_string[i]<=57)
				{	
					cinfo[key_matrix[j][k]-'0'+26].r=j;
					cinfo[key_matrix[j][k]-'0'+26].c=k;
				else
				{
					cinfo[key_matrix[j][k]-'a'].r=j;
					cinfo[key_matrix[j][k]-'a'].r=k;
				}	
				++i;
			}
		}
	}



	return 0;
}