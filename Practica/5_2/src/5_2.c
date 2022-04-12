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

int main(void) {

	int vector[10];
	int contadorPositivos;
	int contadorNegativos;
	int sumatoriaPares;
	int mayorImpar;
	int flagImpar;

	flagImpar = 0;
	sumatoriaPares = 0;
	contadorPositivos = 0;
	contadorNegativos = 0;

	for(int i=0;i<10;i++)
	{
		do
		{
			printf("\nINGRESE UN NUMERO ENTRE -1000 y 1000: ");
			scanf("%d",&vector[i]);
		}while(vector[i]<-1000 || vector[i]>1000);
		if(vector[i]>0)
		{
			contadorPositivos++;
		}
		if(vector[i]<0)
		{
			contadorNegativos++;
		}
		if(vector[i]%2==0)
		{
			sumatoriaPares+=vector[i];
		}
		if(flagImpar == 0 || (vector[i]%2!=0 && vector[i] > mayorImpar) )
		{
			mayorImpar = vector[i];
			flagImpar = 1;
		}
	}
	printf("\nNUMEROS INGRESADOS: ");
	for(int i=0;i<10;i++)
	{
		printf("%d ",vector[i]);
	}
	printf("\nHAY %d NUMEROS POSITIVOS",contadorPositivos);
	printf("\nHAY %d NUMEROS NEGATIVOS",contadorNegativos);
	if(sumatoriaPares > 0)
	{
		printf("\nNUMEROS PARES: ");
		for(int i=0;i<10;i++)
		{
			if(vector[i]%2==0)
			{
				printf("%d ",vector[i]);
			}
		}
		printf("\nLA SUMATORIA DE LOS PARES: %d",sumatoriaPares);
	}
	else
	{
		printf("\nNO HAY NUMEROS PARES");
	}
	if(flagImpar == 1)
	{
		printf("\nPOSICIONES EN DONDE HAY NUMEROS IMPARES: ");
		for(int i=0;i<10;i++)
		{
			if(vector[i]%2!=0)
			{
				printf("%d ",i);
			}
		}
		printf("\nEL MAYOR DE LOS IMPARES: %d",mayorImpar);
	}
	else
	{
		printf("\nNO HAY NUMEROS IMPARES");
	}

	return EXIT_SUCCESS;

}
