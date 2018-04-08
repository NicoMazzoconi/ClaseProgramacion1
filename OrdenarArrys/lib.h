#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

int getInt(char *mensaje, char *error, int intentos, int maximo, int minimo, int *resultado);
float getFloat(char *mensaje, char *error, int intentos, float maximo, float minimo, float *resultado);
int getArray(char *mensaje, char *error, int intentos, int maximo, int minimo, int *resultado, int cantidad);
int mostrarArray(int *arrayRecibida, int cantidad);
int ordenarArray(int *arrayRecibida, int cantidad);
#endif // LIB_H_INCLUDED
