/*
 ============================================================================
 Name        : 4_1.c
 Author      : Cortés Corbelli, Ignacio Martín
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Realizar un programa EN EL MAIN que permita calcular y mostrar
  	  	  	   el factorial de un número. Utilizar la función PedirNumero de
  	  	  	   la ejercitación 3-4.
			   Por ejemplo:
			   5! = 5*4*3*2*1 = 120
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int ingresoDeNumero(int,int);
int factorial(int);

int main(void)
{

	int numero;
	int resultado;

	numero = ingresoDeNumero(0,100);
	resultado = factorial(numero);//realiza el factorial hasta el 12(por ser solo int)
	printf("\nEl factorial es: %d",resultado);

	return EXIT_SUCCESS;

}

int factorial(int numero)
{
	if(numero == 0)
	{
		numero = 1;
	}
	else
	{
		for(int i = numero;i>0;i--)
		{
			if((i-1)!=0)
			{
				numero = numero * (i-1);
			}
		}
	}
	return numero;
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
