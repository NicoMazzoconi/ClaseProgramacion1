#include "alumno.h"
#include <stdio.h>
#include <stdlib.h>

Alumno* alumno_new()
{
    return malloc(sizeof(Alumno));
}

void alumno_delete(Alumno* this)
{
    free(this);
}

int  alumno_setEdad(Alumno* this, int edad)
{
    int retorno = -1;
    if(this != NULL && edad >= 0)
    {
        retorno = 0;
        this->edad = edad;
    }
    return retorno;
}

int alumno_getEdad(Alumno* this, int* edad)
{
    int retorno = -1;
    if(this != NULL && edad != NULL)
    {
        retorno = 0;
        *edad = this->edad;
    }
    return retorno;

}


