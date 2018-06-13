#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cliente.h"
#include <string.h>
#include "utn.h"

static int isValidName(char* name);
static int isValidLastName(char* lastName);
static int isValidEmail(char* email);
static int isValidGenero(char* genero);
static int isValidProfesion(char* profesion);
static int isValidNacionalidad(char* nacionalidad);
static int isValidUsuario(char* usuario);

Cliente* cliente_new()
{
    return (Cliente*) malloc(sizeof(Cliente));
}

void cliente_delete(Cliente* this)
{
    free(this);
}

Cliente* cliente_newParametros(char* nombre, char* apellido, char* email, char* genero, char* profesion, char* nacionalidad, char* usuario, int id)
{
    Cliente* auxC = cliente_new();
    if(     !cliente_setNombre(auxC, nombre)
       &&   !cliente_setApellido(auxC, apellido)
       &&   !cliente_setEmail(auxC, email)
       &&   !cliente_setGenero(auxC, genero)
       &&   !cliente_setProfesion(auxC, profesion)
       &&   !cliente_setNacionalidad(auxC, nacionalidad)
       &&   !cliente_setUsuario(auxC, usuario)
       &&   !cliente_setId(auxC, id))
    {
        return auxC;
    }
    cliente_delete(auxC);
    return NULL;
}

int cliente_setNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL && isValidName(nombre))
    {
        retorno = 0;
        strcpy(this->nombre, nombre);
    }
    return retorno;
}
int cliente_getNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        strcpy(nombre, this->nombre);
    }
    return retorno;
}
int cliente_setApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL && isValidLastName(apellido))
    {
        retorno = 0;
        strcpy(this->apellido, apellido);
    }
    return retorno;
}
int cliente_getApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        retorno = 0;
        strcpy(apellido, this->apellido);
    }
    return retorno;
}
int cliente_setEmail(Cliente* this, char* email)
{
    int retorno = -1;
    if(this != NULL && email != NULL && isValidEmail(email))
    {
        retorno = 0;
        strcpy(this->email, email);
    }
    return retorno;
}
int cliente_getEmail(Cliente* this, char* email)
{
    int retorno = -1;
    if(this != NULL && email != NULL)
    {
        retorno = 0;
        strcpy(email, this->email);
    }
    return retorno;
}
int cliente_setGenero(Cliente* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL && isValidGenero(genero))
    {
        retorno = 0;
        strcpy(this->genero, genero);
    }
    return retorno;
}
int cliente_getGenero(Cliente* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        retorno = 0;
        strcpy(genero, this->genero);
    }
    return retorno;
}
int cliente_setProfesion(Cliente* this, char* profesion)
{
    int retorno = -1;
    if(this != NULL && profesion != NULL && isValidProfesion(profesion))
    {
        retorno = 0;
        strcpy(this->profesion, profesion);
    }
    return retorno;
}
int cliente_getProfesion(Cliente* this, char* profesion)
{
    int retorno = -1;
    if(this != NULL && profesion != NULL)
    {
        retorno = 0;
        strcpy(profesion, this->profesion);
    }
    return retorno;
}
int cliente_setNacionalidad(Cliente* this, char* nacionalidad)
{
    int retorno = -1;
    if(this != NULL && nacionalidad != NULL && isValidNacionalidad(nacionalidad))
    {
        retorno = 0;
        strcpy(this->nacionalidad, nacionalidad);
    }
    return retorno;
}
int cliente_getNacionalidad(Cliente* this, char* nacionalidad)
{
    int retorno = -1;
    if(this != NULL && nacionalidad != NULL)
    {
        retorno = 0;
        strcpy(nacionalidad, this->nacionalidad);
    }
    return retorno;
}


int cliente_setId(Cliente* this, int id)
{
    int retorno = -1;
    static int maximoId = -1;
    if(this != NULL)
    {
        retorno = 0;
        if(id >= 0)
        {
            this->id = id;
            if(id > maximoId)
                maximoId = id;
        }
        else
        {
            maximoId++;
            this->id = maximoId;
        }
    }
    return retorno;
}
int cliente_getId(Cliente* this, int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}
int cliente_setUsuario(Cliente* this, char* usuario)
{
    int retorno = -1;
    if(this != NULL && usuario != NULL && isValidUsuario(usuario))
    {
        retorno = 0;
        strcpy(this->usuario, usuario);
    }
    return retorno;
}
int cliente_getUsuario(Cliente* this, char* usuario)
{
    int retorno = -1;
    if(this != NULL && usuario != NULL)
    {
        retorno = 0;
        strcpy(usuario, this->usuario);
    }
    return retorno;
}

void cliente_print(Cliente* this)
{
    char nombre[64];
    char apellido[64];
    char email[256];
    int id;
    if(this != NULL)
    {
        cliente_getNombre(this, nombre);
        cliente_getApellido(this, apellido);
        cliente_getEmail(this, email);
        cliente_getId(this, &id);
        printf("Nombre: %s, Apellido: %s, Email: %s, ID: %d\n", nombre, apellido, email, id);
    }
}

