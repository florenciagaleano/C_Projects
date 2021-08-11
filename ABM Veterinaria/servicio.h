#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char desc[25];
    float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief muestra el listado
 *
 * \param array con los elementos a mostrar
 * \param tamanio del array
 *
 */
int listarServicios(eServicio servicios[],int tam);

/** \brief muestra un elemento
 *
 * \param elemento a mostrar
 *
 */
void mostrarServicio(eServicio servico);

/** \brief Busca el id pasado por parametro
 *
 * \param vec el array donde buscar
 * \param tam Tamanio del array
 * \param id El id que se va a buscar
 * \return 0 si se encontro el id,sino -1
 *
 */
int validarServicio(eServicio servicios[],int tamS,int id);

/** \brief carga la desce del elmento con el id pasado
 *
 * \param cadena en la que se carga el elemento
 * \param array
 * \param tam del array
 * \param id del elemento a cargar
 * \return 0 si se pudo cargar y -1 si no
 *
 */
int cargarDescServicio(char str[],eServicio servicos[],int tam,int id);

/** \brief muestra el listado de servicios y le pide al usuario que elija uno
 *
 * \param servicios[] eServicio
 * \param tam int
 * \return el id de servicio
 *
 */
int getIdServicio(eServicio servicios[],int tam);
