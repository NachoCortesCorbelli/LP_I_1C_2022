/*
 * Computer.h
 *
 *  Created on: 28 jun. 2022
 *      Author: nacho
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_
#include "LinkedList.h"

typedef struct
{
	int id;
	char descripcion[512];
	float precio;
	int idTipo;
}eComputer;

eComputer* passenger_new(void);
eComputer* computer_newParametrosStr(char* idStr,char* descripcionStr,
									 char* precioStr, char* idTipoStr);
int computer_setIdTxt(eComputer* this,char* id);
int computer_setDescripcion(eComputer* this,char* descripcion);
int computer_setPrecioTxt(eComputer* this,char* precioStr);
int computer_setIdTipoTxt(eComputer* this,char* idTipo);

int computer_getIdTipoTxt(eComputer* this,int idTipo, char* idTipoStr);
int computer_getIdTipo(eComputer* this, int* idTipo);
int computer_getDescripcion(eComputer* this,char* descripcion);
int computer_getPrecio(eComputer* this,float* precio);
int computer_getId(eComputer* this,int* id);

int computer_print(LinkedList* pArrayListComputer, int index);

int computer_sortByIdTipo(void* pElement1, void* pElement2);
int computer_increasePriceByIdTipo(void* pElement1);


#endif /* COMPUTER_H_ */
