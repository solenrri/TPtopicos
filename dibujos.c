#include "configuracion.h"
#include "dibujos.h"

int leer_archivo(t_parametria* param)
{
    FILE* archConfiguracion = fopen("buscaminas.conf", "rt");
    if(!archConfiguracion)
        return ERROR_ARCH;

    char linea[100];
    while (fgets(linea, sizeof(linea), archConfiguracion))
    {
        sscanf(linea, "usuario:%s", param->usuario);
        sscanf(linea, "dimension:%d", &param->dimension);
        sscanf(linea, "cantidad de minas:%s", param->cantidad_minas);
    }
    int cant_minas = valor_de_las_minas(param);
    if(param->dimension<8||param->dimension>32)
    {
        puts("El valor de la dimension debe ser mayor a 8 y menor a 32\n");
        fclose(archConfiguracion);
        return ERROR_ARCH;
    }
    if(cant_minas>=(param->dimension)*(param->dimension) ||cant_minas<1)
    {
        printf("La cantidad de minas debe ser mayor a 0 y menor a %d\n", param->dimension*param->dimension);
        fclose(archConfiguracion);
        return ERROR_ARCH;
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

int guardar_configuracion(t_parametria par)
{
    FILE* archConfiguracion = fopen("buscaminas.conf", "wt");
    if(!archConfiguracion)
        return ERROR_ARCH;

    fprintf(archConfiguracion,"usuario:%s\n", par.usuario);
    fprintf(archConfiguracion,"dimension:%d\n", par.dimension);
    fprintf(archConfiguracion,"cantidad de minas:%s", par.cantidad_minas);
    fclose(archConfiguracion);
    return TODO_OK;
}

void obtener_fecha(t_fecha *f)
{
    time_t t = time(NULL);
    struct tm *fecha = localtime(&t);

    f->dia  = fecha->tm_mday;
    f->mes  = fecha->tm_mon + 1;
    f->anio = fecha->tm_year+ 1900;
    f->h    = fecha->tm_hour;
    f->m    = fecha->tm_min;
    f->s    = fecha->tm_sec;
}
