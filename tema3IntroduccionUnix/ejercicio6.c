#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>


void main(){
	if(fork() == 0){
		if(fork() == 0){
			execl("/bin/ps", "ps", (char*) 0);
		}
		while(wait(NULL) > 0);
		execl("/bin/ls", "ls", (char*) 0);
	}
	while(wait(NULL) > 0);
}
