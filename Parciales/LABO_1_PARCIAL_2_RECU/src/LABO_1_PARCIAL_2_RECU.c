/*
 ============================================================================
 Name        : LABO_1_PARCIAL_2_RECU.c
 Author      : Cortés Corbelli, Ignacio Martín
 Version     : 0.8
 Copyright   : Your copyright notice
 Description : Recuperatorio Parcial 2 de Laboratorio I in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Participante.h"
#include "utn.h"

int main(void) {

    int option = 0;
    char pathCsv[SIZE_STRING];
    int flagTextController = 0;
    int flagNewList = 0;

    LinkedList* listaParticipantes = ll_newLinkedList();

    do{
    	if(!utn_pedirEntero(&option,
    			   	   	   "\n\tMENU"
    					   "\n1-CARGAR PARTICIPANTES DESDE EL .CSV"
    					   "\n2-ORDENAR LISTA SEGUN SCORE DE MANERA DESCENDENTE"
    					   "\n3-MOSTRAR LISTA DE PARTICIPANTES"
    					   "\n4-FILTRAR LA LISTA"
    					   "\n5-CREAR ARCHIVO CON LA LISTA FILTRADA"
    					   "\n6-SALIR"
    					   "\nOpcion: ", "\nERROR\n", 1, 6, 5))
    	{
			switch(option)
			{
				case 1:
					if(flagTextController == 0)
					{
						if( !controller_accessFileByName(pathCsv) &&
							!controller_loadFromText(pathCsv,listaParticipantes))
						{
							printf("\nPARTICIPANTES CARGADOS\n");
							flagTextController = 1;
						}
						else
						{
							printf("\nNO EXISTE DICHO ARCHIVO PARA CARGAR\n");
						}
					}
					else
					{
						printf("\nYA FUE CARGADO UN ARCHIVO\n");
					}
					break;
				case 2:
					if(ll_isEmpty(listaParticipantes)==0 &&
					   flagTextController == 1 &&
					   !controller_sortParticipante(listaParticipantes))
					{
						printf("\nORDENADOS\n");
					}
					else
					{
						printf("\nNO SE PUDO ORDENAR\n");
					}
					break;
				case 3:
					if(ll_isEmpty(listaParticipantes) == 0 &&
					   controller_listParticipante(listaParticipantes) == 0)
					{
						printf("\nMOSTRADOS\n");
					}
					else
					{
						printf("\nLA LISTA ESTA VACIA\n");
					}
					break;
				case 4:
					if(ll_isEmpty(listaParticipantes)==0 &&
					   flagTextController == 1)
					{
						flagNewList = 1;
						printf("\nNUEVA LISTA CREADA\n");
					}
					else
					{
						printf("\nNO SE PUDO CREAR LA LISTA NUEVA\n");
					}
					break;
				case 5:
					if(flagNewList == 1)
					{
						printf("\nARCHIVO FILTRADO.CSV GUARDADO\n");
					}
					else
					{
						printf("\n\n");
					}
					break;
				case 6:
					break;
			}
    	}
    }while(option != 6);

	return EXIT_SUCCESS;
}
