#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cliente.h"
#include "parser.h"
#include <string.h>
#include "utn.h"
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
        auxiliarEmpleado = al_get(array,i);
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
        printf("Error en el arrayList\n");
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
        printf("Error en el arrayList\n");
}

void controller_alta(ArrayList* array)
{
    int retorno;
    if(array != NULL)
    {
        retorno = cliente_alta(array);
        if(retorno == -1)
        {
            printf("Error en los parametros\n");
        }
        else
        {
            if(retorno == -2)
                printf("Error en los datos ingresados\n");
            else
                printf("Cargado correctamente\n");
        }
    }
}

void controller_baja(ArrayList* this)
{
    int id, retorno;
    if(this != NULL)
    {
        if(!getValidInt("ID a borrar?\n", "ID invalido\n", &id, 0, 32767, 2))
        {
            retorno = cliente_baja(this, id);
        }
    }
    if(retorno == -1)
    {
        printf("Error en los parametros\n");
    }
    else
    {
        if(retorno == -2)
        {
            printf("No se encontre el ID\n");
        }
        else
            printf("Borrado correctamente\n");
    }
}

void controller_mod(ArrayList* this)
{
    int retorno, id;
    if(this != NULL)
    {
        if(!getValidInt("ID a modificar?\n", "ID invalidad\n", &id, 0, 32767, 2))
        {
            retorno = cliente_mod(this, id);
        }
    }
    if(retorno == -1)
    {
        printf("Error en los parametros\n");
    }
    else
    {
        if(retorno == -2)
        {
            printf("No se encontre el ID\n");
        }
        else
            printf("Modificado correctamente\n");
    }
}
