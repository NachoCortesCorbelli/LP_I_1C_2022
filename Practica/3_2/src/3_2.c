/*
 ============================================================================
 Name        : 3_2.c
 Author      : Cortés Corbelli, Ignacio Martín
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Crear una función que permita determinar si un número es par o
  	  	  	   no. La función retorna 1 en caso afirmativo y 0 en caso contrario.
  	  	  	   Probar en el main.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int esPar(int);

int main(void) {

	int numero;

	printf("\nIngrese un numero: ");
	scanf("%d",&numero);

	if(esPar(numero) == 1)
	{
		printf("\nES PAR");
	}
	else
	{
		printf("\nNO ES PAR");
	}

	return EXIT_SUCCESS;

}
int esPar(int numero)
{
	int retorno;
	retorno = 0;
	if(numero%2==0)
	{
		retorno = 1;
	}
	return retorno;
}
