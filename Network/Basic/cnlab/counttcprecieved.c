#include<stdio.h>
int main()
{
	FILE * fo=fopen("2708.tr","r");
	FILE * fr=fopen("2708result","w");
	char ch;
	float time;
	int isrc;
	int idest;
	char pt[10]; //packet type
	int psize;
	char rand[8];
	int ri[9];
	long count=0;
	
	while(fscanf(fo,"%c %f %d %d %s %d - - - - - - - %d %d.%d %d.%d %d %d",&ch,&time,&isrc,&idest,pt,&psize,&ri[0],&ri[1],&ri[2],&ri[3],&ri[4],&ri[5],&ri[6])!=EOF)
{
	if(ch=='r'&& idest==4 && pt[0]=='t' && pt[1]=='c')
	{	count=count+1;
		fprintf(fr,"%f %ld\n",time,count);
	}
}
fclose(fo);
fclose(fr);
}
