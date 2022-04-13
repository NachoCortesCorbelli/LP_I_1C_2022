/*
 ============================================================================
 Name        : 5_2.c
 Author      : Cortés Corbelli, Ignacio Martín
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Pedir el ingreso de 10 números enteros entre -1000 y 1000.
 	 	 	   Determinar:
			   Cantidad de positivos y negativos.
			   Sumatoria de los pares.
			   El mayor de los impares.
			   Listado de los números ingresados.
			   Listado de los números pares.
			   Listado de los números de las posiciones impares.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(void) {

	int vector[10];
	int contadorPositivos;
	int contadorNegativos;
	int sumatoriaPares;
	int mayorImpar;

	sumatoriaPares = 0;

	for(int i=0;i<10;i++)
	{
		vector[i] = pideNumero(-1000, 1000);
	}

	mostrar_vectorNumerico(vector, 10);

	contadorPositivos = contador_Positivos(vector, 10);
	printf("\nHAY %d NUMEROS POSITIVOS",contadorPositivos);

	contadorNegativos = contador_Negativos(vector, 10);
	printf("\nHAY %d NUMEROS NEGATIVOS",contadorNegativos);

	sumatoriaPares = sumador_Pares(vector, 10);
	if(sumatoriaPares != 0)
	{
		mostrar_numerosPares(vector, 10);
		printf("\nLA SUMATORIA DE LOS PARES: %d",sumatoriaPares);
	}
	else
	{
		printf("\nNO HAY PARES");
	}

	if(!mayor_Impar(vector, 10, &mayorImpar))
	{
		mostrar_posicionNumerosImpares(vector, 10);
		printf("\nEL MAYOR IMPAR ES: %d",mayorImpar);
	}
	else
	{
		printf("\nNO HAY IMPARES");
	}

	return EXIT_SUCCESS;

}
