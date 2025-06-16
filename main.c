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
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>



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

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    TTF_Font* fuente_resultado = TTF_OpenFont("WorkSans-VariableFont_wght.ttf", 36);
    TTF_Font* fuente_inicio = TTF_OpenFont("BebasNeue-Regular.ttf", 26);

    t_parametria par;
    crear_pantalla_inicio(fuente_inicio, par);

    if(leer_archivo(&par)==ERROR_ARCH)
    {
        TTF_CloseFont(fuente_resultado);
        TTF_CloseFont(fuente_inicio);
        TTF_Quit();
        return 0;
    }

    int ancho_ventana = par.dimension*TAM_PIXEL*PIXELES_X_LADO + par.dimension*PX_PADDING;



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
    int juego_terminado = 0;
    int jugador_gano =0;
    int victoria_mostrada = 0;

    SDL_Rect boton_reinicio = {ancho_ventana/2 - ANCHO_BOTON_REINICIO/2, (ENCABEZADO - ALTO_BOTON_REINICIO)/2, ANCHO_BOTON_REINICIO, ALTO_BOTON_REINICIO};


    dibujar_encabezado(renderer, ancho_ventana, boton_reinicio);

    dibujar_campo(ventana, renderer, casilla, par.dimension);

    t_celda** matriz_minas = crear_matriz(par.dimension);
    colocar_minas(matriz_minas, &par);
    mostrar_matriz_minas(matriz_minas, par.dimension);
    printf("\n");
    mostrar_matriz_minas_ady(matriz_minas, par.dimension);
    int primer_click = 0;
    while (corriendo)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                corriendo = 0;
                printf("Saliendo de SDL\n");
            }
            if(!juego_terminado)
            {
                int resultado = verificar_victoria(matriz_minas,par.dimension);
                if(resultado==1 || resultado==2)
                {
                    juego_terminado=1;
                    jugador_gano=1;
                }
            }
            if(juego_terminado &&jugador_gano && !victoria_mostrada)
            {
                victoria_mostrada =1;
                mostrar_pantalla_final(fuente_resultado, "GANASTE", N);
            }

            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                int tam_celda = PIXELES_X_LADO * TAM_PIXEL + PX_PADDING;
                int boton = e.button.button;
                int x, y;
                if(e.button.y >= ENCABEZADO && juego_terminado==0)
                {
                    x = e.button.x / tam_celda;
                    y = (e.button.y - ENCABEZADO) / tam_celda;
                    if (boton == SDL_BUTTON_LEFT)
                    {
                        if(matriz_minas[y][x].con_mina && primer_click==0)
                        {
                            colocar_minas(matriz_minas,&par);
                        }
                        primer_click=1;
                        if(matriz_minas[y][x].revelada && matriz_minas[y][x].minas_cercanas != 0)
                        {
                            revelar_cercanas(matriz_minas, y, x, ventana, renderer, par.dimension);
                        }

                        else
                        {
                            revelar_celdas(matriz_minas, y, x, ventana, renderer, par.dimension);

                            printf("Hiciste clic izquierdo en (%d, %d)\n", y, x);
                        }
                        if(verificar_derrota(matriz_minas, par.dimension, y, x))
                        {
                            juego_terminado = true;
                            mostrar_pantalla_final(fuente_resultado, "PERDISTE", R);
                        }
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
                    }
                }
                else
                {
                    x = e.button.x;
                    y = e.button.y;
                    if(x>=boton_reinicio.x && x<=boton_reinicio.x + boton_reinicio.w && y>=boton_reinicio.y && y<=boton_reinicio.y + boton_reinicio.h)
                    {
                        reiniciar_juego(&matriz_minas, par, renderer, ventana, ancho_ventana, boton_reinicio, casilla);
                        juego_terminado =0;
                        jugador_gano=0;
                        victoria_mostrada=0;
                        primer_click=0;
                    }
                }
            }
        }
        SDL_Delay(100);  // Esta pausa es para evitar que el procesador se ponga al 100% renderizando constantemente.
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    TTF_CloseFont(fuente_resultado);
    TTF_CloseFont(fuente_inicio);

    liberar_matriz(matriz_minas, par.dimension);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();

    return 0;
}
