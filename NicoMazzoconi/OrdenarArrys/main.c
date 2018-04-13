#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define QTY 6

int main()
{
    int ArrayDesordenada[QTY];

    getArray("Ingrese un valor", "fura de rango\n", 0, 100, 0, ArrayDesordenada, QTY);
  //  mostrarArray(&ArrayDesordenada, QTY);
    //burbujeo(&ArrayDesordenada, QTY, 1);
    //mostrarArray(&ArrayDesordenada, QTY);
   // burbujeo(&ArrayDesordenada, QTY, 0);
    desplazarProfe(ArrayDesordenada, QTY, 2, 2, 1);
    mostrarArray(ArrayDesordenada, QTY);
    return 0;
}
