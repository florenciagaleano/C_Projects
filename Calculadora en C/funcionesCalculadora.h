#ifndef FUNCIONESCALCULADORA_H_INCLUDED
#define FUNCIONESCALCULADORA_H_INCLUDED


#endif // FUNCIONESCALCULADORA_H_INCLUDED

/** \brief Muestra el men� de opciones
 *
 * \param num1 primer operando
 * \param num2 segundo operando
 * \param flag1 Flag del primer operando
 * \param flag2 Flag del segundo operando
 * \param flag3 Flag de la tercera opci�n
 * \return la opci�n elegida
 *
 */
int mostrarMenu(int num1,int num2,int flag1,int flag2,int flag3);

/** \brief Muestra las operaciones que se realizar�n
 *
 * \param num1 primer operando
 * \param num2 segundo operando
 * \param flag Flag de la opci�n 3
 *
 */
void mostrarOperaciones(int num1,int num2,int flag);//funci�n auxiliar a mostrarMenu

/** \brief muestra los resultados de las operaciones
 *
 * \param num1 primer operando
 * \param num2 segundo operando
 * \param suma Resultado de la suma
 * \param resta Resultado de la resta
 * \param division Resultado de la division
 * \param multiplicaci�n Resultado de la multiplicaci�n
 * \param factorialA Resultado del c�lculo del factorial de num1
 * \param factorialB Resultado del c�lculo del factorial de num2
 *
 */
void mostrarResultados(int num1,int num2,int suma,int resta,float division,int multiplicacion,long long int factorialA,long long int factorialB);

/** \brief Pide un numero y lo retorna
 *
 * \param mensaje El mensaje a mostrar
 * \return el n�mero ingresado
 *
 */
int getInt(char mensaje[]);

 /** \brief Muestra un mensaje y pausa la pantalla
 *
 * \param mensaje Mensaje a mostrar
 *
 */
void mostrarMensaje(char mensaje[]);



