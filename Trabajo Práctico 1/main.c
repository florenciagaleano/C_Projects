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
    int opcion;

    do
    {
        system("cls");//la pantalla va actualizando con los valores actuales cargados
        opcion=mostrarMenu(a,b,flagA,flagB,flagOpcion3);

        switch(opcion)//switch de la opción elegida
        {
            case 1:
                printf("Ingrese primer operando: ");
                scanf("%d",&a);
                flagA=1;
                break;
            case 2:
                printf("Ingrese segundo operando: ");
                scanf("%d",&b);
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
                break;
            default:
                mostrarMensaje("Opcion no valida\n\n");

        }

    }
    while(opcion!=5);

    system("cls");//si el usuario elige salir se limpia la consola

    return 0;
}
