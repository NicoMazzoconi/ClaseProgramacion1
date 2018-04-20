#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int getInt(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado)
{
    int retorno = -1;
    char buffer[4096];
    long auxiliarLong;
    do
    {
        printf("%s",mensaje);
        scanf("%4095s",buffer);
        if(esEntero(buffer) == 1)
        {
            auxiliarLong = atol(buffer);
            if(auxiliarLong >= minimo && auxiliarLong <= maximo)
            {
                *resultado = (int)auxiliarLong;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
        reIntentos--;
    }while(reIntentos >= 0);
    return retorno;
}


int esEntero(char *str)
{
    int i;
    for(i=0;str[i] != '\0';i++)
    {
        if(str[i] > '9' || str[i] < '0')
            return 0;
    }
    return 1;
}


int ordenarArrayInt(int * array,int cantidad,int orden)
{
    int i;
    int flagSwap;
    int auxiliar;

    do
    {
        flagSwap = 0;
        for(i=0;i< cantidad-1;i++)
        {
            if((array[i]>array[i+1] && orden == 0) || (array[i]<array[i+1] && orden == 1))
            {
                auxiliar = array[i];
                array[i] = array[i+1];
                array[i+1] = auxiliar;
                flagSwap = 1;
            }

        }
    }while(flagSwap);

    return 0;
}

int mostrarArrayInt(int * array,int cantidad)
{
    int i;
    printf(" ------ ");
    for(i=0;i<cantidad;i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}

int ordenarArrayIntInsertion(int * array,int cantidad,int orden)
{
	int auxiliar;
    int j, i;

	for(i = 1; i < cantidad; i++) {
		auxiliar = array[i];
		j = i;
		while(j > 0 && auxiliar < array[j - 1])
        {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = auxiliar;
	}
    return 0;
}




















