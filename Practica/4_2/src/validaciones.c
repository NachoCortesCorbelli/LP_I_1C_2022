/*
 * validaciones.c
 *
 *  Created on: 9 abr. 2022
 *      Author: nacho
 */
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

/*
 * En la escala Centígrada, el agua se congela a 0° y hierve a 100°.
 * En la escala Fahrenheit, el agua se congela a 32° y hierve a 212°.*/
int esCelcius(float temperatura)
{
	int retorno;
	retorno = 0;
	if(temperatura >= 0 || temperatura <= 100 )
	{
		retorno = 1;
	}
	return retorno;
}
int esFahrenheit(float temperatura)
{
	int retorno;
	retorno = 0;
	if(temperatura >= 32 || temperatura <= 212 )
	{
		retorno = 1;
	}
	return retorno;
}
