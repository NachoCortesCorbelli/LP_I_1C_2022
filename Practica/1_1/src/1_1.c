/*
 ============================================================================
 Name        : 1_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int number1;
	int number2;
	int result;

	printf("\nINGRESE NUMERO: ");
	scanf("%d",&number1);
	printf("\nINGRESE NUMERO: ");
	scanf("%d",&number2);
	result = number1 + number2;
	printf("\nLA SUMA ENTRE %d y %d DA COMO RESULTADO: %d", number1, number2, result);
	return EXIT_SUCCESS;
}
