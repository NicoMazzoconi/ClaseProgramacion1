#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#define QTY 10
#define OCUPADO 0
#define LIBRE 1

static int buscarLugarLibre(Cliente* array,int limite);
static int proximoId();

/** \brief Inicializa el array de los clientes
 *
 * \param Cliente* array el array de los clientes
 * \param int limite el tamaño del array
 * \return int -1 si se le pasan mal los parametros, 0 si esta todo bien
 *
 */
int cliente_init(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty = 1;
        }
    }
    return retorno;
}

/** \brief busca el indice del id de un cliente
 *
 * \param Cliente* array el array de clientes
 * \param int limite el tamaño de la array
 * \param int id el id a encontrar
 * \return int -1 si se le pasan mal los parametros, -2 si no encuntra el id, >=0 si es todo bien
 *
 */
int cliente_buscarPorId(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].idCliente == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief da de baja un cliente
 *
 * \param Cliente* array el array de los clientes
 * \param int limite el tamaño de la array
 * \param int id el id a dar de baja
 * \return int -1 si se le pasan mal los parametros, -2 si el indice es invalido, 0 todo bien
 *
 */
int cliente_baja(Cliente* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    if(array != NULL && limite > 0)
    {
        retorno = -2;
        indice = cliente_buscarPorId(array,limite,id);
        if(indice >= 0)
        {
            retorno = 0;
            array[indice].isEmpty = LIBRE;
        }
    }
    return retorno;
}


/** \brief Muestra los clientes
 *
 * \param Cliente* array el array de los clientes
 * \param int limite el tamaño de la array
 * \return int -1 si se le pasaron mal los parametros, 0 si esta todo bien
 *
 */
int cliente_mostrar(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
               printf("\n[RELEASE] %s - %s - %s - %d - %d",array[i].nombre,array[i].apellido,array[i].cuit,array[i].idCliente,array[i].isEmpty);
            }
        }
    }
    return retorno;
}

/** \brief Muestra los clientes sin discriminar el empty
 *
 * \param Cliente* array el array de los clientes
 * \param int limite el tamaño de la array
 * \return int -1 si se le pasaron mal los parametros, 0 si esta todo bien
 *
 */
int cliente_mostrarDebug(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("\n[DEBUG] %s - %s - %s - %d - %d",array[i].nombre,array[i].apellido,array[i].cuit,array[i].idCliente,array[i].isEmpty);
        }
    }
    return retorno;
}


/** \brief da de alta un cliente
 *
 * \param Cliente* array el array de los clientes
 * \param int limite el tamaño de la array
 * \return int -1 si se pasan los parametros mal, -2 si el indice es invalido, -3 si no se completan los datos bien, 0 todo bien
 *
 */
int cliente_alta(Cliente* array,int limite)
{
    int retorno = -1;
    char nombre[50];
    char apellido[50];
    char cuit[50];
    int id;
    int indice;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(array,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = proximoId();
            if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            {
                if(!getValidString("Apellido?","Error","Overflow", apellido,50,2))
                {
                    if(!pedirCUIT(cuit, "CUIT?", "Error", 2))
                    {
                        retorno = 0;
                        strcpy(array[indice].nombre,nombre);
                        strcpy(array[indice].apellido,apellido);
                        strcpy(array[indice].cuit,cuit);
                        array[indice].idCliente = id;
                        array[indice].isEmpty = OCUPADO;
                    }
                }
            }
        }
    }
    return retorno;
}



/** \brief modifica los datos de un cliente
 *
 * \param Cliente *array el array de clientes
 * \param int limite el tamaño del array
 * \param int id el id a modificar
 * \return int -1 si le pasaron mal los parametros, -2 si el indice es invalido, -3 si no completan bien los datos a modificar, 0 si esta todo bien
 *
 */
int cliente_modificacion(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];
    char apellido[50];
    char cuit[50];
    if(array != NULL && limite >0)
    {
        indice = cliente_buscarPorId(array,limite,id);
        retorno = -2;
        if(indice >= 0)
        {
            retorno = -3;
            if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            {
                if(!getValidString("Apellido?","Error","Overflow", apellido,50,2))
                {
                    if(!pedirCUIT(cuit, "CUIT?", "Error", 2))
                    {
                        retorno = 0;
                        strcpy(array[indice].nombre,nombre);
                        strcpy(array[indice].apellido,apellido);
                        strcpy(array[indice].cuit,cuit);
                    }
                }
            }
        }
    }
    return retorno;
}


/** \brief busca el proximo lugar libre
 *
 * \param Cliente* array el array de las clientes
 * \param int limite el tamaño de la array
 * \return int -1 si se le pasaron parametros mal, -2 si no hay lugar libre, >=0 el indice del array donde esta libre
 *
 */
static int buscarLugarLibre(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief obtiene el proximo id a asignar en alta
 *
 * \return int el id a usar
 *
 */
static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}



/** \brief Ordena la array de clientes por nombre
 *
 * \param Cliente* array el array a ordenar
 * \param int limite el tamaño de la array
 * \param int orden el orden asignado para ordenar (1 o 0)
 * \return int -1 si se le pasan mal los parametros, 0 todo bien
 *
 */
int cliente_ordenar(Cliente* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Cliente auxiliar;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(array[i].isEmpty == OCUPADO && array[i+1].isEmpty == OCUPADO )
                    {
                        if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && !orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && orden)) //<------------
                        {
                            auxiliar = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return retorno;
}









































