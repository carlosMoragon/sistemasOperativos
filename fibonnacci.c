#include <stdio.h>

int fibonnacci(int n){

	if (n < 3)
		return 1;
	else return fibonnacci(n-1) + fibonnacci(n-2);
}


void main(){
	int n;
	scanf("%d", &n);
	printf("El fibonnacci de %d es: %d",n, fibonnacci(n));
	
	for(int i = 0; i < 10; i++)
	printf("\n%d", i);
}
