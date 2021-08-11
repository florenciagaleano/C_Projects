#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "dataStore.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#include "servicio.h"
#include "trabajo.h"
#include "informes.h"

#define TAM_TIPO 5
#define TAM_COLOR 5
#define TAM_MASC 100
#define TAM_SERV 3
#define TAM_HARDCODEMASC 10
#define TAM_TRABAJO 150
#define TAM_HARDCODETRAB 6

/** \brief muestra un menu de opciones y le pide al usuario que elija una
 *
 * \return la opcion elegida
 *
 */
int menu();

/** \brief hardcodea al array de mascotas
 *
 * \param array a hardcodear
 * \param tamanio del array
 * \return 0 si salio tod bien si no -1
 *
 */
int hardcodearMascotas(eMascota mascotas[],int tam);

/** \brief hardcodea al array de trabajos
 *
 * \param array a hardcodear
 * \param tamanio del array
 * \return 0 si salio tod bien si no -1
 *
 */
int hardcodearTrabajos(eTrabajo trabajos[],int tamTra);

int main()
{
     char confirma='n';
     int proxIdMascota=1;//ids de mascota empiezan en 1
     int proxIdTrabajo=500;//ids de trabajo empiezan en 500
     int flag=1;//flag esta en 1 por el hardcodeo
     eMascota mascotas[TAM_MASC];
     eTrabajo trabajos[TAM_TRABAJO];
     eTipo tipos[TAM_TIPO]={
                            {1000,"Ave"},
                            {1001,"Perro"},
                            {1002,"Gato"},
                            {1003,"Roedor"},
                            {1004,"Pez"}
                            };
    eColor colores[TAM_COLOR]={
                                {5000,"Negro"},
                                {5001,"Blanco"},
                                {5002,"Gris"},
                                {5003,"Rojo"},
                                {5004,"Azul"}
                                };
    eServicio servicios[TAM_SERV]={
                                    {20000,"Corte",250},
                                    {20001,"Desparasitado",300},
                                    {20002,"Castrado",400}
                                    };

    inicializarMascotas(mascotas,TAM_MASC);
    inicializarTrabajos(trabajos,TAM_TRABAJO);
    hardcodearMascotas(mascotas,TAM_HARDCODEMASC);
    hardcodearTrabajos(trabajos,TAM_HARDCODETRAB);
    proxIdMascota+=TAM_HARDCODEMASC;//para que se pueden hacer altas y no se repita id
    proxIdTrabajo+=TAM_HARDCODETRAB;//para que se pueden hacer altas y no se repita id

    do
    {
        switch(menu())
        {
        case 1:
            if(!altaMascota(mascotas,TAM_MASC,colores,TAM_COLOR,tipos,TAM_TIPO,proxIdMascota))
            {
                printf("\nAlta exitosa!\nEl id de esta mascota es:%d\n\n",proxIdMascota);
                proxIdMascota++;
                flag=1;//el flag de altas lo pongo en true

            }else
            {
                printf("Sistema completo\n\n");
            }
            break;
        case 2:
           if(flag)
            {
                switch(modificarMascota(mascotas,TAM_MASC,colores,TAM_COLOR,tipos,TAM_TIPO))
                {
                case -1:
                    printf("\nNo se encontro ese id de mascota\n");
                    break;
                case 0:
                    printf("\nModificacion exitosa!\n");
                    break;
                case 1:
                    printf("\nOperacion cancelada\n");
                    break;
                }
            }else
            {
                printf("Primero debe cargar una mascota\n");
            }
            break;
        case 3:
            if(flag)
            {
                switch(bajaMascota(mascotas,TAM_MASC,colores,TAM_COLOR,tipos,TAM_TIPO))
                {
                case -1:
                    printf("\nNo se encontro ese id de mascota\n\n");
                    break;
                case 0:
                    printf("\nBaja exitosa!\n\n");
                    break;
                case 1:
                    printf("\nOperacion cancelada\n\n");
                    break;
                }
            }else
            {
                printf("Primero debe cargar una mascota\n");
            }
            break;
        case 4:
            if(flag)
            {
                system("cls");
                printf("   ***MASCOTAS***\n\n");
                listarMascotas(mascotas,TAM_MASC,colores,TAM_COLOR,tipos,TAM_TIPO);
            }else
            {
                printf("\nPrimero debe cargar una mascota\n");
            }
            break;
        case 5:
            system("cls");
            printf("   ***TIPOS***\n\n");
            listarTipos(tipos,TAM_TIPO);
            break;
        case 6:
            system("cls");
            printf("   ***COLORES***\n\n");
            listarColores(colores,TAM_COLOR);
            break;
        case 7:
            system("cls");
            printf("   ***SERVICIOS***\n\n");
            listarServicios(servicios,TAM_SERV);
            break;
        case 8:
            if(!altaTrabajo(trabajos,TAM_TRABAJO,servicios,TAM_SERV,mascotas,TAM_MASC,colores,TAM_COLOR,tipos,TAM_TIPO,proxIdTrabajo))
            {
                printf("\nAlta exitosa!\nEl id de este trabajo es:%d\n",proxIdTrabajo);
                proxIdTrabajo++;
            }else
            {
                printf("\nNo se pueden cargar mas trabajos\n");
            }
            break;
        case 9:
            system("cls");
            printf("   ***TRABAJOS***\n\n");
            listarTrabajos(trabajos,TAM_TRABAJO,servicios,TAM_SERV,mascotas,TAM_MASC);
            break;
        case 10:
            informar(mascotas,TAM_MASC,colores,TAM_COLOR,tipos,TAM_TIPO,trabajos,TAM_TRABAJO,servicios,TAM_SERV);
            break;
        case 11:
            confirma=getCharTwoOptions("\nEsta seguro de que desea salir?","Ingrese s o n:",'s','n');
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }

        system("pause");//pauso la pantalla

    }while(confirma!='s');//mientras el usurio no confirme salir

    return 0;
}

