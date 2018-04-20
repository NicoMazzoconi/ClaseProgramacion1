#include "empleado.h"
#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

int getInt(char *mensaje, char *error, int intentos, int maximo, int minimo, int *resultado);
float getFloat(char *mensaje, char *error, int intentos, float maximo, float minimo, float *resultado);
void getString(char *mensaje, char *input);
int buscarLibre(Empleado* arrayEmpleados,int sizeArray);
int esString(char *arrayRecibida);
#endif // LIB_H_INCLUDED
