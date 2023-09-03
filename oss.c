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
	int iter;
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
				iter = atoi(optarg);
				break;
		}
	}
	pid_t childPid = fork(); // This is where the child process splits from the parent
	if (childPid == 0) {
		printf("I am a child but a copy of parent! My parent's PID is %d, and my PID is %d\n",
    		getppid(), getpid());
    		char* args[] = {"./worker", "Hello", "there", "exec", "is", "neat", NULL};
    		//execvp(args[0], args);
    		execlp(args[0],args[0],args[1],args[2],args[3],args[4],args[5],args[6],NULL);
    		fprintf(stderr,"Exec failed, terminating\n");
    		exit(1);
  	} else {
    		printf("I'm a parent! My pid is %d, and my child's pid is %d \n",
    		getpid(), childPid);
    		//sleep(1);
    		wait(0);
  	}
  	printf("Parent is now ending.\n");
  	return EXIT_SUCCESS;
}

