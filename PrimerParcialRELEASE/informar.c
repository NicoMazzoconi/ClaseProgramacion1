#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "publicaciones.h"
#include "utn.h"

int informar_duenioPublicaciones(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP, int idPublicacion)
{
    int i,j;
    int retorno = -1;
    if(arrayC != NULL && arrayP != NULL && limiteC > 0 && limiteP > 0)
    {
        for(i=0;i<limiteP;i++)
        {
            retorno = -2;
            if(!arrayP[i].isEmpty && arrayP[i].idPublicaciones == idPublicacion)
            {
                for(j=0;j<limiteC;j++)
                {
                    if(!arrayC[j].isEmpty && arrayC[j].idCliente == arrayP[i].idCliente)
                    {
                        return j;
                    }
                    retorno = -3;
                }
            }
        }
    }
    return retorno;
}

int informar_contadorDeAvisos(Publicaciones *arrayP, int limiteP, int idCliente)
{
    int i;
    int contador =0;
    int retorno = -1;
    if(arrayP != NULL && limiteP > 0)
    {
        for(i=0;i<limiteP;i++)
        {
            if(!arrayP[i].isEmpty && arrayP[i].idCliente == idCliente)
                contador++;
        }
        return contador;
    }
    return retorno;
}
int informar_mostrarClientesConAvisos(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP)
{
    int retorno = -1;
    int i;
    int anuncios;
    retorno = 0;
    if(arrayC != NULL && arrayP != NULL && limiteC > 0 && limiteP > 0)
    {
        for(i=0;i<limiteC;i++)
        {
            if(!arrayC[i].isEmpty)
            {
                anuncios = informar_contadorDeAvisos(arrayP, limiteP, arrayC[i].idCliente);
                printf("\n[RELEASE] %s - %s - %s - %d - %d - %d",arrayC[i].nombre,arrayC[i].apellido,arrayC[i].cuit,arrayC[i].idCliente,arrayC[i].isEmpty, anuncios);
                retorno = 0;
            }
        }
    }
    return retorno;
}

int informar_duenioPublicacionesCliente(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP, int idCliente)
{
    int i;
    int retorno = -1;
    if(arrayC != NULL && arrayP != NULL && limiteC > 0 && limiteP > 0)
    {
        for(i=0;i<limiteC;i++)
        {
            if(!arrayC[i].isEmpty && arrayC[i].idCliente == idCliente)
            {
                return i;
            }
            retorno = -2;
        }
    }
    return retorno;
}

int informar_publicacionesActivas(Publicaciones *arrayP, int limiteP, Cliente *arrayC, int limiteC)
{
    int indice;
    int i;
    int retorno = -1;
    if(arrayC != NULL && arrayP != NULL && limiteC > 0 && limiteP > 0)
    {
        for(i=0;i<limiteP;i++)
        {
            if(!arrayP[i].isEmpty && arrayP[i].estado)
            {
                indice = informar_duenioPublicacionesCliente(arrayC, limiteC, arrayP, limiteP, arrayP[i].idCliente);
                printf("Texto: %s, Rubro: %d, IdCliente: %d, CUIT: %s \n", arrayP[i].texto, arrayP[i].rubro, arrayP[i].idCliente, arrayC[indice].cuit);
                retorno = 0;
            }
        }
    }
    return retorno;
}


