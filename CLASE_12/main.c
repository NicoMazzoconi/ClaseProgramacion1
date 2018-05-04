#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#include "Contratacion.h"
#include "informar.h"

#define QTY 10
#define LEN_CONT 1000

int main()
{
    Pantalla array[QTY];
    Contratacion contrataciones[LEN_CONT];
    int menu;
    int auxiliarId;

    pantalla_init(array,QTY);
    cont_init(contrataciones,LEN_CONT);

    pantalla_altaForzada(array,QTY,"Wilde","Las Flores 50",50,0);
    pantalla_altaForzada(array,QTY,"Avellaneda","Belgrano 250",2000,0);
    pantalla_altaForzada(array,QTY,"Bernal","Cerrito 300",3000,0);
    pantalla_altaForzada(array,QTY,"Quilmes","Lavalle 450",1000,1);
    pantalla_altaForzada(array,QTY,"Berazategui","Mitre 150",5000,1);

    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video.avi","20911911915",100);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video1.avi","20911911915",400);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video2.avi","30911911915",300);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video3.avi","30911911915",400);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video4.avi","40911911915",500);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video5.avi","40911911915",600);

  //informar_ConsultaFacturacion(contrataciones,LEN_CONT,array,QTY,"20911911915");
 //   informar_ListarContrataciones(contrataciones,LEN_CONT,array,QTY);
   // informar_ListarCantidadContratacionesImporte(contrataciones,LEN_CONT,array,QTY);


    do
    {
        getValidInt("\n\n1.Alta pantalla\n2.Baja pantalla\n3.Modificar pantalla\n4.Contratar publicidad\n5.Cancelar publicidad\n6.Modificar condiciones de publicidad\n7.Consulta facturacion\n8.Listar contrataciones\n9.Listar Pantallas\n10.Clientes con contrataciones\n11.Clientes con importes mas altos\n12.Salir\n","\nNo valida\n",&menu,1,12,1);
        switch(menu)
        {
            case 1:
                pantalla_alta(array,QTY);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_baja(array,QTY,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_modificacion(array,QTY,auxiliarId);
                break;
            case 4:
                cont_alta(contrataciones,LEN_CONT,array,QTY);
                break;
            case 5:
                getValidInt("ID?","\nNumero invalido\n",&auxiliarId,0,200,2);
                cont_baja(contrataciones, LEN_CONT, auxiliarId);
                break;
            case 6:
                getValidInt("ID?","\nNumero invalido\n",&auxiliarId,0,200,2);
               // cont_modificacion(contrataciones, LEN_CONT, auxiliarId);
                break;
            case 7:
                informar_ConsultaFacturacion(contrataciones,LEN_CONT,array,QTY,"20911911915");
                break;
            case 8:
                informar_ListarCantidadContratacionesImporte(contrataciones, LEN_CONT, array, QTY);
                break;
            case 9:
                pantalla_mostrar(array, QTY);
                break;
            case 10:
                informar_ListarCantidadContratacionesImporte(contrataciones,LEN_CONT,array,QTY);
                break;
            case 11:

                break;




        }

    }while(menu != 12);

    return 0;
}
