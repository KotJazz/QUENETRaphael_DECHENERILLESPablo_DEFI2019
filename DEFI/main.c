#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "header.h"

int main(int argc, char* argv[])
{
    //JEU
    game myGame;
    //ETAT DU CLAVIER
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    //POLICE
    TTF_Font *mFont=NULL;
    //TEXTE
    char* text="Appuyez sur entree pour commencer";
    init("DEFI",HEIGHT,WIDTH,&myGame,mFont);
    SDL_Color fontColor={254,254,254};
    ShowText(mFont,TITLE,&myGame,230,HEIGHT/3,fontColor,75);
    ShowText(mFont,text,&myGame,330,HEIGHT/2,fontColor,14);
    SDL_RenderPresent(myGame.renderer) ;
    mainloop(state,&myGame,mFont,fontColor);
    return 0;
}
