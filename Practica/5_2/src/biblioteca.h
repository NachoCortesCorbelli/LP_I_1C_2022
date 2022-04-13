/*
 * biblioteca.h
 *
 *  Created on: 12 abr. 2022
 *      Author: nacho
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int pideNumero(int min,int max);
void mostrar_vectorNumerico(int vector[],int tamanoVector);
void mostrar_numerosPares(int vector[],int tamanoVector);
void mostrar_posicionNumerosImpares(int vector[],int tamanoVector);
int contador_Positivos(int vector[],int tamanoVector);
int contador_Negativos(int vector[],int tamanoVector);
int sumador_Pares(int vector[],int tamanoVector);
int mayor_Impar(int vector[],int tamanoVector,int* pMayorImpar);


#endif /* BIBLIOTECA_H_ */
