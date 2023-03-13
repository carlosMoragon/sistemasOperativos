#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>
#include <unistd.h>

char mensajec[] = "He recibido una señal de mi proceso padre\n";
char mensajeb[] = "Soy el proceso P3 y he recibido una señal del proceso P5\n";
pid_t pid;

void senales(int sig){
	switch(sig){
		
		case(SIGUSR1):
			write(1, mensajec, strlen(mensajec));
			break;
			
		case(SIGUSR2):
			write(1, mensajeb, strlen(mensajeb));
			kill(pid, SIGUSR1);
			break;
	
	}

}

void main (void){
	int fd;

	for(int i = 0; i<4; i++){
	
		if(fork()== 0){
			if(i > 1){
				if(i==2) signal(SIGUSR2, senales);
				pid = fork();			
				if(pid == 0){
					if(i==2) signal(SIGUSR1, senales);
					
					kill(getppid(), SIGUSR2);
					sleep(2);
					break;
					
				}
					

				
			}
			break;
		}
	}
	
	while(wait(NULL)>0);
}

