#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
    int isEmpty;

}eServicio;
#endif // SERVICIO_H_INCLUDED


/** \brief imprimir el contenido de la matriz de servicios
 *
 * \param servicios[] eServicio Puntero a la matriz de servicio
 * \param tams int Longitud de la matriz
 * \return int Retorna (0) si Error [Longitud inválida o puntero NULL o sin espacio libre] - (1) si está bien
 *
 */
int mostrarServicios(eServicio servicios[], int tams);

/** \brief imprime el contenido de la matriz de un servicio, pasando esta función para imprimir servicios
 *
 * \param unServicio eServicio array de un solo servicio
 * \return int Retorna (0) si Error [Longitud inválida o puntero NULL o sin espacio libre] - (1) si está bien
 *
 */
int mostrarServicio(eServicio unServicio);

/** \brief busca el indice del lugar donde se encuentra el id
 *
 * \param servicios[] eServicio Puntero a la matriz de servicio
 * \param tams int Longitud de la matriz
 * \param id int del servicio
 * \return int  Retorna el indice del lugar donde se encuentra el ID
 *
 */
int buscarIndiceServicio(eServicio servicios[], int tams, int id);


int cargarDescripcionServicio(int id, eServicio servicios[], int tam, char descrip[]);

