#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#define QTY 50
int main()
{
    Cliente* pArrayClientes[QTY];
    int qtyArrayClientes=0;
    int id;
    cliente_alta(pArrayClientes, &qtyArrayClientes);
    cliente_alta(pArrayClientes, &qtyArrayClientes);
    mostrar(pArrayClientes, qtyArrayClientes);
    id = getInt("Ingrese el ID a modificar");
    cliente_modificar(pArrayClientes, qtyArrayClientes, id);
    mostrar(pArrayClientes, qtyArrayClientes);
    return 0;
}
