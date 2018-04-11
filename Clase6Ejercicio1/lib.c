#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


/** \brief Muestra un mensaje pidiendo un entero, analizando la cantidad de intentos que quieras, y el rango
 *
 * \param char* mensaje mensaje que muestra para pedir el entero
 * \param char* error mensaje que muestra al no respetar lo pedido
 * \param int intentos cantidad de veces que puede intentarlo
 * \param int maximo numero entero maximo a ingresar
 * \param int minimo numero entero minimo a ingresar
 * \param int* resultado devuelve el numero entero ingresado y valido
 * \return int -2 overflow negativo, -1 overflow positivo, 0 todo correcto
 *
 */
int getInt(char *mensaje, char *error, int intentos, int maximo, int minimo, int *resultado)
{
    char auxiliarEntero[4096];
    int aux;
    int retorno = -1;
    do
    {
        intentos--;
        printf("%s \n", mensaje);
        gets(auxiliarEntero);
        if(esEntero(auxiliarEntero)==1)
        {
            aux = atoi(auxiliarEntero);
            if(aux >= minimo && aux <= maximo)
            {
                retorno = 0;
                *resultado = aux;
                break;
            }
            else
            {
                if(aux < minimo)
                {
                    retorno = -2;
                }
                else
                {
                    retorno = -1;
                }
            }
        }
        printf("%s", error);
    }while(intentos >= 0);

    return retorno;
}

/** \brief Muestra un mensaje pidiendo un flotante, analizando la cantidad de intentos que quieras, y el rango
 *
 * \param char* mensaje mensaje que muestra para pedir el flotante
 * \param char* error mensaje que muestra al no respetar lo pedido
 * \param int intentos cantidad de veces que puede intentarlo
 * \param float maximo numero flotante maximo a ingresar
 * \param float minimo numero flotante minimo a ingresar
 * \param float* resultado devuelve el numero flotante ingresado y valido
 * \return int -2 overflow negativo, -1 overflow positivo, 0 todo correcto
 *
 */
float getFloat(char *mensaje, char *error, int intentos, float maximo, float minimo, float *resultado)
{
    char auxiliarFlotante[4096];
    float aux;
    int retorno = -1;
    do
    {
        intentos--;
        printf("%s \n", mensaje);
        gets(auxiliarFlotante);
        if(esFloat(auxiliarFlotante)==1)
        {
            aux = atof(auxiliarFlotante);
            if(aux >= minimo && aux <= maximo)
            {
                retorno = 0;
                *resultado = aux;
                break;
            }
            else
            {
                if(aux < minimo)
                {
                    retorno = -2;
                }
                else
                {
                    retorno = -1;
                }
            }
        }
        printf("%s", error);
    }while(intentos >= 0);
    return retorno;
}

int esEntero(char *strRecibida)
{
    int i = 0;
    while(strRecibida[i] != '\0')
    {
        if(strRecibida[i] < '0' || strRecibida[i] > '9')
            {
                return 0;
            }
        i++;
    }
    return 1;
}

int esFloat(char *strRecibida)
{
    int i = 0;
    int contadorComa = 0;
    while(strRecibida[i] != '\0')
    {
        if(strRecibida[i] < '0' || strRecibida[i] > '9')
        {
            if(strRecibida[i] == '.')
            {
                contadorComa++;
            }
            else
            {
                return 0;
            }
            if(contadorComa==2)
            {
                return 0;
            }
        }
        i++;
    }

    return 1;
}
