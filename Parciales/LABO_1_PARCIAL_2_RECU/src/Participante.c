/*
 * Computer.c
 *
 *  Created on: 28 jun. 2022
 *      Author: nacho
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Validations.h"
#include "LinkedList.h"
#include "Participante.h"

/**
 * \brief Constructor de entidad Participante
 * \return retorna un puntero del tipo eParticipante
 */
eParticipante* participante_new(void)
{
	return (eParticipante*) malloc (sizeof(eParticipante));
}
/**
 * \brief Constructor con todos los datos de la entidad
 * \param idStr el id
 * \param descripcionStr la descripcion
 * \param precioStr el precio
 * \param idTipo el id de Tipo
 * \return si esta bien retorna la el puntero de tipo participante, de lo contrario NULL
 */
eParticipante* participante_newParametrosStr(char* idStr,char* nombreStr,
											 char* edadStr, char* scoreStr,
											 char* idCategoriaStr)
{
	eParticipante* pParticipante = NULL;
	pParticipante = participante_new();
	if(pParticipante != NULL)
	{
		participante_setIdTxt(pParticipante, idStr);
		participante_setNombre(pParticipante, nombreStr);
		participante_setEdadTxt(pParticipante, edadStr);
		participante_setScoreTxt(pParticipante, scoreStr);
		participante_setIdCategoriaTxt(pParticipante, idCategoriaStr);
	}
	return pParticipante;
}
/**
 * \brief Setea el id en la lista
 * \param this la lista
 * \param id el id de la pc
 * \return retorna 0 si es exitoso, -1 de error
 */
int participante_setIdTxt(eParticipante* this,char* id)
{
	int retorno = -1;
	int auxId;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id, SIZE_STRING))
		{
			auxId = atoi(id);
			if(auxId > 0)
			{
				retorno = 0;
				this->id = auxId;
			}
		}
	}
	return retorno;
}
/**
 * \brief Setea el id en la lista
 * \param this la lista
 * \param id el id de la pc
 * \return retorna 0 si es exitoso, -1 de error
 */
int participante_setEdadTxt(eParticipante* this,char* edad)
{
	int retorno = -1;
	int auxEdad;
	if(this != NULL && edad != NULL)
	{
		if(esNumerica(edad, SIZE_STRING))
		{
			auxEdad = atoi(edad);
			if(auxEdad > 0)
			{
				retorno = 0;
				this->edad = auxEdad;
			}
		}
	}
	return retorno;
}
/**
 * \brief Setea la descripcion en la lista
 * \param this la lista
 * \param descripcion la descripcion de la pc
 * \return retorna 0 si es exitoso, -1 de error
 */
int participante_setNombre(eParticipante* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(this->nombre,nombre,512);
	}
	return retorno;
}
/**
 * \brief Setea el precio en la lista
 * \param this la lista
 * \param precioStr el precio de la pc
 * \return retorna 0 si es exitoso, -1 de error
 */
int participante_setScoreTxt(eParticipante* this,char* scoreStr)
{
	int retorno = -1;
	float auxScore;
	if(this != NULL && scoreStr != NULL)
	{
		auxScore = atof(scoreStr);
		if(auxScore > 0)
		{
			retorno = 0;
			this->score = auxScore;
		}
	}
	return retorno;
}
/**
 * \brief Setea el id Tipo en la lista
 * \param this la lista
 * \param idTipo el id de Tipo
 * \return retorna 0 si es exitoso, -1 de error
 */
int participante_setIdCategoriaTxt(eParticipante* this,char* idTipo)
{
	int retorno = -1;
	int auxId;
	if(this != NULL && idTipo != NULL)
	{
		auxId = atoi(idTipo);
		if(auxId > 0)
		{
			retorno = 0;
			this->idCategoria= auxId;
		}
	}
	return retorno;
}
/**
 * \brief Realiza el ordenamiento de 2 computadoras por el id de tipo
 * \param pElement1 el puntero a void del primer elemento
 * \param pElement2 el puntero a void del segundo elemento
 * \return reotrna 0 si son iguales, -1 si es menor el primero y 1 si es mayor
 */