int menu()
{
    int opcion;

    system("cls");//limpio la pantalla
    printf("   ***ABM MASCOTAS***\n\n");
    printf("1.Alta mascota\n");
    printf("2.Modificar mascota\n");
    printf("3.Baja mascota\n");
    printf("4.Listar mascotas\n");
    printf("5.Listar tipos\n");
    printf("6.Listar colores\n");
    printf("7.Listar servicios\n");
    printf("8.Alta trabajo \n");
    printf("9.Listar trabajos\n");
    printf("10.Informes\n");
    printf("11.Salir\n");
    printf("_______________________________\n");

    opcion=getInt("Elija una opcion:","Elija una opcion valida:\n");

    return opcion;
}

int hardcodearMascotas(eMascota mascotas[],int tam)
{
    int retorno=-1;

    if(mascotas!=NULL&&tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            mascotas[i].id=ids[i];
            strcpy(mascotas[i].nombre,nombres[i]);
            mascotas[i].idColor=idsColor[i];
            mascotas[i].idTipo=idsTipos[i];
            mascotas[i].edad=edades[i];
            mascotas[i].isEmpty=0;//pongo los isEmpty de estas mascotas en false
        }
        retorno=0;
    }

    return retorno;
}

int hardcodearTrabajos(eTrabajo trabajos[],int tamTra)
{
    int retorno=-1;

    if(trabajos!=NULL&&tamTra>0)
    {
        for(int i=0;i<tamTra;i++)
        {
            trabajos[i].id=idsTrabajo[i];
            trabajos[i].idMascota=idsMascota[i];
            trabajos[i].idServicio=idsServicios[i];
            trabajos[i].fecha.dia=dias[i];
            trabajos[i].fecha.mes=meses[i];
            trabajos[i].fecha.anio=anios[i];
            trabajos[i].isEmpty=0;
        }
        retorno=0;
    }

    return retorno;
}
