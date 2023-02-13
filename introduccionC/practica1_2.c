#include <stdio.h>
#include <stdlib.h>

#define mult(n, m) atoi(n) * atoi(m)
void main(int argc, char *argv[]){
	
	if(argc == 3){
		printf("%s * %s = %d\n", argv[1], argv[2], mult(argv[1], argv[2]));
	}else{
		printf("Error. Error en los parametros al ejecutar el programa");
	}
}

