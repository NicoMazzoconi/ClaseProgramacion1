#include "parcial.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "lib.h"
/** \brief Inicializa los empty de los usuarios
 *
 * \param usuario *cuantas arrays de las cuentas a modificar
 * \param int sizeArray tamaño de la array
 * \return void
 *
 */
void usr_init(usuario *cuantas,int sizeArray)
{
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        cuantas[i].isEmpty = 1;
    }
}
/** \brief Inicializa los empty de los productos
 *
 * \param producto *articulos arrays de los productos a modificar
 * \param int sizeArray tamaño de la array
 * \return void
 *
 */
void pro_init(producto *articulos,int sizeArray)
{
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        articulos[i].isEmpty = 1;
    }
}
/** \brief Inicializa los empty de las compras
 *
 * \param publicacion *compras arrays de las compras a modificar
 * \param int sizeArray tamaño de la array
 * \return void
 *
 */
void com_init(compra *compras,int sizeArray)
{
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        compras[i].isEmpty = 1;
    }
}
/** \brief Crea un nuevo usuario al sistema
 *
 * \param usuario *cuentas array donde agregar los nuevos datos
 * \param int sizeArray tamaño de la array
 * \param int idUsuarios id a agregar al usuario
 * \return int 0 todo bien, -1 usuarios llenos
 *
 */
int usr_alta(usuario *cuentas, int sizeArray, int idUsuarios)
{
    int empty;
    empty = usuarios_buscarLibre(cuentas, sizeArray);

    if(empty >= 0)
    {
        do
        {
            getString("Ingrese su nombre de usuario\n", cuentas[empty].cuanta);
        }while(esString(cuentas[empty].cuanta) != 0);
        do
        {
            getString("Ingrese su contraseña\n", cuentas[empty].password);
        }while(esPassword(cuentas[empty].password) != 0);
        cuentas[empty].idUsuario = idUsuarios;
        cuentas[empty].isEmpty = 0;
    }
    else
        printf("No hay lugar");
}

/** \brief
 *
 * \param articulos producto*
 * \param sizeArray int
 * \param idProducto int
 * \return int
 *
 */
int pro_alta(producto *articulos, int sizeArray, int idProducto)
{
    int empty;
    int precio;
    float stock;
    empty = productos_buscarLibre(articulos, sizeArray);

    if(empty >= 0)
    {
        do
        {
            getString("Ingrese su nombre\n", articulos[empty].nombre);
        }while(esString(articulos[empty].nombre) != 0);
        getInt("Ingrese el stock", "Stock invalido", 20, 10000, 1, &stock);
        articulos[empty].stock = stock;
        getFloat("Ingrese el precio", "Stock invalido", 20, 10000, 1, &precio);
        articulos[empty].precio = precio;
        articulos[empty].idProducto = idProducto;
        articulos[empty].isEmpty = 0;
    }
    else
        printf("No hay lugar");
}

int usr_baja(usuario *usuarios, int sizeArray)
{
    int idUsuario;
    int i;
    int retorno = -1;
    getInt("Ingrese el Id \n", "Id no valido \n", 3, 10000, 0, &idUsuario);
    for(i = 0; i < sizeArray; i++)
    {
        if(usuarios[i].idUsuario == idUsuario)
        {
            retorno = 0;
            usuarios[i].isEmpty = 1;
            break;
        }
    }
    return retorno;
}

int pro_baja(producto *articulos, int sizeArray)
{
    int idProducto;
    int i;
    int retorno = -1;
    getInt("Ingrese el Id \n", "Id no valido \n", 3, 10000, 0, &idProducto);
    for(i = 0; i < sizeArray; i++)
    {
        if(articulos[i].idProducto == idProducto)
        {
            retorno = 0;
            articulos[i].isEmpty = 1;
            break;
        }
    }
    return retorno;
}

int usr_modificar(usuario *cuentas, int sizeArray)
{
    int idUsuario;
    int i;
    getInt("Ingrese el Id \n", "Id no valido \n", 3, 10000, 0, &idUsuario);
    for(i = 0; i < sizeArray; i++)
    {
        if(cuentas[i].idUsuario == idUsuario)
        {
            break;
        }
    }
    if(i != sizeArray)
    {
        do
        {
            getString("Ingrese su nueva password\n", cuentas[i].password);
        }while(esPassword(cuentas[i].password) != 0);
    }
}

int pro_modificar(producto *articulos, int sizeArray)
{
    int idProducto;
    float precio;
    int stock;
    int i;
    getInt("Ingrese el Id \n", "Id no valido \n", 3, 10000, 0, &idProducto);
    for(i = 0; i < sizeArray; i++)
    {
        if(articulos[i].idProducto == idProducto)
        {
            break;
        }
    }
    if(i != sizeArray)
    {
        do
        {
            getString("Ingrese su nombre\n", articulos[i].nombre);
        }while(esString(articulos[i].nombre) != 0);
        getInt("Ingrese el stock", "Stock invalido", 20, 10000, 1, &stock);
        articulos[i].stock = stock;
        getFloat("Ingrese el precio", "Stock invalido", 20, 10000, 1, &precio);
        articulos[i].precio = precio;
    }
}

int login(char *mandado, char *password, usuario *cuentas, int sizeArray)
{
    int i;
    int retorno = -1;
    for(i=0;i<sizeArray;i++)
    {
        if(cuentas[i].cuanta == mandado)
        {
            break;
        }
    }
    if(cuentas[i].password == password)
    {
        retorno = 0;
    }
    return retorno;
}
