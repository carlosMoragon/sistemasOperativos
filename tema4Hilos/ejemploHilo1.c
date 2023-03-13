#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void * process(void * args){
	printf("%s", (char *) args);
	fflush(stdout);
	pthread_exit(0);
}

int main(){
	pthread_t th_a, th_b;
	
	pthread_create(&th_a, NULL, process, "HELLO");
	pthread_create(&th_b, NULL, process, "WORLD");
	
	sleep(1);
}

