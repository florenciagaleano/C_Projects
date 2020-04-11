#ifndef FUNCIONESCALCULADORA_H_INCLUDED
#define FUNCIONESCALCULADORA_H_INCLUDED


#endif // FUNCIONESCALCULADORA_H_INCLUDED

/** \brief Muestra el menú de opciones
 *
 * \param primer operando
 * \param segundo operando
 * \param flag del primer operando
 * \param flag del segundo operando
 * \param flag de la tercera opción
 * \return devuleve la opción elegida
 *
 */
int mostrarMenu(int,int,int,int,int);

/** \brief Muestra el submenú de la  opción 3
 *
 * \param primer operando
 * \param segundo operando
 * \param flag de la opción 3
 *
 */
void mostrarSubmenu(int,int,int);//función auxiliar a mostrarMenu

/** \brief muestra los resultados de las operaciones
 *
 * \param primer operando
 * \param segundo operando
 *
 */
void mostrarResultados(int,int);

/** \brief Muestra un mensaje
 *
 * \param Mensaje a mostrar
 *
 */
void mostrarMensaje(char[]);



