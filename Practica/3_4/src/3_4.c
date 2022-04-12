/*
 ============================================================================
 Name        : 3_4.c
 Author      : Cortés Corbelli, Ignacio Martín
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Especializar la función anterior para que permita validar el
  	  	  	   entero ingresado en un rango determinado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int ingresoDeNumero(int,int);

int main(void) {

	int numero;

	numero = ingresoDeNumero(5,15);

	printf("\nEl numero ingresado es: %d",numero);

	return EXIT_SUCCESS;

}

int ingresoDeNumero(int min,int max)
{
	int numero;
	do
	{
		printf("\nINGRESE UN NUMERO: ");
		scanf("%d",&numero);
		if(numero < min || numero > max)
		{
			printf("\nNO RESPETA LOS VALORES PASADOS POR PARAMETRO");
		}
	}while(numero < min || numero > max);
	return numero;
}
