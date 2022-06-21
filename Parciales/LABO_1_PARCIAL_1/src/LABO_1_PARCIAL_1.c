/*
 ============================================================================
 Name        : LABO_1_PARCIAL_1.c
 Author      : Cortés Corbelli, Ignacio Martín
 Version     : 1.3
 Copyright   : Your copyright notice
 Description : Parcial 1 Laboratorio I
 ============================================================================
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include "AlbumMusical.h"
int main(void) {

	eAlbum arrayAlbums[QTY_ALBUMS];

	eGenero arrayGeneros[QTY_GENEROS] = { { 1, "ROCK" },
										  { 2, "MUSICA CLASICA" },
										  { 3, "POP" },
										  { 4, "HEAVY METAL" } };
	eArtista arrayArtistas[QTY_ARTISTAS] = {  { 1, "CHARLY GARCIA" },
											  { 2, "LOS REDONDOS" },
											  { 3, "JUDAS PRIEST" },
											  { 4, "ANTONIO VIVALDI" },
											  { 5, "DUA LIPA" },
											  { 6, "MADONNA" } };
	eTipoArtista arrayTipoArtista[QTY_TIPOARTISTA] = { { 1, "SOLISTA" },
													   { 2, "BANDA" } };
	eTipoDeAlbum arrayTipoDeAlbum[QTY_TIPODEALBUM] = {{1,"VINILO"},
													  {2,"CINTA"},
													  {3,"CD"}};
	int idAlbum = 8;
	int opcionMenu;

	album_inicializarArray(arrayAlbums, QTY_ALBUMS);
	//ALTAS FORZADAS
	album_altaForzada(arrayAlbums, QTY_ALBUMS, 1, 1,2,
					  1, 1, "Piano Bar",
					  22, 9, 1984, 1325.25);
	album_altaForzada(arrayAlbums, QTY_ALBUMS, 2, 1,2,
					  1, 1, "Say No More",
					  28, 11, 1996, 1000.5);
	album_altaForzada(arrayAlbums, QTY_ALBUMS, 3, 2,1,
					  4, 1, "Las 4 Estaciones",
					  1, 1, 1725, 2500.5);
	album_altaForzada(arrayAlbums, QTY_ALBUMS, 4, 3,3,
					  5, 1, "Future Nostalgia",
					  27, 3, 2020, 1220.65);
	album_altaForzada(arrayAlbums, QTY_ALBUMS, 5, 3,3,
					  6, 1, "Like a Prayer",
					  21, 3, 1989, 1725.40);
	album_altaForzada(arrayAlbums, QTY_ALBUMS, 6, 1,3,
					  2, 2, "Oktubre",
					  4, 10, 1986, 3000.85);
	album_altaForzada(arrayAlbums, QTY_ALBUMS, 7, 4,3,
					  3, 2, "Turbo",
					  14, 4, 1986, 2300.85);
	album_altaForzada(arrayAlbums, QTY_ALBUMS, 8, 4,3,
					  3, 2, "Painkiller",
					  3, 9, 1990, 2300.85);
	do{
		opcionMenu = album_menu(arrayAlbums, QTY_ALBUMS, &idAlbum, arrayGeneros, QTY_GENEROS,
				 	 	 	 	arrayArtistas, QTY_ARTISTAS, arrayTipoArtista, QTY_TIPOARTISTA,
								arrayTipoDeAlbum, QTY_TIPODEALBUM);
	}while(opcionMenu != SALIR);

	return EXIT_SUCCESS;
}
