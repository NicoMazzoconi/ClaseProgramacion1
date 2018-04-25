#include <stdio.h>
#include <stdlib.h>
#include "parcial.h"
#include "string.h"
#include "lib.h"
#define MAX_USERS 100
#define MAX_PRODUCTOS 1000
#define MAX_COMPRAS 10000

int main()
{
    usuario cuantas[MAX_USERS];
    producto articulos[MAX_PRODUCTOS];
    compra compras[MAX_COMPRAS];
    usr_init(cuantas, MAX_USERS);
    pro_init(articulos, MAX_PRODUCTOS);
    com_init(compras, MAX_COMPRAS);
    int respuesta;
    int opcion;
    int log;
    int idUsuarios=0;
    char nombreUsuario[25];
    char password[10];
    do
    {
        printf("1) Crear cuenta\n");
        printf("2) Conectar\n");
        printf("3) Salir\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            usr_alta(cuantas, MAX_USERS, idUsuarios);
            idUsuarios++;
        break;
        case 2:
            getString("Ingrese el usuario\n", nombreUsuario);
            getString("Ingrese la password\n", password);
            if(login(&nombreUsuario, &password, cuantas, MAX_USERS)==0)
            {
                log = 1;
            }
            else
                printf("Datos invalidos\n");
        break;
        case    3:
            respuesta = 1;
        break;

        }

    }while(respuesta != 1);
    return 0;
}
