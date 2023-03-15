#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

void tratamiento(int sig){

	switch(sig){
	
		case SIGUSR1:
			execl("/bin/ls", "ls", "-l", NULL);	
	}
}

void main (void){
	int pid=fork();
	if (pid==0){
		printf("Haz el primer ps\n");
		fflush(stdout);
		sleep(10);
		printf("Ahora lanzar la señal\n");
		fflush(stdout);
		printf("%s%d\n", "El PID del proceso hijo es ", getpid());
		fflush(stdout);
		signal(SIGUSR1, tratamiento);
		sleep(15);
	}
	while(wait(NULL)>0);
}
