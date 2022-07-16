#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constantes.h"
#include "instructions.h"

void howPlay(SDL_Surface *ecran)
{
    SDL_Surface *modeEmploi = NULL;
    SDL_Rect position;
    SDL_Event event;
    int continuer = 1;

    modeEmploi = IMG_Load("howPlay.jpg");


    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_KEYDOWN:
                continuer = 0;
                break;
        }
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    position.x = LARGEUR_FENETRE / 2 - modeEmploi->w / 2;
    position.y = HAUTEUR_FENETRE / 2 - modeEmploi->h / 2;
    SDL_BlitSurface(modeEmploi, NULL, ecran, &position);
    SDL_Flip(ecran);
    }
    SDL_FreeSurface(modeEmploi);
}

long howEdit(SDL_Surface *ecran)
{
    long level = 0;
    SDL_Surface *modeEmploi = NULL;
    SDL_Rect pos;
    SDL_Event event;

    int continuer = 1;

    modeEmploi = IMG_Load("howEdit.jpg");


    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        level = 0;
                        continuer = 0;
                        break;
                    case SDLK_2:
                        level = 1;
                        continuer = 0;
                        break;
                    case SDLK_3:
                        level = 2;
                        continuer = 0;
                        break;
                }
                break;
        }
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    pos.x = LARGEUR_FENETRE / 2 - modeEmploi->w / 2;
    pos.y = HAUTEUR_FENETRE / 2 - modeEmploi->h / 2;
    SDL_BlitSurface(modeEmploi, NULL, ecran, &pos);
    SDL_Flip(ecran);
    }
    SDL_FreeSurface(modeEmploi);
    return level;
}
