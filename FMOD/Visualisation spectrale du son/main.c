#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <fmod/fmod.h>
#include <fmod/fmod_common.h>
#include "fonctions.h"
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *spectrum[512] = {NULL}; // !!!!!! * devant spectrum!!!
    SDL_Event event;
    SDL_Rect position;
    SDL_TimerID timer;
    int continuer = 0, i, j;
    CanalEtSpectres structure;
    float volume = 1.0;


    FMOD_SYSTEM *system;
    FMOD_System_Create(&system);
    FMOD_System_Init(system, 32, FMOD_INIT_NORMAL, 0);

    FMOD_SOUND *musique;
    FMOD_RESULT resultat, resSpectres;
    resultat = FMOD_System_CreateSound(system, "wish_you_were_here.mp3", FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0, &musique);
    if(resultat != FMOD_OK)
    {
        fprintf(stderr, "Impossible de lire le fichier audio");
        exit(EXIT_FAILURE);
    }
    FMOD_System_GetChannel(musique, 9, &structure.canal); // !!!!!!!
    FMOD_System_PlaySound(system, musique, 0, 0, &structure.canal);
    FMOD_Sound_SetLoopCount(musique, -1);
    resSpectres = FMOD_Channel_GetSpectrum(structure->canal, structure->spectres, 512, 0, FMOD_DSP_FFT_WINDOW_RECT);

    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(512, 500, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Visualisation spectrale du son", NULL);
    for(i=0; i<512; i++)
    {
        spectrum[i]=SDL_CreateRGBSurface(SDL_HWSURFACE, 1, 500, 32, 0, 0, 0, 0);
    }
    timer = SDL_AddTimer(25, obtenirFrequences, &structure);

    SDL_ShowCursor(SDL_DISABLE);
    while(continuer)
    {
        SDL_WaitEvent(&event);

        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                FMOD_Channel_Stop(structure.canal);
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_p)
                {
                    FMOD_BOOL etat;
                    FMOD_Channel_GetPaused(structure.canal, &etat);
                    if(etat == 1)
                        FMOD_Channel_SetPaused(structure.canal, 0);
                    else
                        FMOD_Channel_SetPaused(structure.canal, 1);
                }
                break;
        }


        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        for(i=0; i<512; i++)
        {
            for(j=500; j<0; j--)
            {
                if(structure.spectres[i]<(500 - j)/500)
                {
                    SDL_LockSurface(ecran);
                    setPixel(ecran, i, j, SDL_MapRGB(ecran->format, (500-j)/500 * 255,(j/500)*255,0));
                    SDL_UnlockSurface(ecran);
                }
            }
        }
        SDL_Flip(ecran);
        }
    for(i=0; i<512; i++)
    {
        SDL_FreeSurface(spectrum[i]);
    }
    SDL_Quit();
    FMOD_Sound_Release(musique);
    FMOD_System_Close(system);
    FMOD_System_Release(system);
    return 0;
}


