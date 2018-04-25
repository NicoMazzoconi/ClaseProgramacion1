#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

int getInt(char *mensaje, char *error, int intentos, int maximo, int minimo, int *resultado);
float getFloat(char *mensaje, char *error, int intentos, float maximo, float minimo, float *resultado);
void getString(char *mensaje, char *input);
int usuario_buscarLibre(usuario* arrayEmpleados,int sizeArray);
int productos_buscarLibre(producto* arrayEmpleados,int sizeArray);
int compras_buscarLibre(compra* arrayEmpleados,int sizeArray);
int esString(char *arrayRecibida);
int esPassword(char *arrayRecibida);

#endif // LIB_H_INCLUDED
