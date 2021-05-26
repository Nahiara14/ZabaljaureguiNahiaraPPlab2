#include <stdio.h>
#include <stdlib.h>
#include "marca.h"


int mostrarMarca(eMarca unaMarca)
{
    int todoOk=0;


        printf("%d  %10s\n ", unaMarca.id, unaMarca.descripcion);
        todoOk=1;


    return todoOk;
}
int mostrarMarcas(eMarca Marca[], int tamm)
{
    int todoOk=0;
    printf("-------------------------------------------\n");
    printf("   <<<<<   Listado de marcas   >>>>>\n\n");
    printf("        Id        Descripcion\n");
    printf("--------------------------------------------\n");


    for(int i=0; i<tamm; i++)
    {
        mostrarMarca(Marca[i]);
        todoOk=1;
    }

    return todoOk;
}

int buscarIndiceMarca(eMarca marcas[], int tamm, int id)
{
    int indice=-1;

    for(int i=0; i<tamm; i++)
    {
        if(marcas[i].id==id)
        {
            indice=i;
            break;
        }
    }
    return indice;

}
int cargarDescripcionMarca(int id, eMarca marcas[], int tamm, char descrip[])
{
    int todoOk=0;

    if(id >999 && id <=1003 && marcas != NULL && tamm >0 && descrip !=NULL)
    {
        for(int i=0; i<tamm; i++)
        {
            if(marcas[i].id == id)
            {
                strcpy(descrip, marcas[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }

    return todoOk;

}
