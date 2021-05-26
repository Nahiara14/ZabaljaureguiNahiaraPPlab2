#include <stdio.h>
#include <stdlib.h>
#include "informes.h"
int notebookMarcaSeleccionado(eNotebook lista[], int tamn, eTipo tipos[], int tamt, eMarca marcas[], int tamm,eCliente clientes[], int tamc)
{
    int error = -1;
    int idMarca;
    int flag =0;

    if( lista!= NULL && tamn > 0 && tipos != NULL && tamt >0 && clientes  != NULL && tamc>0 && marcas != NULL && tamm> 0)
    {
        system("cls");
        printf("LISTADO DE NOTEBOOKS POR MARCA\n");

        mostrarMarcas(marcas,tamm);
        printf("Ingrese el id de la marca que desea listar: \n");
        fflush(stdin);
        scanf("%d",&idMarca);
        system("cls");
        printf("   ID              MODELO         MARCA            TIPO          PRECIO          CLIENTE\n\n");
        for(int i=0; i < tamn; i++)
        {
            if(lista[i].isEmpty && (lista[i].idMarca == idMarca))
            {
                mostrarNotebook(lista[i], marcas, tamm, tipos, tamt, clientes, tamc);
                flag = 1;
            }
        }
        printf("\n\n");
        if(flag)
        {
            printf("No se ingreso ninguna notebook\n");
        }
        error = 0;
    }
    return error;
}
int notebookTipoSeleccionado(eNotebook lista[], int tamn, eTipo tipos[], int tamt, eMarca marcas[], int tamm,eCliente clientes[], int tamc)
{
    int error = -1;
    int idTipo;
    int flag =0;

    if( lista!= NULL && tamn > 0 && tipos != NULL && tamt >0 && clientes  != NULL && tamc>0 && marcas != NULL && tamm> 0)
    {
        system("cls");
        printf("LISTADO DE NOTEBOOKS POR TIPO\n");

        mostrarTipos(tipos,tamt);
        printf("Ingrese el id del tipo que desea listar: \n");
        fflush(stdin);
        scanf("%d",&idTipo);
        system("cls");
        printf("   ID              MODELO         MARCA            TIPO          PRECIO          CLIENTE\n\n");
        for(int i=0; i < tamn; i++)
        {
            //if(lista[i].isEmpty && (lista[i].idTipo == idTipo))
            {
                mostrarNotebook(lista[i], marcas, tamm, tipos, tamt, clientes, tamc);
                flag = 1;
            }
        }
        printf("\n\n");
        if(!flag)
        {
            printf("No se ingreso ninguna notebook\n");
        }
        error = 0;
    }
    return error;
}
float notebooksBaratas(eNotebook lista[],int tamn, eMarca marcas[], int tamm, eTipo tipos[], int tamt, eCliente clientes[], int tamc )
{
   float masBarata;
	int flag = 0;

	system("cls");
	printf("** Informe Notebooks Mas Baratas **\n\n");

	for(int i = 0; i < tamn; i++)
	{
		if(flag == 0 && lista[i].isEmpty == 0)
		{
			masBarata = lista[i].precio;
			flag = 1;
		}
		else if (lista[i].isEmpty == 0 && lista[i].precio < masBarata)
		{
			masBarata = lista[i].precio;
		}
	}
	printf("El precio de las notebooks mas baratas es de: $ %.2f y son las siguientes: \n\n", masBarata);
	printf("ID           Modelo          Marca          Tipo        Precio\n\n");
	for(int i = 0; i < tamn; i++)
	{
		if(lista[i].precio == masBarata)
		{
			mostrarNotebook(lista[i], marcas, tamm, tipos, tamt, clientes, tamc);
		}
	}
}

