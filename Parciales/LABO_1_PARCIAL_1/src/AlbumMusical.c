/*
 * AlbumMusical.c
 *
 *  Created on: 2 may. 2022
 *      Author: nacho
 */

#include "AlbumMusical.h"
#include "utn.h"

/**
 * \brief Inicializa el array de Albums
 * \param arrayAlbums el array de albums
 * \param limite el limite del array
 */
void album_inicializarArray(eAlbum arrayAlbums[],int limite)
{
	int i;
	for(i = 0; i < limite; i++)
	{
		arrayAlbums[i].isEmpty = TRUE;
	}
}
/**
 * \brief Obtiene una posicion vacia en el array de Albums
 * \param arrayAlbums el array de albums
 * \param limite el limite del array
 * \return Retorna el indice libre en caso de OK, -1 de ERROR
 */
int album_getEmptyIndex(eAlbum arrayAlbums[],int limite)
{
	int i;
	int retorno = -1;
	if(arrayAlbums != NULL && limite > 0)
	{
		for(i = 0; i < limite; i++)
		{

			if(arrayAlbums[i].isEmpty == TRUE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si el array de albums esta vacio
 * \param arrayAlbums el array de albums
 * \param limite el limite del array
 * \return retorna 0 en caso de FALSO y 1 de VERDADERO
 */
int album_isArrayEmpty(eAlbum arrayAlbums[],int limite)
{
	int i;
	int retorno = TRUE;
	if(arrayAlbums != NULL && limite > 0)
	{
		for(i = 0; i < limite; i++)
		{
			if(arrayAlbums[i].isEmpty == FALSE)
			{
				retorno = FALSE;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si el array de albums esta lleno
 * \param arrayAlbums el array de albums
 * \param limite el limite del array
 * \return retorna 0 en caso de FALSO y 1 de VERDADERO
 */
int album_isArrayFull(eAlbum arrayAlbums[],int limite)
{
	int i;
	int retorno = TRUE;
	if(arrayAlbums != NULL && limite > 0)
	{
		for(i = 0; i < limite; i++)
		{
			if(arrayAlbums[i].isEmpty == TRUE)
			{
				retorno = FALSE;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Muestra los tipos de Album
 * \param arrayTipoDeAlbum el array de tipo de Album
 * \param limite el limite del array
 */
void album_mostrarTipoDeAlbum(eTipoDeAlbum arrayTipoDeAlbum[],int limite)
{
	int i;
	printf("\nID  |TIPO DE ALBUM       |");
	printf("\n-------------------------|");
	for(i=0;i<limite;i++)
	{
		printf("\n%-4d|",arrayTipoDeAlbum[i].idTipoDeAlbum);
		printf("%-20s|",arrayTipoDeAlbum[i].descripcion);
	}
}
/**
 * \brief Muestra los Generos
 * \param arrayGeneros el array de Generos
 * \param limite el limite del array
 */
void album_mostrarGeneros(eGenero arrayGeneros[],int limite)
{
	int i;
	printf("\nID  |GENEROS             |");
	printf("\n-------------------------|");
	for(i=0;i<limite;i++)
	{
		printf("\n%-4d|",arrayGeneros[i].idGenero);
		printf("%-20s|",arrayGeneros[i].descripcion);
	}
}
/**
 * \brief Muestra los Tipos de Artistas
 * \param arrayTipoArtista el array de artistas
 * \param limite el limite del array
 */
void album_mostrarTiposDeArtistas(eTipoArtista arrayTipoArtista[],int limite)
{
	int i;
	printf("\nID  |TIPOS DE ARTISTAS   |");
	printf("\n-------------------------|");
	for(i=0;i<limite;i++)
	{
		printf("\n%-4d|",arrayTipoArtista[i].idTipoArtista);
		printf("%-20s|",arrayTipoArtista[i].descripcion);
	}
}
/**
 * \brief Muestra los Artistas
 * \param arrayArtistas el array de Artistas
 * \param limite el limite del array
 */
void album_mostrarArtistas(eArtista arrayArtistas[],int limite)
{
	int i;
	printf("\nID  |ARTISTAS            |");
	printf("\n-------------------------|");
	for(i=0;i<limite;i++)
	{
		printf("\n%-4d|",arrayArtistas[i].idArtista);
		printf("%-20s|",arrayArtistas[i].nombre);
	}
}
/**
 * \brief Muestra los albums de Vinilo por idArtista
 * \param arrayAlbums el array de Albums
 * \param limite el limite del array
 * \param idArtista el id del artista
 * \return Retorna 0 en caso de OK, -1 de ERROR
 */
int album_mostrarAlbumsViniloPorArtistaDeterminado(eAlbum arrayAlbums[],int limite,int idArtista)
{
	int retorno = -1;
	int i;
	if(arrayAlbums != NULL && limite > 0 && idArtista > 0)
	{
		for(i = 0; i < limite; i++)
		{
			if(arrayAlbums[i].isEmpty == FALSE &&
			   arrayAlbums[i].idArtista == idArtista &&
			   arrayAlbums[i].idTipoDeAlbum == 1)
			{
				album_imprimirAlbum(arrayAlbums[i]);
				retorno = 0;
			}
		}
	}
	return retorno;
}
/**
 * \brief Realiza el alta forzada de un album con todos sus datos
 * \param arrayAlbums el array de albums
 * \param limite el limite del array
 * \param idAlbum el id de album
 * \param idGenero el id de genero
 * \param idTipoDeAlbum el id de tipo de album
 * \param idArtista el id de artista
 * \param idTipoArtista el id de tipo de artista
 * \param titulo el titulo del album
 * \param dia el dia de lanzamiento
 * \param mes el mes de lanzamiento
 * \param anio el anio de lanzamiento
 * \param importe el importe del album
 */
void album_altaForzada(eAlbum arrayAlbums[],int limite,
					   int idAlbum,int idGenero, int idTipoDeAlbum,
					   int idArtista,int idTipoArtista,char titulo[],
					   int dia,int mes, int anio, float importe)
{
	int i;
	for(i = 0; i < limite; i++)
	{
		if(arrayAlbums[i].isEmpty == TRUE)
		{
			arrayAlbums[i].isEmpty = FALSE;
			arrayAlbums[i].idAlbum = idAlbum;
			arrayAlbums[i].idGenero = idGenero;
			arrayAlbums[i].idArtista = idArtista;
			arrayAlbums[i].idTipoArtista = idTipoArtista;
			arrayAlbums[i].importe = importe;
			arrayAlbums[i].idTipoDeAlbum = idTipoDeAlbum;
			strncpy(arrayAlbums[i].titulo,titulo,51);
			arrayAlbums[i].fechaPublicacion.dia = dia;
			arrayAlbums[i].fechaPublicacion.mes= mes;
			arrayAlbums[i].fechaPublicacion.anio = anio;
			break;
		}
	}
}
/**
 * \brief Pide la fecha de lanzamiento de un album y la retorna
 * \return retorna el puntero a la estructura Fecha en caso de exito,
 * \return NULL en caso de ERROR
 */
eFecha* album_pedirFecha()
{
	eFecha* fecha = NULL;
	eFecha auxFecha;
	if(!utn_pedirEntero(&auxFecha.dia, "\nINGRESE DIA(1-31): ",
								  "\nERROR\nINGRESE DIA VALIDO\n",
								  1, 31, 15) )
	{
		if(!utn_pedirEntero(&auxFecha.mes, "\nINGRESE MES(1-12): ",
							"\nERROR\nINGRESE MES VALIDO\n",
							1, 31, 15) &&
			( ( auxFecha.dia == 31 && (auxFecha.mes != 2 && auxFecha.mes != 4 &&
									   auxFecha.mes != 6 && auxFecha.mes != 9 &&
									   auxFecha.mes != 11) )
					||
			  ( auxFecha.dia == 30 && (auxFecha.mes == 4 || auxFecha.mes == 6 ||
									   auxFecha.mes== 9 || auxFecha.mes == 11) )
			)
		  )
		{
			if(!utn_pedirEntero(&auxFecha.anio, "\nINGRESE ANIO: ",
								"\nERROR\nINGRESE ANIO VALIDO\n",
							    500, 2022, 15))
			{
				fecha = &auxFecha;
			}
		}

	}
	return fecha;
}
/**
 * \brief Funcion que pide el tipo de Album
 * \param arrayTipoDeAlbum el array de tipo de album
 * \param limite el limite del array
 * \param pIdTipoDeAlbum el puntero del id tipo de album
 * \return Retorna 0 en caso de exito y -1 de ERROR
 */
int album_pedirTipoDeAlbum(eTipoDeAlbum arrayTipoDeAlbum[],int limite, int* pIdTipoDeAlbum)
{
	int retorno = -1;
	int auxId;
	if(arrayTipoDeAlbum != NULL && pIdTipoDeAlbum!= NULL)
	{
		album_mostrarTipoDeAlbum(arrayTipoDeAlbum, limite);
		if(!utn_pedirEntero(&auxId, "\nINGRESE EL ID DE TIPO DE ALBUM: ", "\nERROR\nREINGRESE EL ID\n",
							1, 3, 15))
		{
			*pIdTipoDeAlbum= auxId;
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief Funcion que pide el genero
 * \param arrayGeneros el arrat de genero
 * \param limite el limite del array
 * \param pIdGenero el puntero al id de genero
 * \return Retorna 0 en caso OK, -1 de ERROR
 */
int album_pedirGenero(eGenero arrayGeneros[],int limite, int* pIdGenero)
{
	int retorno = -1;
	int auxId;
	if(arrayGeneros != NULL && pIdGenero != NULL)
	{
		album_mostrarGeneros(arrayGeneros, limite);
		if(!utn_pedirEntero(&auxId, "\nINGRESE EL ID DE GENERO: ", "\nERROR\nREINGRESE EL ID\n",
							1, 4, 15))
		{
			*pIdGenero = auxId;
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief Funcion que pide el artista
 * \param arrayArtistas el array de artistas
 * \param limite el limite del array
 * \param pIdArtista el puntero del id artista
 * \return Retorna 0 en caso de OK, -1 de ERROR
 */
int album_pedirArtista(eArtista arrayArtistas[],int limite, int* pIdArtista)
{
	int retorno = -1;
	int auxId;
	if(arrayArtistas != NULL && pIdArtista != NULL)
	{
		album_mostrarArtistas(arrayArtistas, limite);
		if(!utn_pedirEntero(&auxId, "\nINGRESE EL ID DE ARTISTA: ", "\nERROR\nREINGRESE EL ID\n",
							1, 6, 15))
		{
			*pIdArtista = auxId;
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief Funcion que pide el tipo de artista
 * \param arrayTipoArtista el array de tipo de artista
 * \param limite el limite del array
 * \param pIdTipoArtista el puntero de tipo de artista
 * \return retorna 0 en caso de OK y -1 de ERROR
 */
int album_pedirTipoDeArtista(eTipoArtista arrayTipoArtista[],int limite, int* pIdTipoArtista)
{
	int retorno = -1;
	int auxId;
	if(arrayTipoArtista != NULL && pIdTipoArtista != NULL)
	{
		album_mostrarTiposDeArtistas(arrayTipoArtista, limite);
		if(!utn_pedirEntero(&auxId, "\nINGRESE EL ID DE TIPO DE ARTISTA: ", "\nERROR\nREINGRESE EL ID\n",
							1, 2, 15))
		{
			*pIdTipoArtista = auxId;
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief Funcion que busca el ID mas alto del array de albums
 * \param arrayAlbums el array de albums
 * \param limite el limite del array
 * \return retorna el id mas alto en caso de exito, -1 de ERROR
 */
int album_buscarIdMasAlto(eAlbum arrayAlbums[], int limite)
{
	int idMasAlto = -1;
	int auxIdMax;
	int i;
	if(arrayAlbums != NULL && limite > 0)
	{
		for(i = 0; i < limite; i++)
		{
			if( arrayAlbums[i].isEmpty == FALSE &&
			   (i == 0 || arrayAlbums[i].idAlbum > auxIdMax) )
			{
				auxIdMax = arrayAlbums[i].idAlbum;
			}
		}
		if(auxIdMax > -1)
		{
			idMasAlto = auxIdMax;
		}
	}
	return idMasAlto;
}
/**
 * \brief Funcion que realiza el alta del album
 * \param arrayAlbums el array de alubms
 * \param limite el limite del array de albums
 * \param pIdAlbum el puntero del id de album
 * \param arrayGeneros el array de generos
 * \param limiteGeneros el limite del array de generos
 * \param arrayArtistas el array de artistas
 * \param limiteArtista el limite del array de artistas
 * \param arrayTipoArtista el array de tipo de artista
 * \param limiteTipoArtista el limite del array de tipo de artista
 * \param arrayTipoDeAlbum el array de tipo de album
 * \param limiteTipoDeAlbum el limite de tipo de album
 * \return Retona 0 en caso de exito, -1 de ERROR
 */
int album_alta(eAlbum arrayAlbums[],int limite, int* pIdAlbum,
			   eGenero arrayGeneros[],int limiteGeneros,
			   eArtista arrayArtistas[],int limiteArtista,
			   eTipoArtista arrayTipoArtista[],int limiteTipoArtista,
			   eTipoDeAlbum arrayTipoDeAlbum[],int limiteTipoDeAlbum)
{
	eAlbum auxAlbum;
	eFecha* auxFecha = NULL;
	int retorno = -1;
	int auxIdGenero;
	int auxIdArtista;
	int auxIdTipoArtista;
	int auxIdTipoDeAlbum;
	int indice;
	if(arrayAlbums != NULL && limite > 0 && pIdAlbum != NULL && arrayGeneros != NULL && limiteGeneros > 0 &&
	   arrayArtistas != NULL && limiteArtista > 0 && arrayTipoArtista != NULL && limiteTipoArtista > 0 &&
	   arrayTipoDeAlbum != NULL && limiteTipoDeAlbum)
	{
		indice = album_getEmptyIndex(arrayAlbums, limite);
		if(indice != -1 &&
		   !utn_pedirCadena(  auxAlbum.titulo, 51, "\nINGRESE EL TITULO DEL ALBUM: ",
							  "\nERROR\n", 3,  51, 10) &&
		   !utn_pedirFlotante(&auxAlbum.importe, "\nINGRESE IMPORTE DEL ALBUM: ",
				              "\nERROR\n", 50, 50000, 10) &&
		   !album_pedirGenero(arrayGeneros, QTY_GENEROS, &auxIdGenero) &&
		   !album_pedirArtista(arrayArtistas, QTY_ARTISTAS, &auxIdArtista) &&
		   !album_pedirTipoDeArtista(arrayTipoArtista, QTY_TIPOARTISTA,  &auxIdTipoArtista) &&
		   !album_pedirTipoDeAlbum(arrayTipoDeAlbum, limiteTipoDeAlbum, &auxIdTipoDeAlbum))
		{
			auxFecha = album_pedirFecha();
			if( auxFecha != NULL)
			{
				auxAlbum.isEmpty = FALSE;
				auxAlbum.fechaPublicacion = *auxFecha;
				auxAlbum.idAlbum = *pIdAlbum + 1;
				auxAlbum.idArtista = auxIdArtista;
				auxAlbum.idGenero = auxIdGenero;
				auxAlbum.idTipoArtista = auxIdTipoArtista;
				auxAlbum.idTipoDeAlbum = auxIdTipoDeAlbum;
				arrayAlbums[indice] = auxAlbum;
				(*pIdAlbum)++;
				retorno = 0;
			}
		}
	}
	return retorno;
}
/**
 * \brief Obtiene un album por ID y lo retorna
 * \param arrayAlbums el array de albums
 * \param limite el limite del array
 * \param idAlbum el id del album
 * \return retorna un puntero a la estructura Album en caso de exito,
 * 		   NULL de ERROR
 */
eAlbum* album_obtenerAlbumPorId(eAlbum arrayAlbums[], int limite, int idAlbum)
{
	eAlbum* pAlbum = NULL;
	int i;
	if(arrayAlbums != NULL && limite > 0 && idAlbum > 0)
	{
		for(i = 0; i < limite; i++)
		{
			if(arrayAlbums[i].isEmpty == FALSE &&
			   arrayAlbums[i].idAlbum == idAlbum)
			{
				pAlbum = &arrayAlbums[i];
			}
		}
	}
	return pAlbum;
}
/**
 * \brief Funcion que realiza la modificacion de un album
 * \param arrayAlbums el array de albums
  * \param limite el limite del array de albums
 * \param arrayTipoDeAlbum el array de tipo de albums
 * \param limiteTipoDeAlbum el limite del array de tipo de album
 * \return Retorna 0 en caso de Exito, -1 de ERROR
 */
int album_modificar(eAlbum arrayAlbums[], int limite,eTipoDeAlbum arrayTipoDeAlbum[], int limiteTipoDeAlbum)
{
	int retorno = -1;
	eAlbum* pAlbum;
	eFecha* pFecha;
	int idMasAlto;
	int idAlbum;
	int opcion;
	if(arrayAlbums != NULL && limite > 0 && arrayTipoDeAlbum != NULL && limiteTipoDeAlbum > 0)
	{
		album_mostrarAlbums(arrayAlbums, limite);
		idMasAlto = album_buscarIdMasAlto(arrayAlbums, limite);
		if(idMasAlto != -1 &&
           !utn_pedirEntero(&idAlbum, "\nINGRESE EL ID DEL ALBUM A MODIFICAR: \n",
							"\nERROR\nINGRESE UN ID VALIDO\n", 1, idMasAlto, 10)&&
		   !utn_pedirEntero(&opcion, "\n1-TITULO\n2-FECHA\n3-IMPORTE\n4-TIPO DE ALBUM\n5-SALIR\nOPCION: ",
				   	   	   "\nERROR\nVUELVA A INGRESAR", 1, 5, 10))
		{
			pAlbum = album_obtenerAlbumPorId(arrayAlbums, limite, idAlbum);
			if(pAlbum != NULL)
			{
				switch(opcion)
				{
				case 1:
					if(!utn_pedirCadena(pAlbum->titulo, 51, "\nINGRESE EL NUEVO TITULO: \n",
									   "\nERROR\nVUELVA A INGRESAR EL TITULO", 2, 51, 15))
					{
						printf("\nMODIFICADO\n");
					}
					break;
				case 2:
					pFecha = album_pedirFecha();
					if(pFecha != NULL)
					{
						pAlbum->fechaPublicacion.dia = pFecha->dia;
						pAlbum->fechaPublicacion.mes = pFecha->mes;
						pAlbum->fechaPublicacion.anio = pFecha->anio;
						printf("\nMODIFICADO\n");
					}
					break;
				case 3:
					if(!utn_pedirFlotante(&pAlbum->importe, "\nINGRESE EL NUEVO IMPORTE: ", "\nERROR\nVUELVA A INGRESAR EL IMPORTE", 100, 1000000, 15))
					{
						printf("\nMODIFICADO\n");
					}
					break;
				case 4:
					album_mostrarTipoDeAlbum(arrayTipoDeAlbum, limiteTipoDeAlbum);
					if(!utn_pedirEntero(&pAlbum->idTipoDeAlbum, "\nINGRESE EL ID DE TIPO DE ALBUM: \n", "\nERROR\nVUELVA A INGRESAR", 1, 3, 15))
					{
						printf("\nMODIFICADO\n");
					}
					break;
				case 5:
					break;
				}
				retorno = 0;
			}
		}
	}
	return retorno;
}
/**
 * \brief
 * \param arrayAlbums
 * \param limite
 * \return
 */
int album_baja(eAlbum arrayAlbums[], int limite)
{
	int retorno = -1;
	int idAlbum;
	int idMasAlto;
	int i;
	if(arrayAlbums != NULL && limite > 0)
	{
		album_mostrarAlbums(arrayAlbums, limite);
		idMasAlto = album_buscarIdMasAlto(arrayAlbums, limite);
		if( idMasAlto != -1 &&
			!utn_pedirEntero(&idAlbum, "\nINGRESE EL ID DEL ALBUM A DAR DE BAJA: \n",
							 "\nERROR\nINGRESE UN ID VALIDO\n", 1, idMasAlto, 10))
		{
			for(i = 0; i < limite; i++)
			{
				if(arrayAlbums[i].idAlbum == idAlbum &&
				   arrayAlbums[i].isEmpty == FALSE)
				{
					arrayAlbums[i].isEmpty = TRUE;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
/**
 * \brief
 * \param unAlbum
 */
void album_imprimirAlbum(eAlbum unAlbum)
{
	printf("\n|%-4d|",unAlbum.idAlbum);
	printf("%-20s|", unAlbum.titulo);
	printf("%-8.2f|",unAlbum.importe);
	printf("%.2d/%.2d/%.4d|",unAlbum.fechaPublicacion.dia,
							 unAlbum.fechaPublicacion.mes,
							 unAlbum.fechaPublicacion.anio);
}
/**
 * \brief
 * \param arrayAlbums
 * \param limiteAlbums
 * \param pCantidadDeAlbums
 * \return
 */
int album_contadorAlbumsPre2000(eAlbum arrayAlbums[],int limiteAlbums, int* pCantidadDeAlbums)
{
	int i;
	int retorno = -1;
	int auxContador = 0;
	if(arrayAlbums != NULL && limiteAlbums > 0 && pCantidadDeAlbums != NULL)
	{
		for(i=0;i<limiteAlbums;i++)
		{
			if(arrayAlbums[i].isEmpty == FALSE &&
			   arrayAlbums[i].fechaPublicacion.anio < 2000)
			{
				auxContador++;
			}
		}
		if(auxContador > 0)
		{
			retorno = 0;
			*pCantidadDeAlbums = auxContador;
		}
	}
	return retorno;
}
/**
 * \brief
 * \param arrayAlbums
 * \param limiteAlbums
 * \return
 */
int album_mostrarAlbumsPre2000(eAlbum arrayAlbums[],int limiteAlbums)
{
	int retorno = -1;
	int i;
	if(arrayAlbums != NULL && limiteAlbums > 0)
	{
		for(i=0;i<limiteAlbums;i++)
		{
			if(arrayAlbums[i].isEmpty == FALSE &&
			   arrayAlbums[i].fechaPublicacion.anio < 2000)
			{
				album_imprimirAlbum(arrayAlbums[i]);
				retorno = 0;
			}
		}
	}
	return retorno;
}
/**
 * \brief
 * \param arrayAlbums
 * \param limiteAlbums
 */
void album_mostrarAlbums(eAlbum arrayAlbums[],int limiteAlbums)
{
	int i;

	printf("\n|ID  |ALBUMS              |IMPORTE |FECHA     |");
	printf("\n|---------------------------------------------|");
	for(i = 0;i< limiteAlbums;i++)
	{
		if(arrayAlbums[i].isEmpty == FALSE)
		{
			album_imprimirAlbum(arrayAlbums[i]);
		}
	}
}
/**
 * \brief
 * \param arrayGeneros
 * \param limite
 * \param idGenero
 */
void album_imprimirGeneroPorId(eGenero arrayGeneros[],int limite, int idGenero)
{
	int i;
	for(i = 0;i<limite;i++)
	{
		if(arrayGeneros[i].idGenero == idGenero )
		{
			printf("%-30s|",arrayGeneros[i].descripcion);
			break;
		}
	}
}
/**
 * \brief
 * \param arrayArtistas
 * \param limite
 * \param idArtistas
 */
void album_imprimirArtistaPorId(eArtista arrayArtistas[],int limite, int idArtistas)
{
	int i;
	for(i = 0;i<limite;i++)
	{
		if(arrayArtistas[i].idArtista == idArtistas)
		{
			printf("%-30s|",arrayArtistas[i].nombre);
			break;
		}
	}
}
/**
 * \brief
 * \param arrayTipoArtista
 * \param limite
 * \param idTipoArtista
 */
void album_imprimirTipoDeArtistaPorId(eTipoArtista arrayTipoArtista[],int limite, int idTipoArtista)
{
	int i;
	for(i = 0;i<limite;i++)
	{
		if(arrayTipoArtista[i].idTipoArtista == idTipoArtista)
		{
			printf("%-6s|",arrayTipoArtista[i].descripcion);
			break;
		}
	}
}
/**
 * \brief
 * \param arrayAlbums
 * \param limite
 */
void album_mostrarAlbumsQueNoSonDeVinilo(eAlbum arrayAlbums[],int limite)
{
	int i;
	if(arrayAlbums != NULL && limite > 0)
	{
		for(i = 0; i<limite; i++)
		{
			if(arrayAlbums[i].isEmpty == FALSE &&
			   arrayAlbums[i].idTipoDeAlbum != 1)
			{
				album_imprimirAlbum(arrayAlbums[i]);
			}
		}
	}
}
/**
 * \brief
 * \param arrayAlbums
 * \param limite
 * \param pContadorAlbums
 * \return
 */
int album_contadorDeAlbums(eAlbum arrayAlbums[],int limite,int* pContadorAlbums)
{
	int retorno = -1;
	int auxContadorAlbums = 0;
	int i;
	if(arrayAlbums != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(arrayAlbums[i].isEmpty == FALSE)
			{
				auxContadorAlbums++;
			}
		}
		if(auxContadorAlbums > 0)
		{
			*pContadorAlbums = auxContadorAlbums;
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief
 * \param arrayAlbums
 * \param limite
 * \param pTotal
 * \return
 */
int album_importeTotal(eAlbum arrayAlbums[],int limite,float* pTotal)
{
	int retorno = -1;
	float auxTotal = 0;
	int i;

	if(arrayAlbums != NULL && limite > 0 && pTotal != NULL)
	{
		for(i=0;i<limite;i++)
		{
			if(arrayAlbums[i].isEmpty == FALSE)
			{
				auxTotal += arrayAlbums[i].importe;
			}
		}
		retorno = 0;
		*pTotal = auxTotal;
	}
	return retorno;
}
/**
 * \brief
 * \param arrayAlbums
 * \param limite
 * \param importeTotal
 * \param pImportePromedio
 * \return
 */
int album_importePromedio(eAlbum arrayAlbums[],int limite,float importeTotal, float* pImportePromedio)
{
	float retorno = -1;
	int cantidadDeAlbums;

	if(arrayAlbums != NULL && limite > 0 && importeTotal > 0)
	{
		if(!album_contadorDeAlbums(arrayAlbums, limite, &cantidadDeAlbums))
		{
			*pImportePromedio = importeTotal / cantidadDeAlbums;
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief
 * \param arrayAlbums
 * \param limite
 * \param pCantidadAlbums
 * \return
 */
int album_contadorAlbumsSuperanPromedio(eAlbum arrayAlbums[],int limite, int* pCantidadAlbums)
{
	int retorno = -1;
	float importeTotal;
	float importePromedio;
	int auxContador = 0;
	int i;
	if(arrayAlbums != NULL && limite > 0 && pCantidadAlbums)
	{
		if(!album_importeTotal(arrayAlbums, limite, &importeTotal) &&
		   !album_importePromedio(arrayAlbums, limite, importeTotal, &importePromedio))
		{
			for(i = 0; i < limite; i++)
			{
				if(arrayAlbums[i].isEmpty == FALSE &&
				   arrayAlbums[i].importe > importePromedio)
				{
					auxContador++;
				}
			}
			if(auxContador > 0)
			{
				retorno = 0;
				*pCantidadAlbums = auxContador;
			}
		}
	}
	return retorno;
}
/**
 * \brief
 * \param arrayAlbums
 * \param limite
 * \return
 */
int album_mostrarAlbumsSuperanPromedio(eAlbum arrayAlbums[],int limite)
{
	int retorno = -1;
	float importeTotal;
	float importePromedio;
	int i;
	if(arrayAlbums != NULL && limite > 0)
	{
		if(!album_importeTotal(arrayAlbums, limite, &importeTotal) &&
		   !album_importePromedio(arrayAlbums, limite, importeTotal, &importePromedio))
		{
			for(i = 0; i < limite; i++)
			{
				if(arrayAlbums[i].isEmpty == FALSE &&
				   arrayAlbums[i].importe > importePromedio)
				{
					retorno = 0;
					album_imprimirAlbum(arrayAlbums[i]);
				}
			}
		}
	}
	return retorno;
}
/**
 * \brief
 * \param arrayAlbums
 * \param limite
 * \param anio
 * \return
 */
int album_mostrarAlbumsPorAnioDeterminado(eAlbum arrayAlbums[],int limite, int anio)
{
	int retorno = -1;
	int i;
	if(arrayAlbums != NULL && limite > 0)
	{
		for(i = 0; i < limite; i++)
		{
			if(arrayAlbums[i].isEmpty == FALSE &&
			   arrayAlbums[i].fechaPublicacion.anio == anio)
			{
				album_imprimirAlbum(arrayAlbums[i]);
				retorno = 0;
			}
		}
	}
	return retorno;
}
/**
 * \brief
 * \param arrayAlbums
 * \param limite
 * \param arrayArtistas
 * \param limiteArtistas
 * \return
 */
int album_mostrarAlbumsPorArtista(eAlbum arrayAlbums[],int limite, eArtista arrayArtistas[], int limiteArtistas)
{
	int retorno = -1;
	int i;
	int j;
	if(arrayAlbums != NULL && limite > 0 && arrayArtistas != NULL && limiteArtistas > 0)
	{
		for(i = 0; i < limiteArtistas; i++)
		{
			printf("\n%s: ",arrayArtistas[i].nombre);
			for(j=0;j<limite;j++)
			{
				if(arrayArtistas[i].idArtista == arrayAlbums[j].idArtista &&
				   arrayAlbums[j].isEmpty == FALSE)
				{
					album_imprimirAlbum(arrayAlbums[j]);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
/**
 * \brief
 * \param arrayAlbums
 * \param limite
 * \param importeMasAlto
 */
void album_mostrarAlbumsConImporteMasAlto(eAlbum arrayAlbums[],int limite, float importeMasAlto)
{
	int i;
	if(arrayAlbums != NULL && limite > 0 && importeMasAlto > 0)
	{
		printf("\nALBUMS CON EL PRECIO MAS ALTO: ");
		for(i = 0; i < limite; i++)
		{
			if(arrayAlbums[i].isEmpty == FALSE &&
			   arrayAlbums[i].importe == importeMasAlto)
			{
				album_imprimirAlbum(arrayAlbums[i]);
			}
		}
	}
}
/**
 * \brief
 * \param arrayAlbums
 * \param limite
 * \param pImporteAlto
 * \return
 */
int album_buscarImporteMasAlto(eAlbum arrayAlbums[],int limite, float* pImporteAlto)
{
	int retorno = -1;
	float auxMaxImporte = -1;
	int i;
	if(arrayAlbums != NULL && limite > 0)
	{
		for(i = 0; i<limite; i++)
		{
			if(arrayAlbums[i].isEmpty == FALSE &&
			   (i == 0 || (arrayAlbums[i].importe > auxMaxImporte)) )
			{
				auxMaxImporte = arrayAlbums[i].importe;
			}
		}
		if(auxMaxImporte > -1)
		{
			*pImporteAlto = auxMaxImporte;
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief
 * \param arrayAlbums
 * \param limite
 * \return
 */
int album_ordenamientoPorImporte(eAlbum arrayAlbums[],int limite)
{
	int retorno = -1;
	int i;
	int flagSwap;
	int nuevoLimite;
	eAlbum auxAlbum;

	if(arrayAlbums != NULL && limite > 0)
	{
		nuevoLimite = limite -1;
		do
		{
			flagSwap = 0;
			for(i = 0; i < nuevoLimite; i++)
			{
				if( arrayAlbums[i].isEmpty == FALSE &&
					arrayAlbums[i].importe < arrayAlbums[i+1].importe)
				{
					// a(4) b(5)-> aux(a)-> a(b)->b(aux)
					flagSwap = 1;
					auxAlbum = arrayAlbums[i];
					arrayAlbums[i] = arrayAlbums[i+1];
					arrayAlbums[i+1] = auxAlbum;
				}
			}
		}while(flagSwap);
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief
 * \param arrayAlbums
 * \param limite
 * \return
 */
int album_ordenamientoPorTitulo(eAlbum arrayAlbums[],int limite)
{
	int retorno = -1;
	int i;
	int flagSwap;
	int nuevoLimite;
	eAlbum auxAlbum;

	if(arrayAlbums != NULL && limite > 0)
	{
		nuevoLimite = limite -1;
		do
		{
			flagSwap = 0;
			for(i = 0; i < nuevoLimite; i++)
			{
				if( arrayAlbums[i].isEmpty == FALSE &&
					strncmp(arrayAlbums[i].titulo,arrayAlbums[i+1].titulo,51) > 0)
				{
					flagSwap = 1;
					auxAlbum = arrayAlbums[i];
					arrayAlbums[i] = arrayAlbums[i+1];
					arrayAlbums[i+1] = auxAlbum;
				}
			}
		}while(flagSwap);
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief
 * \param arrayAlbums
 * \param limite
 * \return
 */
int album_subMenuInformes(eAlbum arrayAlbums[],int limite)
{
	int opcion = -1;
	float importeTotal;
	float promedio;
	int contadorAlbumsPre2000;
	int contadorAlbumsSuperanPromedio;

	if(arrayAlbums != NULL && limite > 0)
	{
		if(!utn_pedirEntero(&opcion, "\n***SUBMENU***"
								 	 "\n|INFORMES¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|"
								 	 "\n|1-TOTAL, PROMEDIO Y CUANTOS ALBUMS SUPERAN EL PROMEDIO|"
								 	 "\n|2-CANTIDAD DE ALBUMS PRE 2000                         |"
									 "\n|3-SALIR					                           |"
								 	 "\n ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"
								 	 "\nOPCION: ",
									 "\nEROR\nREINGRESE NUEVAMENTE",
									 1, 3, 5))
		{
			switch(opcion)
			{
			case 1:
				if(album_isArrayEmpty(arrayAlbums, limite)==FALSE)
				{
					if(!album_importeTotal(arrayAlbums, limite, &importeTotal) &&
					   !album_importePromedio(arrayAlbums, limite, importeTotal, &promedio) &&
					   !album_contadorAlbumsSuperanPromedio(arrayAlbums, limite, &contadorAlbumsSuperanPromedio))
					{
						printf("\nTOTAL: %.2f\n",importeTotal);
						printf("\nPROMEDIO: %.2f\n",promedio);
						printf("\nALBUMS QUE SUPERAN PROMEDIO: %d\n",contadorAlbumsSuperanPromedio);
					}
				}
				else
				{
					printf("\nNO HAY ALBUMES CARGADOS EN EL SISTEMA\n");
				}
				break;
			case 2:
				if(album_isArrayEmpty(arrayAlbums, limite)==FALSE)
				{
					if(!album_contadorAlbumsPre2000(arrayAlbums, limite, &contadorAlbumsPre2000))
					{
						printf("\nCANTIDAD DE ALBUMS PRE AÑOS 2000: %d\n",contadorAlbumsPre2000);
					}
					else
					{
						printf("\nNO HAY ALBUMES PRE ANIOS 2000\n");
					}
				}
				else
				{
					printf("\nNO HAY ALBUMES CARGADOS EN EL SISTEMA\n");
				}
				break;
			case 3:
				break;
			}
		}
	}
	return opcion;
}
/**
 * \brief
 * \param arrayAlbums
 * \param limite
 * \param arrayGeneros
 * \param limiteGeneros
 * \param arrayArtistas
 * \param limiteArtista
 * \param arrayTipoArtista
 * \param limiteTipoArtista
 * \param arrayTipoDeAlbum
 * \param limiteTipoDeAlbum
 * \return
 */
int album_subMenuListado(eAlbum arrayAlbums[],int limite,
			   	   	     eGenero arrayGeneros[],int limiteGeneros,
						 eArtista arrayArtistas[],int limiteArtista,
						 eTipoArtista arrayTipoArtista[],int limiteTipoArtista,
						 eTipoDeAlbum arrayTipoDeAlbum[],int limiteTipoDeAlbum)
{
	int opcion = -1;
	int opcionListado;
	int anio;
	float importeMasAlto;
	int idArtista;

	if(arrayAlbums != NULL && limite > 0)
	{
		if(!utn_pedirEntero(&opcion, "\n***SUBMENU***"
								 	 "\n|LISTADO¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|"
								 	 "\n|1-GENEROS                   |"
								 	 "\n|2-TIPOS DE ARTISTAS         |"
								 	 "\n|3-ARTISTAS                  |"
								 	 "\n|4-ALBUMES                   |"
									 "\n|5-TIPO DE ALBUMES           |"
									 "\n|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|"
									 "\n|LISTADO ALBUMS       	     |"
									 "\n|6-                          |"
									 "\n|  1)POR IMPORTE(DESCENDENTE)|"
									 "\n|  2)POR TITULO(ASCENDENTE)  |"
								 	 "\n|7-FECHA PRE 1/1/2000	     |"
									 "\n|8-SUPEREN PROMEDIO IMPORTE  |"
									 "\n|9-POR ARTISTA               |"
									 "\n|10-POR AÑO DETERMINADO      |"
									 "\n|11-POR IMPORTE MAS ALTO     |"
									 "\n|12-QUE NO SON DE VINILO     |"
									 "\n|----------------------------|"
									 "\n|13-LISTADO ALBUMES DE VINILO|"
									 "\n|   POR ARTISTA DETERMINADO  |"
									 "\n|14-SALIR                    |"
								 	 "\n ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"
								 	 "\nOPCION: ",
									 "\nEROR\nREINGRESE NUEVAMENTE",
									 1, 14, 5))
		{
			switch(opcion)
			{
			case 1:
				album_mostrarGeneros(arrayGeneros, limiteGeneros);
				break;
			case 2:
				album_mostrarTiposDeArtistas(arrayTipoArtista, limiteTipoArtista);
				break;
			case 3:
				album_mostrarArtistas(arrayArtistas, limiteArtista);
				break;
			case 4:
				if(album_isArrayEmpty(arrayAlbums, limite)==FALSE)
				{
					album_mostrarAlbums(arrayAlbums, limite);
				}
				else
				{
					printf("\nNO HAY ALBUMES CARGADOS EN EL SISTEMA\n");
				}
				break;
			case 5:
				album_mostrarTipoDeAlbum(arrayTipoDeAlbum, limiteTipoDeAlbum);
				break;
			case 6:
				if(album_isArrayEmpty(arrayAlbums, limite)==FALSE)
				{
					if(!utn_pedirEntero(&opcionListado, "\n1)POR IMPORTE\n2)POR TITULO\nINGRESE OPCION: ",
									    "\nERROR\nVUELVA A INGRESAR", 1, 2, 5))
					{
						switch(opcionListado)
						{
							case 1:
								if(!album_ordenamientoPorImporte(arrayAlbums, limite))
								{
									album_mostrarAlbums(arrayAlbums, limite);
								}
							break;
							case 2:
								if(!album_ordenamientoPorTitulo(arrayAlbums, limite))
								{
									album_mostrarAlbums(arrayAlbums, limite);
								}
							break;
						}
					}
				}
				else
				{
					printf("\nNO HAY ALBUMES CARGADOS EN EL SISTEMA\n");
				}
				break;
			case 7:
				if(!album_mostrarAlbumsPre2000(arrayAlbums, limite))
				{
					printf("\nIMPRIMIDOS\n");
				}
				else
				{
					printf("\nNO HAY ALBUMS ANTERIORIES AL AÑO 2000\n");
				}
				break;
			case 8:
				if(album_isArrayEmpty(arrayAlbums, limite)==FALSE)
				{
					if(!album_mostrarAlbumsSuperanPromedio(arrayAlbums, limite))
					{
						printf("\n---MOSTRADOS---\n");
					}
					else
					{
						printf("\nNO HAY ALBUMS QUE SUPEREN EL PROMEDIO\n");
					}
				}
				else
				{
					printf("\nNO HAY ALBUMES CARGADOS EN EL SISTEMA\n");
				}
				break;
			case 9:
				if(album_isArrayEmpty(arrayAlbums, limite)==FALSE)
				{
					if(!album_mostrarAlbumsPorArtista(arrayAlbums, limite, arrayArtistas, limiteArtista))
					{
						printf("\nMOSTRADOS\n");
					}
				}
				else
				{
					printf("\nNO HAY ALBUMES CARGADOS EN EL SISTEMA\n");
				}
				break;
			case 10:
				if(album_isArrayEmpty(arrayAlbums, limite)==FALSE)
				{
					if(!utn_pedirEntero(&anio, "\nINGRESE EL ANIO: \n", "\nERROR\nINGRESE UN ANIO VALIDO\n",
										500, 2022, 10) &&
					   !album_mostrarAlbumsPorAnioDeterminado(arrayAlbums, limite, anio))
					{
						printf("\nMOSTRADOS\n");
					}
					else
					{
						printf("\nNO HAY ALBUMS EN DICHO ANIO\n");
					}
				}
				else
				{
					printf("\nNO HAY ALBUMES CARGADOS EN EL SISTEMA\n");
				}
				break;
			case 11:
				if(album_isArrayEmpty(arrayAlbums, limite)==FALSE)
				{
					if(!album_buscarImporteMasAlto(arrayAlbums, limite, &importeMasAlto))
					{
						album_mostrarAlbumsConImporteMasAlto(arrayAlbums, limite, importeMasAlto);
					}
				}
				else
				{
					printf("\nNO HAY ALBUMES CARGADOS EN EL SISTEMA\n");
				}
				break;
			case 12:
				if(album_isArrayEmpty(arrayAlbums, limite)==FALSE)
				{
					album_mostrarAlbumsQueNoSonDeVinilo(arrayAlbums, limite);
				}
				else
				{
					printf("\nNO HAY ALBUMES CARGADOS EN EL SISTEMA\n");
				}
				break;
			case 13:
				if(album_isArrayEmpty(arrayAlbums, limite)==FALSE)
				{
					album_mostrarArtistas(arrayArtistas, limiteArtista);
					if(!utn_pedirEntero(&idArtista, "\nINGRESE EL ID DEL ARTISTA\n",
										"\nERROR\nVUELVA INGRESAR", 1, 6, 10) &&
					   !album_mostrarAlbumsViniloPorArtistaDeterminado(arrayAlbums, limite, idArtista))
					{
						printf("\n---MOSTRADOS---\n");
					}
					else
					{
						printf("\nDICHO ARTISTA NO TIENE ALBUMS DE VINILO\n");
					}
				}
				else
				{
					printf("\nNO HAY ALBUMES CARGADOS EN EL SISTEMA\n");
				}
				break;
			case 14:
				break;
			}
		}
	}
	return opcion;
}
/**
 * \brief
 * \param arrayAlbums
 * \param limite
 * \param pIdAlbum
 * \param arrayGeneros
 * \param limiteGeneros
 * \param arrayArtistas
 * \param limiteArtista
 * \param arrayTipoArtista
 * \param limiteTipoArtista
 * \param arrayTipoDeAlbum
 * \param limiteTipoDeAlbum
 * \return
 */
int album_menu(eAlbum arrayAlbums[],int limite, int* pIdAlbum,
			   eGenero arrayGeneros[],int limiteGeneros,
			   eArtista arrayArtistas[],int limiteArtista,
			   eTipoArtista arrayTipoArtista[],int limiteTipoArtista,
			   eTipoDeAlbum arrayTipoDeAlbum[],int limiteTipoDeAlbum)
{
	int opcion = -1;
	int opcionMenuListado;
	int opcionMenuInformes;

	if(arrayAlbums != NULL && limite > 0 && pIdAlbum != NULL)
	{
		if(!utn_pedirEntero(&opcion, "\n ****MENU***"
								 	 "\n|¯¯¯¯¯¯¯¯¯¯¯|"
								 	 "\n|1-ALTA     |"
								 	 "\n|2-MODIFICAR|"
								 	 "\n|3-BAJA     |"
								 	 "\n|4-INFORMES |"
								 	 "\n|5-LISTAR   |"
									 "\n|6-SALIR    |"
								 	 "\n ¯¯¯¯¯¯¯¯¯¯¯"
								 	 "\nOPCION: ",
							"\nEROR\nREINGRESE NUEVAMENTE",

							1, 6, 5))
		{
			switch(opcion)
			{
			case 1:
				if(album_isArrayFull(arrayAlbums,limite)==FALSE)
				{
					if(!album_alta(arrayAlbums, limite, pIdAlbum,
								   arrayGeneros, limiteGeneros,
								   arrayArtistas, limiteArtista,
								   arrayTipoArtista, limiteTipoArtista,
								   arrayTipoDeAlbum, limiteTipoDeAlbum))
					{
						printf("\nSE CARGO EL ALBUM\n");
					}
					else
					{
						printf("\n***NO SE PUDO CARGAR EL ALBUM***\n");
					}
				}
				else
				{
					printf("\n***NO HAY ESPACIO PARA CARGAR***\n");
				}
				break;
			case 2:
				if(album_isArrayEmpty(arrayAlbums, limite)==FALSE)
				{
					if(!album_modificar(arrayAlbums, limite, arrayTipoDeAlbum, limiteTipoDeAlbum))
					{
						printf("\n----MODIFICACION EXITOSA----\n");
					}
				}
				else
				{
					printf("\nNO HAY ALBUMES CARGADOS EN EL SISTEMA\n");
				}
				break;
			case 3:
				if(album_isArrayEmpty(arrayAlbums, limite)==FALSE)
				{
					if(!album_baja(arrayAlbums, limite))
					{
						printf("\nSE DIO DE BAJA EL ALBUM\n");
					}
				}
				else
				{
					printf("\nNO HAY ALBUMES CARGADOS EN EL SISTEMA\n");
				}
				break;
			case 4:
				do
				{
					opcionMenuInformes= album_subMenuInformes(arrayAlbums, limite);
				}while(opcionMenuInformes != SALIR_MENU_INFORMES);
				break;
			case 5:
				do
				{
					opcionMenuListado = album_subMenuListado(arrayAlbums, limite, arrayGeneros, limiteGeneros,
															 arrayArtistas, limiteArtista, arrayTipoArtista,
															 limiteTipoArtista, arrayTipoDeAlbum, limiteTipoDeAlbum);
				}while(opcionMenuListado != SALIR_MENU_LISTADO);
				break;
			case 6:
				break;
			}
		}
	}
	return opcion;
}