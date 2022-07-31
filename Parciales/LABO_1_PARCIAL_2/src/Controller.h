/*
 * Controller.h
 *
 *  Created on: 28 jun. 2022
 *      Author: nacho
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char* path , LinkedList* pArrayListComputer);
int controller_saveAsText(char* path , LinkedList* pArrayListComputer);
int controller_accessFileByName(char* path);
int controller_sortComputer(LinkedList* pArrayListComputer);
int controller_listComputer(LinkedList* pArrayListComputer);

#endif /* CONTROLLER_H_ */
