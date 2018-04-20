#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "string.h"


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
    int auxiliarEntero;
    int retorno = -1;
    int cantidad;
    cantidad = intentos;
    do
    {
        cantidad--;
        printf("%s \n", mensaje);
        scanf("%d", &auxiliarEntero);
        if(auxiliarEntero >= minimo && auxiliarEntero <= maximo)
        {
            retorno = 0;
            *resultado = auxiliarEntero;
            break;
        }
        else
        {
            if(auxiliarEntero < minimo)
            {
                retorno = -2;
            }
            else
            {
                retorno = -1;
            }
        }
        printf("%s", error);
    }while(cantidad != 0);

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
    int auxiliarFlotante;
    int retorno = -1;
    do
    {
        intentos--;
        printf("%s \n", mensaje);
        scanf("%d \n", &auxiliarFlotante);
        if(auxiliarFlotante >= minimo && auxiliarFlotante <= maximo)
        {
            retorno = 0;
            *resultado = auxiliarFlotante;
            break;
        }
        else
        {
            if(auxiliarFlotante < minimo)
            {
                retorno = -2;
            }
            else
            {
                retorno = -1;
            }
        }
        printf("%s", error);
    }while(intentos >= 0);
}

/** \brief Pide una string
 *
 * \param char *mensaje, mensaje a mostrar
 * \param char *input, donde guardar el string recibido
 * \return void
 *
 */
void getString(char *mensaje, char *input)
{
    printf("%s", mensaje);
    scanf("%s", input);
}

int esString(char *arrayRecibida)
{
    int i;
    int respuesta = 0;
    for(i = 0; i < strlen(arrayRecibida); i++)
    {
        if((arrayRecibida[i] < 'a' || arrayRecibida[i] > 'z') && (arrayRecibida[i] < 'A' || arrayRecibida[i] > 'Z'))
        {
            respuesta = -1;
            break;
        }
    }
    return respuesta;
}
int buscarLibre(Empleado* arrayEmpleados,int sizeArray)
{
    int i;
    int indice;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayEmpleados[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
        indice = -1;
    }
    return indice;
}
