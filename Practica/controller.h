#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
void controller_leerArchivoCliente(char *path, ArrayList* array);
void controller_listarClientes(ArrayList* array);
void controller_ordenarNameLastName(ArrayList* array);
void controller_ordenarEmail(ArrayList* array);
void controller_alta(ArrayList* array);
void controller_baja(ArrayList* this);
void controller_mod(ArrayList* this);
#endif // CONTROLLER_H_INCLUDED
