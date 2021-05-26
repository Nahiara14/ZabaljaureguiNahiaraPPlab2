#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"


int mostrarCliente(eCliente unCliente)
{
    int todoOk=0;


        printf("%d  %10s   %c\n ", unCliente.id, unCliente.nombre,unCliente.sexo);
        todoOk=1;


    return todoOk;
}

int mostrarClientes(eCliente clientes[], int tamc)
{
    int todoOk=0;
    printf("-------------------------------------------\n");
    printf("   <<<<<   Listado de clientes   >>>>>\n\n");
    printf("        Id        Nombre     Sexo\n");
    printf("--------------------------------------------\n");


    for(int i=0; i<tamc; i++)
    {
        mostrarCliente(clientes[i]);
        todoOk=1;
    }

    return todoOk;
}

int cargarNombreCliente(int id, eCliente lista[], int tam, char nombre[])
{
    int todoOk=0;
    int indice;

    if( lista != NULL && tam >0 && nombre !=NULL)
    {
        indice=buscarCliente(lista,tam, id);
        if(indice != -1)
        {
            strcpy(nombre, lista[indice].nombre);
            todoOk=1;
        }
    }

    return todoOk;

}
int buscarCliente(eCliente lista[], int tam, int id)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].id == id && lista[i].isEmpty==0)
        {
            indice=i;
            break;
        }
   }
   return indice;
}
