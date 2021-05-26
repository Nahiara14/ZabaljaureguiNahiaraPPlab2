#include "fecha.h"
#include "notebook.h"
#include "servicio.h"
#include "tipo.h"
#include "marca.h"
#include "cliente.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;

} eTrabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief agregar en una lista existente de trabajos los valores recibidos como parámetros en la primera posición vacía
 *
 * \param trabajos[] eTrabajo Puntero a la matriz de trabajo
 * \param tamtrab int Longitud de la matriz
 * \param lista[] eNotebook  Puntero a la matriz de notebook
 * \param tamn int Longitud de la matriz
 * \param servicios[] eServicio  Puntero a la matriz de servicio
 * \param tams int Longitud de la matriz
 * \param marcas[] eMarca  Puntero a la matriz de marca
 * \param tamm int Longitud de la matriz
 * \param tipos[] eTipo  Puntero a la matriz de tipo
 * \param tamt int Longitud de la matriz
 * \param idTrabajo int* Puntero donde le pasamos la dirección de memoria para autoincrementar el ID
 * \return int  Devuelve (0) si hay Error [Longitud no válida o puntero NULL o sin
   espacio libre] - (1) si está bien
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tamtrab, eNotebook lista[], int tamn, eServicio servicios[], int tams, eMarca marcas[], int tamm,eTipo tipos[], eCliente clientes[], int tamc, int tamt, int* idTrabajo);

/** \brief busca el indice del lugar donde se encuentra el id
 *
 * \param trabajos[] eTrabajo Puntero a la matriz de trabajo
 * \param tamt int Longitud de la matriz
 * \param id int ID del trabajo
 * \return int Retorna el indice del lugar donde se encuentra el ID
 *
 */
int buscarIndiceTrabajo(eTrabajo trabajos[], int tamt, int id);


/*/** \brief  imprime el contenido de la matriz de un trabajo, pasando esta función para imprimir trabajos
 *
 * \param unTrabajo eTrabajo array de un solo trabajo
 * \param unalista eNotebook array de una sola notebook
 * \param unServicio eServicio array de un solo servicio
 * \return int Retorna (0) si Error [Longitud inválida o puntero NULL o sin espacio libre] - (1) si está bien
 *
 */
//int mostrarTrabajo(eTrabajo unTrabajo, eNotebook unalista ,eServicio unServicio);

/** \brief imprimir el contenido de la matriz de trabajos
 *
 * \param trabajos[] eTrabajo Puntero a la matriz de trabajo
 * \param tamtrab int Longitud de la matriz
 * \param lista[] eNotebook Puntero a la matriz de notebook
 * \param tamn int Longitud de la matriz
 * \param servicios[] eServicio Puntero a la matriz de servicios
 * \param tams int Longitud de la matriz
 * \return int Retorna (0) si Error [Longitud inválida o puntero NULL o sin espacio libre] - (1) si está bien
 *
 */
int mostrarTrabajos(eTrabajo trabajos[], int tamtrab,  eNotebook lista[], int tamn, eServicio servicios[], int tams);

/** \brief Para indicar que todas las posiciones de la matriz están vacías, esta función pone la bandera (isEmpty) en VERDADERO en todos
 *
 * \param trabajos[] eTrabajo Puntero a la matriz de trabajo
 * \param tamtrab int Longitud de la matriz
 * \return int
 *
 */
int inicializarTrabajo(eTrabajo trabajos[], int tamtrab);
int buscarIndiceTrabajo(eTrabajo trabajos[], int tamtrab, int id);
void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tams, eNotebook lista[], int tamn);
