#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

//Program attempts to get the number of packets dropped at n3

static int count=0;
char buff[1024];

int main(){
  FILE *in;

  in=fopen("trace1.tr","r");
  if(!in){
  	fprintf(stderr, "Couldn't open trace file\n");
  	_exit(1);
  }

  char received_or_not;
  float ttime;
  int src,dest;
  char *cbr=(char*)malloc(sizeof(char)*3);
  int num_packets;
  char * rest=(char*)malloc(sizeof(char)*50);

  memset(buff,0,sizeof(buff));

  while(fgets(buff,1024,in)){

  	fprintf(stdout,"Extras: %s", buff);
  	system("sleep 2");
  }
 
  fclose(in);
  return 0;
}