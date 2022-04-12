/*
 ============================================================================
 Name        : 2_3.c
 Author      : Cortés Corbelli, Ignacio Martín
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Debemos alquilar el servicio de transporte para llegar a Mar del
  	  	  	   Plata con un grupo de personas, de cada persona debemos obtener los siguientes datos:
			   número de cliente, estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
			   edad( solo mayores de edad, más de 17),
			   temperatura corporal (validar por favor)
			   y genero('f' para femenino, 'm' para masculino, 'o' para no binario).
			   NOTA: El precio por pasajero es de $600.
			   Se debe informar (solo si corresponde):
			   a) La cantidad de personas con estado "viudo" de más de 60 años.
			   b) el número de cliente y edad de la mujer soltera más joven.
			   c) cuánto sale el viaje total sin descuento.
			   d) si hay más del 50% de los pasajeros que tiene más de 60 años ,
			      el precio final tiene un descuento del 25%, que solo mostramos si corresponde.
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>

int main(void) {

	int numeroCliente;
	int edad;
	int edadSolteraJoven;
	int numeroClienteSolteraJoven;
	int cantPersona;
	int cantPersonaMayor;
	int cantViudoMayor;
	int flagSolteraJoven;
	char estadoCivil;
	char genero;
	char seguir;
	float precioTotalConDescuento;
	float temperatura;


	flagSolteraJoven=0;
	cantPersona=0;
	cantPersonaMayor=0;
	cantViudoMayor=0;

	do
	{
		printf("\nIngrese numero de Cliente: ");
		scanf("%d",&numeroCliente);
		do
		{
			printf("\nIngrese estado Civil(s,c,v):");
			scanf(" %c",&estadoCivil);
			if(estadoCivil != 's' &&
			   estadoCivil != 'c' &&
		       estadoCivil != 'v')
			{
				printf("\nReingrese nuevamente");
			}
		}while(estadoCivil != 's' &&
			   estadoCivil != 'c' &&
			   estadoCivil != 'v');
		do
		{
			printf("\nIngrese la edad del cliente: ");
			scanf("%d",&edad);
			if(edad >= 17)
			{
				if(edad > 60)
				{
					cantPersonaMayor++;
					if(estadoCivil == 'v')
					{
						cantViudoMayor++;
					}
				}
				else
				{
					cantPersona++;
				}
			}
			else
			{
				printf("\nReingrese nuevamente");
			}
		}while(edad < 17);
		do
		{
			printf("\nIngrese la temperatura del cliente: ");
			scanf("%f",&temperatura);
			if(temperatura < 36.1 || temperatura > 37.2)
			{
				printf("\nReingrese nuevamente");
			}
		}while(temperatura < 36.1 || temperatura > 37.2);
		do
		{
			printf("\nIngrese el genero del Cliente(m,f,o): ");
			__fpurge(stdin);
			scanf("%c",&genero);
			if(genero != 'm' &&
			   genero != 'f' &&
			   genero != 'o')
			{
				printf("\nReingrese nuevamente");
			}
		}while(genero != 'm' &&
			   genero != 'f' &&
			   genero != 'o');

		if( genero == 'f' &&
			estadoCivil == 's')
		{
			if(flagSolteraJoven == 0)
			{
				flagSolteraJoven = 1;
				edadSolteraJoven = edad;
				numeroClienteSolteraJoven = numeroCliente;
			}
			else if(flagSolteraJoven == 1 &&
					edad < edadSolteraJoven)
			{
				edadSolteraJoven = edad;
				numeroClienteSolteraJoven = numeroCliente;
			}

		}
		printf("\nDesea seguir ingresando Clientes?(s/n)");
		scanf(" %c",&seguir);
	}while(seguir == 's');

	if(cantViudoMayor > 0)
	{
		printf("\na)Hay %d viudos mayores de 60",cantViudoMayor);
	}
	else
	{
		printf("\na)No hay viudos mayores de 60");
	}

	if(flagSolteraJoven == 1)
	{
		printf("\nb)La mujer soltera mas joven tiene %d años y su numero de cliente es: %d",edadSolteraJoven,numeroClienteSolteraJoven);
	}
	else
	{
		printf("\nb)No hay mujer soltera joven");
	}

	if(cantPersona > 0)
	{
		printf("\nc)El total del viaje sin descuento tiene un valor de %d",cantPersona*600);
	}
	else
	{
		printf("\nc)No se insctibió nadie al viaje");
	}

	if(cantPersonaMayor > (cantPersona / 2) )
	{
		precioTotalConDescuento = (float)(cantPersona*600)-(cantPersona*0.25);
		printf("\nd)El total del viaje c/ descuento tiene un valor de: %.2f",precioTotalConDescuento);
	}
	else
	{
		printf("\nd)No hay viaje con descuento");
	}

	return EXIT_SUCCESS;

}














