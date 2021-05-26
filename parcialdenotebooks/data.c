#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "notebook.h"
int idCliente[10]= {1500, 1501, 1502, 1503, 1500, 1501, 1502, 1503, 1500, 1501};
int idTrabajo[10]={1000, 1001, 1002, 1003, 1001, 1002, 1003,1001, 1002, 1003};
int idNotebook[10]={2000, 2001,2002, 2003, 2000, 2001, 2002, 2003, 2000, 2001};
char modelos[10][20]=
{
    "Print",
    "Slow",
    "Flash",
    "Grenday",
    "Supernet",
    "Hipernet",
    "Note10",
    "Note20",
    "Note30",
    "Note40"
};
int idTipo[10]={5000,5001,5002,5003,5000,5001,5002,5003,5000,5001};
int idMarca[10]={1000,1001,1002,1003,1000,1001,1002,1003,1000,1001};
int idServicios[10]={20000,20001,20002,20003,20000,20001,20002,20003,20000,20001};

//char sexos[10]= {'m', 'f','f', 'm', 'm', 'f', 'm', 'm', 'f', 'f'};

//int edades[10]= {56, 70,39, 30, 52, 45, 44, 58, 38, 29};

float precio[10]= {10000,13000,12000,34500,29600,13900,12100,11500,10600,12500};

eFecha fechas[10]=
{

    {4, 3, 2021},
    {8,4,2015},
    {9, 5, 2008},
    {21, 8, 2011},
    { 6, 9, 2016},
    { 1, 10, 2009},
    { 24, 11, 2002},
    { 24, 11, 2002},
    { 24, 11, 2002},
    { 24, 11, 2002}

};


/*eFecha fechas2[]=
{

    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021}

};*/

/*int legajos[] ={20000,20006,20001,20005,20007,20002,20000,20004,20001,20003,20008,20001,20006,20003,20004,20008,20005,20000,20005,20003,20007,20009,20004};
int idComidas[]={1000,1003,1002,1000,1000,1004,1002,1001,1004,1003,1003,1004,1000,1002,1004,1004,1001,1001,1000,1001,1002,1002,1000};

int idSectores[10]= { 500,504,502,502,501,500,503,503,500,504 };*/
int harcodearNotebooks(eNotebook lista[],int tamn,int cant)
{
    int retorno = -1;

    if(lista != NULL && tamn > 0 && cant <= tamn)
    {
        retorno = 0 ;

        for(int i=0; i<cant; i++)
        {
            lista[i].id = idNotebook[i];
            strcpy(lista[i].modelo, modelos[i]);
            lista[i].idTipo = idTipo[i];
            lista[i].idMarca = idMarca[i];
            lista[i].precio = precio[i];
            lista[i].idCliente = idCliente[i];
            lista[i].isEmpty = 0;

            retorno++;
        }
    }
    return retorno;
}
/*void hardcodeoNotebook(eNotebook notebooks[])
{
    char modelo[10][20] =
{
    "Print",
    "Slow",
    "Flash",
    "Grenday",
    "Supernet",
    "Hipernet",
    "Note10",
    "Note20",
    "Note30",
    "Note40"
};
    int idsMarcas[10] = {1000,1001,1002,1003,1000,1001,1002,1003,1000,1001};
    int idsTipos[10] = {5000,5001,5002,5003,5000,5001,5002,5003,5000,5001};
    int precios[10] = {10000,13000,12000,34500,29600,13900,12100,11500,10600,12500};
    int idNotebok[10] = {2000, 2001,2002, 2003, 2000, 2001, 2002, 2003, 2000, 2001};

    for(int i = 0; i < 10; i++)
    {
        notebooks[i].id = idNotebok[i];
        strcpy(notebooks[i].modelo,modelo[i]);
        notebooks[i].idMarca = idsMarcas[i];
        notebooks[i].idTipo = idsTipos[i];
        notebooks[i].precio = precios[i];
        notebooks[i].isEmpty = 1;
    }
}
*/
