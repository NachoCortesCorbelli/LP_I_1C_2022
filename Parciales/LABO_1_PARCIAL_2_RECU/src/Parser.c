/*
 * Parser.c
 *
 *  Created on: 28 jun. 2022
 *      Author: nacho
 */
#include <stdio.h>
#include <stdlib.h>

#include "Participante.h"
#include "utn.h"

/** \brief Parsea los datos de las computadoras desde el archivo data.csv (modo texto).
 * \param path char* la ruta del archivo
 * \param pArrayListParticipante LinkedList* la linked list
 * \return int retorna 0 si pudo parsear -1,-2,-3 error
 */
int parser_participanteFromText(FILE* pFile , LinkedList* pArrayListParticipante)
{
	eParticipante* pParticipante = NULL;
	char auxId[SIZE_STRING];
	char auxNombre[SIZE_STRING];
	char auxEdad[SIZE_STRING];
	char auxScore[SIZE_STRING];
	char auxIdCategoria[SIZE_STRING];
	int retorno = -1;
	int flag = 0;
	if(pFile != NULL && pArrayListParticipante != NULL)
	{
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					  auxId,auxNombre,auxEdad,auxIdCategoria,auxScore)==5)
			{
				if(flag == 1)
				{
					pParticipante = participante_newParametrosStr(auxId, auxNombre, auxEdad, auxScore, auxIdCategoria);
					if(pParticipante != NULL)
					{
						if(!ll_add(pArrayListParticipante, pParticipante))
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
