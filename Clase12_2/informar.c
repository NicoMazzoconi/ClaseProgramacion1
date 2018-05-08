#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "Pantalla.h"


int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(arrayC[i].cuit,cuit))
            {
                indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                printf("\n\nCuit: %s - Unitario: %.2f - Total: %.2f - Dias: %d\n",
                                    arrayC[i].cuit,
                                    pantallas[indexPantalla].precio,
                                    (arrayC[i].dias * pantallas[indexPantalla].precio),
                                    arrayC[i].dias );
            }
        }

        retorno = 0;
    }
    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
                if(!arrayC[i].isEmpty)
                {
                    indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                    printf("\nCuit: %s - Nombre: %s - Video: %s - Dias: %d\n",
                                        arrayC[i].cuit,
                                        pantallas[indexPantalla].nombre,
                                        arrayC[i].archivo,
                                        arrayC[i].dias );
                }


        }

        retorno = 0;
    }
    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    //int indexPantalla;
    char ultimoCuit[50];

    cont_ordenarCuit(arrayC,limite,0);
    strcpy(ultimoCuit,"");
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
                if(!arrayC[i].isEmpty)
                {
                    if(strcmp(ultimoCuit,arrayC[i].cuit) != 0)
                    {
                        printf("\nCuit: %s", arrayC[i].cuit);
                        strcpy(ultimoCuit,arrayC[i].cuit);
                    }


                    //indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                    /*printf("\nCuit: %s - Nombre: %s - Video: %s - Dias: %d\n",
                                        arrayC[i].cuit,
                                        pantallas[indexPantalla].nombre,
                                        arrayC[i].archivo,
                                        arrayC[i].dias );*/

                }


        }

        retorno = 0;
    }
    return retorno;
}


int clientesGastosContrataciones(Contratacion *arrayC, Pantalla *arrayP, int QTYC, int QTYP)
{
    int i;
    char ultimoCuit[50];
    int contrataciones;
    int gasto;
    cont_ordenarCuit(arrayC,QTYC,0);
    strcpy(ultimoCuit,"");
    for(i=0;i<QTYC;i++)
    {
        if(!arrayC[i].isEmpty)
        {
            if(strcmp(ultimoCuit, arrayC[i].cuit) != 0)
            {
                contrataciones = cantidadContrataciones(arrayC, QTYC, arrayC[i].cuit);
                gasto = cuitGastos(arrayC, QTYC, arrayP, QTYP, arrayC[i].cuit);
                printf("CUIT: %s - CONTRATACIONES: %d - GASTO: %d\n", arrayC[i].cuit, contrataciones, gasto);
                strcpy(ultimoCuit, arrayC[i].cuit);
            }
        }
    }
    return 0;
}

int cantidadContrataciones(Contratacion *arrayC, int QTYC, char *cuit)
{
    int i;
    int acumulador=0;
    for(i=0;i<QTYC; i++)
    {
        if(!arrayC[i].isEmpty)
        {
            if(!strcmp(arrayC[i].cuit, cuit))
            {
                acumulador++;
            }
        }
    }
    return acumulador;
}

int cuitGastos(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int gasto;
    int i;
    int indexPantalla;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(arrayC[i].cuit,cuit))
            {
                indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                gasto = (arrayC[i].dias * pantallas[indexPantalla].precio);
            }
        }

    }
    return gasto;
}

