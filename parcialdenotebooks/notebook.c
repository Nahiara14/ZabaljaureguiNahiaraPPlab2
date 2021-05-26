#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "notebook.h"
#include "tipo.h"
#include "marca.h"

int menu()
{
    int opcion;

    system("cls");
    printf("   *** SERVICIO DE NOTEBOOKS ***\n\n");
    printf("1.Alta notebook\n");
    printf("2.Modificar Notebook\n");
    printf("3.Baja Notebook\n");
    printf("4.Listar  Notebooks\n");
    printf("5.Listar Marcas\n");
    printf("6.Listar Tipos\n");
    printf("7.Listar Servicios\n");
    printf("8.Alta Trabajo\n");
    printf("9.Listar Trabajo\n");
    printf(" ** INFORMES ** \n");
    printf("10.Mostrar las notebooks del tipo seleccionado por el usuario.\n");
    printf("11.Mostrar notebooks de una marca seleccionada.\n");
    printf("12.Informar la o las notebooks mas baratas\n");
    printf("13.Mostrar un listado de las notebooks separadas por marca.\n");
    printf("14.Elegir un tipo y una marca y contar cuantas notebooks hay de ese tipo y esa marca.\n");
    printf("15.Mostrar la o las marcas mas elegidas por los clientes..\n");
    printf("16.Pedir una notebook y mostrar todos los trabajos que se le hicieron a la misma.\n");
    printf("17.Pedir un notebook e informar la suma de los importes de los services se le hicieron a la misma.\n");
    printf("18.Pedir un servicio y mostrar las notebooks a las que se realizó ese servicio y la fecha..\n");
    printf("19.Pedir una fecha y mostrar todos los servicios realizados en la misma.\n");
    printf("20.Salir\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
int inicializarNotebook(eNotebook lista[], int tamn)
{
    int todoOk=0;
    for(int i=0; i<tamn; i++)
    {
        lista[i].isEmpty=0;
        todoOk=1;
    }
    return todoOk;
}

int altaNotebook(eNotebook lista[], int tamn, eMarca marcas[], int tamm,eTipo tipos[], int tamt, eCliente clientes[], int tamc,  int* idNotebook)
{
    int todoOk=0;

    for(int i=0; i<tamn; i++)
    {
        if( lista[i].isEmpty==0 )
        {
            printf("Su id es: %d\n", *idNotebook);

            printf("Ingrese modelo: ");
            fflush(stdin);
            gets(lista[i].modelo);

            mostrarMarcas(marcas,tamm);
            printf("Ingrese id de la marca: ");
            scanf("%d", &lista[i].idMarca);

            mostrarTipos(tipos, tamt);
            printf("Ingrese el id del tipo: ");
            scanf("%d", &lista[i].idTipo);

            printf("Ingrese el precio: ");
            scanf("%f", &lista[i].precio);

            mostrarClientes(clientes, tamc);
            printf("ingrese el id del cliente: ");
            scanf("%d", &lista[i].idCliente);

            lista[i].id=*idNotebook;
            lista[i].isEmpty=1;
            *idNotebook=*idNotebook +1;
            todoOk=1;
            break;

        }
    }

    return todoOk;
}

int mostrarNotebook(eNotebook unaNotebook, eMarca  marcas[],int tamm, eTipo tipos[], int tamt, eCliente clientes[], int tamc)
{
    int todoOk=0;
    char nombreCliente[30];
    char descripcion[20];
    char descripcion1[20];
    if(cargarDescripcionMarca(unaNotebook.idMarca, marcas, tamm, descripcion)
    && cargarDescripcionTipo(unaNotebook.idTipo, tipos, tamt, descripcion1)
    && cargarNombreCliente(unaNotebook.idCliente, clientes, tamc, nombreCliente ))
    {
        printf("%d    %s            %s           %s          %.2f   %s\n ",
               unaNotebook.id,
               unaNotebook.modelo,
               descripcion,
               descripcion1,
               unaNotebook.precio,
               nombreCliente
               );
        todoOk=1;
    }
   /* else
    {
        printf("No se pudo cargar la descripcion de tipo o marca");
    }*/

    return todoOk;
}

int mostrarNotebooks(eNotebook lista[], int tamn, eMarca marcas[],int tamm, eTipo tipos[], int tamt, eCliente clientes[], int tamc)
{
    int todoOk=0;

    printf("\n <<<<<<<<Listar notebooks<<<<<<<<<<<\n\n");
    printf(" Id     Modelo    Descripcion Marca    Descripcion Tipo     Precio    Nombre del duenio\n");


    //ordenarNotebooks(lista,tamn); no me funciona el mostrar con el ordenar
    for(int i=0; i<tamn; i++)
    {
        if(lista[i].isEmpty==1)
        {

            mostrarNotebook(lista[i], marcas, tamm, tipos, tamt, clientes, tamc);
            todoOk=1;
        }
    }
    return todoOk;
}
int buscarIndiceNotebook(eNotebook lista[], int tamn, int id)
{
    int indice=-1;

    for(int i=0; i<tamn; i++)
    {
        if(lista[i].id==id )
        {
            indice=i;
        }
    }
    return indice;
}


int bajaNotebooks(eNotebook lista[], int tamn, eMarca marcas[],int tamm, eTipo tipos[], int tamt, eCliente clientes[],int  tamc)
{
    int todoOk=0;
    int id;
    int indice;

    printf("<<<<<<<<<<BAJA NOTEBOOKS<<<<<<<<<<<<<<<\n");
    mostrarNotebooks(lista, tamn, marcas, tamm, tipos, tamt,clientes, tamc);
    printf("\nIngrese el ID de la notebook a dar de baja: \n");
    scanf("%d", &id);
    indice=buscarIndiceNotebook(lista, tamn, id);
    if(indice == -1)
    {
        printf("No se pudo realizar la baja\n");
    }
    else
    {
        lista[indice].isEmpty=0;
        todoOk=1;
    }
    return todoOk;
}

int modificarNotebook(eNotebook lista[], int tamn, eMarca marcas[],int tamm, eTipo tipos[], int tamt, eCliente clientes[], int tamc)
{
    int todoOk=0;
    int id;
    int indice;
    int opcion;

    printf("<<<<<<<<<<Modificar notebooks<<<<<<<<<<<<<<<\n");
    mostrarNotebooks(lista, tamn, marcas, tamm, tipos, tamt, clientes, tamc);
    printf("\nIngrese el id de la notebook a modificar: \n");
    scanf("%d", &id);
    indice=buscarIndiceNotebook(lista, tamn, id);
    if(indice == -1)
    {
        printf("El id que usted quiere modificar es invalido \n");
    }
    else
    {
        printf("¿Que quiere modificar?\n");
        printf("1.Tipo\n");
        printf("2.Precio\n");

        printf("Ingrese opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            mostrarTipos(tipos, tamt);
            printf("Ingrese el id del tipo: ");
            scanf("%d", &lista[indice].idTipo);
            todoOk=1;
            break;
        case 2:
            printf("Ingrese el precio: ");
            scanf("%f", &lista[indice].precio);
            todoOk=1;
            break;
        }
        todoOk=1;
    }
    return todoOk;
}

int cargarNombreNotebook(int id, eNotebook lista[], int tamn, char nombre[])
{
    int todoOk=0;
    int indice;

    if( lista != NULL && tamn >0 && nombre !=NULL)
    {
        indice=buscarIndiceNotebook(lista,tamn, id);
        if(indice != -1)
        {
            strcpy(nombre, lista[indice].modelo);
            todoOk=1;
        }
    }

    return todoOk;

}
void ordenarNotebooks(eNotebook lista[], int tamn)
{
    eNotebook auxNotebook;

    for(int i=0; i<tamn-1; i++)
    {
        for(int j= i+1; j<tamn; j++)
        {
            if(lista[i].idMarca > lista[j].idMarca || ((lista[i].idMarca == lista[j].idMarca && lista[i].precio < lista[j].precio)))
            {
                auxNotebook=lista[i];
                lista[i]=lista[j];
                lista[j]=auxNotebook;
            }

        }
    }
}

