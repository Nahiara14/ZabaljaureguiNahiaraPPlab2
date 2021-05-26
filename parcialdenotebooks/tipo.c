#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

int mostrarTipo(eTipo unTipo)
{
    int todoOk=0;

    printf("%d  %s\n ", unTipo.id,unTipo.descripcion);
    todoOk=1;

    return todoOk;
}

int mostrarTipos(eTipo tipos[], int tamt)
{
    int todoOk;
    printf("-------------------------------------------\n");
    printf("   <<<<<   Listado de Tipos   >>>>>\n\n");
    printf("       Id          Descripcion\n");
    printf("--------------------------------------------\n");

    for(int i=0; i<tamt; i++)
    {
        mostrarTipo(tipos[i]);
        todoOk=1;
    }

    return todoOk;
}

int buscarIndiceTipo(eTipo tipos[], int tamt, int id)
{
    int indice=-1;

    for(int i=0; i<tamt; i++)
    {
        if(tipos[i].id==id)
        {
            indice=i;
        }
    }
    return indice;
}

int cargarDescripcionTipo(int id, eTipo tipos[], int tamt, char descrip[])
{
    int todoOk=0;

    if(id >4999 && id <=5004 && tipos != NULL && tamt >0 && descrip !=NULL)
    {
        for(int i=0; i<tamt; i++)
        {
            if(tipos[i].id == id)
            {
                strcpy(descrip, tipos[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }

    return todoOk;

}
