#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "menu.h"

int menu()
{
    int opcion;

    system("cls");
    printf("   ***ABM ESTUDIANTES***\n\n");
    printf("1.Cargar archivo de texto\n");
    printf("2.Alta estudiante\n");
    printf("3.Modificar estudiante\n");
    printf("4.Baja estudiante\n");
    printf("5.Ordenar estudiantes\n");
    printf("6.Mostrar estudiantes\n");
    printf("7.Insertar estudiante\n");
    printf("8.Vaciar la lista\n");//ll_clar
    printf("9.Crear archivo y lista de seguridad\n");//ll_clone y ll_conatinsAll
    printf("10.Guardar archivo en modo texto\n");
    printf("________________________________\n");

    getInt(&opcion,"Ingrese una opcion:","Ingrese una opcion valida:");

    return opcion;
}

char menuModificar()
{
    char opcion;

    system("cls");
    printf("   ***MENU MODIFICACIONES***\n\n");
    printf("a.Modificar nombre\n");
    printf("b.Modificar sexo\n");
    printf("c.Modificar promedio\n");
    printf("d.Salir\n");
    printf("____________________________\n");

    getChar(&opcion,"Elija una opcion:","Elija una opcion valida:");

    return opcion;
}

char menuOrdenar()
{
    char opcion;

    printf("   ***MENU ORDEN***\n\n");
    printf("a.Ordenar por id\n");
    printf("b.Ordenar por nombre\n");
    printf("c.Ordenar por sexo\n");
    printf("d.Ordenar por promedio\n");
    printf("______________________\n");

    getChar(&opcion,"Elija una opcion:","Elija una opcion valida:");

    return opcion;
}
