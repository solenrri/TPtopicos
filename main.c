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

        TTF_Font* fuente_estadisticas = TTF_OpenFont("BebasNeue-Regular.ttf", 20);


    SDL_Renderer *renderer_menu = NULL;
    SDL_Window *ventana_menu = NULL;
    SDL_Rect botones_menu[3];

    Estado estado = PANTALLA_MENU;
    crear_pantalla_menu(ventana_menu,renderer_menu, botones_menu);
    //validar_click_menu(ventana_menu, renderer_menu, botones_menu);

    while (estado != PANTALLA_SALIR)
    {
        switch (estado)
        {
            case PANTALLA_MENU:
                estado = validar_click_menu(ventana_menu, renderer_menu, botones_menu);
                break;

            case PANTALLA_JUEGO:
                estado = iniciar_juego();
                break;

            case PANTALLA_ESTADISTICAS:
                estado = mostrar_estadisticas(fuente_estadisticas);
                break;

            default:
                estado = PANTALLA_MENU;
                break;
        }
    }

    SDL_DestroyRenderer(renderer_menu);
    SDL_DestroyWindow(ventana_menu);

    TTF_CloseFont(fuente_estadisticas);

    TTF_Quit();
    SDL_Quit();
    IMG_Quit();

    return 0;
}

