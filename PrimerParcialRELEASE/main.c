#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "informar.h"
#include "publicaciones.h"
#include "utn.h"
#define QTY_Cliente 100
#define QTY_Publicaciones 1000

int main()
{
    Cliente arrayCliente[QTY_Cliente];
    Publicaciones arrayPublicaciones[QTY_Publicaciones];
    int menu;
    int auxiliarId;
    int resultado;
    cliente_init(arrayCliente,QTY_Cliente);
    publicaciones_init(arrayPublicaciones,QTY_Publicaciones);
    do
    {
        getValidInt("\n1.Alta Cliente\n2.Modificar Cliente\n3.Baja Cliente\n4.Publicar\n5.Pausar/Renaudar\n6.Imprimir Clientes con avisos\n7.Publicaciones activas\n8.Clientes con mas avisos activos y pausados\n9.Cantidad de publicaciones de x Rubro\n10.Rubro con mas y menos publicaciones\n11.Salir\n","\nNo valida\n",&menu,1,11,1);
        switch(menu)
        {
            case 1:
                resultado = cliente_alta(arrayCliente,QTY_Cliente);
                if(resultado == -1)
                {
                    printf("Error en el array o su cantidad");
                }
                else
                {
                   if(resultado == -2)
                   {
                       printf("El indice es invalido");
                   }
                   else
                    {
                        if(resultado == -3)
                        {
                            printf("No se completaron bien los datos");
                        }
                        else
                        {
                            if(resultado == 0)
                            {
                                printf("Creado correctamente");
                            }
                        }
                    }
                }
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                resultado = cliente_modificacion(arrayCliente,QTY_Cliente,auxiliarId);
                if(resultado == -1)
                {
                    printf("Error en el array o su cantidad");
                }
                else
                {
                   if(resultado == -2)
                   {
                       printf("El indice es invalido");
                   }
                   else
                    {
                        if(resultado == -3)
                        {
                            printf("No se completaron bien los datos");
                        }
                        else
                        {
                            if(resultado == 0)
                            {
                                printf("Modificado correctamente");
                            }
                        }
                    }
                }
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                resultado = cliente_baja(arrayCliente,QTY_Cliente,auxiliarId);
                if(resultado == -1)
                {
                    printf("Se pasaron mal los parametros");
                }
                else
                {
                    if(resultado == -2)
                    {
                        printf("Indice invalido");
                    }
                    else
                    {
                        if(resultado == 0)
                            printf("Dado de baja correctamente");
                    }
                }
                break;
            case 4:
                resultado = publicaciones_alta(arrayPublicaciones, QTY_Publicaciones, arrayCliente, QTY_Cliente);
                if(resultado == -1)
                {
                    printf("Se pasaron mal los parametros");
                }
                else
                {
                    if(resultado == -2)
                    {
                        printf("Error en el indice donde guardar");
                    }
                    else
                    {
                        if(resultado == -3)
                        {
                            printf("Los datos no son validos");
                        }
                        else
                        {
                            if(resultado == 0)
                            {
                                printf("Publicacion creada correctamente");
                            }
                        }
                    }
                }
                break;
            case 5:
                resultado = publicaciones_Estado(arrayPublicaciones, QTY_Publicaciones, arrayCliente, QTY_Cliente);
                if(resultado == -1)
                {
                    printf("Se le pasaron mal los parametros");
                }
                else
                {
                    if(resultado == -2)
                    {
                        printf("Error en idPublicacion");
                    }
                    else
                    {
                        if(resultado == -3)
                        {
                            printf("Cancelado");
                        }
                        else
                        {
                            if(resultado == 0)
                            {
                                printf("Cambio de estado correcto");
                            }
                        }
                    }
                }
                break;
            case 6:
                resultado = informar_mostrarClientesConAvisos(arrayCliente, QTY_Cliente, arrayPublicaciones, QTY_Publicaciones);
                if(resultado == -1)
                {
                    printf("Se le pasaron mal los parametros");
                }
                else
                {
                    if(resultado == 0)
                    {
                        printf("Lista mostrada correctamente");
                    }
                }
                break;
            case 7:
                resultado = informar_publicacionesActivas(arrayPublicaciones,QTY_Publicaciones, arrayCliente, QTY_Cliente);
                if(resultado == -1)
                {
                    printf("Se le pasaron mal los parametros");
                }
                else
                {
                    if(resultado == 0)
                    {
                        printf("Lista mostrada correctamente");
                    }
                }
                break;
            case 8:
                resultado = informar_clienteMasAvisos(arrayCliente, QTY_Cliente, arrayPublicaciones, QTY_Publicaciones);
                if(resultado == -1)
                {
                    printf("Se le pasaron mal los parametros");
                }
                else
                {
                    if(resultado == 0)
                    {
                        printf("Lista mostrada correctamente");
                    }
                }
                resultado = informar_clienteMasAvisosPausados(arrayCliente, QTY_Cliente, arrayPublicaciones, QTY_Publicaciones);
                if(resultado == -1)
                {
                    printf("Se le pasaron mal los parametros");
                }
                else
                {
                    if(resultado == 0)
                    {
                        printf("Lista mostrada correctamente");
                    }
                }
                resultado = informar_clienteMasAvisosActivos(arrayCliente, QTY_Cliente, arrayPublicaciones, QTY_Publicaciones);
                if(resultado == -1)
                {
                    printf("Se le pasaron mal los parametros");
                }
                else
                {
                    if(resultado == 0)
                    {
                        printf("Lista mostrada correctamente");
                    }
                }
                break;
            case 9:
                resultado = informar_cantidadPublicacionActivasRubroIngresado(arrayPublicaciones, QTY_Publicaciones);
                if(resultado == -1)
                {
                    printf("Error en los parametros");
                }
                else
                {
                    if(resultado == 0)
                    {
                        printf("Listra mostrada correctamente");
                    }
                }
                break;
            case 10:
                resultado = informar_rubroMasPublicacionesActivas(arrayPublicaciones, QTY_Publicaciones);
                if(resultado == -1)
                {
                    printf("Error en los parametros");
                }
                else
                {
                    if(resultado == 0)
                    {
                        printf("Listra mostrada correctamente");
                    }
                }
                resultado = informar_rubroMenosPublicacionesActivas(arrayPublicaciones, QTY_Publicaciones);
                if(resultado == -1)
                {
                    printf("Error en los parametros");
                }
                else
                {
                    if(resultado == 0)
                    {
                        printf("Listra mostrada correctamente");
                    }
                }
                break;

        }

    }while(menu != 11);

    return 0;
}
