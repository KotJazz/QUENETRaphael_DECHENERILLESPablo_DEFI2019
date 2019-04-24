#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "header.h"
//MAINLOOP
/*
Boucle principale du jeu et gestion des inputs
*/
void mainloop(const Uint8 *state,game* myGame,TTF_Font* mFont,SDL_Color fontcolor)
{
    int quit = 0;
    int isinmenu = 1;
    SDL_Event eGame;
    int mouseX; //Position de la souris X
    int mouseY; //Position de la souris Y
    int canProgress=1;
    while (!quit)
    {
        SDL_WaitEvent(&eGame);
        switch (eGame.type)
        {
            case SDL_QUIT:
                quit = 1;
                puts("FERMETURE EN COURS !");
            break;
//----------------------------------------------
            case SDL_KEYDOWN: //EVENT CLAVIER
                switch (eGame.key.keysym.sym)
                {
                    case SDLK_RETURN:
                        if (isinmenu==1)//SI on est dans le menu
                        {
                            isinmenu=0;
                            myGame->nDialog=0;
                            SDL_RenderClear(myGame->renderer) ;
                            SDL_RenderPresent(myGame->renderer) ;
                            showimage(myGame,"./assets/carnight.png");
                            ShowText(mFont,"C'est donc une panne.",myGame,50,480,fontcolor,20);
                            ShowText(mFont,"SUIVANT",myGame,650,600,fontcolor,20);
                            SDL_RenderPresent(myGame->renderer) ;
                            break;
                        }
                        else if (canProgress==1)
                        {
                            myGame->nDialog++;
                            updatedialog(myGame,mFont,fontcolor,&canProgress);
                            break;
                        }
                    break;

                }
                break;
            case SDL_MOUSEBUTTONDOWN: //EVENT SOURIS
                    switch (eGame.button.button)
                        {

                            case SDL_BUTTON_LEFT: //CLIC GAUCHE
                                SDL_GetMouseState(&mouseX, &mouseY);
                                if ((mouseX>650)&&(mouseY>600)&&(mouseX<738)&&(mouseY<620)&&(canProgress==1))
                                {
                                    myGame->nDialog++;
                                    updatedialog(myGame,mFont,fontcolor,&canProgress);
                                }
                                if ((canProgress==0)&&(myGame->nDialog==3))
                                {
                                    if ((mouseX>185)&&(mouseY>460)&&(mouseX<430)&&(mouseY<520))
                                    {
                                        myGame->nDialog++;
                                        canProgress=1;
                                        updatedialog(myGame,mFont,fontcolor,&canProgress);
                                    }
                                }
                                break;

                            case SDL_BUTTON_RIGHT: //CLIC DROIT

                                SDL_GetMouseState(&mouseX, &mouseY);

                                break;

                            default:
                                SDL_GetMouseState(&mouseX, &mouseY);
                                SDL_ShowSimpleMessageBox(0, "Mouse", "Some other button was pressed!", myGame->window);

                                break;
                        }
                break;
        }
    }
}
