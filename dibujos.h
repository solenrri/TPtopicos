#ifndef DIBUJOS_H_INCLUDED
#define DIBUJOS_H_INCLUDED
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#define TAM_PIXEL 5
#define PIXELES_X_LADO 8
#define TAM_GRILLA 8
#define PX_PADDING 4
#define DIM 8
#define MINA -1
#define VACIA 0

#define G 0 // Gris
#define C 1 // Claro
#define B 2 // Blanco
#define V 3 // Verde
#define R 4 // Rojo
#define N 5 //Negro

typedef struct
{
    bool conMina;
    bool sinMina;
    bool conBandera;
    int minasCercanas;

}celda;

void dibujar(SDL_Window *ventana, SDL_Renderer *renderer, const int[][PIXELES_X_LADO], int oX, int oY);
void dibujarCampo(SDL_Window *ventana, SDL_Renderer *renderer, const int[][PIXELES_X_LADO]);
void dibujarSegunCorresponda(SDL_Window *ventana, SDL_Renderer *renderer, int x, int y);
void borrarPantalla(SDL_Window *ventana, SDL_Renderer *renderer);
void  inicializar_matriz(int matriz[DIM][DIM]);
void colocarMinas(int mat[DIM][DIM]);
void mostrar_matriz(int mat[DIM][DIM]);

#endif // DIBUJOS_H_INCLUDED
