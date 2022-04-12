/*
 ============================================================================
 Name        : 2_1.c
 Author      : Cortés Corbelli, Ignacio Martín
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Ingresar 5 números enteros calcular y mostrar el promedio de
 	 	 	   los números. Probar la aplicación con distintos valores.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int number;
	int accumulator;
	float average;

	accumulator = 0;

	for(int i=0;i<5;i++)
	{
		printf("\nINGRESE UN NUMERO: ");
		scanf("%d", &number);
		accumulator += number;
	}

	average = (float)accumulator/5;

	printf("\nEL PROMEDIO ES: %.2f", average);

	return EXIT_SUCCESS;
}
