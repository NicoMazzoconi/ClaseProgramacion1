/* Ejercicio array paralelos:
*** Datos hardcodeados
*** Crear char[] apellidos, 2int[5](nota 1 y nota 2) y un float[5] (promedio)
*** Pedir nombre, nota1, nota2, y calcular promedio
*** funcion sacarPromedio
*/
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define QTY 5

int main()
{
    char apellido[QTY][20] = {"Mazzoconi", "Tritto", "Gorraiz", "Perez", "Yema"};
    int notaUno[QTY] = {10, 4, 2, 9, 8};
    int notaDos[QTY] = {1, 8, 2, 8, 10};
    float promedio[QTY];

    sacarPromedio(notaUno, notaDos, promedio, QTY);
    mostrar(apellido, notaUno, notaDos, promedio, QTY);
    ordenarArrayIntInsertion(promedio, QTY, 1, notaUno, notaDos, apellido);
    mostrar(apellido, notaUno, notaDos, promedio, QTY);

    return 0;
}