int ordenarPrecioNombre(Pantalla *arrayP, int QTYP)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Pantalla auxiliarPantalla;

    if(QTYP > 0 && arrayP != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<QTYP-1;i++)
            {
                if(!arrayP[i].isEmpty && !arrayP[i+1].isEmpty)
                {
                    if(arrayP[i].precio >= arrayP[i+1].precio) //******
                    {
                        if(arrayP[i].precio != arrayP[i+1].precio)
                        {
                            auxiliarPantalla = arrayP[i];
                            arrayP[i] = arrayP[i+1];
                            arrayP[i+1] = auxiliarPantalla;
                            flagSwap = 1;
                        }
                        else
                            if(strcmp(arrayP[i].nombre, arrayP[i+1].nombre) > 0)
                            {
                                auxiliarPantalla = arrayP[i];
                                arrayP[i] = arrayP[i+1];
                                arrayP[i+1] = auxiliarPantalla;
                                flagSwap = 1;
                            }
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

int pantallasValorInferiorMil(Pantalla *arrayP, int QTYP)
{
    int i;
    for(i=0;i<QTYP;i++)
    {
        if(arrayP[i].precio <= 1000 && !arrayP[i].isEmpty)
            printf("[RELEASE] - %d - %s - %d - %.2f\n",arrayP[i].idPantalla, arrayP[i].nombre, arrayP[i].isEmpty, arrayP[i].precio);
    }
}


float promedioPrecioPantalla(Pantalla *arrayP, int QTYP)
{
    int i;
    float acumulador = 0;
    float contador = 0;
    for(i=0; i < QTYP; i++)
    {
        if(!arrayP[i].isEmpty)
        {
            contador++;
            acumulador = acumulador + arrayP[i].precio;
        }
    }
    return acumulador / contador;
}
int listarPantallasPrecioMayorPromedio(Pantalla *arrayP, int QTYP)
{
    int i;
    float promedio = promedioPrecioPantalla(arrayP, QTYP);
    for(i=0;i<QTYP;i++)
    {
        if(!arrayP[i].isEmpty && (arrayP[i].precio > promedio))
        {
            printf("[RELEASE] - %d - %s - %d - %.2f\n",arrayP[i].idPantalla, arrayP[i].nombre, arrayP[i].isEmpty, arrayP[i].precio);
        }
    }
}

int listarPantallasPrecioMenorPromedio(Pantalla *arrayP, int QTYP)
{
    int i;
    float promedio = promedioPrecioPantalla(arrayP, QTYP);
    for(i=0;i<QTYP;i++)
    {
        if(!arrayP[i].isEmpty && (arrayP[i].precio < promedio))
        {
            printf("[RELEASE] - %d - %s - %d - %.2f\n",arrayP[i].idPantalla, arrayP[i].nombre, arrayP[i].isEmpty, arrayP[i].precio);
        }
    }
}

int contarPublicacionesPantalla(Contratacion *arrayC, int QTYC, int idPantalla)
{
    int i;
    int contador=0;
    for(i=0;i<QTYC;i++)
    {
        if(!arrayC[i].isEmpty && arrayC[i].idPantalla == idPantalla)
            contador++;
    }
    return contador;
}

int pantallasMasUnaPublicacion(Pantalla *arrayP, int QTYP, Contratacion *arrayC, int QTYC)
{
    int i;
    for(i=0;i<QTYP;i++)
    {
        if(!arrayP[i].isEmpty)
        {
            if(contarPublicacionesPantalla(arrayC, QTYC, arrayP[i].idPantalla) > 1)
                printf("[RELEASE] - %d - %s - %d - %.2f\n",arrayP[i].idPantalla, arrayP[i].nombre, arrayP[i].isEmpty, arrayP[i].precio);
        }
    }
}

int diasContratadaPantalla(Contratacion *arrayC, int QTYC, int idPantalla)
{
    int i;
    int dias = 0;
    for(i=0;i<QTYC;i++)
    {
        if(!arrayC[i].isEmpty && arrayC[i].idPantalla == idPantalla)
            dias = dias + arrayC[i].dias;
    }
    return dias;
}
int listarPantallaConFacturacion(Pantalla *arrayP, int QTYP, Contratacion *arrayC, int QTYC)
{
    int i;
    float facturacion;
    int dias;
    for(i=0;i<QTYP;i++)
    {
        if(!arrayP[i].isEmpty)
        {
            dias = diasContratadaPantalla(arrayC, QTYC, arrayP[i].idPantalla);
            facturacion = dias * arrayP[i].precio;
            printf("[RELEASE] - %d - %s - %.2f\n",arrayP[i].idPantalla, arrayP[i].nombre, facturacion);
        }
    }
}

int pantallaMasFactracion(Pantalla *arrayP, int QTYP, Contratacion *arrayC, int QTYC)
{
    int i;
    float maximo;
    float facturacion;
}
