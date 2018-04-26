#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED
typedef struct{
    char nombre[20];
    int idXxx;
    int isEmpty;
}xxx;

int xxx_buscarEspacio(xxx *arrayRecibida, int sizeArray);
int xxx_init(xxx *arrayRecibida, int sizeArray);
int xxx_alta(xxx *arrayRecibida, int sizeArray);
int xxx_baja(xxx *arrayRecibida, int sizeArray);
int xxx_mod(xxx *arrayRecibida, int sizeArray);
#endif // ABM_H_INCLUDED
