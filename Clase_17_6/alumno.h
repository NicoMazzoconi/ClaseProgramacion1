typedef struct
{
    int edad;
    char nombre[50];
}Alumno;


Alumno* alumno_new();
void alumno_delete(Alumno* this);
int  alumno_setEdad(Alumno* this, int edad);
int alumno_getEdad(Alumno* this, int* edad);

