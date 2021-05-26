#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    int isEmpty;

} eMarca;
#endif // MARCA_H_INCLUDED

/** \brief imprime el contenido de la matriz de un marca, pasando esta función para imprimir marcas
 *
 * \param unaMarca eMarca Array de una sola marca
 * \return int Retorna (0) si Error [Longitud inválida o puntero NULL o sin espacio libre] - (1) si está bien
 *
 */
int mostrarMarca(eMarca unaMarca);

/** \brief  imprimir el contenido de la matriz de marcas
 *
 * \param Marca[] eMarca Puntero de la matriz a marcas
 * \param tamm int Longitud de la matriz
 * \return int Retorna (0) si Error [Longitud inválida o puntero NULL o sin espacio libre] - (1) si está bien
 *
 */
int mostrarMarcas(eMarca Marca[], int tamm);

/** \brief busca el indice del lugar donde se encuentra el id
 *
 * \param marcas[] eMarca Puntero de la matriz a marcas
 * \param tamm int Longitud de la matriz
 * \param id int ID de la marca
 * \return int Retorna el indice del lugar donde se encuentra el ID
 *
 */
int buscarIndiceMarca(eMarca marcas[], int tamm, int id);

int cargarDescripcionMarca(int id, eMarca marcas[], int tamm, char descrip[]);
