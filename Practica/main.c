#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cliente.h"
#include "parser.h"
#include <string.h>
#include "controller.h"
#include "utn.h"

/****************************************************
    Menu:
        1. Cargar datos desde data.csv
        2. Listar Clientes
        3. Ordenar por nombre y apellido
        4. Ordenar por mail
        5. Agregar un Cliente
        6. Elimina un Cliente
        7. Modificar Cliente (Nombre, Apellido y Mail)
        8. Guardar datos en data.csv (modo texto)
        9. Guardar datos en data.bin (modo binario)
*****************************************************/


int main()
{
    ArrayList* pArrayEmpleados;
    pArrayEmpleados = al_newArrayList();
    int opcion;

    do{
        getValidInt("0. Cargar datos desde data.bin\n1. Cargar datos desde data.csv\n2. Listar Clientes\n\
                    3. Ordenar por nombre y apellido\n4. Ordenar por mail\n5. Agregar un Cliente\n\
                    6. Elimina un Cliente\n7. Modificar Cliente (Nombre, Apellido y Mail)\n\
                    8. Guardar datos en data.csv (modo texto)\n9. Guardar datos en data.bin (modo binario)\n\
                    10. Salir\n","Opcion invalida",&opcion,0,10,2);
        switch(opcion)
        {
        case 0  :
            parserEmployeeBinario("data3.bin", pArrayEmpleados);
            break;
        case 1  :
            controller_leerArchivoCliente("data.csv", pArrayEmpleados);
            break;
        case 2  :
            controller_listarClientes(pArrayEmpleados);
            break;
        case 3  :
            controller_ordenarNameLastName(pArrayEmpleados);
            break;
        case 4  :
            controller_ordenarEmail(pArrayEmpleados);
            break;
        case 5  :
            controller_alta(pArrayEmpleados);
            break;
        case 6  :
            controller_baja(pArrayEmpleados);
            break;
        case 7  :
            controller_mod(pArrayEmpleados);
            break;
        case 8  :
            parser_guardarTexto(pArrayEmpleados, "data2.csv");
            break;
        case 9  :
            parser_guardarBinario(pArrayEmpleados, "data3.bin");
            break;
        case 10 :
            break;
        }

    }while(opcion != 10);

    return 0;
}
