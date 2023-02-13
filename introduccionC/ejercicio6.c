
/*
Ejercicio 6. Cree un programa que pida un nombre y un número al
usuario (con scanf y dos llamadas) y lo imprima por pantalla. -
NUEVO
*/

# include <stdio.h>

void main(){
	char nombre[20];
	int numero;
	
	/*
	parametros de scanf -> scanf("los datos que vas a pedir", dir_variable1, dir_variable2, dir_variable3, ...)
	*/
	scanf("%s %d", nombre, &numero);
	
	printf("%s %d", nombre, numero);

}
