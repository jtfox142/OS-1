#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv) {
  printf("Inside of child process\n");
  int iterations;
  iterations = atoi(argv[0]);
  int i;
  for (i =0; i < iterations; i++)
    printf("|%d| ", i);
  printf("\nChild is now ending.\n");
  sleep(3);
  return EXIT_SUCCESS;
}
