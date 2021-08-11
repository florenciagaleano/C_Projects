#include "informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int informar(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT,eTrabajo trabajos[],int tamTrabajos,eServicio servicios[],int tamS)
{
    int retorno=-1;
    int opcion;

    if(mascotas!=NULL&&tamMas>0&&colores!=NULL&&tamC>0&&tipos!=NULL&&tamT>0&&trabajos!=NULL&&tamT>0&&servicios!=NULL&&tamS>0)
    {
        do
        {
            opcion=menuInformes();
            switch(opcion)
            {
            case 'a':
                listarMascotasXUnColor(mascotas,tamMas,colores,tamC,tipos,tamT);
                printf("\n\n");
                system("pause");
                break;
            case 'b':
                listarMascotasXUnTipo(mascotas,tamMas,colores,tamC,tipos,tamT);
                printf("\n\n");
                system("pause");
                break;
            case 'c':
                informarMascotaMasJoven(mascotas,tamMas,colores,tamC,tipos,tamT);
                system("pause");
                break;
            case 'd':
                listarMascotasXTipo(mascotas,tamMas,colores,tamC,tipos,tamT);
                printf("\n\n");
                system("pause");
                break;
            case 'e':
                contarMascotasXUnColorYTipo(mascotas,tamMas,colores,tamC,tipos,tamT);
                system("pause");
                break;
            case 'f':
                informarColorFavorito(mascotas,tamMas,colores,tamC);
                printf("\n\n");
                system("pause");
                break;
            case 'g':
                mostrarTrabajosXUnaMascota(trabajos,tamTrabajos,servicios,tamS,mascotas,tamMas,colores,tamC,tipos,tamT);
                printf("\n\n");
                system("pause");
                break;
            case 'h':
                mostrarGananciaXUnaMascota(trabajos,tamTrabajos,servicios,tamS,mascotas,tamMas,colores,tamC,tipos,tamT);
                system("pause");
                break;
            case 'i':
                mostrarFechaYMascotaXServicio(trabajos,tamTrabajos,servicios,tamS,mascotas,tamMas,colores,tamC,tipos,tamT);
                printf("\n\n");
                system("pause");
                break;
            case 'j':
                mostrarServiciosXFecha(trabajos,tamTrabajos,servicios,tamS);
                printf("\n\n");
                system("pause");
                break;
            case 'k':
                break;
            default:
                printf("Opcion no valida\n");
                break;
            }

            printf("\n\n");

        }while(opcion!='k');//k es la opcion para salir

        retorno=0;
    }

    return retorno;
}

char menuInformes()
{
    char opcion;

    system("cls");
    printf("   ***MENU INFORMES***\n\n");
    printf("a.Listar mascotas de un color\n");
    printf("b.Listar mascotas de un tipo\n");
    printf("c.Mostrar mascota(s) mas joven(es)\n");
    printf("d.Listar mascotas por tipo\n");
    printf("e.Contar mascotas de un color y un tipo\n");
    printf("f.Informar color mas comun\n");
    printf("g.Mostrar trabajos de una mascota\n");
    printf("h.Mostrar suma de importes por una mascota\n");
    printf("i.Informar mascotas por servicio\n");
    printf("j.Mostrar servicios por fecha\n");
    printf("k.Salir\n");
    printf("___________________________________________\n");
    opcion=getChar("Elija una opcion:","Ingrese una opcion valida:");

    return opcion;
}

int listarMascotasXUnColor(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT)
{
    int retorno=-1;
    int bufferId;
    int flag=0;//si la flag queda en 0 es pq no hay ninguna mascota de este color

    if(mascotas!=NULL&&tamMas>0&&colores!=NULL&&tamC>0&&tipos!=NULL&&tamT>0)
    {
        system("cls");
        printf("   MASCOTAS DE UN COLOR\n\n");
        bufferId=getIdColor(colores,tamC);

        printf("\n ID     NOMBRE      COLOR       TIPO  EDAD\n");
        for(int i=0;i<tamMas;i++)
        {
            if(mascotas[i].idColor==bufferId&&mascotas[i].isEmpty==0)
            {
                mostrarMascota(mascotas[i],colores,tamC,tipos,tamT);
                flag=1;
            }
        }

        if(!flag)
        {
            printf("No hay mascotas de este color\n");
        }

        retorno=0;

    }

    return retorno;
}

int listarMascotasXUnTipo(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT)
{
    int retorno=-1;
    int bufferId;
    int flag=0;//si la flag queda en 0 es pq no hay ninguna mascota de este tipo

    if(mascotas!=NULL&&tamMas>0&&colores!=NULL&&tamC>0&&tipos!=NULL&&tamT>0)
    {
        system("cls");
        printf("   MASCOTAS DE UN TIPO\n\n");
        bufferId=getIdTipo(tipos,tamT);
        printf("\n ID     NOMBRE      COLOR       TIPO  EDAD\n");
        for(int i=0;i<tamMas;i++)
        {
            if(mascotas[i].idTipo==bufferId&&mascotas[i].isEmpty==0)
            {
                mostrarMascota(mascotas[i],colores,tamC,tipos,tamT);
                flag=1;
            }
        }

        if(!flag)
        {
            printf("No hay mascotas de este tipo\n");
        }

        retorno=0;

    }

    return retorno;
}

