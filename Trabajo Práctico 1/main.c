#include <stdio.h>
#include <stdlib.h>
#include "funcionesCalculadora.h"

int main()
{
    int a;
    int b;
    int flagA=0;//esta bandera se levanta al ingresar el número A
    int flagB=0;//esta bandera se levanta al ingresar el número B
    int flagOpcion3=0;//esta bandera se levanta si se eligio la opcion 3 y A y B fueron ingresados
    char seguir='s';

    do
    {
        system("cls");//la pantalla va actualizando con los valores actuales cargados

        switch(mostrarMenu(a,b,flagA,flagB,flagOpcion3))//switch de la opción elegida
        {
            case 1:
                getInt("Ingrese primer operando: ");
                flagA=1;
                break;
            case 2:
                getInt("Ingrese segundo operando: ");
                flagB=1;
                break;
            case 3:
                if(flagA&&flagB)
                {
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
                    mostrarResultados(a,b);
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
                seguir='n';
                break;
            default:
                mostrarMensaje("Opcion no valida\n\n");

        }

    }
    while(seguir=='s');

    system("cls");//si el usuario elige salir se limpia la consola

    return 0;
}
