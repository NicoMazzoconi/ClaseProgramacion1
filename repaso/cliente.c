#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int cliente_setId(Cliente* this);
static int cliente_getId(Cliente* this, int *idCliente);

Cliente* cliente_new()
{
    return (Cliente*) malloc(sizeof(Cliente));
}

void cliente_delete(Cliente* this)
{
    free(this);
}

Cliente* cliente_new2(int edad, char *nombre, char *apellido, char *cuit)
{
    Cliente *auxArrayC = cliente_new();
    cliente_setNombre(auxArrayC, nombre);
    cliente_setApellido(auxArrayC, apellido);
    cliente_setEdad(auxArrayC, edad);
    cliente_setCuit(auxArrayC, cuit);
    cliente_setId(auxArrayC);
    return auxArrayC;
}

Cliente* cliente_modNombre(char *nombre)
{
    Cliente *auxArrayC = cliente_new();
    if(nombre != NULL)
        cliente_setNombre(auxArrayC, nombre);
    return auxArrayC;
}
Cliente* cliente_modApellido(char *apellido)
{
    Cliente *auxArrayC = cliente_new();
    if(apellido != NULL)
        cliente_setApellido(auxArrayC, apellido);
    return auxArrayC;
}
Cliente* cliente_modCuit(char *cuit)
{
    Cliente *auxArrayC = cliente_new();
    if(cuit != NULL)
        cliente_setCuit(auxArrayC, cuit);
    return auxArrayC;
}
Cliente* cliente_modEdad(int edad)
{
    Cliente *auxArrayC = cliente_new();
    if(edad != NULL)
        cliente_setEdad(auxArrayC, edad);
    return auxArrayC;
}
int cliente_setEdad(Cliente* this,int edad)
{
    int retorno = -1;
    if(this != NULL) //&& !validarEdad(edad))
    {
        this->edad = edad;
        retorno = 0;

    }
    return retorno;
}

int cliente_getEdad(Cliente* this,int* edad)
{
    int retorno = -1;
    if(this != NULL && edad != NULL)
    {
        *edad = this->edad;
        retorno = 0;
    }
    return retorno;
}

static int cliente_setId(Cliente* this)
{
    int retorno = -1;
    static int ultimoId = -1;
    if(this != NULL)
    {
        ultimoId++;
        this->idCliente = ultimoId;
        retorno = 0;
    }
    return retorno;
}

static int cliente_getId(Cliente* this, int *idCliente)
{
    int retorno = -1;
    if(this != NULL && idCliente != NULL)
    {
        *idCliente = this->idCliente;
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
        strcpy(nombre, this->nombre);
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


void mostrar(Cliente **arrayC, int QTY)
{
    char auxNombre[20];
    char auxApellido[20];
    char auxCuit[20];
    int auxEdad;
    int auxId;
    printf("Nombre\tApellido\tEdad\tID\tCUIT\n");
    for(;QTY > 0; arrayC++, QTY-- )
    {
        cliente_getNombre(*arrayC, &auxNombre);
        cliente_getApellido(*arrayC, &auxApellido);
        cliente_getCuit(*arrayC, &auxCuit);
        cliente_getEdad(*arrayC, &auxEdad);
        cliente_getId(*arrayC, &auxId);
        printf("%s\t%s\t%d\t%d\t%s\n" , auxNombre, auxApellido, auxEdad, auxId, auxCuit);
    }
}

int cliente_alta(Cliente **arrayC, int *qtyArrayClientes)
{
    char nombre[50];
    char apellido[50];
    char cuit[50];
    int edad;
    int retorno = -1;
    if(arrayC != NULL)
    {
        getValidString("Nombre?", "error", "invalido", &nombre, 20, 2);
        getValidString("Apellido?", "error", "invalido", &apellido, 20, 2);
        getValidCuit("Cuit?", "error", "invalido", &cuit, 10, 12, 2);
        getValidInt("Edad?", "error", &edad, 1, 99, 2);
        arrayC[*qtyArrayClientes] = cliente_new2(edad, nombre, apellido, cuit);
        *qtyArrayClientes = *qtyArrayClientes + 1;
        retorno = 0;
    }
    return retorno;
}

int cliente_modificar(Cliente **arrayC, int qtyArrayClientes, int id)
{
    char nombre[50];
    char apellido[50];
    char cuit[50];
    int edad;
    int retorno = -1;
    int opcion=0;
    int indice;
    if(arrayC != NULL)
    {
        indice = cliente_posicionID(arrayC, qtyArrayClientes, id);
        do
        {
            printf("1)Modificar Nombre\n2)Modificar Apellido\n3)Modificar CUIT\n4)Modificar Edad\n5)Salir");
            retorno = 0;
            opcion = getInt("");
            switch(opcion)
            {
                case 1:
                getValidString("Nombre?", "error", "invalido", &nombre, 20, 2);
                arrayC[indice] = cliente_modNombre(nombre);
                break;
                case 2:
                getValidString("Apellido?", "error", "invalido", &apellido, 20, 2);
                arrayC[indice] = cliente_modApellido(apellido);
                break;
                case 3:
                getValidCuit("Cuit?", "error", "invalido", &cuit, 10, 12, 2);
                arrayC[indice] = cliente_modCuit(cuit);
                break;
                case 4:
                getValidInt("Edad?", "error", &edad, 1, 99, 2);
                arrayC[indice] = cliente_modEdad(edad);
                break;
            }
        }while(opcion != 5);
    }
    return retorno;
}

int cliente_posicionID(Cliente **arrayC, int QTY, int id)
{
    int i;
    int retorno = -1;
    int auxID;
    if(arrayC != NULL && QTY >= 0)
    {
        for(i = 0; i < QTY; i++)
        {
            cliente_getId((*(arrayC+i)), &auxID);
            if(auxID == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
