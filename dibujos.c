#include "dibujos.h"
#include <stdio.h>
SDL_Color colores[] =
{
    {50, 50, 50, 255},       // G[0] - Gris
    {140, 140, 140, 255},   // C[1] - Claro
    {255, 255, 255, 255},  // B[2] - Blanco
    {0, 150, 60, 255},          // V[3] - Verde
    {255,0,0,255},         //R[4] - Rojo
    {0,0,0,0},              //N[5] - Negro

/*
    Si necesitan agregar más colores, es necesario agregar en dibujos.h el #define correspondiente
    por ejemplo #define R 3, y acá agregar una fila más que diga {255,0,0,255}
    Nota: el cuarto campo de cada color corresponde a la transparencia: 0 es totalmente transparente, 255 es totalmente visible.
    Ese campo en este ejemplo se ignora, porque después lo pisamos con un valor aleatorio.
*/
};


void dibujar(SDL_Window *ventana, SDL_Renderer *renderer, const int   dibujo[][PIXELES_X_LADO], int oX, int oY)
{
    int offsetX = oX * (PIXELES_X_LADO * TAM_PIXEL + PX_PADDING);
    int offsetY = oY * (PIXELES_X_LADO * TAM_PIXEL + PX_PADDING);

    for (int y = 0; y < PIXELES_X_LADO; y++)
    {
        for (int x = 0; x < PIXELES_X_LADO; x++)
        {
            SDL_SetRenderDrawColor(renderer,
                                   colores[dibujo[y][x]].r,
                                   colores[dibujo[y][x]].g,
                                   colores[dibujo[y][x]].b,
                                   255);
            SDL_Rect pixel = {offsetX + TAM_PIXEL*x, offsetY + TAM_PIXEL*y, TAM_PIXEL, TAM_PIXEL};
            SDL_RenderFillRect(renderer, &pixel);
        }
    }
    SDL_RenderPresent(renderer);
}

void dibujarCampo(SDL_Window *ventana, SDL_Renderer *renderer, const int   dibujo[][PIXELES_X_LADO])
{
    for(int i = 0; i < TAM_GRILLA; i++){
        int offsetX = i * (PIXELES_X_LADO * TAM_PIXEL + PX_PADDING);

        for(int j = 0; j < TAM_GRILLA; j++){
            int offsetY = j * (PIXELES_X_LADO * TAM_PIXEL + PX_PADDING);

            for (int y = 0; y < PIXELES_X_LADO; y++)
            {
                for (int x = 0; x < PIXELES_X_LADO; x++)
                {
                    SDL_SetRenderDrawColor(renderer,
                        colores[dibujo[y][x]].r,
                        colores[dibujo[y][x]].g,
                        colores[dibujo[y][x]].b,
                        255);
                        SDL_Rect pixel = {offsetX + TAM_PIXEL*x, offsetY + TAM_PIXEL*y, TAM_PIXEL, TAM_PIXEL};
                        SDL_RenderFillRect(renderer, &pixel);
                }
            }
        }
    }

    SDL_RenderPresent(renderer);
}

void borrarPantalla(SDL_Window *ventana, SDL_Renderer *renderer)
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0,0,0,0);
    SDL_Rect pixel = {0, 0, 0, 0};
    SDL_RenderFillRect(renderer, &pixel);
    SDL_RenderPresent(renderer);
}

/*
void dibujarSegunCorresponda(SDL_Window *ventana, SDL_Renderer *renderer, int x, int y)
{

}
*/


void colocarMinas(int matriz_minas[DIM][DIM])
{
    int cant_minas=10;
    int contador=0;

    inicializar_matriz(matriz_minas);

     while(contador<cant_minas)
     {
        int fila = rand() %DIM;
        int colum = rand() %DIM;
        matriz_minas[fila][colum]=-1;
        contador++;
     }
}

void  inicializar_matriz(int matriz[DIM][DIM])
{
    for(int i=0;i<DIM;i++)
    {
        for(int j=0; j<DIM; j++)
        {
            matriz[i][j]=0;
        }
    }
}


void mostrar_matriz(int mat[DIM][DIM])
{
    for(int i=0;i<DIM;i++)
    {
        for(int j=0;j<DIM;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}
