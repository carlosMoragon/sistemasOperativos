#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>

#define VUELTAS 100000000000

pid_t pid;

void funcion1(int sig){
	switch(sig){
		case(SIGUSR1):
			kill(pid, SIGUSR2);
			printf("enviado al hijo la señal\n");
			break;
		case(SIGUSR2):
			printf("terminado\n");
			exit(0);
			break;
	}
}

void funcion2(int sig){
	
	kill(getppid(), SIGUSR2);
	printf("Enviado al padre la señal\n");
	exit(0);
	
}

void main (void){
	
	pid = fork(); //CREO AL HIJO -> al padre le devuelve el pid del hijo

	if(pid == 0){
		signal(SIGUSR2, funcion2);
	}else{
	
		signal(SIGUSR1, funcion1);
		signal(SIGUSR2, funcion1);
	}

	for(int i= 0; i<VUELTAS; i++){} //Esto es para q tengamos tiempo de meter la señal
}