int listarMascotasXTipo(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT)
{
    int retorno=-1;
    int flag;//la flag se levanta si hay alguna mascota del tipo se muestra

    if(mascotas!=NULL&&tamMas>0&&colores!=NULL&&tamC>0&&tipos!=NULL&&tamT>0)
    {
        system("cls");
        printf("  LISTADO DE MASCOTAS POR TIPO\n\n");
        for(int t=0;t<tamT;t++)
        {
            flag=0;//incializo la flag en 0 por cada tipo
            printf("\nTipo:%s\n",tipos[t].desc);
            for(int m=0;m<tamMas;m++)
            {
                if(mascotas[m].idTipo==tipos[t].id&&mascotas[m].isEmpty==0)
                {
                    mostrarMascota(mascotas[m],colores,tamC,tipos,tamT);
                    flag=1;
                }
            }

            if(!flag)
            {
                printf("No hay mascotas de este tipo\n");
            }
        }
    }

    return retorno;
}

int informarColorFavorito(eMascota mascotas[],int tamMas,eColor colores[],int tamC)
{
    int retorno=-1;
    int contador[tamC];
    int colorFavorito;

    if(mascotas!=NULL&&tamMas>0&&colores!=NULL&&tamC>0)
    {
        system("cls");
        printf("    COLOR MAS COMUN\n\n");

        for(int c=0;c<tamC;c++)
        {
            contador[c]=0;
            for(int m=0;m<tamMas;m++)
            {
                if(mascotas[m].idColor==colores[c].id&&mascotas[m].isEmpty==0)
                {
                    contador[c]++;
                }
            }
        }

        for(int c=0;c<tamC;c++)
        {
            if(c==0||contador[c]>colorFavorito)
            {
                colorFavorito=contador[c];
            }
        }

        printf("Color(es) favorito(s):\n");

        for(int c=0;c<tamC;c++)
        {
            if(contador[c]==colorFavorito)
            {
                printf("-%s\n",colores[c].desc);
            }
        }

        retorno=0;
    }

    return retorno;
}

int informarMascotaMasJoven(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT)
{
    int retorno=-1;
    int minimoEdad;//en esta var guardo el minimo de edad

    if(mascotas!=NULL&&tamMas>0&&colores!=NULL&&tamC>0&&tipos!=NULL&&tamT>0)
    {
        system("cls");
        printf("   MASCOTA(S) MAS JOVEN(ES)\n\n");
        for(int i=0;i<tamMas;i++)
        {
            if((i==0||mascotas[i].edad<minimoEdad)&&mascotas[i].isEmpty==0)
            {
                minimoEdad=mascotas[i].edad;
            }
        }

        printf("Mascota(s) mas joven(es):\n\n");

        for(int i=0;i<tamMas;i++)
        {
            if((mascotas[i].edad==minimoEdad)&&mascotas[i].isEmpty==0)
            {
                mostrarMascota(mascotas[i],colores,tamC,tipos,tamT);
                retorno=0;
            }
        }
    }

    return retorno;
}

int contarMascotasXUnColorYTipo(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT)
{
    int retorno=-1;
    int bufferColor;
    int bufferTipo;
    int contador=0;

    if(mascotas!=NULL&&tamMas>0&&colores!=NULL&&tamC>0&&tipos!=NULL&&tamT>0)
    {
        system("cls");
        printf("   CONTAR MASCOTAS DE UN COLOR Y TIPO\n\n");
        bufferColor=getIdColor(colores,tamC);//pido y valido id color
        bufferTipo=getIdTipo(tipos,tamT);//pido y valido id de tipo
        for(int i=0;i<tamMas;i++)
        {
            if(mascotas[i].idColor==bufferColor&&mascotas[i].idTipo==bufferTipo&&mascotas[i].isEmpty==0)
            {
                contador++;
            }
        }

        if(!contador)
        {
            printf("\nNo hay mascotas de ese tipo y color\n\n");
        }else if(contador==1)
        {
            printf("\nHay una mascota con ese color y tipo\n\n");
        }else
        {
            printf("\nCantidad de mascotas de este color y tipo:%d\n\n",contador);
        }
    }

    return retorno;
}

