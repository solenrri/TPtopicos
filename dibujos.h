#ifndef DIBUJOS_H_INCLUDED
#define DIBUJOS_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "configuracion.h"
#define TAM_PIXEL 4
#define PIXELES_X_LADO 8
#define PX_PADDING 4
#define ENCABEZADO  50
#define ANCHO_BOTON_REINICIO 30
#define ALTO_BOTON_REINICIO 30
#define MINA 1
#define VACIA 0
#define MAX_CARAC   30

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
    int minas_cercanas;

}t_celda;

void dibujar(SDL_Window *ventana, SDL_Renderer *renderer, const int[][PIXELES_X_LADO], int oX, int oY);
void dibujar_campo(SDL_Window *ventana, SDL_Renderer *renderer, const int[][PIXELES_X_LADO], int dimension);
void borrar_pantalla(SDL_Window *ventana, SDL_Renderer *renderer);
t_celda **crear_matriz(int dimension);
void inicializar_matriz(t_celda** matriz, int dimension);
void colocar_minas(t_celda** mat,t_parametria *param);
void mostrar_matriz_minas(t_celda** mat, int dimension);
void mostrar_matriz_minas_ady(t_celda** mat, int dimension);
void revelar_celdas(t_celda** mat, int fila_Seleccionada, int columna_Seleccionada,SDL_Window* ventana, SDL_Renderer*renderer, int dimension);
void liberar_matriz(t_celda **matriz, int dimension);
void dibujar_encabezado(SDL_Renderer *renderer, int ancho_Ventana, SDL_Rect boton_reinicio);
void revelar_cercanas(t_celda **mat, int fila_seleccionada, int columna_seleccionada, SDL_Window* ventana, SDL_Renderer*renderer, int dimension);
int des_asig_bandera(t_celda **mat, int fila_seleccionada, int columna_seleccionada);
void reiniciar_juego(t_celda ***mat, t_parametria par,SDL_Renderer *renderer,SDL_Window *ventana,int ancho_Ventana,SDL_Rect boton_reinicio, const int[][PIXELES_X_LADO]);
int verificar_victoria(t_celda **mat, int dimension);
void mostrar_pantalla_final(TTF_Font* fuente, char* mensaje, int color);
bool verificar_derrota(t_celda** matriz, int dimension, int fila, int col);
void crear_pantalla_inicio(TTF_Font* fuente, t_parametria par);
void mostrar_texto(SDL_Renderer* renderer, TTF_Font* fuente, const char* texto, int x, int y, int);
int calcular_tamano_fuente(int);

#endif // DIBUJOS_H_INCLUDED
