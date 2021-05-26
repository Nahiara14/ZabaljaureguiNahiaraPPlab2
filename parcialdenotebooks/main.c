#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "marca.h"
#include "time.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"
#include "tipo.h"
#include "cliente.h"
#include "informes.h"
#include "data.h"
#include "datatrabajo.h"
#define TAMM 4
#define TAMT 4
#define TAMS 4
#define TAMN 20
#define TAMTRAB 10
#define TAMC 4

int main()
{
    //int flag=1;
    int flag=1;
    int nextIdNotebook=2000;
    int nextIdTrabajo=1000;

    eMarca marcas[TAMM]=
    {
        {1000,"Compaq"},
        {1001,"Asus"},
        {1002,"Acer"},
        {1003,"HP"}
    };

    eTipo tipos[TAMT]=
    {
        {5000,"Gamer"},
        {5001,"Disenio"},
        {5002,"Ultrabook"},
        {5003,"Normalita"}
    };

    eServicio servicios[TAMS]=
    {
        {20000, "Bateria", 250},
        {20001, "Antivirus", 300},
        {20002, "Actualizacion", 400},
        {20003, "Fuente", 600}
    };

    eNotebook notebooks[TAMM];
    eTrabajo trabajos[TAMTRAB];
    eCliente clientes[TAMC]=
    {
        {4000, "Nahiara", 'f'},
        {4001, "Morena", 'f'},
        {4002, "Romina", 'f'},
        {4003, "Facundo", 'm'}
    };
    inicializarNotebook(notebooks,TAMN);
    inicializarTrabajo(trabajos, TAMTRAB);
    nextIdNotebook+=harcodearNotebooks(notebooks,TAMN,4);
    nextIdTrabajo+=harcodearTrabajos(trabajos, TAMTRAB,4);
   // hardcodeoNotebook(notebooks);


    char salir='n';

    do
    {
        switch(menu())
        {

        case 1:
            system("cls");
            if(altaNotebook(notebooks, TAMN, marcas, TAMM, tipos, TAMT, clientes, TAMC, &nextIdNotebook))
            {
                printf("Alta exitosa !! \n");
                flag=1;
            }
            else
            {
                printf("No se pudo realizar el alta");
            }
            break;
        case 2:
            system("cls");
            if(flag!=0)
            {
                modificarNotebook(notebooks,TAMN,marcas, TAMM, tipos, TAMT, clientes, TAMC);
            }
            else
            {
                printf("Error, primero deberia dar de alta una notebook\n");
            }
            break;
        case 3:
            system("cls");
            if(flag!= 0)
            {
                bajaNotebooks(notebooks, TAMN, marcas, TAMM, tipos, TAMT, clientes, TAMC);
                flag--;
            }
            else
            {
                printf("Error, primero deberia dar de alta una notebook\n");
            }
            break;
        case 4:
            system("cls");
            if(flag!= 0)
            {

                mostrarNotebooks(notebooks,TAMN,marcas,TAMM,tipos,TAMT, clientes, TAMC);
            }
            else
            {
                printf("Error, primero deberia dar de alta una notebook\n");
            }
            break;
        case 5:
            system("cls");
            if(flag!=0)
            {
                mostrarMarcas(marcas, TAMM);
            }
            else
            {
                printf("Error, primero deberia dar de alta una notebook\n");
            }
            break;
        case 6:
            system("cls");
            if(flag!=0)
            {
                mostrarTipos(tipos, TAMT);
            }
            else
            {
                printf("Error, primero deberia dar de alta una notebook\n");
            }
            break;
        case 7:
            system("cls");
            if(flag!=0)
            {
                mostrarServicios(servicios, TAMS);
            }
            else
            {
                printf("Error, primero deberia dar de alta una notebook\n");
            }
            break;
        case 8:
            system("cls");
            if(!altaTrabajo(trabajos, TAMTRAB, notebooks,TAMN,servicios,TAMS,marcas,TAMM,tipos,TAMT,clientes, TAMC, &nextIdTrabajo))
            {
                printf("Hubo un problema para dar el alta del trabajo\n");
            }
            else
            {
                printf("Alta exitosa!\n");
            }
            break;
        case 9:
            system("cls");
            mostrarTrabajos(trabajos, TAMTRAB, notebooks, TAMN, servicios, TAMS);
            break;
        case 10:
            notebookTipoSeleccionado(notebooks, TAMN, tipos, TAMT, marcas, TAMM, clientes, TAMC);
            break;
        case 11:
            notebookMarcaSeleccionado(notebooks, TAMN, tipos, TAMT, marcas, TAMM, clientes, TAMC);
            break;
        case 12:
            notebooksBaratas(notebooks, TAMN, marcas, TAMM, tipos, TAMT, clientes, TAMC);
            break;
        case 13:
            notebooksSeparadaPorMarca(notebooks, TAMN, tipos, TAMT, marcas, TAMM, clientes, TAMC);
            break;
        case 14:
            mostrarCantidadPorMarcaYTipo(notebooks, TAMN, marcas, TAMM, tipos, TAMT);
            break;
        case 15:
            mostrarMarcasMasElegidas(notebooks,TAMN, marcas, TAMM);
            break;
        case 16:
                mostrarTrabajosPorNotebook(trabajos, TAMTRAB, notebooks, TAMN, servicios, TAMS, marcas, TAMM, tipos, TAMT, clientes, TAMC);
            break;
        case 17:
            mostrarImportePorNotebooks(trabajos, TAMTRAB, notebooks, TAMN, servicios, TAMS, marcas, TAMM, tipos, TAMT, clientes, TAMC);
            break;
        case 18:
            mostrarNotebooksPorServicio(trabajos, TAMTRAB, notebooks, TAMN, servicios, TAMS,marcas, TAMM, tipos, TAMT, clientes, TAMC);
            break;
        case 19:
            mostrarServiciosXFecha(trabajos, TAMTRAB, notebooks, TAMN, servicios, TAMS, marcas, TAMM, tipos, TAMT);
            break;
        case 20:
            printf("Esta seguro que quiere salir? ");
            fflush(stdin);
            scanf("%c", &salir);
            break;
        default:
            printf("Opcion invalida\n");
            system("pause");
        }
        system("pause");
    }
    while(salir=='n');

    return 0;
}
