#include "dibujos.h"

SDL_Color colores[] =
{
    { 50,  50,  50, 255},   // G[0] - Gris
    {140, 140, 140, 255},   // C[1] - Claro
    {255, 255, 255, 255},   // B[2] - Blanco
    {  0, 150,  60, 255},   // V[3] - Verde
    {255,   0,   0, 255},   // R[4] - Rojo
    {  0,   0,   0,   0},   // N[5] - Negro
    {  0,   0, 255, 255},
     {173, 216, 230, 255}    // A[6] - Azul

/*
    Si necesitan agregar más colores, es necesario agregar en dibujos.h el #define correspondiente
    por ejemplo #define R 3, y acá agregar una fila más que diga {255,0,0,255}
    Nota: el cuarto campo de cada color corresponde a la transparencia: 0 es totalmente transparente, 255 es totalmente visible.
    Ese campo en este ejemplo se ignora, porque después lo pisamos con un valor aleatorio.
*/
};

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
        dibujar(ventana, renderer, (const int(*)[8]) vector_numeros[(c->minas_cercanas)-1], columna_seleccionada, fila_seleccionada);
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
                                    if(mat[i][j].con_mina)
                                    {
                                        mat[i][j].revelada = true;
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

void mostrar_texto(SDL_Renderer* renderer, TTF_Font* fuente, const char* texto, int x, int y, int alinear_derecha) {
    SDL_Color color = colores[R];

    // Crear superficie con el texto
    SDL_Surface* superficie = TTF_RenderText_Solid(fuente, texto, color);
    if (!superficie) return;

    SDL_Texture* textura = SDL_CreateTextureFromSurface(renderer, superficie);

    int ancho = superficie->w;
    int alto = superficie->h;

    // Si se debe alinear a la derecha, ajustar posición X
    if (alinear_derecha) {
        x = x - ancho;
    }

    SDL_Rect rect = {x, y, ancho, alto};

    // Dibujar fondo negro
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

    // Dibujar texto encima
    SDL_RenderCopy(renderer, textura, NULL, &rect);

    // Liberar recursos
    SDL_FreeSurface(superficie);
    SDL_DestroyTexture(textura);
}

int calcular_tamano_fuente(int dimension) {
    int tam_fuente = dimension * 2.5;
    if (tam_fuente < 16) tam_fuente = 16;
    if (tam_fuente > 32) tam_fuente = 32;
    return tam_fuente;
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

bool verificar_derrota(t_celda **mat, int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            if (mat[j][i].con_mina && mat[j][i].revelada)
            {
                return true;
            }
        }
    }

    return false;
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
        400, 200,
        SDL_WINDOW_SHOWN
    );

    if (!ventana_inicio)
    {
        printf("Error al crear ventana\n");
        return;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(ventana_inicio, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        SDL_DestroyWindow(ventana_inicio);
        printf("Error al crear renderer\n");
        return;
    }


    SDL_Surface* fondo_surface = IMG_Load("img/fondo_inicio.png");
    if (!fondo_surface)
    {
        printf("No se pudo cargar la imagen de fondo\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(ventana_inicio);
        return;
    }

    SDL_Texture* fondo_texture = SDL_CreateTextureFromSurface(renderer, fondo_surface);
    SDL_FreeSurface(fondo_surface);

    SDL_StartTextInput();
    SDL_Event e;
    int corriendo = 1;
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
            } else if (e.type == SDL_TEXTINPUT)
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
                    if(y<=2){
                        campo_activo = y;
                    }
                    else{
                        if(strlen(entrada_datos[0])>0 && strlen(entrada_datos[1])>0 && strlen(entrada_datos[2])>0)
                            corriendo = 0;
                    }

                }
            }
        }


    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, fondo_texture, NULL, NULL);


    for (int i = 0; i < 3; i++)
    {
        char texto[100];
        sprintf(texto, "%s %s", etiquetas[i], entrada_datos[i]);

        SDL_Surface* surface = TTF_RenderText_Solid(fuente, texto, i == campo_activo ? colores[N] : colores[G]);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_SetRenderDrawColor(renderer, colores[A].r, colores[C].g, colores[C].b, colores[C].a);
        SDL_Rect fondo_texto = {50, 10 + i * 50, surface->w, surface->h};
        SDL_RenderFillRect(renderer, &fondo_texto);

        SDL_Rect dst = {50, 10 + i * 50, surface->w, surface->h};
        SDL_RenderCopy(renderer, texture, NULL, &dst);

        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }

    //test
    char texto2[10];
    sprintf(texto2, "Enter");

    SDL_Surface* surface = TTF_RenderText_Solid(fuente, texto2, 3 == campo_activo ? colores[N] : colores[G]);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_SetRenderDrawColor(renderer, colores[A].r, colores[C].g, colores[C].b, colores[C].a);
    SDL_Rect fondo_texto = {300, 10+150, surface->w, surface->h};
    SDL_RenderFillRect(renderer, &fondo_texto);

    SDL_Rect dst = {300, 10+150, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &dst);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);


    SDL_RenderPresent(renderer);
    }
    SDL_StopTextInput();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana_inicio);
    SDL_DestroyTexture(fondo_texture);

    strcpy(par.usuario, entrada_datos[0]);
    par.dimension = atoi(entrada_datos[1]);
    strcpy(par.cantidad_minas, entrada_datos[2]);
    guardar_configuracion(par);
}

