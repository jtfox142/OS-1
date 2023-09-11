#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>

void help() {
        printf("This program is designed to have a parent process call a child process.\n");
        printf("The executable takes three flags: [-n proc], [-s simul], and [-t iter].\n");
        printf("Add more here when you know the specifics of how your program will run.\n");
}

int main(int argc, char** argv) {
	int option;
	int proc;
	int simul;
	char *iter;
	while ((option = getopt(argc, argv, "hn:s:t:")) != -1) {
  		switch(option) {
   			case 'h':
    				help();
    				break;
   			case 'n':
    				proc = atoi(optarg);
    				break;
   			case 's':
				simul = atoi(optarg);
				break;
			case 't':
				iter = optarg;
				break;
		}
	}
	int totalChildren;
	int runningChildren;
	totalChildren = 0;
	runningChildren = 0;

	printf("proc: %d\n", proc);
	printf("simul: %d\n", simul);
	printf("iter: %s\n", iter);

    	while(totalChildren < proc) {
		printf("Running Children: %d\n", runningChildren);
    
		pid_t childPid = fork();
		totalChildren++;
		runningChildren++;

		if(childPid == 0) {
			execlp("./worker", iter, NULL);
			exit(1);
		}
		else{
			if(runningChildren >= simul) {
				wait(0);
				runningChildren--;
			}
		}
	}
	wait(0);
	printf("Parent is now ending.\n");
  	return EXIT_SUCCESS;
}

