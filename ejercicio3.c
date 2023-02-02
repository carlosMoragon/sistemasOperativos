#include <stdio.h> 
void main(void) { 
	//DECLARAMOS UNA VARIABLE TIPO int LLAMADA edad.
	int edad = 20;
	
	//Creamos un puntero tipo int inicializandolo con la dirección de memoria de la variable edad.
	int* pEdad = &edad;  
	
	//Imprimimos el valor de la variable edad.
	printf("%d\n", edad); 
	//Imprimimos la dirección de memoria de la variable edad.
	printf("%p\n", &edad); 
	//Imprimimos el valor del puntero, que en este caso es la dirección de memoria de la variable edad.
	printf("%p\n", pEdad);
	//Imprimimos el valor situado en la direccion donde está posicionado el puntero.
	printf("%d\n", *pEdad); 
} 
