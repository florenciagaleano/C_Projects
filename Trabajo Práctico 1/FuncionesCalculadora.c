#include <stdio.h>
#include <stdlib.h>
#include "funcionesCalculadora.h"
#include "operaciones.h"

int mostrarMenu(int num1,int num2,int flag1,int flag2,int flag3)
{
    int opcion;

    printf("     <<<<< M E N U >>>>>\n\n\n");

    //OPCIÓN 1. Si el usuario ya ingresó el operando "A" este se reemplazaá por el número cargado
    if(flag1)
    {
        printf("1.Ingresar primer operando (A=%d)\n\n",num1);
    }
    else
    {
        printf("1.Ingresar primer operando (A=x)\n\n");
    }

    //OPCIÓN 2. Si el usuario ya ingresó el operando "B" este se reemplazaá por el número cargado
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

void mostrarResultados(int num1,int num2)//Llama a todas las funciones que realizan las operaciones
{
        //SUMA
        printf("a)El resultado de %d+%d es: %d\n",num1,num2,sumar(num1,num2));
        //RESTA
        printf("b)El resultado de %d-%d es: %d\n",num1,num2,restar(num1,num2));
        //IF DE LA DIVISION
        if(num2==0)
        {
            printf("c)No se puede calcular la division si B=0\n");
        }
        else
        {
            printf("c)El resultado de %d / %d es: %.2f\n",num1,num2,dividir(num1,num2));
        }
        //MULTIPLICACION
        printf("d)El resultado de %d * %d es: %d\n",num1,num2,multiplicar(num1,num2));
        //IF DEL FACTORIAL
        if(num1>=0&&num2>=0)
        {
            printf("e)El factorial de %d es %lld y el factorial de %d es %lld\n\n",num1,calcularFactorial(num1),num2,calcularFactorial(num2));
        }else if(num1>=0&&num2<0)
        {
            printf("e)El factorial de %d es %lld y el factorial de %d no se puede calcular\n\n",num1,calcularFactorial(num1),num2);
        }else if(num1<0&&num2>=0)
        {
            printf("e)El factorial de %d no se puede calcular y el factorial de %d es %lld\n\n",num1,num2,calcularFactorial(num2));
        }else
        {
            printf("e)No se puede calcular el factorial de numeros negativos\n\n");
        }

}

void mostrarMensaje(char mensaje[])
{
    puts(mensaje);
    system("pause");//system("pause") le permitirá al usuario leer los errores hasta que pulse una tecla
}





