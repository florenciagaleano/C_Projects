#ifndef FUNCIONESCALCULADORA_H_INCLUDED
#define FUNCIONESCALCULADORA_H_INCLUDED


#endif // FUNCIONESCALCULADORA_H_INCLUDED

/** \brief Muestra el menú de opciones
 *
 * \param num1 primer operando
 * \param num2 segundo operando
 * \param flag1 Flag del primer operando
 * \param flag2 Flag del segundo operando
 * \param flag3 Flag de la tercera opción
 * \return la opción elegida
 *
 */
int mostrarMenu(int num1,int num2,int flag1,int flag2,int flag3);

/** \brief Muestra el submenú de la  opción 3
 *
 * \param num1 primer operando
 * \param num2 segundo operando
 * \param flag Flag de la opción 3
 *
 */
void mostrarSubmenu(int num1,int num2,int flag);//función auxiliar a mostrarMenu

/** \brief muestra los resultados de las operaciones
 *
 * \param num1 primer operando
 * \param num2 segundo operando
 * \param suma Resultado de la suma
 * \param resta Resultado de la resta
 * \param division Resultado de la division
 * \param multiplicación Resultado de la multiplicación
 * \param factorialA Resultado del cálculo del factorial de num1
 * \param FactorialB Resultado del cálculo del factorial de num2
 *
 */
void mostrarResultados(int num1,int num2,int suma,int resta,float division,int multiplicacion,long long int factorialA,long long int factorialB);



/** \brief Pide un numero, lo valida y lo retorna
 *
 * \param mensaje El mensaje a mostrar
 * \param mensajeError El mensaje a mostrar si no se ingresó un numero
 * \return el número ingresado validado
 *
 */
int getInt(char mensaje[],char mensajeError[]);

/** \brief Valida que se hayan ingresado numeros
 *
 * \param cadena a validar
 * \return 1 si se ingresaron solo numeros, 0 si se ingreso otra cosa
 *
 */
int validarNumeros(char cadena[]);

 /** \brief Muestra un mensaje y pausa la pantalla
 *
 * \param mensaje Mensaje a mostrar
 *
 */
void mostrarMensaje(char mensaje[]);



