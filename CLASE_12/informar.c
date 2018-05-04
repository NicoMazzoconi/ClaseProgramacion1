#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "Pantalla.h"
#include "informar.h"


int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;
    int i;
    int indicePantalla;
    if(arrayC != NULL && pantallas != NULL && limite > 0 && lenPantallas > 0)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(arrayC[i].cuit, cuit))
            {
                indicePantalla = pantalla_buscarPorId(pantallas, lenPantallas, arrayC[i].idPantalla);
                printf("CUIT: %s - ID: %d - VALOR %.2f\n", arrayC[i].cuit, arrayC[i].id, arrayC[i].dias * pantallas[indicePantalla].precio);
            }
        }
    }
    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    int indicePantalla;
    if((limite >= 0 && arrayC != NULL) && (lenPantallas >= 0 && pantallas != NULL))
    {
        for(i = 0; i < limite; i++)
        {
            if(!arrayC[i].isEmpty)
            {
                indicePantalla = pantalla_buscarPorId(pantallas, lenPantallas, arrayC[i].idPantalla);
                printf("nombre %s, cuit %s, dias %d, archivo %s, idPantalla %d \n", pantallas[indicePantalla].nombre, arrayC[i].cuit, arrayC[i].dias, arrayC[i].archivo, arrayC[i].idPantalla);
                retorno = 0;
            }
        }
    }
    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite, Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    char ultimoCuit[50]="";
    cont_ordenarCuit(arrayC, limite, 1);
    if((limite >= 0 && arrayC != NULL) && (lenPantallas >= 0 && pantallas != NULL))
    {
        for(i = 0; i < limite; i++)
        {
            if(!arrayC[i].isEmpty && (strcmp(arrayC[i].cuit, ultimoCuit) != 0))
            {
                printf("CLIENTE %s \n", arrayC[i].cuit);
                informar_ListarContratacionesTotal(arrayC, limite, pantallas, lenPantallas, ultimoCuit);
                printf("\n");
                strcpy(ultimoCuit,arrayC[i].cuit);

            }
            else
            {

            }
        }
    }
    return retorno;
}

int informar_ListarContratacionesTotal(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    int indicePantalla;
    int contador=0;
    float acumulador =0;
    if((limite >= 0 && arrayC != NULL) && (lenPantallas >= 0 && pantallas != NULL))
    {
        for(i = 0; i < limite; i++)
        {
            if(!arrayC[i].isEmpty)
            {
                indicePantalla = pantalla_buscarPorId(pantallas, lenPantallas, arrayC[i].idPantalla);
                contador++;
                acumulador+=arrayC[i].dias*pantallas[indicePantalla].precio;
                retorno = 0;
            }
        }
    }
    printf("Cantidad contrataciones %d - Total: %.2f", contador, acumulador);
    return retorno;
}
