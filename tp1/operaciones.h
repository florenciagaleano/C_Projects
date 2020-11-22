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
 * \return el resultado de la multipliaci�n
 *
 */
int multiplicar(int a,int b);

/** \brief Divide dos enteros y devuelve el resultado
 *
 * \param a primer operando
 * \param b segundo operando
 * \return el resultado de la divisi�n y 0 si b es 0
 *
 */
float dividir(int a,int b);

/** \brief Calcula el factorial de un n�mero y lo devuelve
 *
 * \param n�mero entero del que se calcular� el factorial
 * \return 0 si se ingres� un n�mero negativo, sino el resultado del factorial
 *
 */
long long int calcularFactorial(int numero);
//ACLARACION: los resultados de los factoriales son correctos hasta el 20


#endif // OPERACIONES_H_INCLUDED
