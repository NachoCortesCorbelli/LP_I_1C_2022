/*
 ============================================================================
 Name        : 5_1.c
 Author      : Cortés Corbelli, Ignacio Martín
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Pedir el ingreso de 5 números. Mostrarlos, calcular y mostrar
 	 	 	   la sumatoria de los mismos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int vector[5];
	int acumulador;

	acumulador = 0;

	for(int i=0;i<5;i++)
	{
		printf("\nINGRESE UN NUMERO: ");
		scanf("%d",&vector[i]);
		acumulador += vector[i];
	}
	for(int i=0;i<5;i++)
	{
		printf("%d ",vector[i]);
	}
	printf("\nSUMATORIA: %d",acumulador);

	return EXIT_SUCCESS;
}
