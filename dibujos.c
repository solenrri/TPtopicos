#include "dibujos.h"
#include <stdio.h>
#include <SDL2/SDL_ttf.h>


SDL_Color colores[] =
{
    { 50,  50,  50, 255},   // G[0] - Gris
    {140, 140, 140, 255},   // C[1] - Claro
    {255, 255, 255, 255},   // B[2] - Blanco
    {  0, 150,  60, 255},   // V[3] - Verde
    {255,   0,   0, 255},   // R[4] - Rojo
    {  0,   0,   0,   0},   // N[5] - Negro
    {  0,   0, 255, 255},   // A[6] - Azul

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
    int offsetY = oY * (PIXELES_X_LADO * TAM_PIXEL + PX_PADDING) + ENCABEZADO;

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

void dibujar_campo(SDL_Window *ventana, SDL_Renderer *renderer, const int dibujo[][PIXELES_X_LADO], int dimension)
{
    for(int i = 0; i < dimension+1; i++)
    {
        int offsetX = i * (PIXELES_X_LADO * TAM_PIXEL + PX_PADDING);

        for(int j = 0; j < dimension; j++)
        {
            int offsetY = j * (PIXELES_X_LADO * TAM_PIXEL + PX_PADDING) + ENCABEZADO;

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

    SDL_SetRenderDrawColor(renderer, 0,0,0,0);
    SDL_RenderClear(renderer);
    SDL_Rect pixel = {0, 0, 0, 0};
    SDL_RenderFillRect(renderer, &pixel);
}


void colocar_minas(t_celda **matriz_minas, t_parametria* param)
{
    int minasColocadas=0;

    inicializar_matriz(matriz_minas, param->dimension);
    int cant_minas = valor_de_las_minas(param);

     while(minasColocadas<cant_minas)
     {
        int fila = rand() % (param->dimension);
        int colum = rand() % (param->dimension);

        if(!matriz_minas[fila][colum].con_mina){
            matriz_minas[fila][colum].con_mina=1;
            minasColocadas++;

            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int nueva_fila=fila+i;
                    int nueva_columna=colum+j;
                    if(nueva_fila >= 0 && nueva_fila < (param->dimension) && nueva_columna >= 0 && nueva_columna < (param->dimension))
                    {
                        matriz_minas[nueva_fila][nueva_columna].minas_cercanas++;
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
            matriz[i][j].con_bandera=0;
            matriz[i][j].con_mina=0;
            matriz[i][j].minas_cercanas=0;
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
            printf("%d\t",mat[i][j].con_mina);
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
            printf("%d\t",mat[i][j].minas_cercanas);
        }
        printf("\n");
    }
}

void revelar_celdas(t_celda **mat, int fila_seleccionada, int columna_seleccionada, SDL_Window* ventana, SDL_Renderer*renderer, int dimension)
{
    t_celda* c = &mat[fila_seleccionada][columna_seleccionada];
    const int *vector_numeros[8]={(int*)num1, (int*)num2, (int*)num3, (int*)num4, (int*)num5, (int*)num6, (int*)num7, (int*)num8};

    if((c->revelada && c->minas_cercanas == 0)|| c->con_bandera)
        return;

    c->revelada = true;

    if(c->con_mina)
    {
        for(int i=0;i<dimension;i++)
        {
            for(int j=0;j<dimension;j++)
            {
                mat[i][j].revelada = true;
                if(mat[i][j].con_mina)
                {
                    dibujar(ventana, renderer, mina,j,i);
                }
            }
        }

        return;
    }

    if(c->minas_cercanas==0)
    {
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int nueva_fila = fila_seleccionada+i;
                int nueva_columna = columna_seleccionada+j;
                if(nueva_fila>=0&&nueva_fila<dimension&&nueva_columna>=0&&nueva_columna<dimension)
                {
                    revelar_celdas(mat,nueva_fila,nueva_columna, ventana, renderer, dimension);
                }
            }
        }
        dibujar(ventana, renderer, vacia, columna_seleccionada, fila_seleccionada);
    }
    else
    {
        dibujar(ventana, renderer, vector_numeros[(c->minas_cercanas)-1], columna_seleccionada, fila_seleccionada);
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
    if(!mat[fila_seleccionada][columna_seleccionada].revelada)
    {
        if(!mat[fila_seleccionada][columna_seleccionada].con_bandera)
        {
            mat[fila_seleccionada][columna_seleccionada].con_bandera=true;
            return 0;
        }
        else
        {
            mat[fila_seleccionada][columna_seleccionada].con_bandera=false;
            return 1;
        }
    }
    return 2;
}

void revelar_cercanas(t_celda **mat, int fila_seleccionada, int columna_seleccionada, SDL_Window* ventana, SDL_Renderer*renderer, int dimension)
{
    t_celda* c = &mat[fila_seleccionada][columna_seleccionada];

    if(c->con_bandera)
        return;

    int cant_banderas = 0;

    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            int nueva_fila = fila_seleccionada+i;
            int nueva_columna = columna_seleccionada+j;

            if(nueva_fila>=0&&nueva_fila<dimension&&nueva_columna>=0&&nueva_columna<dimension)
            {
                if(mat[fila_seleccionada+i][columna_seleccionada+j].con_bandera)
                {
                    cant_banderas++;
                }
            }
        }
    }

    if(cant_banderas == c->minas_cercanas && cant_banderas != 0)
    {
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int nueva_fila = fila_seleccionada+i;
                int nueva_columna = columna_seleccionada+j;

                if(nueva_fila>=0&&nueva_fila<dimension&&nueva_columna>=0&&nueva_columna<dimension)
                {
                    if(!mat[nueva_fila][nueva_columna].con_bandera)
                    {
                        if(mat[nueva_fila][nueva_columna].con_mina)
                        {
                            printf("Pisaste una mina\n");
                            for(int i=0;i<dimension;i++)
                            {
                                for(int j=0;j<dimension;j++)
                                {
                                    mat[i][j].revelada = true;
                                    if(mat[i][j].con_mina)
                                    {
                                        dibujar(ventana, renderer, mina,j,i);
                                    }
                                }
                            }
                            return;
                        }else{
                            revelar_celdas(mat, nueva_fila, nueva_columna, ventana, renderer, dimension);
                        }
                    }
                }
            }
        }
    }

}

