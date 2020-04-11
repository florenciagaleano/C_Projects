#include <stdio.h>
#include <stdlib.h>
#include "funcionesCalculadora.h"
#include "operaciones.h"

int main()
{
    int a;
    int b;
    int flagA=0;//esta bandera se levanta al ingresar el número A
    int flagB=0;//esta bandera se levanta al ingresar el número B
    int flagOpcion3=0;//esta bandera se levanta si se eligio la opcion 3 y A y B fueron ingresados
    int opcion;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    long long int factorialA;
    long long int factorialB;


    do
    {
        system("cls");//la pantalla va actualizando con los valores actuales cargados
        opcion=mostrarMenu(a,b,flagA,flagB,flagOpcion3);

        switch(opcion)//switch de la opción elegida
        {
            case 1:
                a=getInt("Ingrese primer operando:");
                flagA=1;
                break;
            case 2:
                b=getInt("Ingrese segundo operando:");
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

                    mostrarMensaje("\n\nLas operaciones ya fueron calculadas\n\n");
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
                    system("pause");//system ("pause") para que el usuario pueda ver los resultado hasta que decida pulsar una tecla
                }
                else
                {
                    mostrarMensaje("ERROR. Primero debe calcular los resultados\n\n");
                }

                break;
            case 5:
                break;
            default:
                mostrarMensaje("Opcion no valida\n\n");

        }

    }
    while(opcion!=5);

    system("cls");//si el usuario elige salir se limpia la consola

    return 0;
}
