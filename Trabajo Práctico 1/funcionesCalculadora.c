#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>//esta libreria permite el uso de la funcion atoi()
#include <string.h>//esta libreria permite el uso de la funcion strlen para validar numeros
#include "funcionesCalculadora.h"

int mostrarMenu(int num1,int num2,int flag1,int flag2,int flag3)
{
    int opcion;

    printf("     <<<<< M E N U >>>>>\n\n\n");

    //OPCIÓN 1. Si el usuario ya ingresÃ³ el operando "A" este se reemplazarÃ¡ por el número cargado
    if(flag1)
    {
        printf("1.Ingresar primer operando (A=%d)\n\n",num1);
    }
    else
    {
        printf("1.Ingresar primer operando (A=x)\n\n");
    }

    //OPCIÓN 2. Si el usuario ya ingresó el operando "B" este se reemplazará por el número cargado
    if(flag2)
    {
        printf("2.Ingresar segundo operando (B=%d)\n\n",num2);
    }
    else
    {
        printf("2.Ingresar segundo operando (B=y)\n\n");

    }

    //OPCIÓN 3.
    printf("3.Calcular operaciones\n\n");
    mostrarSubmenu(num1,num2,flag3);

    //OPCIÓN 4.
    printf("4.Informar resultados\n\n");

    //OPCIÓN 5.
    printf("5.Salir\n\n");

    printf("#########################################\n\n");

    opcion=getInt("Elija una opcion:","Reingrese opcion elegida:");

    return opcion;
}

void mostrarSubmenu(int num1,int num2,int flag)//FunciÃ³n auxiliar a mostrarMenÃº
{
    if(flag)//los valores actuales de A y B se muestran cargados si el usuario eligió calcular las operaciones
    {
        printf("a)Calcular la suma (%d + %d)\n",num1,num2);
        printf("b)Calcular la resta (%d - %d)\n",num1,num2);
        printf("c)Calcular la division (%d / %d)\n",num1,num2);
        printf("d)Calcular la multiplicacion (%d * %d)\n",num1,num2);
        printf("e)Calcular el factorial (%d y %d!)\n\n",num1,num2);
    }
    else
    {
        printf("a)Calcular la suma (A + B)\n");
        printf("b)Calcular la resta (A - B)\n");
        printf("c)Calcular la division (A / B)\n");
        printf("d)Calcular la multiplicacion (A * B)\n");
        printf("e)Calcular el factorial (A! y B!)\n\n");
    }
}

void mostrarResultados(int num1,int num2,int suma,int resta,float division,int multiplicacion,long long int factorialA,long long int factorialB)
{
        //SUMA
        printf("\n\na)El resultado de %d+%d es: %d\n",num1,num2,suma);
        //RESTA
        printf("b)El resultado de %d-%d es: %d\n",num1,num2,resta);
        //IF DE LA DIVISIÓN
        if(num2==0)
        {
            printf("c)No se puede dividir por 0\n");
        }else
        {
            printf("c)El resultado de %d/%d es: %.2f\n",num1,num2,division);
        }
        //MULTIPLICACIÓN
        printf("d)El resultado de %d*%d es: %d\n",num1,num2,multiplicacion);
        //FACTORIALES
        printf("e)El resultado del factorial de %d es %lld y el resultado del \nfactorial de %d es %lld\n\n",num1,factorialA,num2,factorialB);
        if(factorialA==0||factorialB==0)

        {
            printf("***ACLARACION***\nEl factorial que dio 0 no se pudo calcular porque no se\npuede calcular el factorial de numeros negativos\n\n");
        }
}

int getInt(char mensaje[],char mensajeError[])
{
    char numero[64];
    int numeroValidado;

    puts(mensaje);
    scanf("%s",numero);

    while(validarNumeros(numero)==0)//si la función validarNumeros devolvió 0 hubo un error
    {
        puts(mensajeError);
        fflush(stdin);
        scanf("%s",numero);
    }

    numeroValidado=atoi(numero);

    return numeroValidado;
}

int validarNumeros(char cadena[])
{
    int retorno=1;

    for(int i=0;i<strlen(cadena);i++)
    {
        if((cadena[i]<'0'||cadena[i]>'9')&&cadena[i]!='-')
        {
            retorno=0;
            break;
        }
    }
    /*la condición (cadena[i]!='-') en el if permite al usuario ingresar numeros
        negativos. Si solo se ingresa '-' será tomado como un 0*/

    return retorno;
}

void mostrarMensaje(char mensaje[])
{
    puts(mensaje);
    system("pause");
    //system("pause") le permitirá al usuario leer el mensaje hasta que pulse una tecla
}





