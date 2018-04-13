#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

int getInt(char *mensaje, char *error, int intentos, int maximo, int minimo, int *resultado);
float getFloat(char *mensaje, char *error, int intentos, float maximo, float minimo, float *resultado);
int getArray(char *mensaje, char *error, int intentos, int maximo, int minimo, int *resultado, int cantidad);
int mostrarArray(int *arrayRecibida, int cantidad);
int ordenarArray(int *arrayRecibida, int cantidad);
int ordenarArrayMejorado(int *arrayRecibida, int cantidad);
int burbujeo(int *arrayRecibido, int cantidad, int orden);
int desplazar(int *arrayRecibido, int cantidad, int indiceA, int indiceB, int sentido);
void desplazarProfe(int *arrayRecibida, int cantidad, int indiceA, int indiceB, int sentido);
#endif // LIB_H_INCLUDED
