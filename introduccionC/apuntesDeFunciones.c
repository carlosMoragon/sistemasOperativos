#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Para ejecutar el codigo y pasarle un parametro.

//./apuntesDeFunciones

//argsc = numero de argumentos + 1

//argv[0] = ./apuntesDeFunciones
//argv[1] = Azul
void main(int argsc, char * argv[]){
	
	if(argsc < 2)
	{
		printf("Error, falta clave de acceso\n");
		exit(0);
	}
	else
	{
		//strcmp() -> t devuelve 0 si son iguales
		if(!strcmp(argv[1], "Azul")){
		
			printf("Acceso al programa...\n");
		}
		else
		{
			printf("Acceso denegado\n");
			exit(0);
		}
		
	}
	
	

}
