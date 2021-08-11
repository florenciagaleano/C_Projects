#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char desc[20];
}eColor;

#endif // COLOR_H_INCLUDED

/** \brief muestra el listado
 *
 * \param array con los elementos a mostrar
 * \param tamanio del array
 *
 */
int listarColores(eColor colores[],int tamCol);


/** \brief muestra un elemento
 *
 * \param elemento a mostrar
 *
 */
void mostrarColor(eColor color);

/** \brief Busca el id pasado por parametro
 *
 * \param vec el array donde buscar
 * \param tam Tamanio del array
 * \param id El id que se va a buscar
 * \return 0 si se encontro el id,sino -1
 *
 */
int validarColor(eColor colores[],int tamC,int id);

/** \brief carga la desce del elmento con el id pasado
 *
 * \param cadena en la que se carga el elemento
 * \param array
 * \param tam del array
 * \param id del elemento a cargar
 * \return 0 si se pudo cargar y -1 si no
 *
 */
int cargarDescColor(char str[],eColor colores[],int tamC,int id);

/** \brief muestra el listado de colores y le pide al usuario que elija uno
 *
 * \param colores Array colores
 * \param tam del array
 * \return int El id ingresado
 *
 */
int getIdColor(eColor colores[],int tam);
