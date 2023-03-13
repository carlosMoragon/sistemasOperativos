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
	pthread_t th_a, th_b, th_c, th_d, th_e, th_f, th_g, th_h;
	
	pthread_create(&th_a, NULL, process, "a");
	pthread_create(&th_b, NULL, process, "b");
	pthread_create(&th_c, NULL, process, "c");
	pthread_create(&th_d, NULL, process, "d");
	pthread_create(&th_e, NULL, process, "e");
	pthread_create(&th_f, NULL, process, "f");
	pthread_create(&th_g, NULL, process, "g");
	pthread_create(&th_h, NULL, process, "h");
	
	sleep(1);
}

