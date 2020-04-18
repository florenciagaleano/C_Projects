#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>//esta biblioteca permite el uso de tolower()
#include "funcionesCalculadora.h"
#include "operaciones.h"

int main()
{
    int a;//primer operando
    int b;//segundo operando
    int flagA=0;//esta bandera se levanta al ingresar el número A
    int flagB=0;//esta bandera se levanta al ingresar el número B
    int flagOpcion3=0;//esta bandera se levanta si se eligio la opcion 3 y A y B fueron ingresados
    int suma;
    int resta;
    float division;
    int multiplicacion;
    long long int factorialA;
    long long int factorialB;
    char respuesta='n';//si la respuesta es diferente a 'n' se rompe el while


    do
    {
        system("cls");//la pantalla se va actualizando con los valores actuales cargados

        switch(mostrarMenu(a,b,flagA,flagB,flagOpcion3))//switch de la opción elegida
        {
            case 1:
                a=getInt("\nIngrese primer operando: ");
                flagA=1;
                break;

            case 2:
                b=getInt("\nIngrese segundo operando:");
                flagB=1;
                break;

            case 3:
                if(flagA&&flagB)
                {
                    suma=sumar(a,b);
                    resta=restar(a,b);
                    division=dividir(a,b);
                    multiplicacion=multiplicar(a,b);
                    factorialA=calcularFactorial(a);
                    factorialB=calcularFactorial(b);

                    mostrarMensaje("\n***LAS OPERACIONES YA FUERON CALCULADAS***\n\n");
                    flagOpcion3=1;
                }
                else
                {
                    mostrarMensaje("ERROR. Primero debe ingresar A y B\n\n");
                }

                break;

            case 4:
                if(flagOpcion3)
                {
                    mostrarResultados(a,b,suma,resta,division,multiplicacion,factorialA,factorialB);
                    flagA=0;
                    flagB=0;
                    flagOpcion3=0;/*reinicializo las variables si el usuario ya vio los resultados
                                        por si quiere realizar otras operaciones*/
                    system("pause");//system ("pause") para que el usuario pueda ver los resultados hasta que decida pulsar una tecla
                }
                else
                {
                    mostrarMensaje("ERROR. Primero debe calcular los resultados\n\n");
                }

                break;

            case 5:
                printf("Esta seguro de que desea salir? s/n\n");
                fflush(stdin);
                scanf("%c",&respuesta);
                respuesta=tolower(respuesta);
                break;

            default:
                mostrarMensaje("Opcion no valida\n\n");
                break;

        }

    }
    while(respuesta=='n');

    system("cls");//si el usuario elige salir se limpia la consola

    return 0;
}
