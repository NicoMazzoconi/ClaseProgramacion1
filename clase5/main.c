#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "libClase5.h"
#define QTY 4

int main()
{
    int i;
    int arrayEnteros[QTY];
    int auxiliarInt;
/*    for(i=0;i<QTY;i++)
    {
        getInt("\nNumero:","\nFuera Rango",2,0,100,&auxiliarInt);
        arrayEnteros[i] = auxiliarInt;
    }*/
    arrayEnteros[0] = 22;
    arrayEnteros[1] = 2;
    arrayEnteros[2] = 32;
    arrayEnteros[3] = 11;


    mostrarArrayInt(arrayEnteros,QTY);
    ordenarArrayInt(arrayEnteros,QTY,0);
    mostrarArrayInt(arrayEnteros,QTY);
    ordenarArrayInt(arrayEnteros,QTY,1);
    mostrarArrayInt(arrayEnteros,QTY);
    return 0;
}
