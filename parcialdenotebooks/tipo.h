#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[30];
    int isEmpty;

} eTipo;
#endif // TIPO_H_INCLUDED

/** \brief imprime el contenido de la matriz de un tipo, pasando esta función para imprimir tipos
 *
 * \param unTipo eTipo Array de un solo tipo
 * \return int Retorna (0) si Error [Longitud inválida o puntero NULL o sin espacio libre] - (1) si está bien
 *
 */
int mostrarTipo(eTipo unTipo);

/** \brief imprimir el contenido de la matriz de tipos
 *
 * \param tipos[] eTipo Puntero a la matriz de tipos
 * \param tamt int Longitud de la matriz
 * \return int Retorna (0) si Error [Longitud inválida o puntero NULL o sin espacio libre] - (1) si está bien
 *
 */
int mostrarTipos(eTipo tipos[], int tamt);

/** \brief busca el indice del lugar donde se encuentra el id
 *
 * \param tipos[] eTipo Puntero a la matriz de tipos
 * \param tamt int Longitud de la matriz
 * \param id int ID del tipo
 * \return int Retorna el indice del lugar donde se encuentra el ID
 *
 */
int buscarIndiceTipo(eTipo tipos[], int tamt, int id);

int cargarDescripcionTipo(int id, eTipo tipos[], int tamt, char descrip[]);
