#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char desc[20];
}eTipo;

#endif // TIPO_H_INCLUDED

/** \brief muestra el listado
 *
 * \param array con los elementos a mostrar
 * \param tamanio del array
 *
 */
int listarTipos(eTipo tipos[],int tamTipos);

/** \brief muestra un elemento
 *
 * \param elemento a mostrar
 *
 */
void mostrarTipo(eTipo tipo);

/** \brief Busca el id pasado por parametro
 *
 * \param vec el array donde buscar
 * \param tam Tamanio del array
 * \param id El id que se va a buscar
 * \return 0 si se encontro el id,sino -1
 *
 */
int validarTipo(eTipo tipos[],int tamT,int id);

/** \brief carga la desce del elmento con el id pasado
 *
 * \param cadena en la que se carga el elemento
 * \param array
 * \param tam del array
 * \param id del elemento a cargar
 * \return 0 si se pudo cargar y -1 si no
 *
 */
int cargarDescTipo(char str[],eTipo tipos[],int tamT,int id);

/** \brief muestra los tipos y le pide al usuario que elija uno
 *
 * \param tipos array eTipo
 * \param tam Tamanio del array
 * \return el id ingresado y validado
 *
 */
int getIdTipo(eTipo tipos[],int tam);