int participante_sortByScore(void* pElement1, void* pElement2)
{
	int retorno;
	eParticipante* auxParticipante1 = NULL;
	eParticipante* auxParticipante2 = NULL;

	auxParticipante1 = (eParticipante*) pElement1;
	auxParticipante2 = (eParticipante*) pElement2;

	if(auxParticipante1->score < auxParticipante2->score)
	{
		retorno = -1;
	}
	else if(auxParticipante1->score > auxParticipante2->score)
	{
		retorno = 1;
	}
	else
	{
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief getter del id participante
 * \param this la lista
 * \param id el id a pasar por referencia
 * \return retorna 0 en caso de OK y -1 de error
 */
int participante_getId(eParticipante* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}
/**
 * \brief getter del id participante
 * \param this la lista
 * \param id el id a pasar por referencia
 * \return retorna 0 en caso de OK y -1 de error
 */
int participante_getEdad(eParticipante* this,int* edad)
{
	int retorno = -1;
	if(this != NULL && edad != NULL)
	{
		retorno = 0;
		*edad = this->edad;
	}
	return retorno;
}
/**
 * \brief getter del precio participante
 * \param this la lista
 * \param precio el precio a pasar por referencia
 * \return retorna 0 en caso de OK y -1 de error
 */
int participante_getScore(eParticipante* this,float* score)
{
	int retorno = -1;
	if(this != NULL && score != NULL)
	{
		retorno = 0;
		*score = this->score;
	}
	return retorno;
}
/**
 * \brief getter de la descripcion de la participante
 * \param this la lista
 * \param descripcion la descripcion a pasar por referencia
 * \return retorna 0 en caso de OK y -1 de error
 */
int participante_getNombre(eParticipante* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,512);
	}
	return retorno;
}
/**
 * \brief getter del id de tipo de la participante
 * \param this la lista
 * \param idTipo el id de tipo a pasar por referencia
 * \return retorna 0 en caso de OK y -1 de error
 */
int participante_getIdCategoria(eParticipante* this, int* idCategoria)
{
	int retorno = -1;
	if(this != NULL && idCategoria != NULL)
	{
		retorno = 0;
		*idCategoria = this->idCategoria;
	}
	return retorno;
}
/**
 * \brief getter del id de tipo de la participante
 * \param this la lista
 * \param idTipo el id de tipo
 * \param idTipoStr el id de tipo a pasar por referencia
 * \return retorna 0 en caso de OK y -1 de error
 */
int participante_getIdCategoriaTxt(eParticipante* this,int idCategoria, char* idCategoriaStr)
{
	int retorno = 0;
	if(this != NULL && idCategoriaStr != NULL && idCategoria > 0)
	{
		switch(idCategoria)
		{
			case 1:
				strncpy(idCategoriaStr,"MENOR",50);
				break;
			case 2:
				strncpy(idCategoriaStr,"MAYOR",50);
				break;
			default:
				retorno = -1;
		}
	}
	return retorno;
}
/**
 * \brief imprime una computadora
 * \param pArrayListParticipante la linked list
 * \param index la posicion en la lista
 * \return retorna 0 si pudo imprimir y -1 de error
 */
int participante_print(LinkedList* pArrayListParticipante, int index)
{
	eParticipante* pAuxParticipante;
	int retorno = -1;
	int id;
	int edad;
	char nombre[SIZE_STRING];
	float score;
	int idCategoria;
	char idCategoriaStr[SIZE_STRING];

	if(pArrayListParticipante != NULL && index >= 0)
	{
		pAuxParticipante = (eParticipante*)ll_get(pArrayListParticipante, index);
		if(pAuxParticipante != NULL &&
		  !participante_getId(pAuxParticipante, &id) &&
		  !participante_getScore(pAuxParticipante, &score) &&
		  !participante_getEdad(pAuxParticipante, &edad) &&
		  !participante_getNombre(pAuxParticipante, nombre) &&
		  !participante_getIdCategoria(pAuxParticipante, &idCategoria) &&
		  !participante_getIdCategoriaTxt(pAuxParticipante, idCategoria,idCategoriaStr))
		{
		  	  printf("\n%d,%s,%d,%s,%.2f",id,nombre,edad,idCategoriaStr,score);
		  	  retorno = 0;
		}
	}
	return retorno;
}
