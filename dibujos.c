#include "dibujos.h"
#include <stdio.h>
SDL_Color colores[] =
{
    { 50,  50,  50, 255},      // G[0] - Gris
    {140, 140, 140, 255},   // C[1] - Claro
    {255, 255, 255, 255},   // B[2] - Blanco
    {  0, 150,  60, 255},      // V[3] - Verde
    {255,   0,   0, 255},          // R[4] - Rojo
    {  0,   0,   0,   0},              // N[5] - Negro
    {  0,   0, 255, 255},          // A[6] - Azul

/*
    Si necesitan agregar más colores, es necesario agregar en dibujos.h el #define correspondiente
    por ejemplo #define R 3, y acá agregar una fila más que diga {255,0,0,255}
    Nota: el cuarto campo de cada color corresponde a la transparencia: 0 es totalmente transparente, 255 es totalmente visible.
    Ese campo en este ejemplo se ignora, porque después lo pisamos con un valor aleatorio.
*/
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

const int num1[8][8] ={
    {C, C, C, C, C, C, C, C},
    {C, C, C, C, C, C, C, C},
    {C, C, C, C, A, C, C, C},
    {C, C, C, A, A, C, C, C},
    {C, C, C, C, A, C, C, C},
    {C, C, C, C, A, C, C, C},
    {C, C, C, C, A, C, C, C},
    {C, C, C, C, C, C, C, C}
};
const int num2[8][8] ={
    {C, C, C, C, C, C, C, C},
    {C, C, C, C, C, C, C, C},
    {C, C, V, V, V, V, C, C},
    {C, C, C, C, C, V, C, C},
    {C, C, V, V, V, V, C, C},
    {C, C, V, C, C, C, C, C},
    {C, C, V, V, V, V, C, C},
    {C, C, C, C, C, C, C, C}
};
const int num3[8][8] ={
    {C, C, C, C, C, C, C, C},
    {C, C, C, C, C, C, C, C},
    {C, C, R, R, R, R, C, C},
    {C, C, C, C, C, R, C, C},
    {C, C, R, R, R, R, C, C},
    {C, C, C, C, C, R, C, C},
    {C, C, R, R, R, R, C, C},
    {C, C, C, C, C, C, C, C}
};
const int num4[8][8] ={
    {C, C, C, C, C, C, C, C},
    {C, C, C, C, C, C, C, C},
    {C, C, A, C, A, C, C, C},
    {C, C, A, C, A, C, C, C},
    {C, C, A, A, A, C, C, C},
    {C, C, C, C, A, C, C, C},
    {C, C, C, C, A, C, C, C},
    {C, C, C, C, C, C, C, C}
};
const int num5[8][8] ={
    {C, C, C, C, C, C, C, C},
    {C, C, C, C, C, C, C, C},
    {C, C, V, V, V, V, C, C},
    {C, C, V, C, C, C, C, C},
    {C, C, V, V, V, V, C, C},
    {C, C, C, C, C, V, C, C},
    {C, C, V, V, V, V, C, C},
    {C, C, C, C, C, C, C, C}
};
const int num6[8][8] ={
    {C, C, C, C, C, C, C, C},
    {C, C, C, C, C, C, C, C},
    {C, C, R, R, R, R, C, C},
    {C, C, R, C, C, C, C, C},
    {C, C, R, R, R, R, C, C},
    {C, C, R, C, C, R, C, C},
    {C, C, R, R, R, R, C, C},
    {C, C, C, C, C, C, C, C}
};
const int num7[8][8] ={
    {C, C, C, C, C, C, C, C},
    {C, C, C, C, C, C, C, C},
    {C, C, A, A, A, C, C, C},
    {C, C, C, C, A, C, C, C},
    {C, C, C, A, A, A, C, C},
    {C, C, C, C, A, C, C, C},
    {C, C, C, C, A, C, C, C},
    {C, C, C, C, C, C, C, C}
};
const int num8[8][8] ={
    {C, C, C, C, C, C, C, C},
    {C, C, C, C, C, C, C, C},
    {C, C, V, V, V, V, C, C},
    {C, C, V, C, C, V, C, C},
    {C, C, V, V, V, V, C, C},
    {C, C, V, C, C, V, C, C},
    {C, C, V, V, V, V, C, C},
    {C, C, C, C, C, C, C, C}
};

void dibujar(SDL_Window *ventana, SDL_Renderer *renderer, const int dibujo[][PIXELES_X_LADO], int oX, int oY)
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

void dibujar_campo(SDL_Window *ventana, SDL_Renderer *renderer, const int   dibujo[][PIXELES_X_LADO], int dimension)
{
    for(int i = 0; i < dimension; i++){
        int offsetX = i * (PIXELES_X_LADO * TAM_PIXEL + PX_PADDING);

        for(int j = 0; j < dimension; j++){
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

void borrar_pantalla(SDL_Window *ventana, SDL_Renderer *renderer)
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0,0,0,0);
    SDL_Rect pixel = {0, 0, 0, 0};
    SDL_RenderFillRect(renderer, &pixel);
    SDL_RenderPresent(renderer);
}


void colocarMinas(t_celda **matriz_minas, t_parametria* param)
{
    int minasColocadas=0;

    inicializar_matriz(matriz_minas, param->dimension);
    int cantMinas = valor_de_las_minas(param);

     while(minasColocadas<cantMinas)
     {
        int fila = rand() % (param->dimension);
        int colum = rand() % (param->dimension);

        if(!matriz_minas[fila][colum].conMina){
            matriz_minas[fila][colum].conMina=1;
            minasColocadas++;
            //cuento las minas cercanas
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int nuevaFila=fila+i;
                    int nuevaColumna=colum+j;
                    if(nuevaFila >= 0 && nuevaFila < (param->dimension) && nuevaColumna >= 0 && nuevaColumna < (param->dimension))
                    {
                        matriz_minas[nuevaFila][nuevaColumna].minasCercanas++;
                    }
                }
            }
        }
    }
}
void  inicializar_matriz(t_celda **matriz, int dimension)
{
    for(int i=0;i<dimension;i++)
    {
        for(int j=0; j<dimension; j++)
        {
            matriz[i][j].conBandera=0;
            matriz[i][j].conMina=0;
            matriz[i][j].minasCercanas=0;
            matriz[i][j].revelada=0;
        }
    }
}


