#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED 123
typedef struct
{
    char nombre[50];
    //char apellido[50];
    int idEmpleado;
    int isEmpty;
}Empleado;
#endif // EMPLEADO_H_INCLUDED


int emp_init(Empleado* arrayEmpleados,int sizeArray);
int emp_mostrar(Empleado* arrayEmpleados,int sizeArray);
int emp_alta(Empleado* arrayEmpleados,int sizeArray,int id);
int emp_baja(Empleado* arrayEmpleados,int sizeArray,int id);
int buscarLibre(Empleado* arrayEmpleados,int sizeArray);

int emp_compactarArrayInsertion(Empleado * arrayEmpleado,int cantidad);
int emp_ordenarEmpleadoNombre(Empleado * arrayEmpleado,int cantidad);
