/*
 * biblioteca.c
 *
 *  Created on: 9 abr. 2022
 *      Author: nacho
 */

#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Para convertir de ºC a ºF use la fórmula:   ºF = ºC x 1.8 + 32.
 * Para convertir de ºF a ºC use la fórmula:   ºC = (ºF-32) ÷ 1.8.
 * */
float fahrenheitToCelsius(float fahrenheit)
{
	float celsius;
	return celsius = (fahrenheit- 32) / 1.8;
}
float celsiusToFahrenheit(float celsius)
{
	float fahrenheit;
	return fahrenheit = (celsius*1.8) + 32;
}