void mostrar_matriz_minas(t_celda **mat, int dimension)
{
    for(int i=0;i<dimension;i++)
    {
        for(int j=0;j<dimension;j++)
        {
            printf("%d\t",mat[i][j].conMina);
        }
        printf("\n");
    }
}
void mostrar_matriz_minas_ady(t_celda **mat, int dimension)
{
     for(int i=0;i<dimension;i++)
    {
        for(int j=0;j<dimension;j++)
        {
            printf("%d\t",mat[i][j].minasCercanas);
        }
        printf("\n");
    }
}

void revelar_celdas(t_celda **mat, int fila_seleccionada, int columna_seleccionada, SDL_Window* ventana, SDL_Renderer*renderer, int dimension)
{
    t_celda* c = &mat[fila_seleccionada][columna_seleccionada];
    const int *vectorNumeros[8]={(int*)num1, (int*)num2, (int*)num3, (int*)num4, (int*)num5, (int*)num6, (int*)num7, (int*)num8};

    if((c->revelada && c->minasCercanas == 0)|| c->conBandera)
        return;

    c->revelada = true;

    if(c->conMina)
    {
        printf("Pisaste una mina\n");
        for(int i=0;i<dimension;i++)
        {
            for(int j=0;j<dimension;j++)
            {
                mat[i][j].revelada = true;
                if(mat[i][j].conMina)
                {
                    dibujar(ventana, renderer, mina,j,i);
                }
            }
        }
        return;
    }

    if(c->minasCercanas==0)
    {
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int nuevaFila = fila_seleccionada+i;
                int nuevaColumna = columna_seleccionada+j;
                if(nuevaFila>=0&&nuevaFila<dimension&&nuevaColumna>=0&&nuevaColumna<dimension)
                {
                    revelar_celdas(mat,nuevaFila,nuevaColumna, ventana, renderer, dimension);
                }
            }
        }
        dibujar(ventana, renderer, vacia, columna_seleccionada, fila_seleccionada);
    }
    else
    {
        dibujar(ventana, renderer, vectorNumeros[(c->minasCercanas)-1], columna_seleccionada, fila_seleccionada);
    }
}

t_celda** crear_matriz(int dimension)
{
    t_celda** matriz = (t_celda**)malloc((dimension)*sizeof(t_celda*));

    if(!matriz)
        return NULL;

    for (int i = 0; i < dimension; i++)
    {
        matriz[i] = malloc((dimension) * sizeof(t_celda));
        if (!matriz[i])
        {
            return NULL;
        }
    }
    return matriz;
}

void liberar_matriz(t_celda **matriz, int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}


int des_asig_bandera(t_celda **mat, int fila_seleccionada, int columna_seleccionada)
{
    t_celda *celda = &mat[fila_seleccionada][columna_seleccionada];

    if(!celda->revelada){
        if(!celda->conBandera){
            celda->conBandera = true;
            return 0;
        }
        else{
            celda->conBandera = false;
            return 1;
        }
    }

    return 2;
}

void revelar_cercanas(t_celda **mat, int fila_seleccionada, int columna_seleccionada, SDL_Window* ventana, SDL_Renderer*renderer, int dimension)
{
    t_celda* c = &mat[fila_seleccionada][columna_seleccionada];

    if(c->conBandera)
        return;

    int cant_banderas = 0;

    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            int nuevaFila = fila_seleccionada+i;
            int nuevaColumna = columna_seleccionada+j;
            if(nuevaFila>=0&&nuevaFila<dimension&&nuevaColumna>=0&&nuevaColumna<dimension){
                if(mat[fila_seleccionada+i][columna_seleccionada+j].conBandera)
                {
                    cant_banderas++;
                }
            }
        }
    }

    if(cant_banderas == c->minasCercanas && cant_banderas != 0){
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nuevaFila = fila_seleccionada+i;
                int nuevaColumna = columna_seleccionada+j;
                if(nuevaFila>=0&&nuevaFila<dimension&&nuevaColumna>=0&&nuevaColumna<dimension){
                    if(!mat[nuevaFila][nuevaColumna].conBandera){
                        if(mat[nuevaFila][nuevaColumna].conMina){
                            printf("Pisaste una mina\n");
                            for(int i=0;i<dimension;i++)
                            {
                                for(int j=0;j<dimension;j++)
                                {
                                    mat[i][j].revelada = true;
                                    if(mat[i][j].conMina)
                                    {
                                        dibujar(ventana, renderer, mina,j,i);
                                    }
                                }
                            }
                            return;
                        }else{
                            revelar_celdas(mat, nuevaFila, nuevaColumna, ventana, renderer, dimension);
                        }
                    }
                }
            }
        }
    }

}
