/*
 * Computer.h
 *
 *  Created on: 28 jun. 2022
 *      Author: nacho
 */

#ifndef PARTICIPANTE_H_
#define PARTICIPANTE_H_
#include "LinkedList.h"

typedef struct
{
	int id;
	int edad;
	char nombre[512];
	float score;
	int idCategoria;
}eParticipante;

eParticipante* participante_new(void);
eParticipante* participante_newParametrosStr(char* idStr,char* nombreStr,
									 	     char* edadStr, char* scoreStr,
									         char* idCategoriaStr);
int participante_setIdTxt(eParticipante* this,char* id);
int participante_setEdadTxt(eParticipante* this,char* edad);
int participante_setNombre(eParticipante* this,char* nombre);
int participante_setScoreTxt(eParticipante* this,char* scoreStr);
int participante_setIdCategoriaTxt(eParticipante* this,char* idCategoria);

int participante_getIdCategoriaTxt(eParticipante* this,int idCategoria, char* idCategoriaStr);
int participante_getIdCategoria(eParticipante* this, int* idCategoria);
int participante_getNombre(eParticipante* this,char* nombre);
int participante_getScore(eParticipante* this,float* score);
int participante_getEdad(eParticipante* this,int* edad);
int participante_getId(eParticipante* this,int* id);

int participante_print(LinkedList* pArrayListParticipante, int index);

int participante_sortByScore(void* pElement1, void* pElement2);


#endif /* PARTICIPANTE_H_ */
