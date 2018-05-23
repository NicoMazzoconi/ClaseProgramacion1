#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{

    char nombre[50];
    char apellido[50];
    char cuit[30];
    int edad;
    int idCliente;

}Cliente;


#endif // CLIENTE_H_INCLUDED

Cliente* cliente_new();
void cliente_delete(Cliente *this);
int cliente_setEdad(Cliente *this, int edad);
int cliente_getEdad(Cliente *this, int *edad);
int cliente_setNombre(Cliente *this, char *nombre);
int cliente_getNombre(Cliente *this, char *nombre);
int cliente_setApellido(Cliente *this, char *Apellido);



void cargar(Cliente **arrayC, int QTY);
void mostrar(Cliente **arrayC, int QTY);


