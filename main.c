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
#include "dibujos.h"
#include "configuracion.h"


int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    TTF_Init();
    IMG_Init(IMG_INIT_PNG);
/*
    SDL_Renderer *renderer_menu = NULL;
    SDL_Window *ventana_menu = NULL;
    SDL_Rect botones_menu[3];

    crear_pantalla_menu(ventana_menu,renderer_menu, botones_menu);
    validar_click_menu(ventana_menu, renderer_menu, botones_menu);
*/
    iniciar_juego();
/*
    SDL_DestroyRenderer(renderer_menu);
    SDL_DestroyWindow(ventana_menu);
*/
    TTF_Quit();
    SDL_Quit();
    IMG_Quit();

    return 0;
}

