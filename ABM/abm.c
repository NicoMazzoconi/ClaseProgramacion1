#include "abm.h"
#include "string.h"
#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>

int xxx_buscarEspacio(xxx *arrayRecibida, int sizeArray)
{
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayRecibida[i].isEmpty == 1)
        {
            return i;
        }
    }
    return -1;
}
int xxx_init(xxx *arrayRecibida, int sizeArray)
{
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        arrayRecibida[i].isEmpty = 1;
    }
}
int xxx_alta(xxx *arrayRecibida, int sizeArray)
{
    int empty;
    int j=1;
    empty = xxx_buscarEspacio(xxx *arrayRecibida, int sizeArray);
    if(empty >= 0)
    {
        do
        {
            if(getStringLetras("Ingrese su nombre", arrayRecibida[empty].nombre))
            {
                j=0;
            }
        }while(j!=0);
    }
    else
        printf("No se encontro espacio vacio en la array");
}
int xxx_baja(int nombre, xxx *arrayRecibida, int sizeArray)
{
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        if(strcmp(arrayRecibida[i].nombre, nombre))
            break;
    }
    if(i != sizeArray)
    {
        arrayRecibida[i].isEmpty = 1;
    }
}
int xxx_mod(xxx *arrayRecibida, int sizeArray)
{
    char seguir='s';
    int opcion;
    while(seguir == 's')
    {
        printf("1) Cambiar nombre\n");
        printf("2) Salir\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1  :
                printf("Ingrese el id del nombre a cambiar");

        }
    }
}
