#ifndef DIBUJOS_H_INCLUDED
#define DIBUJOS_H_INCLUDED
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#include "configuracion.h"
#define TAM_PIXEL 4
#define PIXELES_X_LADO 8
#define PX_PADDING 4
#define MINA 1
#define VACIA 0

#define G 0 // Gris
#define C 1 // Claro
#define B 2 // Blanco
#define V 3 // Verde
#define R 4 // Rojo
#define N 5 //Negro
#define A 6 //Azul

typedef struct
{
    bool conMina;
    bool revelada;
    bool conBandera;
    int minasCercanas;

}t_celda;

void dibujar(SDL_Window *ventana, SDL_Renderer *renderer, const int[][PIXELES_X_LADO], int oX, int oY);
void dibujarCampo(SDL_Window *ventana, SDL_Renderer *renderer, const int[][PIXELES_X_LADO], int dimension);
void dibujarSegunCorresponda(SDL_Window *ventana, SDL_Renderer *renderer, int x, int y);
void borrarPantalla(SDL_Window *ventana, SDL_Renderer *renderer);
t_celda **crear_matriz(int dimension);
void inicializar_matriz(t_celda** matriz, int dimension);
void colocarMinas(t_celda** mat,t_parametria *param);
void mostrar_matriz_minas(t_celda** mat, int dimension);
void mostrar_matriz_minas_ady(t_celda** mat, int dimension);
void revelarCeldas(t_celda** mat, int filaSeleccionada, int columnaSeleccionada,SDL_Window* ventana, SDL_Renderer*renderer, int dimension);
void liberar_matriz(t_celda **matriz, int dimension);



#endif // DIBUJOS_H_INCLUDED
