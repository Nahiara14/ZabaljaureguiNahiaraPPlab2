#include <stdio.h>
#include <stdlib.h>
#include "servicio.h"

int mostrarServicio(eServicio unServicio)
{
    int todoOk=0;


    printf("%d  %10s  %.2f\n ", unServicio.id, unServicio.descripcion, unServicio.precio);
    todoOk=1;


    return todoOk;
}

int mostrarServicios(eServicio servicios[], int tams)
{
    int todoOk;

    for(int i=0; i<tams; i++)
    {
        mostrarServicio(servicios[i]);
        todoOk=1;
    }
    return todoOk;
}

int buscarIndiceServicio(eServicio servicios[], int tams, int id)
{
    int indice=-1;

    for(int i=0; i<tams; i++)
    {
        if(servicios[i].id==id)
        {
            indice=i;
        }
    }
    return indice;
}
int cargarDescripcionServicio(int id, eServicio servicios[], int tams, char descrip[])
{
    int todoOk=0;

    if(id >20000 && id <=20005 && servicios != NULL && tams >0 && descrip !=NULL)
    {
        for(int i=0; i<tams; i++)
        {
            if(servicios[i].id == id)
            {
                strcpy(descrip, servicios[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }

    return todoOk;

}
