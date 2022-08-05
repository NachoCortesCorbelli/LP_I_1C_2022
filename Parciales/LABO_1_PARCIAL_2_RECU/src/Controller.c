/*
 * Controller.c
 *
 *  Created on: 28 jun. 2022
 *      Author: nacho
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Participante.h"
#include "Validations.h"
#include "utn.h"


/** \brief Carga los datos de las computadoras desde el archivo datos_SP.csv (modo texto).
 * \param path char* la ruta del archivo
 * \param pArrayListParticipante LinkedList* la linked list
 * \return int retorna 0 si pudo parsear -1 error
 */
int controller_loadFromText(char* path , LinkedList* pArrayListParticipante)
{
	int retorno = -1;
	int retornoParser;
	FILE* pFile;
	if(pArrayListParticipante != NULL && path != NULL)
	{
		pFile = fopen(path,"r");
		if(pFile != NULL)
		{
			retornoParser = parser_participanteFromText(pFile, pArrayListParticipante);
			if(retornoParser == 0)
			{
				retorno = 0;
			}
			fclose(pFile);
		}
	}
    return retorno;
}
int controller_accessFileByName(char* path)
{
	int retorno = -1;
	char auxFileName[SIZE_STRING];
	FILE* pFile;

	if(!utn_pedirCadena(auxFileName, SIZE_STRING,
						"\nINGRESE EL NOMBRE DEL ARCHIVO: ",
						"\nERROR\nREINGRESE NUEVAMENTE\n",
						3, SIZE_STRING, 5))
	{
		pFile = fopen(auxFileName,"r");
		if(pFile != NULL)
		{
			strncpy(path,auxFileName,SIZE_STRING);
			retorno = 0;
			fclose(pFile);
		}
	}
	return retorno;
}
/** \brief Guarda los datos del mapeado en un nuevo archivo .csv
 * \param path char* la ruta del archivo
 * \param pArrayListParticipante LinkedList* la linked list
 * \return int retorna 0 si OK, -1 error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListParticipante)
{
	int retorno = -1;
	int length;
	FILE* pFile;
	eParticipante* auxParticipante = NULL;
	int id;
	int edad;
	float score;
	char nombre[SIZE_STRING];
	int idCategoria;

	if(pArrayListParticipante != NULL && path != NULL && ll_len(pArrayListParticipante) > 0)
	{
		length = ll_len(pArrayListParticipante);
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			fprintf(pFile, "id,nombre,edad,idCategoria,score\n");
			for(int i = 0; i < length; i++)
			{
				auxParticipante = (eParticipante*)ll_get(pArrayListParticipante, i);
				if(auxParticipante != NULL &&
				   !participante_getId(auxParticipante, &id)&&
				   !participante_getEdad(auxParticipante, &edad)&&
				   !participante_getNombre(auxParticipante, nombre) &&
				   !participante_getScore(auxParticipante, &score) &&
				   !participante_getIdCategoria(auxParticipante, &idCategoria))
				{
					fprintf(pFile,"%d,%s,%d,%d,%.2f\n",
							id,
							nombre,
							edad,
						    idCategoria,
						    score);
				}
			}
			retorno = 0;
			fclose(pFile);
		}
	}
    return retorno;
}
/** \brief Ordenar pasajeros
 *
 * \param path char* la ruta del archivo
 * \param pArrayListPassenger LinkedList* la linked list
 * \return int retorna 0 si pudo parsear -1 error
 *
 */
int controller_sortParticipante(LinkedList* pArrayListParticipante)
{
	int retorno = -1;
	if(pArrayListParticipante != NULL)
	{
		if(!ll_sort(pArrayListParticipante, participante_sortByScore, 0))
		{
			retorno = 0;
		}
	}
    return retorno;
}
/** \brief Listar computadoras
 * \param path char* la ruta del archivo
 * \param pArrayListPassenger LinkedList* la linked list
 * \return int retorna 0 si pudo parsear -1 error
 *
 */
int controller_listParticipante(LinkedList* pArrayListParticipante)
{
	int retorno = -1;
	int i;
	int length;
	if(pArrayListParticipante !=NULL)
	{
		length = ll_len(pArrayListParticipante);
		if(length > 0)
		{
			for(i = 0; i < length; i++)
			{
				if(!participante_print(pArrayListParticipante, i))
				{
					retorno = 0;
					printf("\n");
				}
			}
		}
	}
    return retorno;
}
