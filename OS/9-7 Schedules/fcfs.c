#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

static int no_processes;
static int idle_time = 0;

typedef struct process{
	int id,arriv_time;
	int burst_time;
	int wait_time;
	int ta_time;
	float resp_ratio;
	float weighted_ta;
}process_list;

typedef struct proc_execution{
	int time;
	int serving;
	int *ready;
}proc_ex;

typedef struct process_queue{
	int pid;
	struct process_queue* next;
}queue;

queue *front,*rear;
void enqueue(int data){
	queue *temp;
	temp=(queue *)malloc(sizeof(queue));
	temp->next = NULL;
	temp->pid = data;

   	if(rear==NULL)
   		front = rear = temp;
   	else {
   		queue *p = front;
   		if(rear->pid==data)return;
   		while(p != rear){
   			if (p->pid==data)return;
   			p = p->next;
   		}
   		rear->next = temp;
   		rear = temp;
   	}
 }

int dequeue(){
    queue * p = front;
    int data = 0;

    if(p==NULL)return -1;
    if(p->next != NULL) {
       data = p->pid;
       p = p->next;
       free(front);
       front = p;
     }
     else {
        data = p->pid;
        free(front);
        front = rear = NULL ;
      }
    return data;
  }

void create_process_queue(){
	front = rear = NULL;
}

void display_processes(process_list* proc){
	printf("\nID\tArrival\tBurst\tWait\tTurn\tResp\tWeighted TA\n");

	for(int i = 0; i < no_processes; i++){
		printf("%d\t",proc[i].id );
		printf("%d\t",proc[i].arriv_time);
		printf("%d\t",proc[i].burst_time);
		printf("%d\t",proc[i].wait_time);
		printf("%d\t",proc[i].ta_time);
		printf("%0.2f\t",proc[i].resp_ratio);
		printf("%0.2f\n",proc[i].weighted_ta);
	}
	FILE *fp = fopen("graph_proc.txt","w+");
	fprintf(fp,"\n\"Wait Time\"\n");
	for(int i = 0; i < no_processes; i++)
		fprintf(fp,"%d %d\t\n",proc[i].id,proc[i].wait_time);

	fprintf(fp,"\n\"Turn Aroundd Time\"\n");
	for(int i = 0; i < no_processes; i++)
		fprintf(fp,"%d %d\t\n",proc[i].id,proc[i].ta_time);

	fprintf(fp,"\n\"Weighted Turn Around Time\"\n");
	for(int i = 0; i < no_processes; i++)
		fprintf(fp,"%d %f\t\n",proc[i].id,proc[i].weighted_ta);

	fprintf(fp,"\n\"Completion Time\"\n");
	for(int i = 0; i < no_processes; i++)
		fprintf(fp,"%d %d\t\n",proc[i].id,proc[i].ta_time-proc[i].arriv_time);
	fclose(fp);
}

void display_execution(proc_ex ps){
	printf("%d\t",ps.time );
	if (ps.serving != 0)printf("P%d \t",ps.serving);
	else printf("-\t");

	for(int j = 0; j < no_processes; j++)
		if (ps.ready[j]==1)printf("P%d ",j+1);
		else	printf("- ");
	printf("\n");
}

void isReady(process_list* proc,proc_ex ps){
	for(int i = 0; i < no_processes; i++){
		if (ps.ready[i]==-1)continue;
		if (proc[i].arriv_time<=ps.time){
			ps.ready[i]=1;
			enqueue(i);
		}
	}
}

int get_min(process_list *proc){
	int minimum = INT_MAX;
	for (int i = 0; i < no_processes; i++)
		if (proc[i].arriv_time<=minimum)
			minimum = proc[i].arriv_time;
	return minimum;
}

int not_all_serviced(proc_ex ps){
	for(int i = 0; i < no_processes; i++){
		if (ps.ready[i] != -1)
			return 1;
	}
	return 0;
}

void display_results(process_list*proc){
	float mean_wta = 0,mean_ta = 0,mean_resp = 0,mean_w = 0;
	for (int i = 0; i < no_processes; i++){
		mean_wta += proc[i].weighted_ta;
		mean_ta += proc[i].ta_time;
		mean_resp += proc[i].resp_ratio;
		mean_w += proc[i].wait_time;
	}
	printf("\nMean Turn Around Time: %.2f\n",mean_ta/no_processes);
	printf("Mean Weighted Turn Around Time: %.2f\n",mean_wta/no_processes);
	printf("Mean Response Ratio: %.2f\n",mean_resp/no_processes);
	printf("Mean Waiting Time: %.2f\n",mean_w/no_processes );
	printf("Mean CPU Idle Time: %d\n\n",idle_time );
}

int main(){

    FILE *fp = fopen("proc_input.txt","r");
    fscanf(fp,"%d",&no_processes);

    process_list* proc=(process_list*)malloc(sizeof(process_list)*no_processes);
    assert(proc != NULL);

    for(int i = 0; i < no_processes; i++)fscanf(fp,"%d",&proc[i].arriv_time);
	for(int i = 0; i < no_processes; i++)fscanf(fp,"%d",&proc[i].burst_time);
	for(int i = 0; i < no_processes; i++)proc[i].id = i+1;

	printf("\nArrival: \t"); for(int i = 0; i < no_processes; i++)printf(" %d ",proc[i].arriv_time);
	printf("\nBurst  : \t"); for(int i = 0; i < no_processes; i++)printf(" %d ",proc[i].burst_time);
	printf("\n\nTime\tServe\tReady\n");

	proc_ex ps;
	create_process_queue();

	ps.time = get_min(proc);
	ps.ready=(int *)malloc(sizeof(int)*no_processes);
	isReady(proc,ps);
	ps.serving = dequeue()+1;

	display_execution(ps);

	while(not_all_serviced(ps)){
		int i = ps.serving-1;
		if (i==-1){
			ps.time += 1;
			idle_time += 1;
		}

		else{
			ps.time += proc[i].burst_time;
			proc[i].ta_time = ps.time-proc[i].arriv_time;
			proc[i].wait_time = proc[i].ta_time-proc[i].burst_time;
			proc[i].resp_ratio=(float)proc[i].ta_time/proc[i].burst_time;
			proc[i].weighted_ta=(float)proc[i].ta_time/proc[i].burst_time;
			ps.ready[i]=-1;
		}
		isReady(proc,ps);
		ps.serving = dequeue()+1;
		display_execution(ps);
	}

	display_processes(proc);
	display_results(proc);

	return 0;
}
