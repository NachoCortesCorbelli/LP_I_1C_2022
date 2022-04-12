/*
 ============================================================================
 Name        : 3_1.c
 Author      : Cortés Corbelli, Ignacio Martín
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Crear una función que muestre por pantalla el número flotante
   	   	   	   que recibe como parámetro.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void muestroFloat(float);

int main(void) {

	float flotante;

	flotante = 15.385;

	muestroFloat(flotante);

	return EXIT_SUCCESS;

}

void muestroFloat(float numero)
{
	printf("\nFlotante: %.3f",numero);
}
