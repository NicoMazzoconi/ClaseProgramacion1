#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#include "Contratacion.h"
#include "informar.h"

#define QTY 10
#define LEN_CONT    1000

int main()
{
    Pantalla array[QTY];
    Contratacion contrataciones[LEN_CONT];
    int menu;
    int auxiliarId;

    pantalla_init(array,QTY);
    cont_init(contrataciones,LEN_CONT);

    pantalla_altaForzada(array,QTY,"Wilde","Las Flores 50",5000,0);
    pantalla_altaForzada(array,QTY,"Avellaneda","Belgrano 250",50,0);
    pantalla_altaForzada(array,QTY,"Bernal","Cerrito 300",50,0);
    pantalla_altaForzada(array,QTY,"Quilmes","Lavalle 450",50,1);
    pantalla_altaForzada(array,QTY,"Berazategui","Mitre 150",5000,1);

    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video.avi","98654123651",100);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,1,"video1.avi","20911911915",400);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video2.avi","30911911915",300);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video3.avi","30911911915",400);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,1,"video4.avi","40911911915",500);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video5.avi","40911911915",600);


   // informar_ConsultaFacturacion(contrataciones,LEN_CONT,array,QTY,"20911911915");
   // informar_ListarContrataciones(contrataciones,LEN_CONT,array,QTY);
   // informar_ListarCantidadContratacionesImporte(contrataciones,LEN_CONT,array,QTY);

    //ordenarPrecioNombre(array, QTY);
    //pantalla_mostrar(array, QTY);
    //pantallasValorInferiorMil(array, QTY);
    //listarPantallasPrecioMenorPromedio(array, QTY);
    //pantallasMasUnaPublicacion(array, QTY, contrataciones, LEN_CONT);
    listarPantallaConFacturacion(array, QTY, contrataciones, LEN_CONT);
    do
    {
        getValidInt("\n\n1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n7.Contratar\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                clientesGastosContrataciones(contrataciones, array, LEN_CONT, QTY);
                //pantalla_alta(array,QTY);
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
                pantalla_mostrar(array,QTY);
                cont_mostrar(contrataciones,LEN_CONT);
                break;
            case 5:
                cont_ordenarCuit(contrataciones,LEN_CONT,0);
                pantalla_ordenar(array,QTY,0);
                break;
            case 6:
                pantalla_mostrarDebug(array,QTY);

                break;
            case 7:
                cont_alta(contrataciones,LEN_CONT,array,QTY);
                break;




        }

    }while(menu != 9);

    return 0;
}
