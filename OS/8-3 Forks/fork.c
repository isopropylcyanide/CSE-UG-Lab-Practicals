#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t pid; int status;
	printf("Starting process (%d) \n",(int)getpid());

	pid=fork();

	if(pid<0)
	  perror("\nCouldn't create a child process.\n");

	else if (pid==0)
	{
		printf("\nChild process (%d) of parent (%d)\n",getpid(),getppid());
        exit(-1);
	}

	else if (pid>0)
	{
	   printf("\nParent process (%d)\n",getpid());
	   waitpid(pid,&status,0);

	   if(WIFEXITED(status))
		 printf("Child Exits normally : %d\n", WEXITSTATUS(status));
	   else
		 perror("Abnormally exits \n");
	}
    return 0;
}
