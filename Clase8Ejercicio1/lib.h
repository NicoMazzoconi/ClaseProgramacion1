#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

int getInt(char *mensaje, char *error, int intentos, int maximo, int minimo, int *resultado);
float getFloat(char *mensaje, char *error, int intentos, float maximo, float minimo, float *resultado);
int getArray(char *mensaje, char *error, int intentos, int maximo, int minimo, int *resultado, int cantidad);
int mostrarArray(float *arrayRecibida, int cantidad);
int ordenarArray(int *arrayRecibida, int cantidad);
int ordenarArrayMejorado(int *arrayRecibida, int cantidad);
float sacarPromedio(int *notaUno, int *notaDos, float *promedio, int cantidad);
int mostrar(char *apellido[][20], int *notaUno, int *notaDos, float *promedio, int cantidad);
int ordenarArrayIntInsertion(float * promedio,int cantidad,int orden, int *notaUno, int *notaDos, char apellido[][20]);
#endif // LIB_H_INCLUDED
