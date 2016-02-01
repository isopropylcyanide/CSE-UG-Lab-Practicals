#include<stdio.h>
#include<unistd.h>
#include<termios.h>
#include<stdlib.h>
#include<string.h>

/*To turn off terminal echo you can also use  stty -echo and then remember
 to turn it back on. Given below is the bigger way using termios.h*/

typedef struct user_details{
	char name[20];
	char pass[10];
}user;

int main(){

 FILE *out;

 if(!isatty(fileno(stdout))){
 	fprintf(stderr,"You are not a terminal.\n");
 }
  else
  	fprintf(stderr,"You are a terminal\n");

 out=fopen("out","w");

 if(!out){
 	fprintf(stderr, "Couldn't open output file\n");
 	exit(1);
 }

  struct termios init,newer;
 
  int num,i;
  fprintf(stderr, "Enter number of users: ");
  scanf("%d",&num);

  user e[num];
  
  for(i=0; i<num; i++){ 
    fprintf(stderr,"\n\n%d. Name : ",i+1 );
    scanf("%s",e[i].name);

    tcgetattr(fileno(stdin),&init);
    newer=init;
    newer.c_lflag&= ~ECHO;
	fprintf(stderr,"%d. Pass : ",i+1 );
    
    tcsetattr(fileno(stdin),TCSANOW,&newer);
    scanf("%s",e[i].pass);
    tcsetattr(fileno(stdin),TCSANOW,&init);

    fprintf(out,"\n\n%d. Name : %s\n",i+1,e[i].name);
    fprintf(out,"%d. Pass : %s",i+1,e[i].pass);
  }
 
	fclose(out);
	return 0;
}