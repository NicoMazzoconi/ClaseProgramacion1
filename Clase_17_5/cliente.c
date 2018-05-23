#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include <string.h>



Cliente* cliente_new()
{
    return (Cliente*) malloc(sizeof(Cliente));
}

void cliente_delete(Cliente *this)
{
    free(this);
}
//gets se pueden armar cosas a partir de dos campos de estructuras


static int cliente_setId(Cliente* this)
{
    int retorno = -1;
    static int ultimoId =-1;

    if(this != NULL)//validarEdad en vez de validar todo dentro del if
    {
        ultimoId++;
        this->idCliente = ultimoId;
        retorno = 0;
    }
    return retorno;
}


int cliente_setEdad(Cliente* this, int *edad)
{
    int retorno = -1;
    if(this != NULL && !validarEdad(edad) )//validarEdad en vez de validar todo dentro del if
    {
        this->edad = edad;
        retorno = 0;
    }
    return retorno;
}

int cliente_getEdad(Cliente* this, int* edad)
{
    int retorno = -1;
    if(this != NULL && edad != NULL )//validarEdad en vez de validar todo dentro del if
    {
        *edad = this->edad;
        retorno = 0;
    }
    return retorno;
}


int cliente_setNombre(Cliente *this, char *nombre)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}

int cliente_getNombre(Cliente *this, char *nombre)
{
    int retorno = -1;

     if(this != NULL)
    {
        strcpy(*nombre, this->nombre);
         retorno = 0;
    }

    return retorno;

}


int cliente_setApellido(Cliente *this, char *Apellido)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy(this->apellido, Apellido);
        retorno = 0;
    }
    return retorno;
}


int cliente_getApellido(Cliente *this, char *Apellido)
{
    int retorno = -1;

     if(this != NULL)
    {
        strcpy(Apellido, this->apellido);
         retorno = 0;
    }

    return retorno;

}


int cliente_setCuit(Cliente *this, char *Cuit)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy(this->cuit, Cuit);
        retorno = 0;
    }
    return retorno;
}

int cliente_getCuit(Cliente *this, char *Cuit)
{
    int retorno = -1;

     if(this != NULL)
    {
        strcpy(Cuit, this->cuit);
         retorno = 0;
    }

    return retorno;

}



void cargar(Cliente **arrayC, int QTY)
{
    int i;


    for(i=0;i<QTY;i++)
    {
        *(arrayC+i) = cliente_new();

        cliente_setNombre(*(arrayC+i),"jorge");


        //(arrayA+i)->edad = 10+i;
        //arrayA[i].edad = 22; *********NO SE USA MAS***************************
    }
}

void mostrar(Cliente **arrayC, int QTY)
{
    char auxNombre[20];

    for(;QTY > 0;arrayC++, QTY--)
    {
        cliente_getNombre(*arrayC, &auxNombre);
        printf(" %s\n" , auxNombre);
    }
}



