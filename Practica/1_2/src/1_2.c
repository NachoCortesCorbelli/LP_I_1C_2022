/*
 ============================================================================
 Name        : 1_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int number;
	int max;
	int index;
	for(int i=0;i<3;i++)
	{
		printf("\nIngrese un numero: ");
		scanf("%d",&number);
		if(i == 0 || number > max)
		{
			max = number;
			index = i+1;
		}
	}
	switch(index)
	{
		case 1:
			printf("\nEL MAYOR DE LOS NUMEROS ES EL PRIMERO");
			break;
		case 2:
			printf("\nEL MAYOR DE LOS NUMEROS ES EL SEGUNDO");
			break;
		case 3:
			printf("\nEL MAYOR DE LOS NUMEROS ES EL TERCERO");
			break;
	}
	return EXIT_SUCCESS;
}
