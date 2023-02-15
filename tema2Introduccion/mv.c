#include <stdio.h>
#include <fcntl.h>

void main(int argc, char *argv[]){
	if(argc == 3){
		int fd = open(argv[1], O_CREAT|O_RDWR, 0666);
		
	}else printf("Error en los parametros.") ;
}


