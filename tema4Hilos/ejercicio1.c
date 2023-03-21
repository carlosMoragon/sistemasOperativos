#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

/*
Ejercicio 1. Modifique el código siguiente para que el proceso hijo
ejecute el comando ps -l, al recibir una señal reservada para el
usuario (SIGUSR1).
¿Qué diferencias hay entre los procesos en ejecución antes y después del cambio de imagen
del proceso actual?
Nota: para poder ejecutar el comando ps -l antes del cambio de imagen, no se olvide de ejecutar
el programa en segundo plano (./nombrePrograma &).
*/

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


/*

Antes de hacer el cambio de imagen del proceso hijo, el padre y el hijo tenian el mismo contexto, además el ppid del hijo es el pid del proceso main.
Tras hacer el cambio de imagen del proceso hijo, el contexto del hijo cambia, sin afectar al contexto del proceso padre. Además cambian las instrucciones a seguir del proceso hijo, cambiandose a
las instrucciones del proceso "ls -l".


*/
