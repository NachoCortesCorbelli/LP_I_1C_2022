/*
 ============================================================================
 Name        : 1_3.c
 Author      : Cortés Corbelli, Ignacio Martín
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Ejercicio 1-3: ingresar 3 números y mostrar el número del medio,
  	  	  	   sólo si existe. En caso de que no exista también informarlo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	int number[3];

	for(int i=0;i<3;i++)
	{
		printf("\nIngrese un numero: ");
		scanf("%d",&number[i]);
	}

	if( (number[0] > number[1] && number[0] < number[2]) ||
		(number[0] < number[1] && number[0] > number[2]) )
	{
		printf("\nEL NUMERO DEL MEDIO ES: %d",number[0]);
	}
	else if( (number[1] > number[0] && number[1] < number[2]) ||
			 (number[1] < number[0] && number[1] > number[2]) )
	{
		printf("\nEL NUMERO DEL MEDIO ES: %d",number[1]);
	}
	else if((number[2] > number[0] && number[2] < number[1]) ||
			(number[2] < number[0] && number[2] > number[1]))
	{
		printf("\nEL NUMERO DEL MEDIO ES: %d",number[2]);
	}
	else
	{
		printf("\nNO HAY NUMERO DEL MEDIO");
	}
	return EXIT_SUCCESS;

}
