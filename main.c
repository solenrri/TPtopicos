/*
Integrantes

Apellido: Enrri, Sol Mariel
DNI: 39766510
Entrega: Si

Apellido: Tuso, Ramiro Agustín
DNI:
Entrega: Si

Apellido: Cuevas, Brandon Nahuel
DNI: 43510488
Entrega: Si
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dibujos.h"

const int casilla[8][8] ={
    {B, B, B, B, B, B, B, G},
    {B, C, C, C, C, C, C, G},
    {B, C, C, C, C, C, C, G},
    {B, C, C, C, C, C, C, G},
    {B, C, C, C, C, C, C, G},
    {B, C, C, C, C, C, C, G},
    {B, C, C, C, C, C, C, G},
    {B, G, G, G, G, G, G, G}
};

const int vacia[8][8] ={
    {C, C, C, C, C, C, C, C},
    {C, C, C, C, C, C, C, C},
    {C, C, C, C, C, C, C, C},
    {C, C, C, C, C, C, C, C},
    {C, C, C, C, C, C, C, C},
    {C, C, C, C, C, C, C, C},
    {C, C, C, C, C, C, C, C},
    {C, C, C, C, C, C, C, C}
};

const int bandera[8][8] ={
    {B, B, B, B, B, B, B, G},
    {B, C, C, R, R, C, C, G},
    {B, C, R, R, R, C, C, G},
    {B, C, C, R, R, C, C, G},
    {B, C, C, C, N, C, C, G},
    {B, C, C, C, N, C, C, G},
    {B, C, C, C, N, C, C, G},
    {B, G, N, N, N, N, N, G}
};

const int mina[8][8] ={
    {C, C, C, C, C, C, C, C},
    {C, C, C, N, N, C, C, C},
    {C, C, N, N, N, N, C, C},
    {C, N, B, N, N, N, N, C},
    {C, C, N, N, N, N, C, C},
    {C, C, N, N, N, N, C, C},
    {C, C, C, N, N, C, C, C},
    {C, C, C, C, C, C, C, C}
};

int main(int argc, char* argv[])
{

    SDL_Init(SDL_INIT_VIDEO);
    char nombreVentana[100];
    sprintf(nombreVentana, "Tablero %dx%d",TAM_GRILLA,TAM_GRILLA);
    SDL_Window *ventana = SDL_CreateWindow(nombreVentana,
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           TAM_GRILLA * TAM_PIXEL * PIXELES_X_LADO  + TAM_GRILLA * PX_PADDING, TAM_GRILLA * TAM_PIXEL * PIXELES_X_LADO  + TAM_GRILLA * PX_PADDING,
                                           2);

    SDL_Renderer *renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    borrarPantalla(ventana, renderer);
    srand(time(0));

    SDL_Event e;
    int corriendo = 1;
    int offsetX =  0;
    int offsetY = 0;
    dibujarCampo(ventana, renderer, casilla);
//    colocarMinas();
    while (corriendo)
    {

        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                corriendo = 0;
                printf("Saliendo de SDL\n");
            }

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int tamCelda = PIXELES_X_LADO * TAM_PIXEL + PX_PADDING;

                int x = e.button.x / tamCelda;
                int y = e.button.y / tamCelda;
                int boton = e.button.button;

                if (boton == SDL_BUTTON_LEFT)
                {
                    printf("Hiciste clic izquierdo en (%d, %d) poniendo un dibujo en la posición aleatoria [%d,%d]\n", x, y, offsetX, offsetY);
                   // dibujarSegunCorresponda(ventana, renderer,x,y);
                    dibujar(ventana, renderer, vacia, x, y);
                    //dibujar(ventana, renderer, mina, x, y);

                }
                else if (boton == SDL_BUTTON_RIGHT)
                {
                    printf("Hiciste clic derecho en (%d, %d)\n", x, y);
                    dibujar(ventana, renderer, bandera, x, y);
                    //borrarPantalla(ventana, renderer);

                }
            }
        }
        SDL_Delay(100);  // Esta pausa es para evitar que el procesador se ponga al 100% renderizando constantemente.
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    SDL_Quit();
    return 0;
}
