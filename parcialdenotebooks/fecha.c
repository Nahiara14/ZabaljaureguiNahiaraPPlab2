#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
eFecha ingresarFecha()
{
    int dia, mes, anio;
    eFecha fecha;
    int flag = 0;

    printf("Ingrese fecha dd/mm/aaaa: ");
    scanf("%d/%d/%d",&dia,&mes,&anio);


    if ( mes >= 1 && mes <= 12 )
    {
        switch ( mes )
        {
        case  1 :
        case  3 :
        case  5 :
        case  7 :
        case  8 :
        case 10 :
        case 12 :
            if ( dia >= 1 && dia <= 31 )
            {
                printf( "\nfecha valida!!\n" );
                flag = 1;
            }
            else
                printf( "\nfecha invalida\n" );
            break;

        case  4 :
        case  6 :
        case  9 :
        case 11 :
            if ( dia >= 1 && dia <= 30 )
            {
                printf( "\n fecha valida\n" );
                flag = 1;
            }
            else
                printf( "\nfecha invalida\n" );
            break;

        case  2 :
            if( anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0 )
                if ( dia >= 1 && dia <= 29 )
                {
                    printf( "\nfecha valida\n" );
                    flag = 1;
                }
                else
                    printf( "\n  fecha invalida \n" );
            else if ( dia >= 1 && dia <= 28 )
            {
                printf( "\nfecha valida\n" );
                flag = 1;
            }
            else
                printf( "\n fecha invalida \n" );
        }
    }
    else
        printf( "\nfecha invalida\n" );

    if(!flag)
    {
        ingresarFecha();
    }


    fecha.dia = dia;
    fecha.mes = mes;
    fecha.anio = anio;

    return fecha;
}
