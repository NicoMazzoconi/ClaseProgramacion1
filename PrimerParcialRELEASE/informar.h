#include "cliente.h"
#include "publicaciones.h"

/** \brief Pasas una idPublicacion y devuelve el inidice del cliente
 *
 * \param arrayC Cliente* array de los clientes
 * \param limiteC int espacio del array de clientes
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \param idPublicacion int el id a encontrar cliente dueño
 * \return int -1 error en los parametros recibidos, -2 no se encontro el id de pantalla, -3 no se encontro el cliente, > 0 indice del array del cliente
 *
 */
int informar_duenioPublicaciones(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP, int idPublicacion);

/** \brief Cuenta la cantidad de aviso del id del cliente
 *
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \param idCliente int cliente a encontrar
 * \return int -1 error en los parametros recibidos, >= 0 cantidad de avisos registrados
 *
 */
int informar_contadorDeAvisos(Publicaciones *arrayP, int limiteP, int idCliente);

/** \brief Muestra todos los clientes que tengan un aviso o mas
 *
 * \param arrayC Cliente* array de los clientes
 * \param limiteC int espacio del array de clientes
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \return int -1 error en los parametros recibidos, 0 cantidad de avisos encontrados
 *
 */
int informar_mostrarClientesConAvisos(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP);

/** \brief muestra las publicaciones activas
 *
 * \param arrayC Cliente* array de los clientes
 * \param limiteC int espacio del array de clientes
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \return int -1 error en los parametros recibidos, 0 todos bien muestra los encontrados
 *
 */
int informar_publicacionesActivas(Publicaciones *arrayP, int limiteP, Cliente *arrayC, int limiteC);

/** \brief Busca el indice del cliente enviado
 *
 * \param arrayC Cliente* array de los clientes
 * \param limiteC int espacio del array de clientes
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \param idCliente int cliente a identificar
 * \return int -1 error en los parametros recibidos, -2 no encontro el id de cliente, >= 0 indice del array de cliente donde se encuentra
 *
 */
int informar_duenioPublicacionesCliente(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP, int idCliente);

/** \brief Muestra el cliente con mas avisos
 *
 * \param arrayC Cliente* array de los clientes
 * \param limiteC int espacio del array de clientes
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \return int -1 error en los parametros recibidos, 0 todo bien muestra el cliente con mas avisos
 *
 */
int informar_clienteMasAvisos(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP);

/** \brief Muestra el cliente con mas avisos pausados
 *
 * \param arrayC Cliente* array de los clientes
 * \param limiteC int espacio del array de clientes
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \return int -1 error en los parametros recibidos, 0 todo bien muestra el cliente con mas avisos pausados
 *
 */
int informar_clienteMasAvisosPausados(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP);

/** \brief Muestra el cliente con mas avisos activos
 *
 * \param arrayC Cliente* array de los clientes
 * \param limiteC int espacio del array de clientes
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \return int -1 error en los parametros recibidos, 0 todo bien muestra el cliente con mas activos
 *
 */
int informar_clienteMasAvisosActivos(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP);

/** \brief Pide un rubro yte dice cuantas veces fue publicado
 *
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \return int -1 error en los parametros recibidos, 0 todo bien muestra cantidad de publicaciones activas del rubro
 *
 */
int informar_cantidadPublicacionActivasRubroIngresado(Publicaciones *arrayP, int limiteP);

/** \brief El rubro mas publicado en publicaciones activas
 *
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \return int -1 error en los parametros recibidos, 0 todo bien muestra el rubro con mas cantidad de publicaciones activas
 *
 */
int informar_rubroMasPublicacionesActivas(Publicaciones *arrayP, int limiteP);

/** \brief El rubro mas publicado en publicaciones pausadas
 *
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \return int -1 error en los parametros recibidos, 0 todo bien muestra el rubro con menos cantidad de publicaciones activas
 *
 */
int informar_rubroMenosPublicacionesActivas(Publicaciones *arrayP, int limiteP);
