#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constantes.h"
#include "jeu.h"
#include "editeur.h"
#include "instructions.h"
#include "fichiers.h"

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *menu = NULL;
    SDL_Event event;
    SDL_Rect positionMenu;

    positionMenu.x=0;
    positionMenu.y=0;

    int continuer=1, gagne = 0;
    long level = 0;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetIcon(IMG_Load("caisse.jpg"), NULL);

    ecran=SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE || SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Mario Sokoban", NULL);

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    menu=IMG_Load("menu.jpg");

    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                    case SDLK_1:
                        jouer(ecran);
                        break;
                    case SDLK_2:
                        level = howEdit(ecran);
                        editeur(ecran, level);
                        break;
                    case SDLK_3:
                        howPlay(ecran);
                        break;
                }
                break;
        }
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
        SDL_Flip(ecran);
    }

    SDL_FreeSurface(menu);
    SDL_Quit();
    return EXIT_SUCCESS;
}
