/*
Ejercicio 8. Dado el siguiente programa, explique los mensajes que
se mostrarán por pantalla. Además, indique a qué función se le
pasan los argumentos por valor y por referencia.
*/

#include<stdio.h>

void func1(int u, int v); /*Prototipo de la función func1*/

void func2(int *pu, int *pv); /*Prototipo de la función func2*/

void main(void){
	int u=1;
	int v=3;
	printf("\nAntes de la llamada a func1: u=%d v=%d", u, v);
	func1(u,v);
	printf("\nDespués de la llamada a func1: u=%d v=%d", u, v);
	printf("\nAntes de la llamada a func2: u=%d v=%d", u, v);
	func2(&u,&v);
	printf("\nDespués de la llamada a func2: u=%d v=%d", u, v);
}

void func1(int u, int v){
	u=0;
	v=0;
	printf("\nDentro de func1: u=%d v=%d", u, v);
	return;
}

void func2(int *pu, int *pv){
	*pu=0;
	*pv=0;
	printf("\nDentro de func2: *pu=%d *pv=%d", *pu, *pv);
	return;
}

//EXPLICACIÓN:

/*

SALIDA POR PANTALLA:

----

Antes de la llamada a func1: u=1 v=3
Dentro de func1: u=0 v=0
Después de la llamada a func1: u=1 v=3
Antes de la llamada a func2: u=1 v=3
Dentro de func2: *pu=0 *pv=0
Después de la llamada a func2: u=0 v=0

----


A la función "func1" se le pasa por argumentos el valor de las variables "u" y "v", y no una referencia a dichas variables, por lo cual al variar el valor de los argumentos no varia el valor de
las variables originales.

Por otro lado, a la función func2 se le pasa por parametro una referencia a las variables "u" y "v", debido a que se le asigna la dirección de dichas variables a 2 punteros. Cuando hacen cambios
en los argumentos también cambian los originales.

*/
