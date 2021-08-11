#include "mascota.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializarMascotas(eMascota mascotas[],int tamMas)
{
    int retorno=-1;

    if(mascotas!=NULL&&tamMas>0)
    {
        for(int i=0; i<tamMas; i++)
        {
            mascotas[i].isEmpty=1;//pongo todos los isEmmpty en 1
        }
        retorno=0;
    }

    return retorno;
}

int buscarLibreMascota(eMascota mascotas[],int tamMas)
{
    int retorno=-1;

    if(mascotas!=NULL&&tamMas>0)
    {
        for(int i=0; i<tamMas; i++)
        {
            if(mascotas[i].isEmpty==1)
            {
                retorno=i;
                break;//salgo del bucle si encontre unlugar libre
            }
        }
    }

    return retorno;
}

int altaMascota(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT,int proxId)
{
    int retorno=-1;
    int indice;//indice del lugar libre
    eMascota nuevaMascota;

    system("cls");
    printf("   ***ALTAS***\n");

    if(mascotas!=NULL&&tamMas>0&&colores!=NULL&&tamC>0&&tipos!=NULL&&tamT>0)
    {
        indice=buscarLibreMascota(mascotas,tamMas);
        if(indice!=-1)//si el indice es -1 ya no hay mas lugar
        {
            nuevaMascota.id=proxId;
            getString(nuevaMascota.nombre,sizeof(nuevaMascota.nombre),"\nIngrese nombre de la mascota:","Ingrese nombre valido:");
            printf("\n");
            nuevaMascota.idColor=getIdColor(colores,tamC);
            nuevaMascota.idTipo=getIdTipo(tipos,tamT);
            nuevaMascota.edad=getInt("\nIngrese edad de la mascota:","Ingrese edad valida:");

            nuevaMascota.isEmpty=0;//el isEmpty lo pongo como falso
            mascotas[indice]=nuevaMascota;//cargo el nuevo elemento en el array

            retorno=0;//retorno 0 xq salio todo bien
        }
    }

    return retorno;
}

