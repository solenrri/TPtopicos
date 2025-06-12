#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

#define TODO_OK 1
#define ERROR_ARCH  2
#define SIN_MEM 3

typedef struct
{
    int dimension;
    char cantidad_minas[4];
}t_parametria;

int leer_archivo(t_parametria* param);
int es_porcentaje(char* cad);
int valor_de_las_minas(t_parametria* param);


#endif // CONFIGURACION_H_INCLUDED
