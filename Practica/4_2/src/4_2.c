/*
 ============================================================================
 Name        : 4_2.c
 Author      : Cortés Corbelli, Ignacio Martín
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Realizar un programa que permita la carga de temperaturas en
  	  	  	   celsius y fahrenheit , validando que las temperaturas ingresadas
  	  	  	   estén entre el punto de congelación y ebullición del agua para
  	  	  	   cada tipo de escala.
			   Las validaciones se hacen en una biblioteca.
			   Las funciones de transformación de fahrenheit a celsius y de
			   celsius a fahrenheit se hacen en otra biblioteca.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "validaciones.h"

int main(void) {

	float celsius;
	float fahrenheit;

	do
	{
		printf("\nIngrese Celisius: ");
		scanf("%f",&celsius);
	}while(!esCelcius(celsius));
	fahrenheit = celsiusToFahrenheit(celsius);
	printf("\nCelsius: %.2f",celsius);
	printf("\nFahrenheit: %.2f",fahrenheit);
	do
	{
		printf("\nIngrese Fahrenheit: ");
		scanf("%f",&fahrenheit);
	}while(!esFahrenheit(fahrenheit));
	celsius = fahrenheitToCelsius(fahrenheit);
	printf("\nFahrenheit: %.2f",fahrenheit);
	printf("\nCelsius: %.2f",celsius);

	return EXIT_SUCCESS;

}
