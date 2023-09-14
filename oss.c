#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>

void help() {
        printf("This program is designed to have a parent process fork off into child processes.\n");
	printf("The child processes don't do anything special: they simply output their parent's\n");
	printf("process id, their own process id, and the number of times that the child has looped.\n\n");
        printf("The executable takes three flags: [-n proc], [-s simul], and [-t iter].\n");
        printf("The value of proc determines the total number of child processes to be produced.\n");
	printf("The value of simul determines the number of children that can run simultaneously.\n");
	printf("The value of iter determines the number of times each child process will loop.\n");
	printf("\nMADE BY JACOB (JT) FOX\n9/11/2023\n");
	exit(1);
}

//void inputValidation(int flagValue, 

int main(int argc, char** argv) {
	int option;
	int proc;
	int simul;
	char *iter;
	while ((option = getopt(argc, argv, "hn:s:t:")) != -1) {
		int intarg;
		intarg = atoi(optarg);
  		switch(option) {
   			case 'h':
    				help();
    				break;
   			case 'n':
    				intarg < 1 ? proc = 1 : (proc = intarg);
    				break;
   			case 's':
				intarg < 1 ? simul = 1 : (simul = intarg);
				break;
			case 't':
				iter = optarg; //figure out how to fix this shit, then update readme and -h with defaults.
				break;
		}
	}
	int totalChildren;
	int runningChildren;
	int finalChild;
	totalChildren = 0;
	runningChildren = 0;

    	while(totalChildren < proc) { 
		pid_t childPid = fork();
		finalChild = childPid;
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
	pid_t waitForAllStop = waitpid(finalChild, NULL, 0); //ensures parent doesn't end before final child
  	return EXIT_SUCCESS;
}

