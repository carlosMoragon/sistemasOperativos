#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wait.h>

/*

Ejercicio 5. Explique la finalidad y los parámetros de la función
execl() y el comportamiento del proceso tras la llamada a dicha
función

*/

int main(int argc, char *argv[]){
	int rt;
	rt=fork();
	
	
	if (rt==0) execl("/bin/ls","ls","-l",(char*)0);
	
	while (wait(NULL)>0);
}

/*

Los parámetros de la función execl(), son los siguientes:
	- El path del fichero que va a ser ejecutado. En este caso "/bin/ls".
	- El nombre de la llamada al sistema
	- Extension de la llamada al sistema
	- Un puntero NULL, para terminar la lista de argumentos.

El comportamiento del proceso tras llamar a la función execl cambia al comportamiento que se le indica en el fichero indicado como primer parámetro.

*/