int informar_clienteMasAvisos(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP)
{
    int i;
    int contadorIguales = 0;
    int indiceIguales[50];
    int maximo = 0;
    int contador = 0;
    int j;
    int retorno = -1;
    if(arrayC != NULL && arrayP != NULL && limiteC > 0 && limiteP > 0)
    {
        for(i=0;i<limiteC;i++)
        {
            contador = 0;
            for(j=0;j<limiteP;j++)
            {
                if(!arrayP[j].isEmpty && arrayP[j].idCliente == arrayC[i].idCliente)
                    contador++;
            }
            if(contador > maximo)
            {
                maximo = contador;
                retorno = 0;
                indiceIguales[0] = i;
                contadorIguales = 0;
            }
            else
            {
                if(contador == maximo)
                {
                    contadorIguales++;
                    indiceIguales[contadorIguales] = i;
                }
            }
        }
    }
    if(retorno == 0)
        for(i=0; i < contadorIguales;i++)
        {
            printf("El cliente con mas avisos es: %s, con %d avisos\n", arrayC[indiceIguales[i]].nombre, maximo);
        }
    return retorno;
}
int informar_clienteMasAvisosPausados(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP)
{
    int i;
    int contadorIguales = 0;
    int indiceIguales[50];
    int maximo = 0;
    int contador = 0;
    int j;
    int retorno = -1;
    if(arrayC != NULL && arrayP != NULL && limiteC > 0 && limiteP > 0)
    {
        for(i=0;i<limiteC;i++)
        {
            contador = 0;
            for(j=0;j<limiteP;j++)
            {
                if(!arrayP[j].isEmpty && arrayP[j].idCliente == arrayC[i].idCliente && !arrayP[j].estado)
                    contador++;
            }
            if(contador > maximo)
            {
                maximo = contador;
                retorno = 0;
                indiceIguales[0] = i;
                contadorIguales = 0;
            }
            else
            {
                if(contador == maximo)
                {
                    contadorIguales++;
                    indiceIguales[contadorIguales] = i;
                }
            }
        }
    }
    if(retorno == 0)
        for(i=0; i < contadorIguales;i++)
        {
            printf("El cliente con mas avisos pausados es: %s, con %d avisos\n", arrayC[indiceIguales[i]].nombre, maximo);
        }
    return retorno;
}
int informar_clienteMasAvisosActivos(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP)
{
    int i;
    int maximo = 0;
    int contador = 0;
    int j;
    int retorno = -1;
    int contadorIguales = 0;
    int indiceIguales[50];
    if(arrayC != NULL && arrayP != NULL && limiteC > 0 && limiteP > 0)
    {
        for(i=0;i<limiteC;i++)
        {
            contador = 0;
            for(j=0;j<limiteP;j++)
            {
                if(!arrayP[j].isEmpty && arrayP[j].idCliente == arrayC[i].idCliente && arrayP[j].estado)
                    contador++;
            }
            if(contador > maximo)
            {
                maximo = contador;
                retorno = 0;
                indiceIguales[0] = i;
                contadorIguales = 0;
            }
            else
            {
                if(contador == maximo)
                {
                    contadorIguales++;
                    indiceIguales[contadorIguales] = i;
                }
            }
        }
    }
    if(retorno == 0)
        for(i=0; i < contadorIguales;i++)
        {
            printf("El cliente con mas avisos activos es: %s, con %d avisos\n", arrayC[indiceIguales[i]].nombre, maximo);
        }
    return retorno;
}

int informar_cantidadPublicacionActivasRubroIngresado(Publicaciones *arrayP, int limiteP)
{
    int i;
    int rubro;
    int contador = 0;
    getValidInt("Rubro?", "Error", &rubro, 0, 100, 2);
    int retorno = -1;
    if(arrayP != NULL && limiteP > 0)
    {
        retorno = 0;
        for(i=0;i<limiteP;i++)
        {
            if(!arrayP[i].isEmpty && arrayP[i].rubro == rubro)
                contador++;
        }
    }
    if(retorno == 0)
        printf("El rubro elegido tiene %d publicaciones\n", contador);
    return retorno;
}
int informar_rubroMasPublicacionesActivas(Publicaciones *arrayP, int limiteP)
{
    int i;
    int contadorIguales=0;
    int indiceIguales[50];
    int maximo = 0;
    int contador = 0;
    int j;
    int retorno = -1;
    if(arrayP != NULL && limiteP > 0)
    {
        for(i=0;i<limiteP;i++)
        {
            contador = 0;
            for(j=i+1;j<limiteP;j++)
            {
                if(!arrayP[j].isEmpty && arrayP[j].estado && arrayP[j].rubro == arrayP[i].rubro)
                    contador++;
            }
            if(contador > maximo)
            {
                maximo = contador;
                indiceIguales[0] = i;
                retorno = 0;
                contadorIguales = 0;
            }
            else
            {
                if(contador == maximo)
                {
                    contadorIguales++;
                    indiceIguales[contadorIguales] = i;
                }
            }
        }
    }
    if(retorno == 0)
        for(i=0; i < contadorIguales;i++)
        {
            printf("El rubro con mas avisos pausados es: %d, con %d avisos\n", arrayP[indiceIguales[i]].rubro, maximo);
        }
    return retorno;
}
int informar_rubroMenosPublicacionesActivas(Publicaciones *arrayP, int limiteP)
{
    int i;
    int maximo = 0;
    int contador = 0;
    int j;
    int retorno = -1;
    int contadorIguales=0;
    int indiceIguales[50];
    if(arrayP != NULL && limiteP > 0)
    {
        for(i=0;i<limiteP;i++)
        {
            contador = 0;
            for(j=i+1;j<limiteP;j++)
            {
                if(!arrayP[j].isEmpty && arrayP[j].estado && arrayP[j].rubro == arrayP[i].rubro)
                    contador++;
            }
            if(contador < maximo)
            {
                maximo = contador;
                retorno = 0;
                indiceIguales[0] = i;
                contadorIguales = 0;
            }
            else
            {
                if(contador == maximo)
                {
                    contadorIguales++;
                    indiceIguales[contadorIguales] = i;
                }
            }
        }
    }
    if(retorno == 0)
        for(i=0; i < contadorIguales;i++)
        {
            printf("El rubro con mas avisos activos es: %d, con %d avisos\n", arrayP[indiceIguales[i]].rubro, maximo);
        }
    return retorno;
}
