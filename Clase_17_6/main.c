#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

void mostrar(Alumno* array[],int cantidad);
void cargar(Alumno* array[],int cantidad);
int main()
{
    Alumno* arrayPunteroAlumnos[50];
    int array[50];
    cargar(arrayPunteroAlumnos,50);


    mostrar(arrayPunteroAlumnos,50);
    return 0;
}

void cargar(Alumno** array,int cantidad)
{
    int i;
    Alumno* auxiliarAlumno;
    for(i=0;i<cantidad;i++)
    {

        *(array+i)  = alumno_new();
        alumno_setEdad(*(array+i),i+10);

        auxiliarAlumno = alumno_new();
        *(array+i)  = auxiliarAlumno;
        alumno_setEdad(auxiliarAlumno,i+10);

        auxiliarAlumno = malloc(sizeof(Alumno));
        if(auxiliarAlumno != NULL)
        {
            auxiliarAlumno->edad = 44;
            *(array+i) = auxiliarAlumno;
        }


    }
}

void mostrar(Alumno* array[],int cantidad)
{
    int auxiliarEdad;
    for(;cantidad > 0; array++,cantidad--)
    {
        alumno_getEdad(*array,&auxiliarEdad);
        printf("%d\n",auxiliarEdad);
    }
}

