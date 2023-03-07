#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

/*
Cada proceso debe imprimir su PID y su PPID.
¿En qué orden se imprimen los mensajes? Justifica tu respuesta
*/

void main(){
	
	pid_t pid;
	printf("el pid del padre %d\n-------------------\n", getpid());
	pid = fork();
	for(int i = 0; i<8; i++){
		if(pid != 0) pid = fork();
		else{
			printf("%d mi pid es %d y mi padre es %d \n", i, getpid(), getppid());
			exit(0);
		}
	
	}
	
	while(wait(NULL) > 0);

	//wait(NULL) -> devuelve el numero de hijos que tiene el proceso
}

/*
Se imprimen en un orden aleatorio, por que no tenemos forma de saber cual procesara primero el sistema operativo.

*/
