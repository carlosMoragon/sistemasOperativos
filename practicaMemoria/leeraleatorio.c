#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static void error(char* mensaje) {
 	fprintf(stderr, "%s", mensaje);
 	exit(1);
}

int main(int argc, char* argv[]) {
	int f;
	char c;
	off_t pos;
	if (argc != 3)
		error("Error en los argumentos\n");
	if ((f = open(argv[1], O_RDONLY)) < 0) error("Error en el origen\n");
	if (lseek(f, pos = atoi(argv[2]), SEEK_SET) < 0) error("Error en el posicionamiento\n");
	if (read(f, &c, 1) != 1)
		error("Error de lectura\n");
	printf("%s[%ld]= %c (%x hex)\n", argv[1], pos, c, c);
	exit(0); 
}
