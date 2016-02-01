#include<stdio.h>
#include<string.h>

void main()
{
	FILE *fp,*fp1;
	char event_type[2],packet_type[10],s[10];
	int from,to,flow_id,packet_id,seq_id,packet_size,rcount=0,tcount=0,drop=0,src1=0,src2=0,src=3; 
	float time,current_time=0.0,source,dest;;
	
	fp=fopen("topology1.tr","r");
	fp1=fopen("graphtopo.txt","w");
	fprintf(fp1, "%f  %d\n",current_time,rcount );
	current_time=current_time+0.2;
	while(!feof(fp))
	{
		
		fscanf(fp,"%s %f %d %d %s %d %s %d %f %f %d %d\n",event_type,&time,&from,&to,packet_type,&packet_size,s,&flow_id,&source,&dest,&packet_id,&seq_id);
		if(!(strcmp(event_type,"r"))&&to==3)
		{
			++rcount;
		}
		
		if(!(strcmp(event_type,"r"))&&from==0 &&to==2&&dest==3.0)
		{
			++src1;
		}
		if(!(strcmp(event_type,"r"))&&from==1&&to==2&&dest==3.0)
		{
			++src2;
		}
		if(time>=current_time)
		{
			fprintf(fp1,"%f  %d\n",current_time,rcount );
			current_time=current_time+0.2;
			rcount=0;
		}		
	}
	printf("\nThe received packets are%d\n",rcount);
	printf("The received packets from src1=%d\n",src1 );
	printf("The received packets from src2=%d\n",src2 );
	
}

						
			
			
