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

typedef struct
{
    char dimension[6];
    float cantidad_minas;
}parametria;

void dibujar(SDL_Window *ventana, SDL_Renderer *renderer, const int[][PIXELES_X_LADO], int oX, int oY);
void dibujarCampo(SDL_Window *ventana, SDL_Renderer *renderer, const int[][PIXELES_X_LADO]);
void dibujarSegunCorresponda(SDL_Window *ventana, SDL_Renderer *renderer, int x, int y);
void borrarPantalla(SDL_Window *ventana, SDL_Renderer *renderer);
void inicializar_matriz(t_celda matriz[DIM][DIM]);
void colocarMinas(t_celda mat[DIM][DIM]);
void mostrar_matriz_minas(t_celda mat[DIM][DIM]);
void mostrar_matriz_minas_ady(t_celda mat[DIM][DIM]);
void crearArchivo();
void revelarCeldas(t_celda mat[DIM][DIM], int filaSeleccionada, int columnaSeleccionada,SDL_Window* ventana, SDL_Renderer*renderer);
SDL_Texture* SDL_CargarImagenes(SDL_Renderer *renderer, const char* rutaArchivo);



#endif // DIBUJOS_H_INCLUDED
