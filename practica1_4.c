#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]){
	
	if(argc == 2){
		int primo = atoi(argv[1]) != 0;
		for(int i = 2; i < atoi(argv[1]); i++){
			if(atoi(argv[1])%i == 0){
				primo = 0;
				break;
			}
		}
		if(primo)
			printf("EL numero %s es primo\n", argv[1]);
		else
			printf("EL numero %s no es primo\n", argv[1]);
	}else printf("Fallo en los parametros. Por favor inserta un número\n");
}

