#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>
#include <unistd.h>

char mensajeb[] = "Soy el proceso P3 y he recibido una señal del proceso P5\n";
char mensajec[] = "He recibido una señal de mi proceso padre";
char mensaje2[] = "Soy P6\n";
void senales(int sig){
	switch(sig){
		
		case(SIGUSR1):
			//apartado d)
			for(int i=0; i<strlen(mensaje2); i++){
				write(1, &mensaje2[i], 1);
				sleep(1);
			}
			
			// apartado b)
			write(1, mensajeb, strlen(mensajeb));
			break;
	
	}

}

void main (void){
	int fd;
	pid_t pid;
	for(int i = 0; i<4; i++){
	
		if(fork()== 0){
			
			//apartado b)
			if(i==2) signal(SIGUSR1, senales); 
			
			
			if(i > 1){
				pid = fork();
				if(pid == 0){
					//Apartado b)
					if(i==2){
						kill(getppid(), SIGUSR1);
						
					}
					
					break;
					
				}
				
			}
			
			
			//apartado a)
			if(i==1) fd = open("fichero_practica2.txt", O_CREAT, 0666);
			
			break;
		}
	}
	
	while(wait(NULL)>0);
}

