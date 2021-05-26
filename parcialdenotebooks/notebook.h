#include "tipo.h"
#include "marca.h"
#include "cliente.h"
#include "servicio.h"
#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;
    int idCliente;

} eNotebook;
#endif // NOTEBOOK_H_INCLUDED

/** \brief Me muestra el menu de opciones
 *
 * \return int La opcion elegida por el usuario
 *
 */
int menu();

/** \brief agregar en una lista existente de empleados los valores recibidos como parámetros en la primera posición vacía
 *
 * \param lista[] eNotebook Puntero a la matriz de notebook
 * \param tamn int Longitud de la matriz
 * \param marcas[] eMarca Puntero a la matriz de marca
 * \param tamm int Longitud de la matriz
 * \param tipos[] eTipo Puntero a la matriz de tipo
 * \param tamt int Longitud de la matriz
 * \param clientes[] eCliente Puntero a la matriz de cliente
 * \param tamt int Longitud de la matriz
 * \param idNotebook int* Puntero donde le pasamos la dirección de memoria para autoincrementar el ID
 * \return int Devuelve (0) si hay Error [Longitud no válida o puntero NULL o sin
   espacio libre] - (1) si está bien
 *
 */
int altaNotebook(eNotebook lista[], int tamn, eMarca marcas[], int tamm,eTipo tipos[], int tamt, eCliente clientes[], int tamc,  int* idNotebook);

/** \brief Para indicar que todas las posiciones en la matriz están vacías
 *
 * \param lista[] eNotebook Puntero a la matriz de notebook
 * \param tamn int Longitud de la matriz
 * \return int  Devuelve (0) si hay Error [Longitud no válida o puntero NULL o sin
   espacio libre] - (1) si está bien
 *
 */
int inicializarNotebook(eNotebook lista[], int tamn);

/** \brief Para indicar que todas las posiciones de la matriz están vacías, esta función pone la bandera (isEmpty) en VERDADERO en todos
 *
 * \param unaNotebook eNotebook Array de una sola notebook
 * \param unaMarca eMarca Array de una sola marca
 * \param unTipo eTipo Array de un solo tipo
* \return int Devuelve (0) si hay Error [Longitud no válida o puntero NULL o sin
   espacio libre] - (1) si está bien
 *
 */
int mostrarNotebook(eNotebook unaNotebook, eMarca  marcas[],int tamm, eTipo tipos[], int tamt, eCliente clientes[], int tamc);

/** \brief imprimir el contenido de la matriz de notebooks
 *
 * \param lista[] eNotebook Puntero a la matriz notebook
 * \param tamn int Longitud de la matriz
 * \param marcas[] eMarca Puntero a la matriz marcas
 * \param tamm int Longitud de la matriz
 * \param tipos[] eTipo  Puntero a la matriz tipo
 * \param tamt int Longitud de la matriz
 * \return int Devuelve (0) si hay Error [Longitud no válida o puntero NULL o sin
   espacio libre] - (1) si está bien
 *
 */


/** \brief busca el indice del lugar donde se encuentra el id
 *
 * \param lista[] eNotebook Puntero a la matriz notebook
 * \param tamn int Longitud de la matriz
 * \param id int ID de la notebook
 * \return int Retorna el indice del lugar donde se encuentra el ID
 *
 */
int buscarIndiceNotebook(eNotebook lista[], int tamn, int id);

/** \brief Eliminar a una notebook por Id (poner isEmpty Flag en 0)
 *
 * \param lista[] eNotebook Puntero a la matriz notebook
 * \param tamn int Longitud de la matriz
 * \param marcas[] eMarca Puntero a la matriz marca
 * \param tamm int Longitud de la matriz
 * \param tipos[] eTipo Puntero a la matriz tipo
 * \param tamt int Longitud de la matriz
 * \return int Retorna (0) si Error [Longitud inválida o puntero NULL o sin espacio libre] - (1) si está bien
 *
 */
int bajaNotebooks(eNotebook lista[], int tamn, eMarca marcas[],int tamm, eTipo tipos[], int tamt, eCliente clientes[],int  tamc);

/** \brief modificar los datos del empleado indicando su ID
 *
 * \param lista[] eNotebook Puntero a la matriz notebook
 * \param tamn int  Longitud de la matriz
 * \param marcas[] eMarca Puntero a la matriz marca
 * \param tamm int  Longitud de la matriz
 * \param tipos[] eTipo Puntero a la matriz tipo
 * \param tamt int  Longitud de la matriz
 * \return int Retorna (0) si Error [Longitud inválida o puntero NULL o sin espacio libre] - (1) si está bien
 *
 */
int modificarNotebook(eNotebook lista[], int tamn, eMarca marcas[],int tamm, eTipo tipos[], int tamt, eCliente clientes[], int tamc);

/** \brief Ordene los elementos en la matriz de notebooks, el orden de los argumentos es por marca de la notebook y precio de la misma
 *
 * \param lista[] eNotebook Puntero a la matriz notebook
 * \param tamn int Longitud de la matriz
 * \param marcas[] eMarca Puntero a la matriz marca
 * \param tamm ints Longitud de la matriz
 * \return void
 *
 */

int mostrarNotebooks(eNotebook lista[], int tamn, eMarca marcas[],int tamm, eTipo tipos[], int tamt, eCliente clientes[], int tamc);
/** \brief
 *
 * \param id int
 * \param lista[] eNotebook
 * \param tamn int
 * \param nombre[] char
 * \return int
 *
 */
int cargarNombreNotebook(int id, eNotebook lista[], int tamn, char nombre[]);


int cargarNombreCliente(int id, eCliente lista[], int tam, char nombre[]);
int buscarCliente(eCliente lista[], int tam, int id);
/** \brief Ordene los elementos en la matriz de notebooks, el orden de los argumentos es por marca de la notebook y precio de la misma
 *
 * \param lista[] eNotebook Puntero a la matriz notebook
 * \param tamn int Longitud de la matriz
 * \return void
 *
 */
void ordenarNotebooks(eNotebook lista[], int tamn);
