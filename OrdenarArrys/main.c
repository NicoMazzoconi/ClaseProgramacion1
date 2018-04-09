#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define QTY 4

int main()
{
    int ArrayDesordenada[QTY];

    getArray("Ingrese un valor", "fura de rango", 2, 100, 0, &ArrayDesordenada, QTY);
  //  mostrarArray(&ArrayDesordenada, QTY);
    ordenarArrayMejorado(&ArrayDesordenada, QTY);
    mostrarArray(&ArrayDesordenada, QTY);
    return 0;
}
