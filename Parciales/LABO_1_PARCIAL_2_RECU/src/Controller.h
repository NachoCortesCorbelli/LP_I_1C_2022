/*
 * Controller.h
 *
 *  Created on: 28 jun. 2022
 *      Author: nacho
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char* path , LinkedList* pArrayListParticipante);
int controller_saveAsText(char* path , LinkedList* pArrayListParticipante);
int controller_accessFileByName(char* path);
int controller_sortParticipante(LinkedList* pArrayListParticipante);
int controller_listParticipante(LinkedList* pArrayListParticipante);

#endif /* CONTROLLER_H_ */
