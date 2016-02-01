#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char **argv)
{
    if (argc != 3){
        perror(" Usage: count <lowerLimit> <upperLimit>\n");
        return -1;
    }

	int i;
	int llim=atoi(argv[1]);
	int ulim=atoi(argv[2]);

	printf("\n Displaying count from %d to %d",llim,ulim);

	for(i=llim; i<ulim; i++)
		printf("\n Count : %d ",i);

	printf("\n");
	return 120;
}
