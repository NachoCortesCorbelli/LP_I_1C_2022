/*
 * Parser.c
 *
 *  Created on: 28 jun. 2022
 *      Author: nacho
 */
#include <stdio.h>
#include <stdlib.h>
#include "Computer.h"
#include "utn.h"

/** \brief Parsea los datos de las computadoras desde el archivo data.csv (modo texto).
 * \param path char* la ruta del archivo
 * \param pArrayListComputer LinkedList* la linked list
 * \return int retorna 0 si pudo parsear -1,-2,-3 error
 */
int parser_ComputerFromText(FILE* pFile , LinkedList* pArrayListComputer)
{
	eComputer* pPassenger = NULL;
	char auxId[SIZE_STRING];
	char auxDescripcion[SIZE_STRING];
	char auxPrecio[SIZE_STRING];
	char auxIdTipo[SIZE_STRING];
	int retorno = -1;
	int flag = 0;
	if(pFile != NULL && pArrayListComputer != NULL)
	{
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
					  auxId,auxDescripcion,auxPrecio, auxIdTipo)==4)
			{
				if(flag == 1)
				{
					pPassenger = computer_newParametrosStr( auxId, auxDescripcion,
															 auxPrecio, auxIdTipo);
					if(pPassenger != NULL)
					{
						if(!ll_add(pArrayListComputer, pPassenger))
						{
							retorno = 0;
						}
					}
					else
					{
						retorno = -3;
					}
				}
				else if(flag == 0)
				{
					flag = 1;
					continue;
				}
			}
			else
			{
				retorno = -2;
			}
		}while(!feof(pFile));
	}
    return retorno;
}
