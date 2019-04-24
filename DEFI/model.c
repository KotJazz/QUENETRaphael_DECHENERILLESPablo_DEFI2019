#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "header.h"

//INIT
/*
Initialise la SDL.
*/
int init(char *title,int height, int width,game *myGame, TTF_Font* mFont)
{
    if( SDL_Init( SDL_INIT_VIDEO ) != 0 )
    {
        printf("Impossible d'initialiser la SDL ! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
    else
    {
        myGame->window = SDL_CreateWindow( title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
        if (myGame->window == NULL)
        {
            printf( "La fenetre n'a pas pu etre creee ! SDL_Error: %s\n", SDL_GetError() );
            return 0;
        }
        else
        {
            myGame->surface = SDL_GetWindowSurface( myGame->window );
            SDL_FillRect( myGame->surface, NULL, SDL_MapRGB( myGame->surface->format, 0, 0, 0 ) );
            SDL_UpdateWindowSurface( myGame->window );
        }
    }
    // On crée un renderer pour la SDL et on active la synchro verticale : VSYNC
    myGame->renderer = SDL_CreateRenderer(myGame->window,
                                  -1,
                                  SDL_RENDERER_PRESENTVSYNC) ;
    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    mFont=TTF_OpenFont("./fonts/redlightredheat.ttf",14);
    if(!mFont) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    return 0;
}
//DESTROYFONT
/*
Détruit une police
*/
void destroyFont(TTF_Font*mFont){
    if(mFont!=NULL){
        TTF_CloseFont(mFont);
        mFont=NULL;
    }

}
//DESTROYTEXTURE
/*
Détruit une texture
*/
void destroyTexture(game *myGame){

    //Destroy texture
    if(myGame!=NULL)
            SDL_DestroyTexture(myGame->texture);
}