int notebooksSeparadaPorMarca(eNotebook notebooks[], int tamn, eTipo tipos[], int tamt, eMarca marcas[], int tamm,eCliente clientes[], int tamc)
{
    int flag;
    int invalido = -1;
    system("cls");
    printf("** Informe de notebooks por marca **\n\n");
    for(int i=0; i < tamt; i++)
    {
        flag=0;
        printf(" \n Marca: %s\n",marcas[i].descripcion);
        printf(" ------\n\n");
        for(int j=0; j<tamn; j++)
        {
            if(notebooks[j].isEmpty == 0 && notebooks[j].idMarca == marcas[i].id)
            {
                mostrarNotebook(notebooks[j],tipos,tamt, marcas, tamm, clientes,tamc);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("No hay notebooks para mostrar \n\n");
        }
    }
    return invalido;
}
int mostrarCantidadPorMarcaYTipo(eNotebook lista[],int tamn,eMarca marcas[],int tamm,eTipo tipos[],int tamt)
{
    int retorno=-1;
    int opcionMarca;
    int opcionTipo;
    int contador=0;
    char descripMarca[25];
    char descripTipo[25];

    if(lista != NULL && tamn > 0 && marcas!= NULL && tamm > 0 && tipos != NULL && tamt > 0)
    {

        system("cls");
        printf("----------------------------------------------------------------------------------------------------------------------\n");
        printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< CONTADOR POR MARCA Y TIPO <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
        printf("--------------------------------------------------------------------------------------------------------------------\n\n");


        mostrarMarcas(marcas,tamm);
        printf("Ingrese el id de la marca que desea listar: \n");
        scanf("%d",&opcionMarca);

        cargarDescripcionMarca(marcas,tamm,opcionMarca,descripMarca);

        system("cls");
        mostrarTipos(tipos,tamt);
        printf("Ingrese el id  del tipo que desea listar: ");
        scanf("%d", &opcionTipo);

        cargarDescripcionTipo(tipos,tamt,opcionTipo,descripTipo);

        for(int i=0; i<tamn; i++)
        {

            if(!lista[i].isEmpty && (lista[i].idTipo == opcionTipo)&& (lista[i].idMarca == opcionMarca))
            {

                contador++;


            }

        }

        system("cls");
        printf("hay %d notebooks de marca %s y de tipo %s \n",contador,descripMarca,descripTipo);



        retorno=0;
    }

    return retorno;
}
int mostrarMarcasMasElegidas(eNotebook lista[],int tamn,eMarca marcas[],int tamm)
{
    int retorno=-1;
    int contadores[tamm];
    int mayor;
    int flag=0;

    if(lista != NULL && tamn > 0 && marcas != NULL && tamm > 0)
    {
        printf("----------------------------------------------------------------------------------------------------------------------\n");
        printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  MAS ELEGIDOS  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
        printf("--------------------------------------------------------------------------------------------------------------------\n\n");
        for(int i=0; i<tamm; i++)
        {
            contadores[i]=0;
        }

        for(int m=0; m<tamm; m++)
        {


            for(int n=0; n<tamn; n++)
            {
                if(!lista[n].isEmpty && lista[n].idMarca == marcas[m].id)
                {
                    contadores[m]++;
                }
            }
        }
        for(int i=0; i<tamm; i++)
        {
            if(contadores[i]> mayor ||flag ==0)
            {
                mayor=contadores[i];
                flag=1;
            }
        }
        printf("La o las marcas mas elegidos son : \n");
        for(int i=0; i<tamm; i++)
        {
            if(contadores[i] ==mayor)
            {
                printf("%s\n",marcas[i].descripcion);
            }
        }
        printf("\n\n");

        retorno=0;

    }
    return retorno;
}

int mostrarImportePorNotebooks(eTrabajo trabajos[],int tamtrab,eNotebook lista[],int tamn,eServicio servicios[],int tams,eMarca marcas[],int tamm,eTipo tipos[],int tamt, eCliente clientes[], int tamc)
{
    int retorno=-1;
    int opcion;
    int idServicio;
    float total = 0;

    if(trabajos !=NULL && tamtrab > 0 && lista != NULL && tamn > 0 && servicios != NULL && tams > 0 && marcas != NULL && tamm > 0 && tipos != NULL && tamt > 0)
    {
        system("cls");
        mostrarNotebooks(lista,tamn,tipos,tamt,marcas,tamm, clientes, tamc);

        printf("Ingrese el id de la notebook que se quiere saber el importe: ");
        scanf("%d", &opcion);

        for(int i=0; i<tamtrab; i++)
        {
            if(trabajos[i].idNotebook == opcion && !trabajos[i].isEmpty)
            {

                idServicio=trabajos[i].idServicio;

                for(int j=0; j<tams; j++)
                {
                    if(servicios[j].id == idServicio )
                    {
                        total=total + servicios[j].precio;

                    }
                }

            }
        }
        printf("El total gastado por el id %d es %.2f\n",opcion,total);
    }

    return retorno;
}
int mostrarTrabajosPorNotebook(eTrabajo trabajos[],int tamtrab,eNotebook lista[],int tamn,eServicio servicios[],int tams,eMarca marcas[],int tamm,eTipo tipos[],int tamt, eCliente clientes[], int tamc)
{
    int retorno=-1;
    int opcion;

    if(trabajos !=NULL && tamtrab > 0 && lista != NULL && tamn > 0 && servicios != NULL && tams > 0 && marcas != NULL && tamm > 0 && tipos != NULL && tamt > 0)
    {
        system("cls");
        mostrarNotebooks(lista,tamn,marcas,tamm,tipos,tamt, clientes, tamc);
        printf("Ingrese id de la notebook que quiere listar: ");
        scanf("%d", &opcion);

        system("cls");
        printf("---------------------------------------------------------------------------------------------------------------------\n");
        printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< NOTEBOOKS X TRABAJO <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
        printf("-------------------------------------------------------------------------------------------------------------------\n\n");
        printf("ID TRABAJOS            MARCA                             SERVICIO                               FECHA\n\n");
        for(int i=0; i<tamtrab; i++)
        {
            if(trabajos[i].idNotebook == opcion && !trabajos[i].isEmpty)
            {
                mostrarTrabajo(trabajos[i],lista,tamn,servicios,servicios);
            }
        }
    }
    return retorno;
}
int mostrarNotebooksPorServicio(eTrabajo trabajos[],int tamtrab,eNotebook lista[],int tamn,eServicio servicios[],int tams,eMarca marcas[],int tamm,eTipo tipo[],int tamt, eCliente clientes[], int tamc)
{
    int retorno= -1;
    int opcion;
    char descripServicio[25];
    if(trabajos !=NULL && tamtrab > 0 && lista != NULL && tamn > 0 && servicios != NULL && tams > 0 && marcas != NULL && tamm > 0 && tipo
            != NULL && tamt > 0)
    {

        system("cls");
        mostrarServicios(servicios,tams);
        printf("Ingrese el id del servicio que desea: \n");
        scanf("%d", &opcion);

        system("cls");
        printf("-----------------------------------------------------------------------------------------------------------------------\n");
        printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Notebooks por servicio<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
        printf("---------------------------------------------------------------------------------------------------------------------\n\n");

        cargarDescripcionServicio(servicios, tams,opcion,descripServicio);
        printf("El servicio seleccionado es %s\n\n",descripServicio);
        printf("ID                     MODELO            DESCRIPCION           FECHA      \n\n");

        for(int i=0; i<tamtrab; i++)
        {

            if(trabajos[i].idServicio == opcion && !trabajos[i].isEmpty)
            {
                for(int j=0; j< tamn; j++)
                {

                    if(trabajos[i].idNotebook == lista[j].id && !lista[j].isEmpty)
                    {
                        printf("______________________________________________________________________________________________________________________\n");
                        mostrarNotebook(lista[i],marcas,tamm,tipo,tamt, clientes, tamc);

                        printf("\nLa fecha en la que se realizo el trabajo es:%d/%d/%d\n",trabajos[i].fecha.dia,trabajos[i].fecha.mes,trabajos[i].fecha.anio);
                        printf("______________________________________________________________________________________________________________________\n");

                    }
                }

            }

        }

        retorno = 0;
    }


    return retorno;
}

int mostrarServiciosXFecha(eTrabajo trabajos[],int tamtrab,eNotebook lista[],int tamn,eServicio servicios[],int tams,eMarca marca[],int tamm,eTipo tipo[],int tamt)
{
    int retorno=-1;
    eFecha auxFecha;
    int entero;
    char descripServicio[25];
    int flag = 1;

    if(trabajos !=NULL && tamtrab > 0 && lista != NULL && tamn > 0 && servicios != NULL && tams > 0 && marca != NULL && tamm > 0 && tipo != NULL && tamt> 0)
    {

        system("cls");
        printf("Ingrese dia\n");
        auxFecha.dia=entero;
        printf("Ingrese mes\n");
        auxFecha.mes=entero;
        printf("Ingrese anio\n");
        auxFecha.anio=entero;

        for(int i=0; i<tamtrab; i++)
        {
            if(!trabajos[i].isEmpty && (auxFecha.dia == trabajos[i].fecha.dia) &&(auxFecha.mes == trabajos[i].fecha.mes) && (auxFecha.anio == trabajos[i].fecha.anio))
            {
                flag=0;
                retorno=0;
                cargarDescripcionServicio(servicios,tams,trabajos[i].idServicio,descripServicio);
                printf("Se hizo el servicio %s en la fecha %d/%d/%d\n",descripServicio,trabajos[i].fecha.dia,trabajos[i].fecha.mes,trabajos[i].fecha.anio);
            }
        }

        if(flag)
        {
            printf("No hay servicios con esa fecha\n");
        }
    }
    return retorno;
}
