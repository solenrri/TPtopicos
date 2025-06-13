#ifndef DIBUJOS_H_INCLUDED
#define DIBUJOS_H_INCLUDED
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#include "configuracion.h"
#define TAM_PIXEL 2
#define PIXELES_X_LADO 8
#define PX_PADDING 4
#define ENCABEZADO  50
#define ANCHO_BOTON_REINICIO 30
#define ALTO_BOTON_REINICIO 30
#define MINA 1
#define VACIA 0

#define G 0 // Gris
#define C 1 // Claro
#define B 2 // Blanco
#define V 3 // Verde
#define R 4 // Rojo
#define N 5 // Negro
#define A 6 // Azul

typedef struct
{
    bool con_mina;
    bool revelada;
    bool con_bandera;
    int  minas_cercanas;

}t_celda;

void dibujar(SDL_Window *ventana, SDL_Renderer *renderer, const int[][PIXELES_X_LADO], int oX, int oY);
void dibujar_campo(SDL_Window *ventana, SDL_Renderer *renderer, const int[][PIXELES_X_LADO], int dimension);
void dibujar_segun_corresponda(SDL_Window *ventana, SDL_Renderer *renderer, int x, int y);
void borrar_pantalla(SDL_Window *ventana, SDL_Renderer *renderer);
t_celda **crear_matriz(int dimension);
void inicializar_matriz(t_celda** matriz, int dimension);
void colocar_minas(t_celda** mat,t_parametria *param);
void mostrar_matriz_minas(t_celda** mat, int dimension);
void mostrar_matriz_minas_ady(t_celda** mat, int dimension);
void revelar_celdas(t_celda** mat, int fila_seleccionada, int columna_seleccionada,SDL_Window* ventana, SDL_Renderer*renderer, int dimension);
void liberar_matriz(t_celda **matriz, int dimension);
int  des_asig_bandera(t_celda **mat, int fila_seleccionada, int columna_seleccionada);
void revelar_cercanas(t_celda **mat, int fila_seleccionada, int columna_seleccionada, SDL_Window* ventana, SDL_Renderer*renderer, int dimension);
void dibujar_encabezado(SDL_Renderer *renderer, int ancho_ventana);


#endif // DIBUJOS_H_INCLUDED