int cliente_compareNameLastName(void* clienteA, void* clienteB)
{
    char nombreA[64];
    char nombreB[64];
    char apellidoA[64];
    char apellidoB[64];
    cliente_getNombre(clienteA, nombreA);
    cliente_getNombre(clienteB, nombreB);
    cliente_getApellido(clienteA, apellidoA);
    cliente_getApellido(clienteB, apellidoB);
    if(strcmp(nombreA, nombreB) == 0)
    {
        return strcmp(apellidoA, apellidoB);
    }
    else
        return strcmp(nombreA, nombreB);
}

int cliente_compareEmail(void* clienteA, void* clienteB)
{
    char emailA[256];
    char emailB[256];
    cliente_getEmail(clienteA, emailA);
    cliente_getEmail(clienteB, emailB);
    return strcmp(emailA, emailB);
}

int cliente_alta(ArrayList* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = -2;
        Cliente* auxCliente = cliente_new();
        char nombre[64];
        char apellido[64];
        char email[256];
        char genero[1];
        char profesion[256];
        char nacionalidad[256];
        char usuario[64];
        if(!getValidString("Nombre?\n", "nombre invalido\n", "Demasiado largo\n", nombre, 64, 2))
            if(!getValidString("Apellido?\n", "apellido invalido\n", "Demasiado largo\n", apellido, 64, 2))
                if(!getValidString("Email??\n", "email invalido\n", "Demasiado largo\n", email, 256, 2))
                    if(!getValidString("Genero?\n", "genero invalido\n", "Demasiado largo\n", genero, 2, 2))
                        if(!getValidString("Profesion?\n", "profesion invalido\n", "Demasiado largo\n", profesion, 256, 2))
                            if(!getValidString("Nacionalidad?\n", "nacionalidad invalido\n", "Demasiado largo\n", nacionalidad, 256, 2))
                                if(!getValidString("Usuario?\n", "usuario invalido\n", "Demasiado largo\n", usuario, 64, 2))
                                {
                                    auxCliente = cliente_newParametros(nombre, apellido, email, genero, profesion, nacionalidad, usuario, -1);
                                    al_add(this, auxCliente);
                                    retorno = 0;
                                }
    }
    return retorno;
}

int cliente_baja(ArrayList* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        int i,auxid;
        Cliente* auxCliente = cliente_new();
        retorno = -2;
        for(i = 0; i < al_len(this); i++)
        {
            auxCliente = al_get(this, i);
            cliente_getId(auxCliente, &auxid);
            if(auxid == id)
            {
                retorno = 0;
                break;
            }
        }
        al_remove(this, i);
    }
    return retorno;
}

int cliente_mod(ArrayList* this, int id)
{
    int retorno = -1;
    int i,auxid;
    if(this != NULL && id >= 0)
    {
        Cliente* auxCliente = cliente_new();
        retorno = -2;
        for(i = 0; i < al_len(this); i++)
        {
            auxCliente = al_get(this, i);
            cliente_getId(auxCliente, &auxid);
            if(auxid == id)
            {
                retorno = 0;
                break;
            }
        }
        char nombre[64];
        char apellido[64];
        char email[256];
        char genero[1];
        char profesion[256];
        char nacionalidad[256];
        char usuario[64];
        if(!getValidString("Nombre?\n", "nombre invalido\n", "Demasiado largo\n", nombre, 64, 2))
            if(!getValidString("Apellido?\n", "apellido invalido\n", "Demasiado largo\n", apellido, 64, 2))
                if(!getValidString("Email??\n", "email invalido\n", "Demasiado largo\n", email, 256, 2))
                    if(!getValidString("Genero?\n", "genero invalido\n", "Demasiado largo\n", genero, 2, 2))
                        if(!getValidString("Profesion?\n", "profesion invalido\n", "Demasiado largo\n", profesion, 256, 2))
                            if(!getValidString("Nacionalidad?\n", "nacionalidad invalido\n", "Demasiado largo\n", nacionalidad, 256, 2))
                                if(!getValidString("Usuario?\n", "usuario invalido\n", "Demasiado largo\n", usuario, 64, 2))
                                {
                                    auxCliente = cliente_newParametros(nombre, apellido, email, genero, profesion, nacionalidad, usuario, id);
                                    al_set(this, i, auxCliente);
                                    retorno = 0;
                                }
    }
    return retorno;
}
static int isValidName(char* name)
{
    return 1;
}

static int isValidLastName(char* lastName)
{
    return 1;
}

static int isValidEmail(char* email)
{
    return 1;
}

static int isValidGenero(char* genero)
{
    return 1;
}

static int isValidProfesion(char* profesion)
{
    return 1;
}

static int isValidNacionalidad(char* nacionalidad)
{
    return 1;
}

static int isValidUsuario(char* usuario)
{
    return 1;
}