void crear_pantalla_menu(SDL_Window *ventana,SDL_Renderer *renderer, SDL_Rect botones[])
{
    TTF_Font* fuente_menu = TTF_OpenFont("BebasNeue-Regular.ttf", 40);
    ventana = SDL_CreateWindow(
        "Menu",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        ANCHO_MENU, ANCHO_MENU,
        SDL_WINDOW_SHOWN
    );

    if (!ventana)
    {
        printf("Error al crear ventana\n");
        return;
    }

     renderer= SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        SDL_DestroyWindow(ventana);
        printf("Error al crear renderer\n");
        return;
    }

    SDL_SetRenderDrawColor(renderer,colores[L].r,colores[L].g,colores[L].b,colores[L].a);
    SDL_RenderClear(renderer);

    SDL_Rect cuadrado;
    cuadrado.h=ANCHO_CUADRADO_MENU;
    cuadrado.w=ANCHO_CUADRADO_MENU;
    cuadrado.x=(ANCHO_MENU-ANCHO_CUADRADO_MENU)/2;
    cuadrado.y=(ANCHO_MENU-ANCHO_CUADRADO_MENU)/2;

    SDL_SetRenderDrawColor(renderer,colores[B].r,colores[B].g,colores[B].b,colores[B].a);
    SDL_RenderFillRect(renderer, &cuadrado);

    SDL_SetRenderDrawColor(renderer, colores[A].r, colores[B].g, colores[A].b, colores[A].a);
    SDL_RenderDrawRect(renderer, &cuadrado);
    const char *etiquetas[]= {"Juego Nuevo","Continuar Partida", "Estadisticas"};

    for (int i = 0; i < 3; i++)
    {
        char texto[100];
        sprintf(texto, "%s", etiquetas[i]);


        SDL_Surface* menu_surface = TTF_RenderText_Solid(fuente_menu, texto, colores[N]);
        SDL_Texture* menu_texture = SDL_CreateTextureFromSurface(renderer, menu_surface);


        int centro_etiquetas = (ANCHO_MENU - menu_surface->w)/2;

        SDL_SetRenderDrawColor(renderer, colores[L].r, colores[L].g, colores[L].b, colores[L].a);
        SDL_Rect fondo_texto = {centro_etiquetas, 80 + i * 100, menu_surface->w, menu_surface->h};

        botones[i]=fondo_texto;

        SDL_RenderFillRect(renderer, &fondo_texto);

        SDL_Rect dst = {centro_etiquetas, 80 + i * 100, menu_surface->w, menu_surface->h};
        SDL_RenderCopy(renderer, menu_texture, NULL, &dst);

        SDL_FreeSurface(menu_surface);
        SDL_DestroyTexture(menu_texture);
    }

        SDL_RenderPresent(renderer);
        TTF_CloseFont(fuente_menu);

}
Estado validar_click_menu(SDL_Window *ventana,SDL_Renderer *renderer, SDL_Rect botones_menu[])
{
    int esperando=1;
    SDL_Event e;

    while (esperando)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                esperando = 0;
                return PANTALLA_SALIR;
            }
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                int x = e.button.x;
                int y = e.button.y;

                for(int i=0;i<3;i++)
                {
                    if(SDL_PointInRect(&(SDL_Point){x,y},&botones_menu[i]))
                    {
                        switch(i)
                        {
                            case 0:
                               return PANTALLA_JUEGO;

                            case 1:
                               return PANTALLA_CONTINUAR_PARTIDA;

                            case 2:
                                return PANTALLA_ESTADISTICAS;
                       }

                    }
                }
            }
        }
    }

    return PANTALLA_MENU;
}