void dibujar_encabezado(SDL_Renderer *renderer, int ancho_ventana, SDL_Rect boton_reinicio)
{
    SDL_SetRenderDrawColor(renderer,colores[C].r,colores[C].g,colores[C].b,colores[C].a);
    SDL_Rect encabezado = {0, 0, ancho_ventana, ENCABEZADO};
    SDL_RenderFillRect(renderer,&encabezado);

    SDL_SetRenderDrawColor(renderer,colores[N].r,colores[N].g,colores[N].b,colores[N].a);
    SDL_RenderDrawRect(renderer, &encabezado);

    SDL_SetRenderDrawColor(renderer,colores[R].r,colores[R].g,colores[R].b,colores[R].a);

    SDL_RenderFillRect(renderer, &boton_reinicio);

    SDL_SetRenderDrawColor(renderer,colores[N].r,colores[N].g,colores[N].b,colores[N].a);
    SDL_RenderDrawRect(renderer,&boton_reinicio);
}

void reiniciar_juego(t_celda ***mat, t_parametria par, SDL_Renderer *renderer,SDL_Window *ventana, int ancho_Ventana, SDL_Rect boton_reinicio, const int dibujo[][PIXELES_X_LADO])
{
    liberar_matriz(*mat,par.dimension);
    borrar_pantalla(ventana,renderer);
    *mat = crear_matriz(par.dimension);
    dibujar_encabezado(renderer, ancho_Ventana,boton_reinicio);
    dibujar_campo(ventana, renderer,dibujo, par.dimension);
    colocar_minas(*mat,&par);
    SDL_RenderPresent(renderer);
}

int verificar_victoria(t_celda **mat, int dimension)
{
    int victoria_normal = 1;
    
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            if (!mat[j][i].con_mina && !mat[j][i].revelada)
            {
                victoria_normal = 0;
            }
        }
    }
    int victoria_truco = 0;

    if(mat[0][0].con_bandera && mat[0][dimension-1].con_bandera &&
     mat[dimension-1][0].con_bandera && mat[dimension-1][dimension-1].con_bandera)
     {
         victoria_truco = 1;
     }

     if(victoria_truco)
        return 2;
     else if(victoria_normal)
        return 1;

     return 0;

}

bool verificar_derrota(t_celda** matriz, int dimension, int fila, int col)
{
    return matriz[fila][col].con_mina && matriz[fila][col].revelada;
}


