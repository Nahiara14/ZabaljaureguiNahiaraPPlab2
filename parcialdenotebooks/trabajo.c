#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "trabajo.h"

int altaTrabajo(eTrabajo trabajos[], int tamtrab, eNotebook lista[], int tamn, eServicio servicios[], int tams, eMarca marcas[], int tamm,eTipo tipos[], eCliente clientes[], int tamc, int tamt, int* idTrabajo)
{
    int todoOk=0;
    int id;
    int idS;

    for(int i=0; i<tamtrab; i++)
    {
        if( trabajos[i].isEmpty==0 )
        {
            printf("Su id es: %d\n", *idTrabajo);
            buscarIndiceTrabajo(trabajos, tamtrab, id);

            printf("***Elija su notebook****\n");
            mostrarNotebooks(lista,tamn, marcas, tamm, tipos, tamt,clientes, tamc );

            printf("Ingrese el id de la notebook ");
            scanf("%d", &id);

            while(buscarIndiceNotebook(lista,tamn,id) == -1)
            {
                printf("Error, reingrese el id de la notebook ");
                scanf("%d", &id);
            }

            printf(" ***Elija su servicio***\n");
            mostrarServicios(servicios,tams);

            printf("Ingrese el id de su servicio a elegir:");
            scanf("%d", &idS);

            while(buscarIndiceServicio(servicios,tams,id) != -1)
            {
                printf("Error, reingrese el id de su servicio ");
                scanf("%d", &id);
            }

            trabajos[i].fecha=ingresarFecha();

            trabajos[i].id=*idTrabajo;
            trabajos[i].isEmpty=1;
            (*idTrabajo)++;
            todoOk=1;
            break;

        }
    }

    return todoOk;
}

void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tams, eNotebook lista[], int tamn)
{
    char nombreNotebook[20];
    char descripcionServicio[20];
    if(cargarNombreNotebook(unTrabajo.idNotebook, lista, tamn, nombreNotebook)
           && cargarDescripcionServicio(unTrabajo.idServicio, servicios, tams, descripcionServicio))
    {
        printf("   %d   %d    %d %s %d/%d/%d \n",
              unTrabajo.id,
               nombreNotebook,
               descripcionServicio,
               unTrabajo.fecha.dia,
               unTrabajo.fecha.mes,
               unTrabajo.fecha.anio
               );

    }
    else
    {
        printf("No pude mostrar el listado");
    }

}

int mostrarTrabajos(eTrabajo trabajos[], int tamtrab,  eNotebook lista[], int tamn, eServicio servicios[], int tams)
{
    int todoOk;

    printf("\n <<<<<<<<Listar Trabajos<<<<<<<<<<<\n");
    printf(" ID    ID Notebook    ID Servicio    Fecha\n");

    for(int i=0; i<tamtrab; i++)
    {
        if(trabajos[i].isEmpty==1)
        {
         mostrarTrabajo(trabajos[i], servicios, tams, lista,tamn);
       // indiceServicios=buscarIndiceServicio( servicios,tams, trabajos[i].idServicio);
        //indiceNotebook=buscarIndiceNotebook(lista,tamn, trabajos[i].idNotebook);
        }
       // mostrarTrabajo(trabajos[i],lista[indiceNotebook], servicios[indiceServicios]);
        todoOk=1;
    }
    return todoOk;
}
int inicializarTrabajo(eTrabajo trabajos[], int tamtrab)
{
    int todoOk=0;
    for(int i=0; i<tamtrab; i++)
    {
        trabajos[i].isEmpty=0;
        todoOk=1;
    }
    return todoOk;
}
int buscarIndiceTrabajo(eTrabajo trabajos[], int tamtrab, int id)
{
    int indice=-1;

    for(int i=0; i<tamtrab; i++)
    {
        if(trabajos[i].id==id)
        {
            indice=i;
        }
    }
    return indice;
}
