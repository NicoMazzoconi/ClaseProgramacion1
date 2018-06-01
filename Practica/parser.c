#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"


int parserEmployee(char* path , ArrayList* pArrayListEmployee)
{
    Cliente* auxCliente;
    int retorno = -1;
    FILE* pFile;
    char nombre[64];
    char apellido[64];
    char email[256];
    char genero[10];
    char profesion[256];
    char nacionalidad[256];
    char usuario[64];
    char auxId[10];
    int id;
    if(path != NULL)
    {
        pFile= fopen(path, "r");
        if(pFile != NULL && pArrayListEmployee != NULL)
        {
            retorno = 0;
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, nombre, apellido, email, genero, profesion, usuario, nacionalidad);
            while(!feof(pFile))
            {
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, nombre, apellido, email, genero, profesion, usuario, nacionalidad);
                id = atoi(auxId);
                auxCliente = cliente_newParametros(nombre, apellido, email, genero, profesion, nacionalidad, usuario, id);
                al_add(pArrayListEmployee, auxCliente);
            }
        }
        fclose(pFile);
    }
    return retorno;
}

int parser_guardarTexto(ArrayList* array, char* path)
{
    int retorno = -1;
    FILE* pFile;
    char nombre[64];
    char apellido[64];
    char email[256];
    char genero[1];
    char profesion[256];
    char nacionalidad[256];
    char usuario[64];
    int id;
    if(array != NULL && path != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            int i;
            Cliente* auxCliente;
            for(i = 0; i < al_len(array);i++)
            {
                auxCliente = al_get(array, i);
                cliente_getNombre(auxCliente, nombre);
                cliente_getApellido(auxCliente, apellido);
                cliente_getEmail(auxCliente, email);
                cliente_getGenero(auxCliente, genero);
                cliente_getNacionalidad(auxCliente, nacionalidad);
                cliente_getProfesion(auxCliente, profesion);
                cliente_getUsuario(auxCliente, usuario);
                cliente_getId(auxCliente, &id);
                fprintf(pFile, "%d,%s,%s,%s,%s,%s,%s,%s\n", id, nombre, apellido, email, genero, profesion, usuario, nacionalidad);
            }
        }
    }
    fclose(pFile);
    return retorno;
}

int parser_guardarBinario(ArrayList* array, char* path)
{
    int retorno = -1;
    FILE* pFile;
    char nombre[64];
    char apellido[64];
    char email[256];
    char genero[1];
    char profesion[256];
    char nacionalidad[256];
    char usuario[64];
    int id;
    if(array != NULL && path != NULL)
    {
        pFile = fopen(path, "wb");
        if(pFile != NULL)
        {
            int i;
            Cliente* auxCliente;
            for(i = 0; i < al_len(array);i++)
            {
                auxCliente = al_get(array, i);
                cliente_getNombre(auxCliente, nombre);
                cliente_getApellido(auxCliente, apellido);
                cliente_getEmail(auxCliente, email);
                cliente_getGenero(auxCliente, genero);
                cliente_getNacionalidad(auxCliente, nacionalidad);
                cliente_getProfesion(auxCliente, profesion);
                cliente_getUsuario(auxCliente, usuario);
                cliente_getId(auxCliente, &id);
                fprintf(pFile, "%d,%s,%s,%s,%s,%s,%s,%s\n", id, nombre, apellido, email, genero, profesion, usuario, nacionalidad);
            }
        }
    }
    fclose(pFile);
    return retorno;
}

