/*
 * Computer.c
 *
 *  Created on: 28 jun. 2022
 *      Author: nacho
 */
#include <stdio.h>
#include <stdlib.h>
#include "Computer.h"
#include "utn.h"
#include "Validations.h"
#include "LinkedList.h"

/**
 * \brief Constructor de entidad Computer
 * \return retorna un puntero del tipo eComputer
 */
eComputer* passenger_new(void)
{
	return (eComputer*) malloc (sizeof(eComputer));
}
/**
 * \brief Constructor con todos los datos de la entidad
 * \param idStr el id
 * \param descripcionStr la descripcion
 * \param precioStr el precio
 * \param idTipo el id de Tipo
 * \return si esta bien retorna la el puntero de tipo computer, de lo contrario NULL
 */
eComputer* computer_newParametrosStr(char* idStr,char* descripcionStr,
									 char* precioStr, char* idTipoStr)
{
	eComputer* pComputer = NULL;
	pComputer = passenger_new();
	if(pComputer != NULL)
	{
		computer_setIdTxt(pComputer, idStr);
		computer_setDescripcion(pComputer, descripcionStr);
		computer_setPrecioTxt(pComputer, precioStr);
		computer_setIdTipoTxt(pComputer, idTipoStr);
	}
	return pComputer;
}
/**
 * \brief Setea el id en la lista
 * \param this la lista
 * \param id el id de la pc
 * \return retorna 0 si es exitoso, -1 de error
 */
int computer_setIdTxt(eComputer* this,char* id)
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
 * \brief Setea la descripcion en la lista
 * \param this la lista
 * \param descripcion la descripcion de la pc
 * \return retorna 0 si es exitoso, -1 de error
 */
int computer_setDescripcion(eComputer* this,char* descripcion)
{
	int retorno = -1;
	if(this != NULL && descripcion != NULL)
	{
		retorno = 0;
		strncpy(this->descripcion,descripcion,512);
	}
	return retorno;
}
/**
 * \brief Setea el precio en la lista
 * \param this la lista
 * \param precioStr el precio de la pc
 * \return retorna 0 si es exitoso, -1 de error
 */
int computer_setPrecioTxt(eComputer* this,char* precioStr)
{
	int retorno = -1;
	float auxPrecio;
	if(this != NULL && precioStr != NULL)
	{
		if(esPrecio(precioStr, SIZE_STRING) == TRUE )
		{
			auxPrecio = atof(precioStr);
			if(auxPrecio > 0)
			{
				retorno = 0;
				this->precio = auxPrecio;
			}
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
int computer_setIdTipoTxt(eComputer* this,char* idTipo)
{
	int retorno = -1;
	int auxId;
	if(this != NULL && idTipo != NULL)
	{
		auxId = atoi(idTipo);
		if(auxId > 0)
		{
			retorno = 0;
			this->idTipo = auxId;
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
int computer_sortByIdTipo(void* pElement1, void* pElement2)
{
	int retorno;
	eComputer* auxComputer1 = NULL;
	eComputer* auxComputer2 = NULL;

	auxComputer1 = (eComputer*) pElement1;
	auxComputer2 = (eComputer*) pElement2;

	if(auxComputer1->idTipo < auxComputer2->idTipo)
	{
		retorno = -1;
	}
	else if(auxComputer1->idTipo > auxComputer2->idTipo)
	{
		retorno = 1;
	}
	else
	{
		retorno = 0;
	}
	return retorno;
}
int computer_increasePriceByIdTipo(void* pElement1)
{
	int retorno = 0;
	float auxPrice;
	eComputer* auxComputer1 = NULL;

	auxComputer1 = (eComputer*) pElement1;
	auxPrice = auxComputer1->precio;

	if(auxComputer1->idTipo == 1)
	{
		auxComputer1->precio = auxPrice + (auxPrice * 0.10);
	}
	else if(auxComputer1->idTipo == 2)
	{
		auxComputer1->precio = auxPrice + (auxPrice * 0.20);
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}
/**
 * \brief getter del id computer
 * \param this la lista
 * \param id el id a pasar por referencia
 * \return retorna 0 en caso de OK y -1 de error
 */
int computer_getId(eComputer* this,int* id)
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
 * \brief getter del precio computer
 * \param this la lista
 * \param precio el precio a pasar por referencia
 * \return retorna 0 en caso de OK y -1 de error
 */
int computer_getPrecio(eComputer* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio = this->precio;
	}
	return retorno;
}
/**
 * \brief getter de la descripcion de la computer
 * \param this la lista
 * \param descripcion la descripcion a pasar por referencia
 * \return retorna 0 en caso de OK y -1 de error
 */
int computer_getDescripcion(eComputer* this,char* descripcion)
{
	int retorno = -1;
	if(this != NULL && descripcion != NULL)
	{
		retorno = 0;
		strncpy(descripcion,this->descripcion,512);
	}
	return retorno;
}
/**
 * \brief getter del id de tipo de la computer
 * \param this la lista
 * \param idTipo el id de tipo a pasar por referencia
 * \return retorna 0 en caso de OK y -1 de error
 */
int computer_getIdTipo(eComputer* this, int* idTipo)
{
	int retorno = -1;
	if(this != NULL && idTipo != NULL)
	{
		retorno = 0;
		*idTipo = this->idTipo;
	}
	return retorno;
}
/**
 * \brief getter del id de tipo de la computer
 * \param this la lista
 * \param idTipo el id de tipo
 * \param idTipoStr el id de tipo a pasar por referencia
 * \return retorna 0 en caso de OK y -1 de error
 */
int computer_getIdTipoTxt(eComputer* this,int idTipo, char* idTipoStr)
{
	int retorno = 0;
	if(this != NULL && idTipoStr != NULL && idTipo > 0)
	{
		switch(idTipo)
		{
			case 1:
				strncpy(idTipoStr,"Desktop",50);
				break;
			case 2:
				strncpy(idTipoStr,"Laptop",50);
				break;
			default:
				retorno = -1;
		}
	}
	return retorno;
}
/**
 * \brief imprime una computadora
 * \param pArrayListComputer la linked list
 * \param index la posicion en la lista
 * \return retorna 0 si pudo imprimir y -1 de error
 */
int computer_print(LinkedList* pArrayListComputer, int index)
{
	eComputer* pAuxComputer;
	int retorno = -1;
	int id;
	char descripcion[SIZE_STRING];
	float precio;
	int idTipo;
	char idTipoStr[SIZE_STRING];

	if(pArrayListComputer != NULL && index >= 0)
	{
		pAuxComputer = (eComputer*)ll_get(pArrayListComputer, index);
		if(pAuxComputer != NULL &&
		  !computer_getId(pAuxComputer, &id) &&
		  !computer_getPrecio(pAuxComputer, &precio) &&
		  !computer_getDescripcion(pAuxComputer, descripcion) &&
		  !computer_getIdTipo(pAuxComputer, &idTipo) &&
		  !computer_getIdTipoTxt(pAuxComputer, idTipo,idTipoStr))
		{
		  	  printf("\n%d,%s,%.2f,%s",id,descripcion,precio,idTipoStr);
		  	  retorno = 0;
		}
	}
	return retorno;
}
