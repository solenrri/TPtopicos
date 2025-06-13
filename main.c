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
#include "configuracion.h"

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

int main(int argc, char* argv[])
{

    t_parametria par;
    leer_archivo(&par);
    int ancho_ventana = par.dimension*TAM_PIXEL*PIXELES_X_LADO + par.dimension*PX_PADDING;

    SDL_Init(SDL_INIT_VIDEO);
    char nombre_ventana[100];
    sprintf(nombre_ventana, "Tablero %dx%d",par.dimension,par.dimension);
    SDL_Window *ventana = SDL_CreateWindow(nombre_ventana,
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           ancho_ventana, ancho_ventana + ENCABEZADO,
                                           2);

    SDL_Renderer *renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    borrar_pantalla(ventana, renderer);
    srand(time(0));

    SDL_Event e;
    int corriendo = 1;

    dibujar_encabezado(renderer, ancho_ventana);

    dibujar_campo(ventana, renderer, casilla, par.dimension);

    t_celda** matriz_minas = crear_matriz(par.dimension);
    colocar_minas(matriz_minas, &par);
    mostrar_matriz_minas(matriz_minas, par.dimension);
    printf("\n");
    mostrar_matriz_minas_ady(matriz_minas, par.dimension);
    while (corriendo)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                corriendo = 0;
                printf("Saliendo de SDL\n");
            }

            if(e.button.y >= ENCABEZADO)
            {
                if (e.type == SDL_MOUSEBUTTONDOWN)
                {
                    int tam_celda = PIXELES_X_LADO * TAM_PIXEL + PX_PADDING;

                    int x = e.button.x / tam_celda;
                    int y = (e.button.y - ENCABEZADO) / tam_celda;
                    int boton = e.button.button;

                    if (boton == SDL_BUTTON_LEFT)
                    {
                        if(matriz_minas[y][x].revelada && matriz_minas[y][x].minas_cercanas != 0)
                            revelar_cercanas(matriz_minas, y, x, ventana, renderer, par.dimension);
                        else
                            revelar_celdas(matriz_minas, y, x, ventana, renderer, par.dimension);
                        
                        printf("Hiciste clic izquierdo en (%d, %d)\n", y, x);
                    }
                    else if (boton == SDL_BUTTON_RIGHT)
                    {
                        int bandera2 = des_asig_bandera(matriz_minas, y, x);

                        if(bandera2 == 0){
                            dibujar(ventana, renderer, bandera, x, y);
                            printf("Hiciste clic derecho en (%d, %d)\n", x, y);
                        }
                        else if(bandera2 ==1){
                            dibujar(ventana, renderer, casilla, x, y);
                            printf("Hiciste clic derecho en (%d, %d)\n", x, y);
                        }
                    
                        //borrar_pantalla(ventana, renderer);
                    }
                }
            }
        }
        SDL_Delay(100);  // Esta pausa es para evitar que el procesador se ponga al 100% renderizando constantemente.
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    SDL_Quit();
    liberar_matriz(matriz_minas, par.dimension);

    return 0;
}
