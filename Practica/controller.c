#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "parser.h"
#include <string.h>

void controller_leerArchivoCliente(char* path, ArrayList* array)
{   int resultado;
    resultado = parserEmployee(path , array);
    if(!resultado)
    {
        printf("Cargado correctamente");
    }
    else
    {
        printf("Error en los parametros");
    }
}

void controller_listarClientes(ArrayList* array)
{
    Cliente* auxiliarEmpleado;
    int i;
    for(i=0; i<al_len(array); i++)
    {
        auxiliarEmpleado = (Cliente*) al_get(array,i);
        cliente_print(auxiliarEmpleado);
    }
}

void controller_ordenarNameLastName(ArrayList* array)
{
    int retorno = -1;
    if(array != NULL)
    {
        al_sort(array, cliente_compareNameLastName, 1);
        retorno = 0;
    }
    if(!retorno)
        printf("Ordenado correctamente\n");
    else
        printf("Error en el arrayList");
}

void controller_ordenarEmail(ArrayList* array)
{
    int retorno = -1;
    if(array != NULL)
    {
        al_sort(array, cliente_compareEmail, 1);
        retorno = 0;
    }
    if(!retorno)
        printf("Ordenado correctamente\n");
    else
        printf("Error en el arrayList");
}


