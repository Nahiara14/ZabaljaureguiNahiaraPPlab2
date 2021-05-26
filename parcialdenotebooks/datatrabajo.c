#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fecha.h"
#include "trabajo.h"

int idTrab[10]={1000,1001,1002,1003,1000,1001,1002,1003,1000,1001};
int idNote[10]={2000,2001,2002,2003,2000,2001,2002,2003,2000,20001};
eFecha fechaTrabajo[10]={

    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021}

};

int idServi[10]={20000,20001,20002,20003,20000,20001,20002,20003,20000,20001};

int harcodearTrabajos(eTrabajo trabajos[],int tam,int cant)
{
    int retorno = -1;

    if(trabajos != NULL && tam > 0 && cant <= tam)
    {
        retorno = 0 ;

        for(int i=0; i<cant; i++)
        {
            trabajos[i].id = idTrab[i];
            trabajos[i].idNotebook = idNote[i];
            trabajos[i].idServicio = idServi[i];
            trabajos[i].fecha = fechaTrabajo[i];
            trabajos[i].isEmpty = 0;

            retorno++;
        }
    }
    return retorno;
}