int mostrarTrabajosXUnaMascota(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamS,eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT)
{
    int retorno=-1;
    int bufferId;
    int flag=0;

    if(trabajos!=NULL&&tamTra>0&&servicios!=NULL&&tamS>0&&mascotas!=NULL&&tamMas>0)
    {
        system("cls");
        printf("   LISTAR TRABAJOS DE UNA MASCOTA\n\n");
        bufferId=getIdMascota(mascotas,tamMas,colores,tamC,tipos,tamT);

        printf("\n\n");
        printf(" ID      MASCOTA MASCOTA(ID)  SERVICIO   FECHA\n");
        for(int i=0;i<tamMas;i++)
        {
            if(trabajos[i].idMascota==bufferId&&trabajos[i].isEmpty==0)
            {
                mostrarTrabajo(trabajos[i],servicios,tamS,mascotas,tamMas);
                flag=1;
            }
        }

        if(!flag)
        {
            printf("No se realizo ningun trabajo con esta mascota\n\n");
        }

        retorno=0;
    }

    return retorno;
}

int mostrarGananciaXUnaMascota(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamS,eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT)
{
    int retorno=-1;
    int bufferId;
    float acumulador=0;//acumula las ganancias x trabajo
    int flag=0;

    if(trabajos!=NULL&&tamTra>0&&servicios!=NULL&&tamS>0&&mascotas!=NULL&&tamMas>0)
    {
        system("cls");
        printf("   LISTAR GANANCIAS POR UNA MASCOTA\n\n");
        bufferId=getIdMascota(mascotas,tamMas,colores,tamC,tipos,tamT);

        for(int i=0;i<tamMas;i++)
        {
            if(trabajos[i].idMascota==bufferId&&trabajos[i].isEmpty==0)
            {
                flag=1;
                for(int j=0;j<tamS;j++)//recorro array de servicios
                {
                    if(trabajos[i].idServicio==servicios[j].id)
                    {
                        acumulador+=servicios[j].precio;
                    }
                }//for j
            }//fin if trabajos y mascota
        }//fin for mascotas

        if(!flag)
        {
            printf("\nNo se obtuvo ninguna ganancia con esta mascota\n\n");
        }else
        {
            printf("\nSuma de importes:%.2f\n\n",acumulador);
        }
    }

    return retorno;
}

int mostrarFechaYMascotaXServicio(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamS,eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT)
{
    int retorno=-1;
    int bufferServicio;
    int flag=0;

    if(trabajos!=NULL&&tamTra>0&&servicios!=NULL&&tamS>0&&mascotas!=NULL&&tamMas>0)
    {
        system("cls");
        printf("   INFORMAR POR UN SERVICIO\n\n");
        bufferServicio=getIdServicio(servicios,tamS);

        for(int i=0;i<tamTra;i++)
        {
            if(trabajos[i].idServicio==bufferServicio&&trabajos[i].isEmpty==0)//recorro los trabajos pq ahi van a estar las mascotas que usaron un servicio
            {
                printf("\n\n");
                mostrarMascota(mascotas[buscarMascotaXId(mascotas,tamMas,trabajos[i].idMascota)],colores,tamC,tipos,tamT);
                printf("\nFecha:%02d/%02d/%d",trabajos[i].fecha.dia,trabajos[i].fecha.mes,trabajos[i].fecha.anio);
                printf("\n_____________________________________________\n");
                flag=1;
            }
        }

        if(!flag)
        {
            printf("No hay trabajos que hayan requerido este servicio\n\n");
        }

        retorno=0;
    }


    return retorno;
}

int mostrarServiciosXFecha(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamS)
{
    int retorno=-1;
    eFecha fecha;
    char bufferServicio[25];//aca se guarda la dessc del servicio
    int flag=0;

    if(trabajos!=NULL&&tamTra>0&&servicios!=NULL&&tamS>0)
    {
        system("cls");
        printf("   MOSTRAR SERVICIOS(S) POR FECHA\n\n");

        fecha.dia=getInt("-DIA.Ingrese dia:","Ingrese dia valido:");
        while(fecha.dia<1||fecha.dia>31)//valido el ida
        {
            fecha.dia=getInt("Ingrese dia valido:","Ingrese dia valido:");
        }
        fecha.mes=getInt("-MES.Ingrese mes:","Ingrese mes valido:");
        while(fecha.mes<1||fecha.mes>12)//valido el mes
        {
            fecha.mes=getInt("Ingrese mes valido:","Ingrese mes valido:");
        }
        fecha.anio=getInt("-ANIO.Ingrese anio:","Ingrese anio valido:");
        while(fecha.anio<1980||fecha.anio>2020)//anio puede ser despues de 1980 hasta 2020
        {
            fecha.anio=getInt("Ingrese anio valido:","Ingrese anio valido:");
        }

        printf("\n\nServicio(s) realizado(s) en esa fecha:\n");
        for(int i=0;i<tamTra;i++)
        {
            if(trabajos[i].fecha.dia==fecha.dia&&trabajos[i].fecha.mes==fecha.mes&&trabajos[i].fecha.anio==fecha.anio&&trabajos[i].isEmpty==0)
            {
                cargarDescServicio(bufferServicio,servicios,tamS,trabajos[i].idServicio);
                printf("-%s\n",bufferServicio);
                flag=1;
            }
        }

        if(!flag)
        {
            printf("No hay trabajos cargados ese dia\n");
        }

        retorno=0;
    }

    return retorno;
}
