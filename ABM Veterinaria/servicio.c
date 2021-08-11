#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int listarServicios(eServicio servicios[],int tam)
{
    int retorno=-1;

    if(servicios!=NULL&&tam>0)
    {
        printf("  ID        SERVICIO PRECIO\n");
        for(int i=0;i<tam;i++)
        {
            mostrarServicio(servicios[i]);
            retorno=0;
        }
    }

    return retorno;
}

void mostrarServicio(eServicio servico)
{
    printf(" %d %13s %.2f\n",servico.id,servico.desc,servico.precio);
}

int validarServicio(eServicio servicios[],int tamS,int id)
{

    int retorno=-1;

    if(servicios!=NULL&&tamS>0)
    {
        if(id>19999&&id<20003)//ids de servicio esetan entre 20000 y 20002
        {
            retorno=0;
        }
    }

    return retorno;

}

int cargarDescServicio(char str[],eServicio servicos[],int tam,int id)
{
    int retorno=-1;

    if(servicos!=NULL&&tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            if(servicos[i].id==id)
            {
                strcpy(str,servicos[i].desc);
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}

int getIdServicio(eServicio servicios[],int tam)
{
    int id;

    listarServicios(servicios,tam);
    printf("_______________________________\n");
    id=getInt("Ingrese id de servicio:","Ingrese id de servicio valido:");
    while(validarServicio(servicios,tam,id)==-1)
    {
        id=getInt("Ingrese id de servicio valido:","Ingrese id de servicio valido:");
    }

    return id;
}
