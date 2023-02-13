#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]){
	int var;
	scanf("%d", &var);
	while(var != 0){
		restar(&var);
		sleep(1);
		printf("%d\n", var);

	}

}

void restar(int *pn){
	*pn = *pn -1;
}
