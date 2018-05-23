#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"


int main()
{
    Cliente *arrayPunteroC[1];
    int qtyArrayCliente=0;

    arrayPunteroC = (Cliente*) malloc(sizeof(Cliente));// se declara de tipo cliente para que sepa cuanto moverse para busca al proimo

    cargar(arrayPunteroC, 50);
    mostrar(arrayPunteroC,50);
}
