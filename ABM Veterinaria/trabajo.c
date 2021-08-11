#include "trabajo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int inicializarTrabajos(eTrabajo trabajos[],int tam)
{
    int retorno=-1;

    if(trabajos!=NULL&&tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            trabajos[i].isEmpty=1;//pongo todos los isEmpty de trabajo en true
            retorno=0;
        }
    }

    return retorno;
}

int buscarLibreTrabajo(eTrabajo trabajos[],int tam)
{
    int retorno=-1;

    if(trabajos!=NULL&&tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            if(trabajos[i].isEmpty==1)//me fijo que el lugar no este ocupado
            {
                retorno=i;
                break;//salgo del bucle si encutnro un lugar vacio
            }
        }
    }

    return retorno;
}

int altaTrabajo(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[],int tamS,eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT,int proxId)
{
    int retorno=-1;
    int indice;
    eTrabajo nuevoTrabajo;

    if(mascotas!=NULL&&tamMas>0&&colores!=NULL&&tamC>0&&tipos!=NULL&&tamT>0&&trabajos!=NULL&&tamT>0&&servicios!=NULL&&tamS>0)
    {
        indice=buscarLibreTrabajo(trabajos,tamTrabajos);
        if(indice!=-1)
        {
            system("cls");
            printf("   ***ALTA TRABAJO***\n\n");
            nuevoTrabajo.id=proxId;
            nuevoTrabajo.idMascota=getIdMascota(mascotas,tamMas,colores,tamC,tipos,tamT);
            nuevoTrabajo.idServicio=getIdServicio(servicios,tamS);
            printf("\nFecha:\n");
            nuevoTrabajo.fecha.dia=getInt("-DIA.Ingrese dia:","Ingrese dia valido:");
            while(nuevoTrabajo.fecha.dia<1||nuevoTrabajo.fecha.dia>31)//valido el ida
            {
                nuevoTrabajo.fecha.dia=getInt("Ingrese dia valido:","Ingrese dia valido:");
            }
            nuevoTrabajo.fecha.mes=getInt("-MES.Ingrese mes:","Ingrese mes valido:");
            while(nuevoTrabajo.fecha.mes<1||nuevoTrabajo.fecha.mes>12)//valido el mes
            {
                nuevoTrabajo.fecha.mes=getInt("Ingrese mes valido:","Ingrese mes valido:");
            }
            nuevoTrabajo.fecha.anio=getInt("-ANIO.Ingrese anio:","Ingrese anio valido:");
            while(nuevoTrabajo.fecha.anio<1980||nuevoTrabajo.fecha.anio>2020)//anio puede ser despues de 1980 hasta 2020
            {
                nuevoTrabajo.fecha.anio=getInt("Ingrese anio valido:","Ingrese anio valido:");
            }

            nuevoTrabajo.isEmpty=0;//pongo el isEmpty del nuevo elemento en false
            trabajos[indice]=nuevoTrabajo;//guardo el nuevo trabajo en el array de trabajos

            retorno=0;
        }
    }

    return retorno;
}

int listarTrabajos(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[],int tamS,eMascota mascotas[],int tamMas)
{
    int retorno=-1;
    int flag=0;

    if(trabajos!=NULL&&tamTrabajos>0&&servicios!=NULL&&tamS>0)
    {
        printf(" ID      MASCOTA MASCOTA(ID)  SERVICIO   FECHA\n");
        for(int i=0;i<tamTrabajos;i++)
        {
            if(trabajos[i].isEmpty==0)
            {
                mostrarTrabajo(trabajos[i],servicios,tamS,mascotas,tamMas);
                flag=1;
            }
        }

        if(!flag)//muestro un mensaje si no habia trabajos cargados
        {
            printf("\nNo hay trabajos que listar\n");
        }
    }

    return retorno;
}

void mostrarTrabajo(eTrabajo trabajo,eServicio servicios[],int tamS,eMascota mascotas[],int tamMas)
{
    char servicio[25];
    char mascota[20];
    int indiceMascota=buscarMascotaXId(mascotas,tamMas,trabajo.idMascota);

    cargarDescServicio(servicio,servicios,tamS,trabajo.idServicio);

    if(indiceMascota!=-1)
    {
        strcpy(mascota,mascotas[indiceMascota].nombre);//muestro el nombre de la mascota
    }else
    {
        strcpy(mascota,"");//si la mascota esta dada de baja muestro una cadena vacia
    }

    printf(" %d %10s %8d %13s %02d/%02d/%d\n",trabajo.id,mascota,trabajo.idMascota,servicio,trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);
}
