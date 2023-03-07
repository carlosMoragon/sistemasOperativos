#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

/*
Cada proceso debe imprimir su PID y su PPID.
¿En qué orden se imprimen los mensajes?
*/

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


/*
Se imprime primero el proceso main, debido a que imprime por pantalla antes de crear a su proceso hijo. Después imprime el proceso hijo del main (proceso P1), debido a que todavia no se a creado el
proceso hijo de P1, por lo cual se sigue el orden. Por último, se imprime el proceso P2, debido a que los otros ya han impreso por pantalla, y P2 ha sido el último en ser creado.
*/
