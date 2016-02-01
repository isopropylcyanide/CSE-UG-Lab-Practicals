#include<stdio.h>
#include<string.h>

void main(int argc,char * argv[])
{
	FILE *fp,*fp1,*fp2;
	char event_type[2],packet_type[10],s[10];
	int from,to,flow_id,packet_id,seq_id,packet_size,rcount=0,tcount=0,ucount=0,fsrc,fdest; 
	double ti,current_time=0.0,source,dest,fti;
	char fal[10];
	
	fp=fopen(argv[1],"r");
	fp1=fopen("graphtopo3tcp.txt","w");
	fp2=fopen("graphtopo3udp.txt","w");
	fprintf(fp1, "%f  %d\n",current_time,rcount );
	fprintf(fp2, "%f  %d\n",current_time,ucount );
	current_time=current_time+0.2;
	while(!feof(fp))
	{
		fscanf(fp,"%s",event_type);
		if(strcmp(event_type,"v")){

		fscanf(fp," %lf %d %d %s %d %s %d %lf %lf %d %d\n",&ti,&from,&to,packet_type,&packet_size,s,&flow_id,&source,&dest,&packet_id,&seq_id);
		if(!(strcmp(event_type,"r"))&&to==3)
		{
			if(!(strcmp(packet_type,"tcp")))
				++rcount;
			
		}
		if(!(strcmp(event_type,"r"))&&to==2)
		{
			if(!(strcmp(packet_type,"cbr")))
				++ucount;
		}
				
		if(ti>=current_time)
		{
			fprintf(fp1,"%lf  %d\n",current_time,rcount );
			fprintf(fp2,"%lf  %d\n",current_time,ucount );
			current_time=current_time+0.2;
			rcount=0;
			ucount=0;	
					
		}	
		}
		else
		{
			fscanf(fp,"%lf%s%d%d",&fti,fal,&fsrc,&fdest);
		}	
	}

	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	printf("\nThe received packets tcp packets are%d\n",rcount);
	printf("\nThe received packets udp packets are%d\n",ucount);
	
}

						
			
			
