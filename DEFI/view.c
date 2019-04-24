#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "header.h"
//SHOWIMAGE
/*
Sert à charger et convertir une image en texture
*/
void showimage(game* myGame,char* path)
{
    SDL_Rect r;
    SDL_Surface *image =NULL ;
// Chargement de l'image
    image = IMG_Load(path) ;
// Gestion des erreurs au niveau du chargement de l'image
    if (!image)
    {
        printf("IMG_Load : %s\n", IMG_GetError()) ;
    }
// Conversion de l'image en texture
    myGame->texture = SDL_CreateTextureFromSurface(myGame->renderer,image) ;
    SDL_FreeSurface(image) ;
    image = NULL ;
// Règle le rectangle à dessiner selon la taille de l'image source
    r.x = 0 ;
    r.y = 0 ;
// Dessine l'image entiere sur l'écran aux coordonnées x et y
    SDL_QueryTexture(myGame->texture,NULL,NULL,&r.w,&r.h) ;
    SDL_RenderCopy(myGame->renderer,myGame->texture,NULL,&r) ;
}
//SHOWTEXT
/*
Sert à afficher du texte en le transformant en texture
*/
void ShowText(TTF_Font* mFont,char* text,game* myGame,int x,int y,SDL_Color fontColor,int nFontSize)
{
    SDL_Rect r;
    mFont=TTF_OpenFont("./fonts/redlightredheat.ttf",nFontSize);
    if(!mFont) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    myGame->surface=TTF_RenderUTF8_Blended(mFont, text, fontColor);
    //
    if (myGame->surface != NULL)
    {
//ON MODIFIE LE CODE POUR PROFITER DE LA MEMOIRE GRAPHIQUE QUI GERE LES TEXTURES
// Conversion de la chaine en texture
        myGame->texture = SDL_CreateTextureFromSurface(myGame->renderer,myGame->surface) ;
// On se debarasse du pointeur vers une surface
// On libere la SDL_Surface temporaire (pour eviter les fuites de mémoires)
    SDL_FreeSurface(myGame->surface) ;
    myGame->surface = NULL ;
// On dessine cette texture a l'ecran
    r.x = x ; //POSITION DU TEXTE
    r.y = y ;
    SDL_QueryTexture(myGame->texture,NULL,NULL,&r.w,&r.h) ;
    SDL_RenderCopy(myGame->renderer,myGame->texture,NULL,&r) ;
    }
    else
    {
        printf("La chaine n'a pas pu être écrite : %s\n",TTF_GetError()) ;
    }
// Affichage
    //SDL_RenderPresent(myGame->renderer) ;
}

//UPDATEDIALOG
/*
Sert à déterminer où le joueur en est dans le dialogue et lui afficher la ligne en conséquence.
*/
void updatedialog(game *myGame,TTF_Font* mFont,SDL_Color fontcolor,int* canProgress)
{
    SDL_RenderClear(myGame->renderer);
    switch (myGame->nDialog)
    {
        case 1:showimage(myGame,"./assets/carnight.png");
        ShowText(mFont,"J'avais bien besoin de ca !",myGame,50,480,fontcolor,20);
        break;

        case 2:showimage(myGame,"./assets/carnight.png");
        ShowText(mFont,"Voyons voir s'il y a quelque chose dans le coffre.",myGame,50,480,fontcolor,20);
        break;

        case 3:showimage(myGame,"./assets/carnight.png");
        *canProgress=0;
        break;

        case 4:showimage(myGame,"./assets/trunk.png");
        break;

        case 5:showimage(myGame,"./assets/trunk.png");
        ShowText(mFont,"Stupide voiture de location, y'a aucun outil avec !",myGame,50,480,fontcolor,20);
        break;

        case 6:showimage(myGame,"./assets/trunk.png");
        ShowText(mFont,"Bon, je n'arriverai a rien en restant la.",myGame,50,480,fontcolor,20);
        break;

    }
    if (*canProgress==1){ShowText(mFont,"SUIVANT",myGame,650,600,fontcolor,20);}
    SDL_RenderPresent(myGame->renderer) ;
}
