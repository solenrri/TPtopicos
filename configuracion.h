#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TODO_OK 1
#define ERROR_ARCH  2
#define SIN_MEM 3

typedef struct
{
    int dimension;
    char cantidad_minas[4];
}t_parametria;

typedef struct
{
    int dia, mes, anio, h, m, s;
}t_fecha;

int leer_archivo(t_parametria* param);
int es_porcentaje(char* cad);
int valor_de_las_minas(t_parametria* param);
int guardar_configuracion(t_parametria par);
void obtener_fecha(t_fecha *f);


#endif // CONFIGURACION_H_INCLUDED
