/*
 ============================================================================
 Name        : 2_4.c
 Author      : Cortés Corbelli, Ignacio Martín
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Ingresar 5 caracteres e informar cuantas letras p (minúsculas)
  	  	  	   se ingresaron.
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>

int main(void) {

	char letra;
	char contadorP;

	contadorP = 0;

	for(int i=0;i<5;i++)
	{
		__fpurge(stdin);
		printf("\nINGRESE UNA LETRA: ");
		scanf("%c",&letra);
		if(letra == 'p')
		{
			contadorP++;
		}
	}

	if(contadorP > 0)
	{
		printf("\nHay %d p",contadorP);
	}
	else
	{
		printf("\nNo hubo p");
	}


	return EXIT_SUCCESS;
}
