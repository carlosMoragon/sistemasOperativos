#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#define mult(n, m) atoi(n) * atoi(m)
void main(int argc, char *argv[]){
	
	if(argc == 3){
		printf("%s * %s = %d\n", argv[1], argv[2], mult(argv[1], argv[2]));
	}else{
		printf("Error. Error en los parametros al ejecutar el programa");
	}
}
/*
#define mult(n, m) atof(n) * atof(m)
void main(int argc, char *argv[]){
	
	if(argc == 3){
		if(!((strcmp(argv[1], "0") || strcmp(argv[2], "0")) && mult(argv[1], argv[2])))
			printf("Error añadido algo raro");
		else 
			printf("%s * %s = %f\n", argv[1], argv[2], mult(argv[1], argv[2]));
	}else
		printf("Error. Error en los parametros al ejecutar el programa");
}*/
