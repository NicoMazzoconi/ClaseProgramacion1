#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "empleado.h"
#define QTY 12000

int main()
{
    int continuar;
    int proximoId=0;
    int valor;
    Empleado arraysEmpleado[QTY];
    emp_init(arraysEmpleado, QTY);
    do
    {
        getInt("1) Agregar un empleado\n2) Dar de baja un empleado\n3) Listar empleados\n4) Ordenar empleados\n5) Salir", "Opcion no valida\n", 2, 5, 1, &valor);
        switch(valor)
        {
        case 1:
            emp_alta(arraysEmpleado, QTY, proximoId);
            proximoId++;
        break;
        case 2:
            if(emp_baja(arraysEmpleado, QTY) == 0)
            {
                printf("Dado de baja\n");
            }
            else
                printf("ID no encontrado\n");
        break;
        case 3:
            emp_mostrar(arraysEmpleado, QTY);
        break;
        case 4:
            emp_ordenar(arraysEmpleado, QTY);
        break;
        case 5:
            continuar = 0;
        break;
        }
    }while(continuar);

    return 0;
}
