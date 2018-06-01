#ifndef _CLIENTE_H
#define _CLIENTE_H
struct
{
    char nombre[64];
    char apellido[64];
    char email[256];
    char genero[1];
    char profesion[256];
    char nacionalidad[256];
    char usuario[64];
    int id;
}typedef Cliente;

Cliente* cliente_new();
void cliente_delete(Cliente* this);
Cliente* cliente_newParametros(char* nombre, char* apellido, char* email, char* genero, char* profesion, char* nacionalidad, char* usuario, int id);

int cliente_setNombre(Cliente* this, char* nombre);
int cliente_getNombre(Cliente* this, char* nombre);
int cliente_setApellido(Cliente* this, char* apellido);
int cliente_getApellido(Cliente* this, char* apellido);
int cliente_setEmail(Cliente* this, char* email);
int cliente_getEmail(Cliente* this, char* email);
int cliente_setGenero(Cliente* this, char* genero);
int cliente_getGenero(Cliente* this, char* genero);
int cliente_setProfesion(Cliente* this, char* profesion);
int cliente_getProfesion(Cliente* this, char* profesion);
int cliente_setNacionalidad(Cliente* this, char* nacionalidad);
int cliente_getNacionalidad(Cliente* this, char* nacionalidad);
int cliente_setId(Cliente* this, int id);
int cliente_getId(Cliente* this, int* id);
int cliente_setUsuario(Cliente* this, char* usuario);
int cliente_getUsuario(Cliente* this, char* usuario);
void cliente_print(Cliente* this);
int cliente_compareNameLastName(Cliente* clienteA, Cliente* clienteB);
int cliente_compareEmail(Cliente* clienteA, Cliente* clienteB);
#endif // _CLIENTE_H

