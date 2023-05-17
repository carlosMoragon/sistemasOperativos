#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static void error(char* mensaje) {
 	fprintf(stderr, "%s", mensaje);
 	exit(1);
}

int main(int argc, char* argv[]) {
	int f;
	char c;
	off_t pos;
	if (argc != 4)
		error("Error en los argumentos\n");
	if ((f = open(argv[1], O_RDWR)) < 0) error("Error en el origen\n");
	if (lseek(f, pos = atoi(argv[2]), SEEK_SET) < 0) error("Error en el posicionamiento\n");
	if (write(f, argv[3], 1) != 1) error("Error de escritura\n");
	
	printf("%s[%ld]= %c (%x hex)\n", argv[1], pos, c, c);
	exit(0); 
}

/*

Salida:

carlosmoragon@ubuntu:~/ceu/sistemasOperativos/practicaMemoria$ ./ejercicio4-1 prueba.txt 3 a
prueba.txt[3]= O (4f hex)
carlosmoragon@ubuntu:~/ceu/sistemasOperativos/practicaMemoria$ cat prueba.txt
HELaO WORLD

*/