void mostrar_pantalla_final(TTF_Font* fuente, char* mensaje, int color)
{
    SDL_Window* ventana_mensaje = SDL_CreateWindow(
        "Resultado",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 200,
        SDL_WINDOW_SHOWN
    );

    if (!ventana_mensaje) {
        printf("Error al crear ventana: %s\n", SDL_GetError());
        return;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(ventana_mensaje, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_DestroyWindow(ventana_mensaje);
        printf("Error al crear renderer: %s\n", SDL_GetError());
        return;
    }

    SDL_Color fondo = colores[0];
    SDL_Color texto = colores[color];

    SDL_SetRenderDrawColor(renderer, fondo.r, fondo.g, fondo.b, fondo.a);
    SDL_RenderClear(renderer);

    SDL_Surface* surface = TTF_RenderText_Blended(fuente, mensaje, texto);
    if (!surface) {
        printf("Error al renderizar texto: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(ventana_mensaje);
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect destino = {
        (400 - surface->w) / 2,
        (200 - surface->h) / 2,
        surface->w,
        surface->h
    };
    SDL_FreeSurface(surface);

    SDL_RenderCopy(renderer, texture, NULL, &destino);
    SDL_RenderPresent(renderer);


    SDL_Event e;
    int esperando = 1;
    while (esperando)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_KEYDOWN)
            {
                esperando = 0;
            }
        }
        SDL_Delay(10);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana_mensaje);
}

void crear_pantalla_inicio(TTF_Font* fuente, t_parametria par)
{
    SDL_Window* ventana_inicio = SDL_CreateWindow(
        "Inicio",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 150,
        SDL_WINDOW_SHOWN
    );

    if (!ventana_inicio)
    {
        printf("Error al crear ventana: %s\n", SDL_GetError());
        return;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(ventana_inicio, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        SDL_DestroyWindow(ventana_inicio);
        printf("Error al crear renderer: %s\n", SDL_GetError());
        return;
    }
    SDL_StartTextInput();
    SDL_Event e;
    int corriendo = 1;
    char usuario [30];
    const char *etiquetas[]= {"Usuario:","Dimension:", "Cantidad de Minas:"};
    char entrada_datos[3][50] = {"", "", ""};
    int campo_activo = 0;

    while(corriendo)
    {
        while(SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                SDL_StopTextInput();
                corriendo = 0;
                printf("Saliendo de SDL\n");
            }else if(e.type == SDL_KEYDOWN)
            {
                 if (e.key.keysym.sym == SDLK_TAB)
                {
                    campo_activo = (campo_activo + 1) % 3;
                } else if (e.key.keysym.sym == SDLK_RETURN)
                {
                    if(strlen(entrada_datos[0])>0 && strlen(entrada_datos[1])>0 && strlen(entrada_datos[2])>0)
                    {
                        corriendo = 0;
                    }
                } else if (e.key.keysym.sym == SDLK_BACKSPACE)
                {
                    int len = strlen(entrada_datos[campo_activo]);
                    if (len > 0)
                        entrada_datos[campo_activo][len - 1] = '\0';
                }
            }else if (e.type == SDL_TEXTINPUT)
            {
                if (strlen(entrada_datos[campo_activo]) < MAX_CARAC - 1)
                {
                    strcat(entrada_datos[campo_activo], e.text.text);
                }
            }else if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                int boton = e.button.button;
                int y = round(e.button.y / 50);

                if (boton == SDL_BUTTON_LEFT)
                {
                    campo_activo = y;
                }
            }
        }


    SDL_RenderClear(renderer);

    for (int i = 0; i < 3; i++)
    {
        char texto[100];
        sprintf(texto, "%s %s", etiquetas[i], entrada_datos[i]);

        SDL_Surface* surface = TTF_RenderText_Solid(fuente, texto, i == campo_activo ? colores[C] : colores[G]);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_Rect dst = {50, 10 + i * 50, surface->w, surface->h};
        SDL_RenderCopy(renderer, texture, NULL, &dst);

        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }

    SDL_RenderPresent(renderer);

    }
    SDL_StopTextInput();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana_inicio);

    strcpy(usuario,entrada_datos[0]);
    par.dimension = atoi(entrada_datos[1]);
    strcpy(par.cantidad_minas,entrada_datos[2]);
    guardar_configuracion(par);
}


