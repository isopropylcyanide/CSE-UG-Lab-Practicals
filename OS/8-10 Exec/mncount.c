#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


char *path = "/home/aman/Desktop/prog/OS/8-10 Exec/count";

/*  Program to count the number of digits from a minimum to a maximum and distributing
	the work in k child processes. eg- ./mncount min max k. Please note that the number 	of digits in the min and the maximum should be same due to the way sprintf works.
*/

int main(int argc,char **argv)
{
	FILE *fp;
	fp = fopen(path,"r");
	if (!fp){
		perror("\n Compile the count.c executable to generate count object file\n");
		return -1;
	}
	fclose(fp);

	if(argc<4){
		perror(" Usage: count <lowerLimit> <upperLimit> <interval> \n");
		return -1;
	}

	int llim=atoi(argv[1]);
	int ulim=atoi(argv[2]);
	int mid =atoi(argv[3]);
	int status;
	pid_t pid[mid];
	int i,offset,left,a,a1,a2;

	int diff=ulim-llim;
	if(mid>diff)
		{
		perror("\n Given counts can not be distributed amongst entered processes\n");
		return -1;
		}

	offset=diff%mid;
	left=diff/mid;

	for(i=0; i<mid; i++)
	{
		pid[i]=fork();

		if(pid[i]==0)
		{
			printf("\n Child(%d): %d ",i,getpid());

			a=atoi(argv[1]);
			a1=a+ left*i;
			if(i==mid-1)
				 a2=a1+left+offset;
			else a2=a+ left*(i+1);

			sprintf(argv[1],"%d",a1);
			sprintf(argv[2],"%d",a2);

			char *new_arg[4]={"count",argv[1],argv[2],NULL};

			int r=execvp(path,new_arg);

			if(r==-1)
				perror("\nCouldn't create child sub-process\n");
		}

		else if(pid[i]>0)
		{
			printf("\n Parent(%d): %d",i,getpid());
			waitpid(pid[i],&status,0);
			printf("\n Child(%d) ",i);

			if(WIFEXITED(status))
				printf("Exits normally : %d\n", WEXITSTATUS(status));

			else if(WIFSTOPPED(status))
				printf("Stopped By : %d\n", WSTOPSIG(status));

			else if(WIFSIGNALED(status))
				printf("Signalled by : %d\n", WTERMSIG(status));
			else
				perror("Abnormally exits \n");

			continue;
		}

		else perror("\nCouldn't create a process\n");
	}
	printf("\n");
	return 0;
}
