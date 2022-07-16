#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
void pause();

int main ( int argc, char** argv )
{
    SDL_Surface *lignes[766]={NULL};
    SDL_Rect position;
    int i;
    if(SDL_Init(SDL_INIT_VIDEO)==-1)
    {
        fprintf(stderr, "Errer d'initialisation : %s \n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_Surface *ecran=NULL;
    ecran=SDL_SetVideoMode(766, 440, 32, SDL_HWSURFACE);
    if(ecran==NULL)
    {
        fprintf(stderr, "\nImpossible de charger le mode video : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("Mon drapeau", NULL);

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

    for(i=0; i<766; i++)
    {
        lignes[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, 1, 440, 32, 0, 0, 0, 0);
    }
    for(i=0; i<=255;i++)
    {
        position.x=i;
        position.y=0;

        SDL_FillRect(lignes[i], NULL, SDL_MapRGB(ecran->format, i, i, 255));

        SDL_BlitSurface(lignes[i], NULL, ecran, &position);
    }

for(i=0; i<=255;i++)
    {
        position.x=255+i;
        position.y=0;

        SDL_FillRect(lignes[255 + i], NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        SDL_BlitSurface(lignes[255 + i], NULL, ecran, &position);
    }
    for(i=0; i<=255;i++)
    {
        position.x=510+i;
        position.y=0;

        SDL_FillRect(lignes[510 + i], NULL, SDL_MapRGB(ecran->format, 255, 255-i, 255-i));

        SDL_BlitSurface(lignes[510 + i], NULL, ecran, &position);
    }



    SDL_Flip(ecran);
    pause();
    for(i=0; i<766; i++)
    {
    SDL_FreeSurface(lignes[i]);
    }
    SDL_Quit();
    return EXIT_SUCCESS;
}

void pause()
{
    int continuer=1;
    SDL_Event event;

    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;

        }

    }
}
