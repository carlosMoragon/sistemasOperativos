#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#define MAX 6

sem_t sem_A;
sem_t sem_B;
sem_t sem_C;


void *escribirA(void *nada);

void *escribirB(void *nada);

void *escribirC(void *nada);

int main (int argc, char *argv[]) {

	sem_init(&sem_A, 0, 0);
	sem_init(&sem_B, 0, 0);
	sem_init(&sem_C, 0, 0);
	
	pthread_t th1, th2, th3;
	srandom(time(NULL));
	pthread_create(&th1, NULL, escribirA, NULL);
	pthread_create(&th2, NULL, escribirB, NULL);
	pthread_create(&th3, NULL, escribirC, NULL);
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	pthread_join(th3, NULL);
	return 0;
}

void *escribirA(void *nada){
	
	int num;
	for(num=0; num<MAX; num++){
		printf("A");
		fflush(stdout);
		sleep(random()%3);
		sem_post(&sem_B);
		sem_wait(&sem_A);
	}
	pthread_exit(NULL);

}

void *escribirB(void *nada){
	
	int num;
	for(num=0; num<MAX; num++){
		sem_wait(&sem_B);
		printf("B");
		fflush(stdout);
		sleep(random()%3);
		sem_post(&sem_C);
	}
	pthread_exit(NULL);
	
}

void *escribirC(void *nada){
	int num;
	for(num=0; num<MAX; num++){
	sem_wait(&sem_C);
	printf("C");
	fflush(stdout);
	sleep(random()%3);
	sem_post(&sem_A);
	}
	pthread_exit(NULL);
}
