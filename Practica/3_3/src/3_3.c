/*
 ============================================================================
 Name        : 3_3.c
 Author      : Cortés Corbelli, Ignacio Martín
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Crear una función que pida el ingreso de un entero y lo retorne.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int ingresoDeNumero();

int main(void) {

	int numero;

	numero = ingresoDeNumero();

	printf("\nEl numero ingresado es: %d",numero);

	return EXIT_SUCCESS;

}

int ingresoDeNumero()
{
	int numero;

	printf("\nINGRESE UN NUMERO: ");
	scanf("%d",&numero);

	return numero;
}
