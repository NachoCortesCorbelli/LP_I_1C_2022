/*
 ============================================================================
 Name        : 2_2.c
 Author      : Cortés Corbelli, Ignacio Martín
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Ingresar 10 números enteros, distintos de cero. Mostrar:
			   a)Cantidad de pares e impares.
			   b)El menor número ingresado.
			   c)De los pares el mayor número ingresado.
			   d)Suma de los positivos.
			   e)Producto de los negativos.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int numbers[10];
	int counterEvenNumber;//par
	int counterOddNumber;//impar
	int counterNegatives;
	int smallestNumber;
	int biggestEvenNumber;
	int auxEvenNumber;
	int sumOfPositives;
	int productOfNegatives;
	int flag;
	int flagNegatives;

	flag = 0;
	counterNegatives = 0;
	counterEvenNumber = 0;
	counterOddNumber = 0;
	sumOfPositives = 0;

	for(int i=0;i<10;i++)
	{
		do
		{
			printf("\nINGRESE UN NUMERO: ");
			scanf("%d",&numbers[i]);
			if(numbers[i] != 0)
			{
				if(numbers[i]>0)
				{
					sumOfPositives+=numbers[i];
				}
				else// if(numbers[i]<0)
				{
					counterNegatives++;
				}

				if(numbers[i]%2==0)
				{
					counterEvenNumber++;
				}
				else// if(numbers[i]%2!=0)
				{
					counterOddNumber++;
				}

				if(i == 0 || numbers[i] < numbers[i-1])
				{
					smallestNumber = numbers[i];
				}
			}
			else
			{
				printf("\nNO SE PUEDE INGRESAR 0"
					   "\nREINGRESELO NUEVAMENTE");
			}

		}while(numbers[i]==0);
	}

	if(counterEvenNumber > 0)
	{
		for(int i=0;i<10;i++)
		{
			if(numbers[i]%2==0)
			{
				if(flag == 1 &&
				   numbers[i] > auxEvenNumber)
				{
					biggestEvenNumber = auxEvenNumber;
				}
				else if(flag == 0)
				{
					flag = 1;
					auxEvenNumber = numbers[i];
				}
			}
		}
	}

	if(counterNegatives > 0)
	{
		for(int i=0;i<10;i++)
		{
			if(numbers[i] < 0)
			{
				if(flagNegatives == 1)
				{
					productOfNegatives *= numbers[i];
				}
				else if(flagNegatives == 0)
				{
					flagNegatives = 1;
					productOfNegatives = numbers[i];
				}
			}
		}
	}

	printf("\na)Cantidad de pares: %d, Cantidad de impares: %d"
		   "\nb)El menor numero ingresado: %d",counterEvenNumber, counterOddNumber, smallestNumber);
	if(counterEvenNumber > 0)
	{
		printf("\nc)De los pares el mayor numero ingresado es: %d",biggestEvenNumber);
	}
	else
	{
		printf("\nc)No hubo numeros pares");
	}
	printf("\nd)La suma de los positivos es: %d",sumOfPositives);
	if(counterNegatives > 0)
	{
		printf("\ne)El producto de los negativos es: %d",productOfNegatives);
	}
	else
	{
		printf("\ne)No hay numeros negativos");
	}


	return EXIT_SUCCESS;
}























