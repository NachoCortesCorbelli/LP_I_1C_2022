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
#include "Computer.h"
#include "Validations.h"
#include "utn.h"


/** \brief Carga los datos de las computadoras desde el archivo datos_SP.csv (modo texto).
 * \param path char* la ruta del archivo
 * \param pArrayListComputer LinkedList* la linked list
 * \return int retorna 0 si pudo parsear -1 error
 */
int controller_loadFromText(char* path , LinkedList* pArrayListComputer)
{
	int retorno = -1;
	int retornoParser;
	FILE* pFile;
	if(pArrayListComputer != NULL && path != NULL)
	{
		pFile = fopen(path,"r");
		if(pFile != NULL)
		{
			retornoParser = parser_ComputerFromText(pFile, pArrayListComputer);
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
 * \param pArrayListComputer LinkedList* la linked list
 * \return int retorna 0 si OK, -1 error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListComputer)
{
	int retorno = -1;
	int length;
	FILE* pFile;
	eComputer* auxComputer = NULL;
	int id;
	float precio;
	char descripcion[SIZE_STRING];
	int idTipo;
	char idTipoStr[SIZE_STRING];

	if(pArrayListComputer != NULL && path != NULL && ll_len(pArrayListComputer) > 0)
	{
		length = ll_len(pArrayListComputer);
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			fprintf(pFile, "id,descripcion,precio,id tipo\n");
			for(int i = 0; i < length; i++)
			{
				auxComputer = (eComputer*)ll_get(pArrayListComputer, i);
				if(auxComputer != NULL &&
				   !computer_getId(auxComputer, &id)&&
				   !computer_getDescripcion(auxComputer, descripcion) &&
				   !computer_getPrecio(auxComputer, &precio) &&
				   !computer_getIdTipo(auxComputer, &idTipo) &&
				   !computer_getIdTipoTxt(auxComputer, idTipo, idTipoStr))
				{
					fprintf(pFile,"%d,%s,%.2f,%s\n",
							id,
							descripcion,
						    precio,
						    idTipoStr);
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
int controller_sortComputer(LinkedList* pArrayListComputer)
{
	int retorno = -1;
	if(pArrayListComputer != NULL)
	{
		if(!ll_sort(pArrayListComputer, computer_sortByIdTipo, 1))
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
int controller_listComputer(LinkedList* pArrayListComputer)
{
	int retorno = -1;
	int i;
	int length;
	if(pArrayListComputer !=NULL)
	{
		length = ll_len(pArrayListComputer);
		if(length > 0)
		{
			for(i = 0; i < length; i++)
			{
				if(!computer_print(pArrayListComputer, i))
				{
					retorno = 0;
					printf("\n");
				}
			}
		}
	}
    return retorno;
}
