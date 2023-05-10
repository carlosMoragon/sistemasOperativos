#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int A;

void escribe(char* texto, void *dir) {
	printf("Dirección de %-4s = %10x\n", texto, (unsigned int)dir);
}

int main(void) {
	int B;
	int *C = malloc(0x1000);
	escribe ("main", main);
	escribe("A", &A);
	escribe ("B", &B);
	escribe ("C", C);
	sleep(1000);
	exit(0);
}

/*
SALIDAS:

Dirección de main =    a2ba1de	-> Se encuentra entre: (55fc0a2ba000-55fc0a2bb000) que constituye el espacio reservado para procesos/codigo
Dirección de A    =    a2bd014	-> Se encuentra entre: (55fc0a2bd000-55fc0a2be000) que constituye el espacio reservado para variables globales
Dirección de B    =   5ab6ddbc	-> Se encuentra entre: (7ffe5ab4e000-7ffe5ab6f000) que constituye el espacio reservado para variables locales, es decir, en la pila.
Dirección de C    =    a3782a0	-> Se encuentra entre: (55fc0a378000-55fc0a399000) que constituye el espacio reservado para la reserva dinámica de variables.

cat /proc/3469/maps
55fc0a2b9000-55fc0a2ba000 r--p 00000000 08:05 685779                     /home/carlosmoragon/ceu/sistemasOperativos/practicaMemoria/direcciones
55fc0a2ba000-55fc0a2bb000 r-xp 00001000 08:05 685779                     /home/carlosmoragon/ceu/sistemasOperativos/practicaMemoria/direcciones	-> Código (MAIN) -> permisos de ejecución y lectura
55fc0a2bb000-55fc0a2bc000 r--p 00002000 08:05 685779                     /home/carlosmoragon/ceu/sistemasOperativos/practicaMemoria/direcciones
55fc0a2bc000-55fc0a2bd000 r--p 00002000 08:05 685779                     /home/carlosmoragon/ceu/sistemasOperativos/practicaMemoria/direcciones
55fc0a2bd000-55fc0a2be000 rw-p 00003000 08:05 685779                     /home/carlosmoragon/ceu/sistemasOperativos/practicaMemoria/direcciones	->variables globales-> permisos de escritura y lectura
55fc0a378000-55fc0a399000 rw-p 00000000 00:00 0                          [heap]	-> Reserva dinámica -> permisos de escritura y lectura
7f076f2fa000-7f076f31c000 r--p 00000000 08:05 526467                     /usr/lib/x86_64-linux-gnu/libc-2.31.so
7f076f31c000-7f076f494000 r-xp 00022000 08:05 526467                     /usr/lib/x86_64-linux-gnu/libc-2.31.so
7f076f494000-7f076f4e2000 r--p 0019a000 08:05 526467                     /usr/lib/x86_64-linux-gnu/libc-2.31.so
7f076f4e2000-7f076f4e6000 r--p 001e7000 08:05 526467                     /usr/lib/x86_64-linux-gnu/libc-2.31.so
7f076f4e6000-7f076f4e8000 rw-p 001eb000 08:05 526467                     /usr/lib/x86_64-linux-gnu/libc-2.31.so
7f076f4e8000-7f076f4ee000 rw-p 00000000 00:00 0 
7f076f4fd000-7f076f4fe000 r--p 00000000 08:05 526462                     /usr/lib/x86_64-linux-gnu/ld-2.31.so
7f076f4fe000-7f076f521000 r-xp 00001000 08:05 526462                     /usr/lib/x86_64-linux-gnu/ld-2.31.so
7f076f521000-7f076f529000 r--p 00024000 08:05 526462                     /usr/lib/x86_64-linux-gnu/ld-2.31.so
7f076f52a000-7f076f52b000 r--p 0002c000 08:05 526462                     /usr/lib/x86_64-linux-gnu/ld-2.31.so
7f076f52b000-7f076f52c000 rw-p 0002d000 08:05 526462                     /usr/lib/x86_64-linux-gnu/ld-2.31.so
7f076f52c000-7f076f52d000 rw-p 00000000 00:00 0 
7ffe5ab4e000-7ffe5ab6f000 rw-p 00000000 00:00 0                          [stack]	-> variables locales -> permisos de escritura y lectura
7ffe5abe1000-7ffe5abe5000 r--p 00000000 00:00 0                          [vvar]
7ffe5abe5000-7ffe5abe7000 r-xp 00000000 00:00 0                          [vdso]
ffffffffff600000-ffffffffff601000 --xp 00000000 00:00 0                  [vsyscall]

*/