Estado mostrar_estadisticas(TTF_Font* fuente){
    FILE *stats;
    char usuario[30], resultado[6];
    int seg;

    stats = fopen("buscaminas.stats", "rt");

    char linea[50];

    SDL_Window* ventana_mensaje = SDL_CreateWindow(
        "Estadisticas",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 220,
        SDL_WINDOW_SHOWN
    );

    if (!ventana_mensaje) {
        printf("Error al crear ventana: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(ventana_mensaje, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_DestroyWindow(ventana_mensaje);
        printf("Error al crear renderer: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Color fondo = colores[0];
    SDL_Color texto = colores[B];

    SDL_SetRenderDrawColor(renderer, fondo.r, fondo.g, fondo.b, fondo.a);
    SDL_RenderClear(renderer);

    int i = 0;
    while (fgets(linea, sizeof(linea), stats))
    {
        sscanf(linea, "jugador:%s\ttiempo:%d\tresultado:%s", usuario, &seg, resultado);
        printf("%s %d %s\n", usuario, seg, resultado);

        SDL_Surface* surface = TTF_RenderText_Blended(fuente, linea, texto);
        if (!surface) {
            printf("Error al renderizar texto: %s\n", TTF_GetError());
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(ventana_mensaje);
            return 1;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect destino =
        {20,
            i*20,
            surface->w,
            surface->h
        };
        SDL_FreeSurface(surface);


        SDL_RenderCopy(renderer, texture, NULL, &destino);
        SDL_RenderPresent(renderer);
        i++;

        if(i==10)
            break;
    }

        SDL_Event e;
        int esperando = 1;
        while (esperando)
        {
            while (SDL_PollEvent(&e))
            {
                if (e.type == SDL_QUIT || e.type == SDL_MOUSEBUTTONDOWN)
                {
                    esperando = 0;
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(ventana_mensaje);
                    return PANTALLA_SALIR;
                }
                if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
                {
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(ventana_mensaje);
                    return PANTALLA_MENU;
                }
            }
            SDL_Delay(10);
        }

        //SDL_DestroyTexture(texture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(ventana_mensaje);

    fclose(stats);
    return PANTALLA_MENU;
}

Estado iniciar_juego()
{
    TTF_Font* fuente_resultado = TTF_OpenFont("WorkSans-VariableFont_wght.ttf", 36);
    TTF_Font* fuente_inicio = TTF_OpenFont("BebasNeue-Regular.ttf", 26);
    t_parametria par;
    crear_pantalla_inicio(fuente_inicio, par);

    t_fecha f;
    FILE *log, *stats;
    char contenido_stats[10][50], linea[50];
    int i=0, cant_partidas = 0;

    log = fopen("buscaminas.log", "wt");
    if(!log){
        return 1;
    }

    stats = fopen("buscaminas.stats", "rt");
    if(!stats){
        fclose(log);
        return 1;
    }

    while (fgets(&contenido_stats[i][0], sizeof(linea), stats) && i!=10){
        i++;
    }
    fclose(stats);

    stats = fopen("buscaminas.stats", "w");
    if(!stats){
        fclose(log);
        return 1;
    }

    if(leer_archivo(&par)==ERROR_ARCH)
    {
        fclose(log);
        TTF_CloseFont(fuente_resultado);
        TTF_CloseFont(fuente_inicio);
        TTF_Quit();
        return 1;
    }

    int ancho_ventana = par.dimension*TAM_PIXEL*PIXELES_X_LADO + par.dimension*PX_PADDING;

    // Inicialización del temporizador
    Uint32 tiempo_ultimo_segundo = SDL_GetTicks();
    int segundos = 0;

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
    int primer_click = 0;
    int banderas_colocadas = valor_de_las_minas(&par);
    int padding = 10;
    char texto_tiempo[32];
    char texto_banderas[32];

    TTF_Font* fuente_digital = TTF_OpenFont("fnt/DS-DIGI.TTF", calcular_tamano_fuente(par.dimension));

    SDL_Rect boton_reinicio = {ancho_ventana/2 - ANCHO_BOTON_REINICIO/2, (ENCABEZADO - ALTO_BOTON_REINICIO)/2, ANCHO_BOTON_REINICIO, ALTO_BOTON_REINICIO};

    dibujar_encabezado(renderer, ancho_ventana, boton_reinicio);
    dibujar_campo(ventana, renderer, casilla, par.dimension);

    t_celda** matriz_minas = crear_matriz(par.dimension);
    colocar_minas(matriz_minas, &par);
    mostrar_matriz_minas(matriz_minas, par.dimension);
    printf("\n");
    mostrar_matriz_minas_ady(matriz_minas, par.dimension);

    while (corriendo)
    {
        // Controlar si pasó un segundo para actualizar el temporizador
        Uint32 tiempo_actual = SDL_GetTicks();
        if (tiempo_actual - tiempo_ultimo_segundo >= 1000 && primer_click==1 && juego_terminado!=1) {
            segundos++;
            tiempo_ultimo_segundo = tiempo_actual;
        }
        // Redibujar encabezado y contadores
        dibujar_encabezado(renderer, ancho_ventana,boton_reinicio);
        sprintf(texto_banderas, "%03d", banderas_colocadas);
        mostrar_texto(renderer, fuente_digital, texto_banderas, padding, padding, 0);
        sprintf(texto_tiempo, "%03d", segundos);
        mostrar_texto(renderer, fuente_digital, texto_tiempo, ancho_ventana - padding, padding, 1);

        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                corriendo = 0;
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(ventana);
                return PANTALLA_SALIR;
                printf("Saliendo de SDL\n");
            }

            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
            {
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(ventana);
                for(int j=0; j<i; j++){
                    sprintf(linea,"%s", &contenido_stats[j][0]);
                    fprintf(stats,"%s", linea);
                }

                if(juego_terminado ==0){
                    guardar_partida(matriz_minas, &par, segundos);
                }

                fclose(stats);
                return PANTALLA_MENU;  // Volver al menú
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
                obtener_fecha(&f);
                fprintf(log, "(%02d/%02d/%4d %02d:%02d:%02d): Fin de juego - Partida ganada\n", f.dia, f.mes, f.anio, f.h, f.m, f.s);

                fprintf(stats, "jugador:%s|tiempo:%d|resultado:gano\n", par.usuario, segundos);
                cant_partidas++;

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
                        if(primer_click==0)
                        {
                            obtener_fecha(&f);
                            fprintf(log, "(%02d/%02d/%4d %02d:%02d:%02d): Inicia partida\n", f.dia, f.mes, f.anio, f.h, f.m, f.s);
                            primer_click = 1;

                            if(matriz_minas[y][x].con_mina){
                                colocar_minas(matriz_minas, &par);
                                obtener_fecha(&f);
                                fprintf(log, "(%02d/%02d/%4d %02d:%02d:%02d): click izquierdo en (%d, %d)\n", f.dia, f.mes, f.anio, f.h, f.m, f.s, y, x);
                            }
                        }

                        if(matriz_minas[y][x].revelada && matriz_minas[y][x].minas_cercanas != 0 && (!matriz_minas[y][x].con_mina))
                        {
                            revelar_cercanas(matriz_minas, y, x, ventana, renderer, par.dimension);
                            obtener_fecha(&f);
                            fprintf(log, "(%02d/%02d/%4d %02d:%02d:%02d): click izquierdo en (%d, %d)\n", f.dia, f.mes, f.anio, f.h, f.m, f.s, y, x);
                        }
                        else
                        {
                            revelar_celdas(matriz_minas, y, x, ventana, renderer, par.dimension);
                            obtener_fecha(&f);
                            fprintf(log, "(%02d/%02d/%4d %02d:%02d:%02d): click izquierdo en (%d, %d)\n", f.dia, f.mes, f.anio, f.h, f.m, f.s, y, x);
                        }
                        if(verificar_derrota(matriz_minas, par.dimension))
                        {
                            juego_terminado = true;
                            obtener_fecha(&f);
                            fprintf(log, "(%02d/%02d/%4d %02d:%02d:%02d): Fin de juego - Partida perdida\n", f.dia, f.mes, f.anio, f.h, f.m, f.s);

                            fprintf(stats, "jugador:%s|tiempo:%d|resultado:perdio\n", par.usuario, segundos);
                            cant_partidas++;

                            mostrar_pantalla_final(fuente_resultado, "PERDISTE", R);
                        }
                    }
                    else if (boton == SDL_BUTTON_RIGHT)
                    {
                        int bandera2 = des_asig_bandera(matriz_minas, y, x);

                        if(bandera2 == 0){
                            dibujar(ventana, renderer, bandera, x, y);
                            obtener_fecha(&f);
                            banderas_colocadas--;
                            fprintf(log, "(%02d/%02d/%4d %02d:%02d:%02d): click derecho en (%d, %d)\n", f.dia, f.mes, f.anio, f.h, f.m, f.s, y, x);
                        }
                        else if(bandera2 ==1){
                            dibujar(ventana, renderer, casilla, x, y);
                            obtener_fecha(&f);
                            banderas_colocadas++;
                            fprintf(log, "(%02d/%02d/%4d %02d:%02d:%02d): click derecho en (%d, %d)\n", f.dia, f.mes, f.anio, f.h, f.m, f.s, y, x);
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
                        segundos=0;
                        banderas_colocadas=valor_de_las_minas(&par);
                    }
                }
            }
        }
        SDL_Delay(100);  // Esta pausa es para evitar que el procesador se ponga al 100% renderizando constantemente.
    }

    liberar_matriz(matriz_minas, par.dimension);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    TTF_CloseFont(fuente_resultado);
    TTF_CloseFont(fuente_inicio);
    TTF_CloseFont(fuente_digital);

    fclose(log);
    return PANTALLA_MENU;
}

int guardar_partida(t_celda **mat, t_parametria* param, int tiempo){
    FILE *partida;

    partida = fopen("partida.bin", "wb");

    if(!partida){
        return 1;
    }

    //Escribo parametros ingresados en partida
    fwrite(param, sizeof(t_parametria), 1, partida);

    for(int i=0;i<param->dimension;i++)
    {
        for(int j=0;j<param->dimension;j++)
        {
            fwrite(&mat[i][j], sizeof(t_celda), 1, partida);
        }
    }

    return TODO_OK;
}

Estado retomar_juego()
{
    TTF_Font* fuente_resultado = TTF_OpenFont("WorkSans-VariableFont_wght.ttf", 36);
    TTF_Font* fuente_inicio = TTF_OpenFont("BebasNeue-Regular.ttf", 26);
    t_parametria par;
    t_fecha f;
    FILE *log, *stats, *partida;
    char contenido_stats[10][50], linea[50];
    int i=0, cant_partidas = 0;

    log = fopen("buscaminas.log", "wt");
    if(!log){
        return 1;
    }

    stats = fopen("buscaminas.stats", "rt");
    if(!stats){
        fclose(log);
        return 1;
    }

    while (fgets(&contenido_stats[i][0], sizeof(linea), stats) && i!=10){
        i++;
    }
    fclose(stats);

    stats = fopen("buscaminas.stats", "w");
    if(!stats){
        fclose(log);
        return 1;
    }

    //
    partida = fopen("partida.bin", "rb");
    if(!partida){
        fclose(log);
        fclose(stats);
        return 1;
    }
    fread(&par, sizeof(t_parametria), 1, partida);

    if(leer_archivo(&par)==ERROR_ARCH)
    {
        fclose(log);
        TTF_CloseFont(fuente_resultado);
        TTF_CloseFont(fuente_inicio);
        TTF_Quit();
        return 1;
    }

    int ancho_ventana = par.dimension*TAM_PIXEL*PIXELES_X_LADO + par.dimension*PX_PADDING;

    // Inicialización del temporizador
    Uint32 tiempo_ultimo_segundo = SDL_GetTicks();
    int segundos = 0;

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
    int banderas_colocadas = valor_de_las_minas(&par);
    int padding = 10;
    char texto_tiempo[32];
    char texto_banderas[32];

    TTF_Font* fuente_digital = TTF_OpenFont("fnt/DS-DIGI.TTF", calcular_tamano_fuente(par.dimension));

    SDL_Rect boton_reinicio = {ancho_ventana/2 - ANCHO_BOTON_REINICIO/2, (ENCABEZADO - ALTO_BOTON_REINICIO)/2, ANCHO_BOTON_REINICIO, ALTO_BOTON_REINICIO};

    dibujar_encabezado(renderer, ancho_ventana, boton_reinicio);
    dibujar_campo(ventana, renderer, casilla, par.dimension);

    t_celda** matriz_minas = crear_matriz(par.dimension);

    //colocar_minas(matriz_minas, &par);

    for(int i=0;i<par.dimension; i++)
    {
        for(int j=0;j<par.dimension; j++)
        {
            fread(&matriz_minas[i][j], sizeof(t_celda), 1, partida);
            printf("%d ", matriz_minas[i][j].con_mina);
        }
        printf("\n");
    }

    mostrar_matriz_minas(matriz_minas, par.dimension);
    printf("\n");
    mostrar_matriz_minas_ady(matriz_minas, par.dimension);

    obtener_fecha(&f);
    fprintf(log, "(%02d/%02d/%4d %02d:%02d:%02d): Retoma partida\n", f.dia, f.mes, f.anio, f.h, f.m, f.s);

    while (corriendo)
    {
        // Controlar si pasó un segundo para actualizar el temporizador
        Uint32 tiempo_actual = SDL_GetTicks();
        if (tiempo_actual - tiempo_ultimo_segundo >= 1000 && juego_terminado!=1) {
            segundos++;
            tiempo_ultimo_segundo = tiempo_actual;
        }
        // Redibujar encabezado y contadores
        dibujar_encabezado(renderer, ancho_ventana,boton_reinicio);
        sprintf(texto_banderas, "%03d", banderas_colocadas);
        mostrar_texto(renderer, fuente_digital, texto_banderas, padding, padding, 0);
        sprintf(texto_tiempo, "%03d", segundos);
        mostrar_texto(renderer, fuente_digital, texto_tiempo, ancho_ventana - padding, padding, 1);

        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                corriendo = 0;
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(ventana);
                return PANTALLA_SALIR;
                printf("Saliendo de SDL\n");
            }

            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
            {
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(ventana);
                for(int j=0; j<i; j++){
                    sprintf(linea,"%s", &contenido_stats[j][0]);
                    fprintf(stats,"%s", linea);
                }

                if(juego_terminado !=0){
                    guardar_partida(matriz_minas, &par, segundos);
                }

                fclose(stats);
                return PANTALLA_MENU;  // Volver al menú
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
                obtener_fecha(&f);
                fprintf(log, "(%02d/%02d/%4d %02d:%02d:%02d): Fin de juego - Partida ganada\n", f.dia, f.mes, f.anio, f.h, f.m, f.s);

                fprintf(stats, "jugador:%s|tiempo:%d|resultado:gano\n", par.usuario, segundos);
                cant_partidas++;

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
                        if(matriz_minas[y][x].revelada && matriz_minas[y][x].minas_cercanas != 0 && (!matriz_minas[y][x].con_mina))
                        {
                            revelar_cercanas(matriz_minas, y, x, ventana, renderer, par.dimension);
                            obtener_fecha(&f);
                            fprintf(log, "(%02d/%02d/%4d %02d:%02d:%02d): click izquierdo en (%d, %d)\n", f.dia, f.mes, f.anio, f.h, f.m, f.s, y, x);
                        }
                        else
                        {
                            revelar_celdas(matriz_minas, y, x, ventana, renderer, par.dimension);
                            obtener_fecha(&f);
                            fprintf(log, "(%02d/%02d/%4d %02d:%02d:%02d): click izquierdo en (%d, %d)\n", f.dia, f.mes, f.anio, f.h, f.m, f.s, y, x);
                        }
                        if(verificar_derrota(matriz_minas, par.dimension))
                        {
                            juego_terminado = true;
                            obtener_fecha(&f);
                            fprintf(log, "(%02d/%02d/%4d %02d:%02d:%02d): Fin de juego - Partida perdida\n", f.dia, f.mes, f.anio, f.h, f.m, f.s);

                            fprintf(stats, "jugador:%s|tiempo:%d|resultado:perdio\n", par.usuario, segundos);
                            cant_partidas++;

                            mostrar_pantalla_final(fuente_resultado, "PERDISTE", R);
                        }
                    }
                    else if (boton == SDL_BUTTON_RIGHT)
                    {
                        int bandera2 = des_asig_bandera(matriz_minas, y, x);

                        if(bandera2 == 0){
                            dibujar(ventana, renderer, bandera, x, y);
                            obtener_fecha(&f);
                            banderas_colocadas--;
                            fprintf(log, "(%02d/%02d/%4d %02d:%02d:%02d): click derecho en (%d, %d)\n", f.dia, f.mes, f.anio, f.h, f.m, f.s, y, x);
                        }
                        else if(bandera2 ==1){
                            dibujar(ventana, renderer, casilla, x, y);
                            obtener_fecha(&f);
                            banderas_colocadas++;
                            fprintf(log, "(%02d/%02d/%4d %02d:%02d:%02d): click derecho en (%d, %d)\n", f.dia, f.mes, f.anio, f.h, f.m, f.s, y, x);
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
                        segundos=0;
                        banderas_colocadas=valor_de_las_minas(&par);
                    }
                }
            }
        }
        SDL_Delay(100);  // Esta pausa es para evitar que el procesador se ponga al 100% renderizando constantemente.
    }

    liberar_matriz(matriz_minas, par.dimension);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    TTF_CloseFont(fuente_resultado);
    TTF_CloseFont(fuente_inicio);
    TTF_CloseFont(fuente_digital);

    fclose(log);
    return PANTALLA_MENU;
}
