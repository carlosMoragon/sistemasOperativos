#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>

void main (void){
	int variable = 0;
	for(int i = 0; i<4; i++){
	
		if(fork()== 0){
		
			//printf("Soy el proceso %d y mi padre es %d \n",getpid(), getppid()); 
			
			if(i > 1){
			
				if(fork() == 0){
				
					//printf("Soy el proceso %d y mi padre es %d \n",getpid(), getppid()); 
					printf("Proceso P%d: variable: %d\n", getpid(), variable);
					exit(0);
					
				}
				
			}
			
			if(i<3) variable++;
			
			if(i==3) execl("/bin/ls", "ls", (char*) 0);
			
			while(wait(NULL)>0);
			
			printf("Proceso P%d: variable: %d\n", getpid(), variable);
			exit(0);
		}
	}
	
	while(wait(NULL)>0);
}

/*
a)

b) No se puede saber el proceso que se ejecutara antes debido a que su ejecución es aleatoria.

c) El valor final de la variable en los proceso P1, P2 y P3 es '1', esto se debe a que nacen del proceso main el cual nunca se incrementa el valor de la variable, y nacen con el valor de la variable igual a 0. Por otro el P5 recibe el valor de la variable de P3, pero como el incremento de dicha variable se hace después de crear el hijo, imprime el valor 0.

*/
