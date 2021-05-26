#include "notebook.h"
#include "trabajo.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int notebookTipoSeleccionado(eNotebook lista[], int tamn, eTipo tipos[], int tamt, eMarca marcas[], int tamm ,eCliente clientes[], int tamc);
float notebooksBaratas(eNotebook lista[],int tamn, eMarca marcas[], int tamm, eTipo tipos[], int tamt, eCliente clientes[], int tamc );
int notebooksSeparadaPorMarca(eNotebook notebooks[], int tamn, eTipo tipos[], int tamt, eMarca marcas[], int tamm,eCliente clientes[], int tamc);
int mostrarCantidadPorMarcaYTipo(eNotebook lista[],int tamn,eMarca marcas[],int tamm,eTipo tipos[],int tamt);
int mostrarMarcasMasElegidas(eNotebook lista[],int tamn,eMarca marcas[],int tamm);
int mostrarImportePorNotebooks(eTrabajo trabajos[],int tamtrab,eNotebook lista[],int tamn,eServicio servicios[],int tams,eMarca marcas[],int tamm,eTipo tipos[],int tamt, eCliente clientes[], int tamc);
int mostrarTrabajosPorNotebook(eTrabajo trabajos[],int tamtrab,eNotebook lista[],int tamn,eServicio servicios[],int tams,eMarca marcas[],int tamm,eTipo tipos[],int tamt, eCliente clientes[], int tamc);
int mostrarNotebooksPorServicio(eTrabajo trabajos[],int tamtrab,eNotebook lista[],int tamn,eServicio servicios[],int tams,eMarca marcas[],int tamm,eTipo tipo[],int tamt, eCliente clientes[], int tamc);
int mostrarServiciosXFecha(eTrabajo trabajos[],int tamtrab,eNotebook lista[],int tamn,eServicio servicios[],int tams,eMarca marca[],int tamm,eTipo tipo[],int tamt);
#endif // INFORMES_H_INCLUDED
