#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#include "servicio.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief Inicializa al array  poniendo isEmpty en 1
 *
 * \param vec Array a inicializar
 * \param tam Tamanio del array a inicializar
 *
 */
int inicializarTrabajos(eTrabajo trabajos[],int tam);

/** \brief busca un lugar libre en el array de trabajos
 *
 * \param trabajos[] array trabajos
 * \param tam tamanio del array
 * \return el indice del lugar libre o -1 si ya no hay lugar
 *
 */
int buscarLibreTrabajo(eTrabajo trabajos[],int tam);

/** \brief carga un nuevo trabajo en el array trabajos
 *
 * \param trabajos[] array trabajos
 * \param tamTrabajos tamanio del array
 * \param servicios[] eServicio
 * \param tamS int
 * \param mascotas[] eMascota
 * \param tamMas int
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \param proxId el id del nuevo trabajo
 * \return 0 si se pudo hacer el alta o -1 si no
 *
 */
int altaTrabajo(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[],int tamS,eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT,int proxId);

/** \brief muestra un trabajo del array trabajos
 *
 * \param trabajo trabajo a mostrar
 * \param servicios[] eServicio
 * \param tamS int
 * \param mascotas[] eMascota
 * \param tamMas int
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajo,eServicio servicios[],int tamS,eMascota mascotas[],int tamMas);

/** \brief lista todos los trabajos cargados
 *
 * \param trabajos[] eTrabajo
 * \param tamTrabajos int
 * \param servicios[] eServicio
 * \param tamS int
 * \param mascotas[] eMascota
 * \param tamMas int
 * \return 0 si se pudieron listar o -1 si no
 *
 */
int listarTrabajos(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[],int tamS,eMascota mascotas[],int tamMas);
