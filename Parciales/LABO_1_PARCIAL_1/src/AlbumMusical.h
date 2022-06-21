/*
 *  AlbumMusical.h
 *  Created on: 2 may. 2022
 *  Author: nacho
 */

#ifndef ALBUMMUSICAL_H_
#define ALBUMMUSICAL_H_

#define TRUE 1
#define FALSE 0

#define SALIR 6
#define SALIR_MENU_LISTADO 14
#define SALIR_MENU_INFORMES 3

#define QTY_ALBUMS 100
#define QTY_GENEROS 4
#define QTY_ARTISTAS 6
#define QTY_TIPOARTISTA 2
#define QTY_TIPODEALBUM 3

typedef struct
{
	int idTipoDeAlbum;
	char descripcion[51];
}eTipoDeAlbum;
typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;
typedef struct{
	int idAlbum; //PK
	int idArtista; //FK
	int idGenero; //FK
	int idTipoDeAlbum;
	int idTipoArtista; //FK
	char titulo[51];
	eFecha fechaPublicacion;
	float importe;
	int isEmpty; // TRUE 1 - FALSE 0
}eAlbum;
typedef struct {
	int idGenero; //PK
	char descripcion[51];
}eGenero;
typedef struct {
	int idArtista; //PK
	char nombre[51];
}eArtista;
typedef struct {
	int idTipoArtista; //PK
	char descripcion[51];
}eTipoArtista;
//INICIALIZO ↓
void album_inicializarArray(eAlbum arrayAlbums[], int limite);
//ALTA FORZADA ↓
void album_altaForzada(eAlbum arrayAlbums[], int limite, int idAlbum,
		int idGenero, int idTipoDeAlbum, int idArtista, int idTipoArtista, char titulo[], int dia,
		int mes, int anio, float importe);
//MUESTREOS ↓
void album_mostrarAlbums(eAlbum arrayAlbums[],int limiteAlbums);
void album_mostrarArtistas(eArtista arrayArtistas[], int limite);
void album_mostrarTiposDeArtistas(eTipoArtista arrayTipoArtista[], int limite);
void album_mostrarGeneros(eGenero arrayGeneros[], int limite);
void album_mostrarTipoDeAlbum(eTipoDeAlbum arrayTipoDeAlbum[],int limite);
int album_mostrarAlbumsPre2000(eAlbum arrayAlbums[],int limiteAlbums);
int album_mostrarAlbumsSuperanPromedio(eAlbum arrayAlbums[],int limite);
int album_mostrarAlbumsPorArtista(eAlbum arrayAlbums[],int limite, eArtista arrayArtistas[], int limiteArtistas);
int album_mostrarAlbumsViniloPorArtistaDeterminado(eAlbum arrayAlbums[],int limite,int idArtista);
void album_mostrarAlbumsConImporteMasAlto(eAlbum arrayAlbums[],int limite, float importeMasAlto);
void album_imprimirGeneroPorId(eGenero arrayGeneros[], int limite, int idGenero);
void album_imprimirArtistaPorId(eArtista arrayArtistas[], int limite, int idArtistas);
void album_imprimirTipoDeArtistaPorId(eTipoArtista arrayTipoArtista[], int limite, int idTipoArtista);
void album_mostrarAlbumsQueNoSonDeVinilo(eAlbum arrayAlbums[],int limite);
void album_imprimirAlbum(eAlbum unAlbum);
//MENUS ↓
int album_menu(eAlbum arrayAlbums[], int limite, int *pIdAlbum,
			   eGenero arrayGeneros[], int limiteGeneros, eArtista arrayArtistas[],
			   int limiteArtista, eTipoArtista arrayTipoArtista[], int limiteTipoArtista,
			   eTipoDeAlbum arrayTipoDeAlbum[],int limiteTipoDeAlbum);
int album_subMenuListado(eAlbum arrayAlbums[],int limite,
			   	   	     eGenero arrayGeneros[],int limiteGeneros,
						 eArtista arrayArtistas[],int limiteArtista,
						 eTipoArtista arrayTipoArtista[],int limiteTipoArtista,
						 eTipoDeAlbum arrayTipoDeAlbum[],int limiteTipoDeAlbum);
int album_subMenuInformes(eAlbum arrayAlbums[],int limite);

//ABM ↓
int album_alta(eAlbum arrayAlbums[], int limite, int *pIdAlbum,
			   eGenero arrayGeneros[], int limiteGeneros, eArtista arrayArtistas[],
			   int limiteArtista, eTipoArtista arrayTipoArtista[],
			   int limiteTipoArtista, eTipoDeAlbum arrayTipoDeAlbum[],int limiteTipoDeAlbum);
int album_baja(eAlbum arrayAlbums[], int limite);
int album_modificar(eAlbum arrayAlbums[], int limite,eTipoDeAlbum arrayTipoDeAlbum[], int limiteTipoDeAlbum);
//PEDIDOS INDIVIDUALES ↓
eFecha* album_pedirFecha();
int album_pedirGenero(eGenero arrayGeneros[], int limite, int *pIdGenero);
int album_pedirArtista(eArtista arrayArtistas[], int limite, int *pIdArtista);
int album_pedirTipoDeArtista(eTipoArtista arrayTipoArtista[], int limite, int *pIdTipoArtista);
int album_pedirTipoDeAlbum(eTipoDeAlbum arrayTipoDeAlbum[],int limite, int* pIdTipoDeAlbum);
//ORDENAMIENTO ↓
int album_ordenamientoPorImporte(eAlbum arrayAlbums[],int limite);
int album_ordenamientoPorTitulo(eAlbum arrayAlbums[],int limite);
//BUSQUEDAS ↓
eAlbum* album_obtenerAlbumPorId(eAlbum arrayAlbums[], int limite, int idAlbum);
int album_getLoadedIndexFromPosition(eAlbum arrayAlbums[], int limite, int desde);
int album_getEmptyIndex(eAlbum arrayAlbums[], int limite);
int album_buscarIdMasAlto(eAlbum arrayAlbums[], int limite);
int album_buscarImporteMasAlto(eAlbum arrayAlbums[],int limite, float* pImporteAlto);
//CALCULOS Y CONTADORES ↓
int album_importePromedio(eAlbum arrayAlbums[],int limite,float importeTotal, float* pImportePromedio);
int album_importeTotal(eAlbum arrayAlbums[],int limite,float* pTotal);
int album_contadorDeAlbums(eAlbum arrayAlbums[],int limite,int* pContadorAlbums);
int album_contadorAlbumsPre2000(eAlbum arrayAlbums[],int limiteAlbums, int* pCantidadDeAlbums);
int album_contadorAlbumsSuperanPromedio(eAlbum arrayAlbums[],int limite, int* pCantidadAlbums);
//CHEQUEOS ARRAY ↓
int album_isArrayEmpty(eAlbum arrayAlbums[], int limite);
int album_isArrayFull(eAlbum arrayAlbums[], int limite);
//INFORMES ↓

#endif /* ALBUMMUSICAL_H_ */
