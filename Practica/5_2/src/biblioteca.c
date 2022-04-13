/*
 * biblioteca.c
 *
 *  Created on: 12 abr. 2022
 *      Author: nacho
 */
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

void mostrar_vectorNumerico(int vector[],int tamanoVector)
{
	printf("\nNUMEROS INGRESADOS: ");
	for(int i=0;i<tamanoVector;i++)
	{
		printf("%d ",vector[i]);
	}
}
void mostrar_numerosPares(int vector[],int tamanoVector)
{
	printf("\nNUMEROS PARES: ");
	for(int i=0;i<tamanoVector;i++)
	{
		if(vector[i]%2==0)
		{
			printf("%d ",vector[i]);
		}
	}
}
void mostrar_posicionNumerosImpares(int vector[],int tamanoVector)
{
	printf("\nLOS IMPARES SE ENCUENTRAN EN LAS POSICIONES: ");
	for(int i=0;i<tamanoVector;i++)
	{
		if(vector[i]%2!=0)
		{
			printf("%d ",i);
		}
	}
}
int pideNumero(int min,int max)
{
	int numero;
	do
	{
		printf("\nINGRESE UN NUMERO QUE ESTÉ ENTRE EL %d Y EL %d: ",min,max);
		scanf("%d",&numero);
		if(numero < min || numero > max)
		{
			printf("\nINGRESE UN NUMERO QUE ESTÉ DENTRO DEL RANGO");
		}
	}while(numero < min || numero > max);
	return numero;
}
int contador_Positivos(int vector[],int tamanoVector)
{
	int contadorPositivos = 0;
	for(int i=0;i<tamanoVector;i++)
	{
		if(vector[i]>0)
		{
			contadorPositivos++;
		}
	}
	return contadorPositivos;
}
int contador_Negativos(int vector[],int tamanoVector)
{
	int contadorNegativos = 0;
	for(int i=0;i<tamanoVector;i++)
	{
		if(vector[i]<0)
		{
			contadorNegativos++;
		}
	}
	return contadorNegativos;
}
int sumador_Pares(int vector[],int tamanoVector)
{
	int sumatoriaPares = 0;
	for(int i=0;i<tamanoVector;i++)
	{
		if(vector[i]%2==0)
		{
			sumatoriaPares+=vector[i];
		}
	}
	return sumatoriaPares;
}
int mayor_Impar(int vector[],int tamanoVector,int* pMayorImpar)
{
	int resultado = -1;
	int auxImpar;
	for(int i=0;i<tamanoVector;i++)
	{
		if( (resultado == -1 && vector[i]%2!=0) ||
			(vector[i]%2!=0 && vector[i] > auxImpar) )
		{
			auxImpar = vector[i];
			resultado = 0;
		}
	}
	if(resultado == 0)
	{
		*pMayorImpar = auxImpar;
	}
	return resultado;
}
