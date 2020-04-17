#include "operaciones.h"

int sumar(int a,int b)
{
    int suma;
    suma=a+b;
    return suma;
}

int restar(int a, int b)
{
    int resta;
    resta=a-b;
    return resta;
}

int multiplicar(int a,int b)
{
    int multiplicacion;
    multiplicacion=a*b;
    return multiplicacion;
}

float dividir(int a,int b)
{
    float division;
    if(b==0)
    {
        division=0;
    }
    else
    {
        division=(float)a/b;
    }
    return division;
}

long long int calcularFactorial(int numero)
{
    long long int factorial=0;

    if(numero>=0)
    {
        if(numero==0)
        {
            factorial=1;
        }
        else
        {
            factorial=numero*calcularFactorial(numero-1);
        }
    }


    return factorial;

}


