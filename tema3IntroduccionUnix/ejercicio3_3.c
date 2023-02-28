#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>


void main(){
	printf("soy padre pid: %d ppid: %d \n", getpid(), getppid());
	if(fork() == 0){
		printf("soy hijo pid: %d ppid: %d \n", getpid(), getppid());
		if(fork() == 0){
			printf("soy nieto pid: %d ppid: %d \n", getpid(), getppid());
		}
	}
	while(wait(NULL) > 0);
}
