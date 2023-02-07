#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

void main(int argc, char *argv[]){
	int var;
	scanf("%d", &var);
	while(var != 0){
		restar(&var);
		printf("%d\n", var);
	}

}

void restar(int *pn){
	*pn = *pn -1;
}
