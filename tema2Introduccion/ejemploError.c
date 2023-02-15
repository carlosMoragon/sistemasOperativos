#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


void main(){

	char buffer[100]	;
	int iden = 20;
	if(read(iden, buffer, 100) == -1) printf("\n%d: %s\n", errno, strerror(errno));
	
}
