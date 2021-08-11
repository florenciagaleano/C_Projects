#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#include "servicio.h"
#include "trabajo.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#endif // INFORMES_H_INCLUDED


/** \brief
 *
 * \param mascotas array eMascota
 * \param tamMas int
 * \param colores array eColor
 * \param tamC int
 * \param tipos array eTipo
 * \param tamT int
 * \param trabajos array eTrabajo
 * \param tamTrabajos int
 * \param servicios array eServicio
 * \param tamS int
 * \return 0 si salio todo bien o -1 si no
 *
 */
int informar(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT,eTrabajo trabajos[],int tamTrabajos,eServicio servicios[],int tamS);

/** \brief muestra un menu de opciones y le pide al usuario que elija una
 *
 * \return char La opcion elegida
 *
 */
char menuInformes();

/** \brief lista mascotas de un color elegido por el usuario
 *
 * \param mascotas array eMascota
 * \param tamMas int
 * \param colores array eColor
 * \param tamC int
 * \param tipos array eTipo
 * \param tamT int
 * \return 0 si salio todo bien y -1 si no
 *
 */
int listarMascotasXUnColor(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT);

/** \brief lista mascotas de un tipo elegido por el usuario
 *
 * \param mascotas array eMascota
 * \param tamMas int
 * \param colores array eColor
 * \param tamC int
 * \param tipos array eTipo
 * \param tamT int
 * \return 0 si salio todo bien y -1 si no
 *
 */
int listarMascotasXUnTipo(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT);

/** \brief muestra todas las mascotas separadas por tipo
 *
 * \param mascotas array eMascota
 * \param tamMas int
 * \param colores array eColor
 * \param tamC int
 * \param tipos array eTipo
 * \param tamT int
 * \return 0 si salio todo bien y -1 si no
 *
 */
int listarMascotasXTipo(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT);

/** \brief muestra el color mas comun entre las mascotas
 *
 * \param mascotas array eMascota
 * \param tamMas int
 * \param colores array eColor
 * \param tamC int
 * \return 0 si salio todo bien y -1 si no
 *
 */
int informarColorFavorito(eMascota mascotas[],int tamMas,eColor colores[],int tamC);

/** \brief muestra la o las mascotas de menor edad
 *
 * \param mascotas array eMascota
 * \param tamMas int
 * \param colores array eColor
 * \param tamC int
 * \param tipos array eTipo
 * \param tamT int
 * \return 0 si salio todo bien y -1 si no
 *
 */
int informarMascotaMasJoven(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT);

/** \brief cuenta la cantidad de mascotas de un color y un tipo determinados por el usuario
 *
 * \param mascotas array eMascota
 * \param tamMas int
 * \param colores array eColor
 * \param tamC int
 * \param tipos array eTipo
 * \param tamT int
 * \return 0 si salio todo bien y -1 si no
 *
 */
int contarMascotasXUnColorYTipo(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT);
///////////////////////////////////TRABAJOS//////////////////////////////////////

/** \brief pide alusuario que elija una mascota y muestra los trabajos que se le realizaron
 *
 * \param trabajos array eTrabajo
 * \param tamTra int
 * \param servicios array eServicio
 * \param tamS int
 * \param mascotas array eMascota
 * \param tamMas int
 * \param colores array eColor
 * \param tamC int
 * \param tipos array eTipo
 * \param tamT int
 * \return 0 si salio todo bien y -1 si no
 *
 */
int mostrarTrabajosXUnaMascota(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamS,eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT);

/** \brief pide una mascota y muestra la suma de importes por los servicios que se le realizaron
 *
 * \param trabajos[] eTrabajo
 * \param tamTra int
 * \param servicios[] eServicio
 * \param tamS int
 * \param mascotas[] eMascota
 * \param tamMas int
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return 0 si salio todo bien y -1 si no
 *
 */
int mostrarGananciaXUnaMascota(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamS,eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT);

/** \brief pide un servicio y muestra las mascotas y la fecha en que se realizo
 *
 * \param trabajos array eTrabajo
 * \param tamTra int
 * \param servicios array eServicio
 * \param tamS int
 * \param mascotas array eMascota
 * \param tamMas int
 * \param colores array eColor
 * \param tamC int
 * \param tipos array eTipo
 * \param tamT int
 * \return 0 si salio todo bien y -1 si no
 *
 */
int mostrarFechaYMascotaXServicio(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamS,eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT);

/** \brief pide al usuario una fecha y muestra los servicios realizados en la misma
 *
 * \param trabajos[] eTrabajo
 * \param tamTra int
 * \param servicios[] eServicio
 * \param tamS int
 * \return 0 si salio todo bien y -1 si no
 *
 */
int mostrarServiciosXFecha(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamS);
