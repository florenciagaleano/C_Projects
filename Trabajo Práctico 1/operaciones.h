#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED

/** \brief Suma dos enteros y devuelve el resultado
 *
 * \param a primer operando
 * \param b segundo operando
 * \return el resultado de la suma
 *
 */
int sumar(int a,int b);

/** \brief Resta dos enteros y devuelve el resultado
 *
 * \param a primer operando
 * \param b segundo operando
 * \return el resultado de las resta
 *
 */
int restar(int a,int b);

/** \brief Multiplica dos enteros y devuelve el resultado
 *
 * \param a primer operando
 * \param b segundo operando
 * \return el resultado de la multipliación
 *
 */
int multiplicar(int a,int b);

/** \brief Divide dos enteros y devuelve el resultado
 *
 * \param a primer operando
 * \param b segundo operando
 * \return el resultado de la división y 0 si b es 0
 *
 */
float dividir(int a,int b);

/** \brief Calcula el factorial de un número y lo devuelve
 *
 * \param número entero del que se calculará el factorial
 * \return 0 si se ingresó un número negativo, sino el resultado del factorial
 *
 */
long long int calcularFactorial(int numero);


#endif // OPERACIONES_H_INCLUDED
