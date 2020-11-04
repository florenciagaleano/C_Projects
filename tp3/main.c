#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    /*ACORDARME DE BORRAR LO DE PROXID CUANDO LO ENTREGUE*/

    int option=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        option=menu();

        switch(option)
        {
            case 1:
                if(!controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("\nEmpleados cargados exitosamente!\n\n");
                }else
                {
                    printf("\nProblemas para cargar los empleados\n\n");
                }
                break;
            case 2:
                if(!controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf("\nEmpleados cargados exitosamente!\n\n");
                    //imprimirEmpleados(listaEmpleados);
                }else
                {
                    printf("\nProblemas para cargar los empleados\n\n");
                }
                break;
            case 3:
                if(!controller_addEmployee(listaEmpleados))
                {
                    printf("\nAlta exitosa!!!\n\n");
                }else
                {
                    printf("\nProblemas para dar de alta\n\n");
                }
                break;
            case 4:
                switch(controller_editEmployee(listaEmpleados))
                {
                case -1:
                    printf("\nProblemas para modificar\n\n");
                    break;
                case 0:
                    printf("\nModificacion exitosa!\n\n");
                    break;
                case 1:
                    printf("\nOperacion cancelada\n\n");
                    break;
                }
                break;
            case 5:
                switch(controller_removeEmployee(listaEmpleados))
                {
                case -1:
                    printf("\nProblemas para dar de baja\n\n");
                    break;
                case 0:
                    printf("\nBaja exitosa!\n\n");
                    break;
                case 1:
                    printf("\nOperacion cancelada\n\n");
                    break;
                }
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                if(!controller_saveAsText("data.csv",listaEmpleados))
                {
                    printf("\nEmpleados guardados exitosamente\n\n");
                }else
                {
                    printf("\nProblemas para guardar a los empleados\n\n");
                }
                break;
            case 9:
                if(!controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    printf("\nEmpleados guardados exitosamente\n\n");
                }else
                {
                    printf("\nNo se pudieron cagar los empleados\n\n");
                }
                break;
        }

        system("pause");

    }while(option != 10);

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}

