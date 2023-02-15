#include <stdio.h>
#include <string.h>
#include <sys/types.h>

void main(){
	pid_t pid;
	pid = fork();
	
	printf("pid%d\nppid %d\n", getpid(), getppid());
}

