#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

int esTelefono(char *telefono);
int esApellido(char *apellido);
void getString(char *mensaje,char *input);
int getStringLetras(char *mensaje,char *input);
int getStringNumeros(char *mensaje,char *input);
int getInt(char *mensaje, char *error, int intentos, int maximo, int minimo, int *resultado);
float getFloat(char *mensaje, char *error, int intentos, float maximo, float minimo, float *resultado);


#endif // BIBLIOTECA_H_INCLUDED
