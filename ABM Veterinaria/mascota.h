#include "color.h"
#include "tipo.h"

#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    int isEmpty;
}eMascota;

#endif // MASCOTA_H_INCLUDED


/** \brief inicializa array poniendo los isEmpty en 0
 *
 * \param mascotas[] array a inicializar
 * \param tamMas tamanio del array
 * \return 0 si se pudo inicializar y -1 si no
 *
 */
int inicializarMascotas(eMascota mascotas[],int tamMas);

/** \brief busca un lugar libre en el array de mascotas
 *
 * \param mascotas[] array en el que buscar
 * \param tamMas tamanio del array
 * \return indice del lugar libre o -1 si ya no hay lugar
 *
 */
int buscarLibreMascota(eMascota mascotas[],int tamMas);

/** \brief cagra una nueva mascota en el array de mascotas
 *
 * \param mascotas[] array de mascotas
 * \param tamMas tamanio del array
 * \param colores[]
 * \param tamC
 * \param tipos[]
 * \param tamT
 * \param proxId El id que tendra la nueva mascota
 * \return 0 si se pudo cargar y -1 si no
 *
 */
int altaMascota(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT,int proxId);

/** \brief busca una mascota de acuerdo a un id pasado
 *
 * \param mascotas[] array mascotas
 * \param tamMas tamanio del aray
 * \param id id de la mascota a buscar
 * \return el indice en donde esta la mascota o -1 si no se encontro
 *
 */
int buscarMascotaXId(eMascota mascotas[],int tamMas,int id);

/** \brief lista a las mascotas cargadas
 *
 * \param mascotas[] array de mascotas
 * \param tamMas tamanio del array
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return 0 si se pudieron listar o -1 si no
 *
 */
int listarMascotas(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT);

/** \brief muestra a una sola mascota
 *
 * \param mascota la mascota a mostrar
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return void
 *
 */
void mostrarMascota(eMascota mascota,eColor colores[],int tamC,eTipo tipos[],int tamT);

/** \brief muestra las opciones de modificacion y le pide al usuario que elija una
 *
 * \return char La opcion elegida
 *
 */
char menuModificar();

/** \brief le pide al usuario que elija una mascota y modifica lo que el usuario pide
 *
 * \param mascotas[] array mascotas
 * \param tamMas tamanio del array mascotas
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return 0 si se puedo modificar,1 si el usuario no confirma o -1 si no se encontro el id de mascota
 *
 */
int modificarMascota(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT);

/** \brief le pide al usuario que elija una mascota y modifica lo que el usuario pide
 *
 * \param mascotas[] array mascotas
 * \param tamMas tamanio del array mascotas
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return 0 si se puedo hacer la baja,1 si el usuario no confirma o -1 si no se encontro el id de mascota
 *
 */
int bajaMascota(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT);

/** \brief ordena las mascotas por tipo y nombre
 *
 * \param mascotas[] array a ordenar
 * \param tamMas tamanio del array
 * \param tipos[] eTipo
 * \param tamT int
 * \return 0 si se pudieron ordenar o -1 si no
 *
 */
int ordenarMascotas(eMascota mascotas[],int tamMas,eTipo tipos[],int tamT);

/** \brief muestra un listado de mascotas y le pide al usuario que elija un id
 *
 * \param mascotas array eMascota
 * \param tam int
 * \param colores array eColor
 * \param tamC int
 * \param tipos array eTipo
 * \param tamTip int
 * \return id de la mascota validado
 *
 */
int getIdMascota(eMascota mascotas[],int tam,eColor colores[],int tamC,eTipo tipos[],int tamTip);
