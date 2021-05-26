#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[30];
    char sexo;
    int isEmpty;

}eCliente;

#endif // CLIENTE_H_INCLUDED
/** \brief Me carga el nombre del cliente
 *
 * \param id int id de la función complementaria buscar cliente
 * \param lista[] eCliente Puntero a la matriz cliente
 * \param tam int Longitud de la matriz
 * \param nombre[] char array de nombre, cadena de caracteres
 * \return int Retorna (0) si Error [Longitud inválida o puntero NULL o sin espacio libre] - (1) si está bien
 *
 */
int cargarNombreCliente(int id, eCliente lista[], int tam, char nombre[]);

/** \brief Busca el cliente por ID
 *
 * \param lista[] eCliente Puntero a la matriz cliente
 * \param tam int Longitud de la matriz
 * \param id int ID a comparar
 * \return int el indice del lugar donde se encuentra el id
 *
 */
int buscarCliente(eCliente lista[], int tam, int id);
/** \brief imprime el contenido de la matriz de un cleinte, pasando esta función para imprimir clientes
 *
 * \param unTipo eTipo Array de un solo tipo
 * \return int Retorna (0) si Error [Longitud inválida o puntero NULL o sin espacio libre] - (1) si está bien
 *
 */
int mostrarCliente(eCliente unCliente);
/** \brief imprimir el contenido de la matriz de cliente
 *
 * \param tipos[] eTipo Puntero a la matriz de cliente
 * \param tamt int Longitud de la matriz
 * \return int Retorna (0) si Error [Longitud inválida o puntero NULL o sin espacio libre] - (1) si está bien
 *
 */
int mostrarClientes(eCliente clientes[], int tamc);
