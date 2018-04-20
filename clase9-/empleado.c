#include <stdio.h>
#include <string.h>
#include "empleado.h"

int emp_mostrar(Empleado* arrayEmpleados,int sizeArray)
{
    int i;
    for(i=0;i<sizeArray;i++)
    {
        if(!arrayEmpleados[i].isEmpty)
            printf("\nNombre: %s - Id: %d - Index:%d",arrayEmpleados[i].nombre,arrayEmpleados[i].idEmpleado,i);
    }
    return 0;
}

int emp_len (Empleado* arrayEmpleados,int sizeArray)
{
    int i;
    for(i=0;i<sizeArray;i++)
    {
        if(arrayEmpleados[i].isEmpty)
            break;
    }
    return i;
}

int emp_compactarArrayInsertion(Empleado * arrayEmpleado,int cantidad)
{
	Empleado auxiliar;
    int j, i;

	for(i = 1; i < cantidad; i++) {
		auxiliar = arrayEmpleado[i];
		j = i;
		while(j > 0 && auxiliar.isEmpty < arrayEmpleado[j - 1].isEmpty)
        {
			arrayEmpleado[j] = arrayEmpleado[j - 1];
			j--;
		}
		arrayEmpleado[j] = auxiliar;
	}
    return 0;
}

int emp_ordenarEmpleadoNombre(Empleado * arrayEmpleado,int cantidad)
{
	Empleado auxiliar;
    int j, i;

    emp_compactarArrayInsertion(arrayEmpleado,cantidad);
    cantidad = emp_len(arrayEmpleado,cantidad);

	for(i = 1; i < cantidad; i++) {
		auxiliar = arrayEmpleado[i];
		j = i;
		while(j > 0 && strcmp(auxiliar.nombre , arrayEmpleado[j - 1].nombre) > 0)
        {
			arrayEmpleado[j] = arrayEmpleado[j - 1];
			j--;
		}
		arrayEmpleado[j] = auxiliar;
	}
    return 0;
}
