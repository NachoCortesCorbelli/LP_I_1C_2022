/*
 ============================================================================
 Name        : 3_5.c
 Author      : Cortés Corbelli, Ignacio Martín
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Realizar un programa en donde se puedan utilizar los prototipos
  	  	  	   de la función Sumar en sus 4 combinaciones. (Apunta a que entie-
  	  	  	   ndan el concepto de independencia del código)
			   int Sumar1(int, int);
			   int Sumar2(void);
			   void  Sumar3(int, int);
			   void Sumar4(void);
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int Sumar1(int, int);
int Sumar2(void);
void Sumar3(int, int);
void Sumar4(void);

int main(void)
{

	int operando1;
	int operando2;
	int resultado1;
	int resultado2;

	printf("\nINGRESE OPERANDO: ");
	scanf("%d",&operando1);
	printf("\nINGRESE OPERANDO: ");
	scanf("%d",&operando2);
	resultado1 = Sumar1(operando1,operando2);
	resultado2 = Sumar2();
	printf("\nSUMAR 1: %d",resultado1);
	printf("\nSUMAR 2: %d",resultado2);
	Sumar3(operando1,operando2);
	Sumar4();
	return EXIT_SUCCESS;
}
int Sumar1(int operando1, int operando2)
{
	return operando1 + operando2;
}
int Sumar2(void)
{
	int operando1;
	int operando2;
	printf("\nIngrese un numero: ");
	scanf("%d",&operando1);
	printf("\nIngrese un numero: ");
	scanf("%d",&operando2);
	return operando1 + operando2;
}
void Sumar3(int operando1, int operando2)
{
	int resultado;
	resultado = operando1 + operando2;
	printf("\nSUMAR 3: %d",resultado);
}
void Sumar4(void)
{
	int resultado;
	int operando1;
	int operando2;
	printf("\nIngrese un numero: ");
	scanf("%d",&operando1);
	printf("\nIngrese un numero: ");
	scanf("%d",&operando2);
	resultado = operando1 + operando2;
	printf("\nSUMAR 4: %d",resultado);
}

