#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "publicaciones.h"
#include "utn.h"
#define QTY 10
#define OCUPADO 0
#define LIBRE 1
#include "cliente.h"
#include "informar.h"

static int buscarLugarLibre(Publicaciones* array,int limite);
static int proximoId();

/** \brief Inicializa el empty del array publicaciones
 *
 * \param Publicaciones* array array a inicializar
 * \param int limite tamaño del array
 * \return int -1 si se le pasaron parametros mal, 0 si esta todo bien
 *
 */
int publicaciones_init(Publicaciones* array,int limite)
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

/** \brief Busca el indice atravez de recibir un id
 *
 * \param Publicaciones* array  array en la cual buscar
 * \param int limite tamaño de la array
 * \param int id el id a encontrar su indice
 * \return int -1 si se le pasaron parametros mal, -2 si no se encontro el id, >=0 ek indice donde se encuentra el id
 *
 */
int publicaciones_buscarPorId(Publicaciones* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].idPublicaciones == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief da de baja una publicacion
 *
 * \param Publicaciones* array el array en la cual dar de baja
 * \param int limite el tamaño de la array
 * \param int id el id a encontrar para dar de baja
 * \return int -1 si se le pasaron mal los parametros, -2 si no se encontro el indice, 0 todo correcto lo da de baja
 *
 */
int publicaciones_baja(Publicaciones* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    if(limite > 0 && array != NULL)
    {
        indice = publicaciones_buscarPorId(array,limite,id);
        if(indice >= 0)
        {
            retorno = 0;
            array[indice].isEmpty = LIBRE;
        }
        else
        {
            retorno = -2;
        }
    }
    return retorno;
}

/** \brief Muestra todas la publicaciones
 *
 * \param Publicaciones* array el array de las publicaciones
 * \param int limite el tamaño de la array
 * \return int -1 si se le pasan mal los parametros, 0 si esta todo bien
 *
 */
int publicaciones_mostrar(Publicaciones* array,int limite)
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
               printf("\n[RELEASE] %s - %d - %d",array[i].texto,array[i].idPublicaciones,array[i].isEmpty);
            }
        }
    }
    return retorno;
}

/** \brief Muestra todas la publicaciones incluidas las empty
 *
 * \param Publicaciones* array el array de las publicaciones
 * \param int limite el tamaño de la array
 * \return int -1 si se le pasan mal los parametros, 0 si esta todo bien
 *
 */
int publicaciones_mostrarDebug(Publicaciones* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("\n[DEBUG] %s - %d - %d",array[i].texto,array[i].idPublicaciones,array[i].isEmpty);
        }
    }
    return retorno;
}


/** \brief da de alta una publicacion
 *
 * \param Publicaciones* array el array de las publicaciones
 * \param int limite tamaño de la array de publicaciones
 * \param Cliente* arrayC el array de los clientes
 * \param int limiteC tamaño del array de clientes
 * \return int -1 si se pasaron mal los parametros, -2 si el indice esta mal, -3 si no registra bien los datos, 0 todo bien
 *
 */
int publicaciones_alta(Publicaciones* array,int limite, Cliente *arrayC, int limiteC)
{
    int retorno = -1;
    char texto[65];
    int rubro;
    int idCliente;
    int id;
    int indice;

    if(limite > 0 && array != NULL && arrayC != NULL && limiteC > 0)
    {
        retorno = -2;
        indice = buscarLugarLibre(array,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = proximoId();
            if(!getValidString("Texto?","Error","Overflow", texto,65,2))
            {
                if(!getValidInt("Rubro?", "Error", &rubro, 0, 50, 2))
                {
                    if(!getValidId(arrayC, limiteC, &idCliente))
                    {
                        retorno = 0;
                        array[indice].rubro = rubro;
                        array[indice].idCliente = idCliente;
                        strcpy(array[indice].texto,texto);
                        array[indice].idPublicaciones = id;
                        array[indice].isEmpty = OCUPADO;
                        array[indice].estado = 1;
                        printf("Texto: %s  IdCliente: %d\n", array[indice].texto, array[indice].idCliente);
                    }
                }
            }
        }
    }
    return retorno;
}



