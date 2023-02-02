#include <stdio.h>

void main(void){
	int x[2];
	x[0] = 1;
	x[1] = 2;
	
	int *px = x;
	
	printf("%d\a", *px);
	px = px + 1;
	printf("\t %d\a", *px);
	
	struct altura{
		char nombre[100];
		float h;
	};
	
	struct altura persona, *p;
	
	p = &persona;
	p-> h = 1.65;
	
//	typedef int entero; cambiar el nombre de una variable (de int a 'entero')
}
