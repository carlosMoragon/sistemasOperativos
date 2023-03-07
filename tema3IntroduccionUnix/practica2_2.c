#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>
#include <unistd.h>

char mensaje[] = "Soy el proceso P3 y he recibido una señal del proceso P5\n";
char mensaje2[] = "Soy P6\n";

void senales(int sig){
	switch(sig){
		
		case(SIGUSR1):
			for(int i=0; i<strlen(mensaje2); i++){
				write(1, &mensaje2[i], 1);
				//lseek(mensaje2, 0, SEEK_SET);
				sleep(1);
			}
			//write(1, mensaje, strlen(mensaje));
			break;
	
	}

}

void main (void){
	int fd;
	
	for(int i = 0; i<4; i++){
	
		if(fork()== 0){
		
			if(i==2) signal(SIGUSR1, senales);
			
			if(i > 1){
			
				if(fork() == 0){
					if(i==2){
						//sleep(5);
						kill(getppid(), SIGUSR1);
						
					}
					//exit(0)
					break;
					
				}
				
			}
			
			if(i==1) fd = open("fichero_practica2.txt", O_CREAT, 0666);
			
			break;
			/*
			while(wait(NULL)>0);
			
			exit(0);*/
		}
	}
	
	while(wait(NULL)>0);
}

