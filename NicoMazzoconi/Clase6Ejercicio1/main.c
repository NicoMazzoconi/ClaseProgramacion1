#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main()
{
    float entero;

    if(getFloat("Ingrese un float", "No valido", 2, 100, 0, &entero)==0)
    {
        printf("%.2f", entero);
    }
    else
        printf("Fuera de rango");


    return 0;

}
