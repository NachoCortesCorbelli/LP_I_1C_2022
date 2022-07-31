/*
 ============================================================================
 Name        : LABO_1_PARCIAL_2.c
 Author      : Cortés Corbelli, Ignacio Martín
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Laboratorio 1 Parcial 2 in C, Ansi-style
 ============================================================================
 */
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Computer.h"
#include "utn.h"

int main(void) {

    int option = 0;
    char pathCsv[SIZE_STRING];
    //char pathNewSavedCsv[SIZE_STRING];
    int flagTextController = 0;
    int flagNewList = 0;

    LinkedList* listaComputadoras = ll_newLinkedList();
    LinkedList* listaComputadorasPrecioAumentado = ll_newLinkedList();

    do{

    	if(!utn_pedirEntero(&option,
    			   	   	   "\n\tMENU"
    					   "\n1-CARGAR COMPUTADORAS DESDE EL .CSV"
    					   "\n2-ORDENAR LISTA SEGUN ID TIPO"
    					   "\n3-MOSTRAR LISTA DE COMPUTADORAS"
    					   "\n4-CREAR NUEVA LISTA CON PRECIOS ACTUALIZADOS"
    					   "\n5-CREAR ARCHIVO CON PRECIOS ACTUALIZADOS"
    					   "\n6-SALIR"
    					   "\nOpcion: ", "\nERROR\n", 1, 6, 5))
    	{
			switch(option)
			{
				case 1:
					if(flagTextController == 0)
					{
						if( !controller_accessFileByName(pathCsv) &&
							!controller_loadFromText(pathCsv,listaComputadoras))
						{
							printf("\nPCS CARGADOS\n");
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
					if(ll_isEmpty(listaComputadoras)==0 &&
					   flagTextController == 1 &&
					   !controller_sortComputer(listaComputadoras))
					{
						printf("\nORDENADOS\n");
					}
					else
					{
						printf("\nNO SE PUDO ORDENAR\n");
					}
					break;
				case 3:
					if(ll_isEmpty(listaComputadoras) == 0 &&
					   controller_listComputer(listaComputadoras) == 0)
					{
						printf("\nMOSTRADOS\n");
					}
					else
					{
						printf("\nLA LISTA ESTA VACIA\n");
					}
					break;
				case 4:
					if(ll_isEmpty(listaComputadoras)==0 &&
					   flagTextController == 1)
					{
						listaComputadorasPrecioAumentado = ll_clone(listaComputadoras);
						if(listaComputadorasPrecioAumentado != NULL &&
						   !ll_map(listaComputadorasPrecioAumentado, computer_increasePriceByIdTipo))
						{
							flagNewList = 1;
							printf("\nNUEVA LISTA CREADA\n");
						}
					}
					else
					{
						printf("\nNO SE PUDO CREAR LA LISTA NUEVA\n");
					}
					break;
				case 5:
					if(flagNewList == 1 &&
					   ll_isEmpty(listaComputadorasPrecioAumentado)==0 &&
					   !controller_saveAsText("mapeado.csv", listaComputadorasPrecioAumentado))
					{
						printf("\nARCHIVO MAPEADO.CSV GUARDADO\n");
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
