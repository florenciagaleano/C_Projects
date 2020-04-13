#include <stdio.h>
#include <stdlib.h>
#include "funcionesCalculadora.h"

int mostrarMenu(int num1,int num2,int flag1,int flag2,int flag3)
{
    int opcion;

    printf("     <<<<< M E N U >>>>>\n\n\n");

    //OPCIÓN 1. Si el usuario ya ingresó el operando "A" este se reemplazará por el número cargado
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

    printf("Elija una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void mostrarSubmenu(int num1,int num2,int flag)//Función auxiliar a mostrarMenú
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
        printf("a)El resultado de %d+%d es: %d\n",num1,num2,suma);
        //RESTA
        printf("b)El resultado de %d-%d es: %d\n",num1,num2,resta);
        //IF DE LA DIVISION
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

int getInt(char mensaje[])
{
    int numero;

    puts(mensaje);
    scanf("%d",&numero);

    return numero;
}

void mostrarMensaje(char mensaje[])
{
    puts(mensaje);
    system("pause");//system("pause") le permitirá al usuario leer los errores hasta que pulse una tecla
}





