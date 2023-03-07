#include <stdio.h>
#include <string.h>
#include <sys/types.h>

void main(){
	pid_t pid;
	pid = fork(); //fork() crea un proceso hijo
	
	if(pid != 0)
		printf("Soy padre con pid %d y ppid %d\n", getpid(), getppid());
	else printf("Soy hijo con pid %d y ppid %d\n", getpid(), getppid());
	
	//El padre devuelve el pid del hijo y el hijo devuelve 0.
}
