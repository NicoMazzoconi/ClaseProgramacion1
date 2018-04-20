#include <stdio.h>
#include <string.h>
#include "funcs.h"
#include "empleado.h"
#define QTY 10



int main(void)
{

    Empleado arrayEmpleados[QTY];
    strcpy(arrayEmpleados[0].nombre,"Luis");
    strcpy(arrayEmpleados[2].nombre,"Juan");
    strcpy(arrayEmpleados[4].nombre,"Ernesto");
    strcpy(arrayEmpleados[6].nombre,"Juana");
    strcpy(arrayEmpleados[8].nombre,"Monica");
    arrayEmpleados[0].idEmpleado = 100;
    arrayEmpleados[2].idEmpleado = 200;
    arrayEmpleados[4].idEmpleado = 300;
    arrayEmpleados[6].idEmpleado = 400;
    arrayEmpleados[8].idEmpleado = 500;
    arrayEmpleados[0].isEmpty = 0;
    arrayEmpleados[1].isEmpty = 1;
    arrayEmpleados[2].isEmpty = 0;
    arrayEmpleados[3].isEmpty = 1;
    arrayEmpleados[4].isEmpty = 0;
    arrayEmpleados[5].isEmpty = 1;
    arrayEmpleados[6].isEmpty = 0;
    arrayEmpleados[7].isEmpty = 1;
    arrayEmpleados[8].isEmpty = 0;
    arrayEmpleados[9].isEmpty = 1;

    emp_mostrar(arrayEmpleados,10);
    emp_mostrar(arrayEmpleados,10);

    emp_ordenarEmpleadoNombre(arrayEmpleados,10);
    emp_mostrar(arrayEmpleados,10);

    return 0;
}