/** \brief modifica una publicacion
 *
 * \param Publicaciones* array el array de las publicaciones
 * \param int limite el tamaño de la array
 * \param int id el id de la publicacion a modificar
 * \return int -1 si se le pasan mal los parametros, -2 si no se obtienen los datos
 *
 */
int publicaciones_modificacion(Publicaciones* array,int limite, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];
    if(array != NULL && limite > 0)
    {
        indice = publicaciones_buscarPorId(array,limite,id);
        if(indice >= 0)
        {
            retorno = -2;
            if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            {
                retorno = 0;
                strcpy(array[indice].texto,nombre);
            }
        }
    }
    return retorno;
}


/** \brief busca el proximo lugar libre
 *
 * \param Publicaciones* array el array de las publicaciones
 * \param int limite el tamaño de la array
 * \return int -1 si se le pasaron parametros mal, -2 si no hay lugar libre, >=0 el indice del array donde esta libre
 *
 */
static int buscarLugarLibre(Publicaciones* array,int limite)
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



/** \brief pide una id y la verifica
 *
 * \param Cliente* arrayC array de clientes
 * \param int limiteC limite de la array
 * \param int* idCliente donde guardar la id encontrada valida
 * \return int -1 si se le pasan parametros mal, -2 si no es valida, 0 si esta todo bien
 *
 */
int getValidId(Cliente *arrayC, int limiteC, int *idCliente)
{
    int i;
    int aux;
    int retorno = -1;
    getValidInt("IdCliente?", "Error", &aux, 0, 1000, 2);
    if(limiteC > 0 && arrayC != NULL)
    {
        for(i=0;i<limiteC;i++)
        {
            if(!arrayC[i].isEmpty && arrayC[i].idCliente == aux)
            {
                *idCliente = aux;
                retorno = 0;
                break;
            }
            retorno = -2;
        }
    }
    return retorno;
}

/** \brief Obtiene una publicacion valida
 *
 * \param Publicaciones* array el array de las publicaciones
 * \param int limite el tamaño de la array
 * \param int* idPublicacion lugar donde guardar el id obtenido
 * \param int* indice lugar donde guardar el indice de la id obtenida
 * \return int -1 si se le pasaron mal los parametros, -2 si no se encontro el id, 0 si esta todo bien
 *
 */
int getValidIdPublicacion(Publicaciones *array, int limite, int *idPublicacion, int *indice)
{
    int i;
    int aux;
    getValidInt("IdPublicacion?", "Error", &aux, 0, 1000, 2);
    int retorno = -1;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPublicaciones == aux)
            {
                *idPublicacion = aux;
                *indice =i;
                retorno = 0;
                break;
            }
            retorno = -2;
        }
    }
    return retorno;
}



/** \brief Cambia el estado de una publicacion
 *
 * \param Publicaciones* array el array de las publicaciones
 * \param int limite el tamaño del array de publicaciones
 * \param Cliente* arrayC el array de los clientes
 * \param int limiteC el tamaño del array de los clientes
 * \return int -1 si se le pasan mal los parametros, -2 si no obtiene un idpublicacion valido, -3 si quiso cancelar, 0 si todo bien
 *
 */
int publicaciones_Estado(Publicaciones *array, int limite, Cliente *arrayC, int limiteC)
{
    int idPublicacion;
    int indicePublicacion;
    int indice;
    int opcion = -1;
    int retorno = -1;
    if(limiteC > 0 && arrayC != NULL && limite > 0 && array != NULL)
    {
        retorno = -2;
        if(!getValidIdPublicacion(array, limite, &idPublicacion, &indicePublicacion))
        {
            indice = informar_duenioPublicaciones(arrayC, limiteC, array, limite, idPublicacion);
            printf("Cliente seleccionado es: %s %s cuit: %s id: &d\n",arrayC[indice].nombre, arrayC[indice].apellido, arrayC[indice].cuit, arrayC[indice].idCliente);
            retorno = 0;
        }
        getValidInt("Seleccione 1 pausar, 2 renaudar, 3 cancelar", "No valido", &opcion, 1,3,2);
        switch(opcion)
        {
        case 1:
            array[indicePublicacion].estado = 0;
            break;
        case 2:
            array[indicePublicacion].estado = 1;
            break;
        case 3:
            retorno = -3;
            break;
        default :
            printf("Opcion invalida");
            break;
        }
    }
        return retorno;

}





































