#include<stdio.h>
#include<string.h>

void main(int argc,char * argv[])
{
	FILE *fp,*fp1,*fp2;
	char event_type[2],packet_type[10],s[10];
	int from,to,flow_id,packet_id,seq_id,packet_size,rcount=0,tcount=0,ucount=0; 
	float time,current_time=0.0,source,dest;;
	
	fp=fopen(argv[1],"r");
	fp1=fopen("graphtopo2tcp.txt","w");
	fp2=fopen("graphtopo2udp.txt","w");
	fprintf(fp1, "%f  %d\n",current_time,rcount );
	fprintf(fp1, "%f  %d\n",current_time,ucount );
	current_time=current_time+0.2;
	while(!feof(fp))
	{
		
		fscanf(fp,"%s %f %d %d %s %d %s %d %f %f %d %d\n",event_type,&time,&from,&to,packet_type,&packet_size,s,&flow_id,&source,&dest,&packet_id,&seq_id);
		if(!(strcmp(event_type,"r"))&&to==4)
		{
			if(!(strcmp(packet_type,"tcp")))
				++rcount;
			if(!(strcmp(packet_type,"cbr")))
				++ucount;
		}
		
		/*if(!(strcmp(event_type,"r"))&&from==0 &&to==2)
		{
			++src1;
		}
		if(!(strcmp(event_type,"r"))&&from==1&&to==2)
		{
			++src2;
		}*/
		if(time>=current_time)
		{
			fprintf(fp1,"%f  %d\n",current_time,rcount );
			fprintf(fp2,"%f  %d\n",current_time,ucount );
			current_time=current_time+0.2;
			rcount=0;
			ucount=0;	
					
		}		
	}
	printf("\nThe received packets tcp packets are%d\n",rcount);
	printf("\nThe received packets udp packets are%d\n",ucount);
	/*printf("The received packets from src1=%d\n",src1 );
	printf("The received packets from src2=%d\n",src2 );
	*/
}

						
			
			
