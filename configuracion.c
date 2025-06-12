#include "configuracion.h"
#include "dibujos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int leer_archivo(t_parametria* param)
{
    FILE* archConfiguracion = fopen("buscaminas.conf", "rt");
    if(!archConfiguracion)
        return ERROR_ARCH;

    char linea[100];
    while (fgets(linea, sizeof(linea), archConfiguracion))
    {
        sscanf(linea, "dimension:%d", &param->dimension);
        sscanf(linea, "cantidad de minas:%s", param->cantidad_minas);
    }
    fclose(archConfiguracion);
    return TODO_OK;
}

int es_porcentaje(char* cad)
{
    return strchr(cad, '%') != NULL;
}

int valor_de_las_minas(t_parametria* param)
{
    if(es_porcentaje(param->cantidad_minas))
    {
        int porcentaje;
        sscanf(param->cantidad_minas,"%d",&porcentaje);
        return ((porcentaje*(param->dimension*param->dimension))/100);
    }
    else
        return atoi(param->cantidad_minas);
}