int buscarMascotaXId(eMascota mascotas[],int tamMas,int id)
{
    int retorno=-1;

    if(mascotas!=NULL&&tamMas>0)
    {
        for(int i=0; i<tamMas; i++)
        {
            if(mascotas[i].id==id&&mascotas[i].isEmpty==0)//me fijo que sea ese el id y que no este dado de baja
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int listarMascotas(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT)
{
    int retorno=-1;

    if(mascotas!=NULL&&tamMas>0&&colores!=NULL&&tamC>0&&tipos!=NULL&&tamT>0)
    {
        printf(" ID     NOMBRE      COLOR       TIPO  EDAD\n");
        ordenarMascotas(mascotas,tamMas,tipos,tamT);//ordeno las mascotas antes de mostrarlas
        for(int i=0; i<tamMas; i++)
        {
            if(mascotas[i].isEmpty==0)//me fijo que ningun elemento este dado de baja
            {
                mostrarMascota(mascotas[i],colores,tamC,tipos,tamT);
            }
        }

        retorno=0;
    }

    return retorno;
}

void mostrarMascota(eMascota mascota,eColor colores[],int tamC,eTipo tipos[],int tamT)
{
    char color[20];
    char tipo[20];

    cargarDescColor(color,colores,tamC,mascota.idColor);//cargo el nombre del color
    cargarDescTipo(tipo,tipos,tamT,mascota.idTipo);//cargo el nombre del tipo
    printf(" %02d %10s %10s %10s   %2d\n",mascota.id,mascota.nombre,color,tipo,mascota.edad);
}

int modificarMascota(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT)
{
    int retorno=-1;
    int bufferId;//guardo el id del elemento a modifica
    int indice;
    char confirma;//el usuario debe confirma la modificacion

    if(mascotas!=NULL&&tamMas>0&&colores!=NULL&&tamC>0&&tipos!=NULL&&tamT>0)
    {
        system("cls");//limpio la pantalla
        printf("   ***MODIFICACIONES***\n\n");
        listarMascotas(mascotas,tamMas,colores,tamC,tipos,tamT);
        printf("______________________________________________\n");
        bufferId=getInt("Ingrese el id:","Ingrese id valido:");
        indice=buscarMascotaXId(mascotas,tamMas,bufferId);
        if(indice!=-1)
        {
            mostrarMascota(mascotas[indice],colores,tamC,tipos,tamT);//musetro el elemtno que eligio el usuario
            confirma=getCharTwoOptions("\nEs esta la mascota que desea modificar?","Ingrese s o n:",'s','n');//confirmo que sea ese el elemetno
            if(confirma=='s')
            {
                switch(menuModificar())
                {
                case 'a':
                    mascotas[indice].idTipo=getIdTipo(tipos,tamT);
                    break;
                case 'b':
                    mascotas[indice].edad=getInt("Ingrese edad de la mascota:","Ingrese edad valida:");
                    break;
                default:
                    printf("Opcion no valida\n");
                    break;
                }

                retorno=0;
            }else
            {
                retorno=1;//si no confirmo
            }


        }

    }

    return retorno;
}

char menuModificar()
{
    char opcion;

    system("cls");
    printf("***MENU MODIFICACIONES***\n\n");

    printf("a.Modificar tipo\n");
    printf("b.Modificar edad\n");
    printf("_____________________________\n");

    opcion=getChar("Elija una opcion:","Elija una opcion valida:");

    return opcion;
}

int bajaMascota(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT)
{
    int retorno=-1;
    int bufferId;//guardo el id del elemento a modificar
    int indice;
    char confirma;//confirmo que ese sea el elemtno a dar de baja

    if(mascotas!=NULL&&tamMas>0&&colores!=NULL&&tamC>0&&tipos!=NULL&&tamT>0)
    {
        system("cls");
        printf("   ***BAJAS***\n\n");
        listarMascotas(mascotas,tamMas,colores,tamC,tipos,tamT);
        printf("______________________________________________\n");
        bufferId=getInt("Ingrese el id de la mascota a dar de baja:","Ingrese id valido:");
        indice=buscarMascotaXId(mascotas,tamMas,bufferId);
        if(indice!=-1)
        {
            mostrarMascota(mascotas[indice],colores,tamC,tipos,tamT);//muestro la mascota que se dara de baja
            confirma=getCharTwoOptions("\nEs esta la mascota que desea dar de baja?","Ingrese s o n:",'s','n');
            if(confirma=='s')
            {
                mascotas[indice].isEmpty=1;//pongo el isEmpty de ese elemento en true
                retorno=0;

            }
            else
            {
                retorno=1;//si no confirmo
            }
        }

    }

    return retorno;
}

int ordenarMascotas(eMascota mascotas[],int tamMas,eTipo tipos[],int tamT)
{
    int retorno=-1;
    char tipoI[20];//aca se cargaran las desc del for con I
    char tipoJ[20];//aca se cargaran las desec del for con J
    eMascota aux;//aux para el swappeo

    if(mascotas!=NULL&&tamMas>0&&tipos!=NULL&&tamT>0)
    {
        for(int i=0;i<tamMas-1;i++)
        {
            for(int j=i+1;j<tamMas;j++)
            {
                if(mascotas[i].isEmpty==0&&mascotas[j].isEmpty==0)//chequeo que ambos elementos sean activos
                {
                    cargarDescTipo(tipoI,tipos,tamT,mascotas[i].idTipo);//cargo desc i
                    cargarDescTipo(tipoJ,tipos,tamT,mascotas[j].idTipo);//cargo desc j
                    if(stricmp(tipoI,tipoJ)>0)
                    {
                        aux=mascotas[i];
                        mascotas[i]=mascotas[j];
                        mascotas[j]=aux;
                    }else if(stricmp(tipoI,tipoJ)==0&&stricmp(mascotas[i].nombre,mascotas[j].nombre)>0)
                    {
                        aux=mascotas[i];
                        mascotas[i]=mascotas[j];
                        mascotas[j]=aux;
                    }
                }//fin if isEmpty
            }//fin if j
        }//fin if i

        retorno=0;
    }

    return retorno;
}

int getIdMascota(eMascota mascotas[],int tam,eColor colores[],int tamC,eTipo tipos[],int tamTip)
{
    int id;

    listarMascotas(mascotas,tam,colores,tamC,tipos,tamTip);
    printf("____________________________________________\n");
    id=getInt("Elija una mascota(id):","Ingrese id de mascota valido:");
    while(buscarMascotaXId(mascotas,tam,id)==-1)
    {
        id=getInt("Ingrese id de mascota valido:","Ingrese id de mascota valido:");
    }
    printf("\n");

    return id;
}
