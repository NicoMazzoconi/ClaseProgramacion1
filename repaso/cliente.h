typedef struct
{
    char nombre[50];
    char apellido[50];
    char cuit[14];
    int edad;
    int idCliente;
}Cliente;

Cliente* cliente_new();
Cliente* cliente_new2(int edad, char *nombre, char *apellido, char *cuit);
void cliente_delete(Cliente *this);
int cliente_setEdad(Cliente *this, int edad);
int cliente_getEdad(Cliente *this, int *edad);
int cliente_setNombre(Cliente *this, char *nombre);
int cliente_getNombre(Cliente *this, char *nombre);
int cliente_setApellido(Cliente *this, char *Apellido);
int cliente_getApellido(Cliente *this, char *Apellido);
int cliente_setCuit(Cliente *this, char *Cuit);
int cliente_getCuit(Cliente *this, char *Cuit);
int cliente_alta(Cliente **arrayC, int *qtyArrayClientes);
int cliente_modificar(Cliente **arrayC, int qtyArrayClientes, int id);
Cliente* cliente_mod(int edad, char *nombre, char *apellido, char *cuit);
void mostrar(Cliente **arrayC, int QTY);
int cliente_posicionID(Cliente **arrayC, int QTY, int id);
Cliente* cliente_modEdad(int edad);
Cliente* cliente_modCuit(char *cuit);
Cliente* cliente_modNombre(char *nombre);
Cliente* cliente_modApellido(char *apellido);



