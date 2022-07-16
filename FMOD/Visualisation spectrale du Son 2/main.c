#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <fmod/fmod.h>
#include <fmod/fmod_common.h>
#include <fmod/fmod_errors.h>

void setPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL;  // !!!!!! * devant spectrum!!!
    SDL_Event event;
    SDL_Rect position;

    int continuer = 1, i, j, tempsActuel = 0, tempsPrecedent = 0, channel, bin, couleur = 0;
    float spectres[512] = {0};
    float volume = 1.0;


    FMOD_SYSTEM *system;
    FMOD_System_Create(&system);
    FMOD_System_Init(system, 32, FMOD_INIT_NORMAL, 0);

    FMOD_SOUND *musique;
    FMOD_RESULT resultat;
    resultat = FMOD_System_CreateSound(system, "wish_you_were_here.mp3", FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0, &musique);
    if(resultat != FMOD_OK)
    {
        fprintf(stderr, "Impossible de lire le fichier audio");
        exit(EXIT_FAILURE);
    }
    FMOD_CHANNEL *canal;
    FMOD_System_GetChannel(system, 9, &canal); // !!!!!!!
    FMOD_System_PlaySound(system, musique, 0, 0, &canal);

    /* CODE POURRI QUI MARCHE PAS
    FMOD_DSP *fftdsp;
    FMOD_Channel_RemoveDSP(canal, fftdsp);
    FMOD_Channel_AddDSP(canal, FMOD_DSP_PARAMETER_DATA_TYPE_FFT, fftdsp);
    FMOD_DSP_PARAMETER_FFT *fft;
    FMOD_DSP_GetParameterData(fftdsp, FMOD_DSP_FFT_SPECTRUMDATA, &fft, 512, 0, 0);
    */

    /*NULL;
    valeur = malloc(512 * sizeof(float));
    */


    FMOD_Sound_SetLoopCount(musique, -1);


    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(512, 500, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Visualisation spectrale du son", NULL);
    tempsActuel = SDL_GetTicks();

    SDL_ShowCursor(SDL_DISABLE);
    while(continuer)
    {
        SDL_PollEvent(&event); // !!!!!!!!!!!!!!!!!!
        //FMOD_System_Update(system);
        FMOD_Channel_SetVolume(canal, volume); // !!!!!!!!!!!!!!!!!
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                FMOD_Channel_Stop(canal);
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_p)
                {
                    FMOD_BOOL etat;
                    FMOD_Channel_GetPaused(canal, &etat);
                    if(etat == 1)
                        FMOD_Channel_SetPaused(canal, 0);
                    else
                        FMOD_Channel_SetPaused(canal, 1);
                }
                break;
        }
        tempsActuel = SDL_GetTicks();

        /*
        if(tempsActuel - tempsPrecedent < 25)
        {
             SDL_Delay(25 - (tempsActuel - tempsPrecedent));
        }
        tempsPrecedent = SDL_GetTicks();
        */
            /* CODE POURRI
             for (channel = 0; channel < 2; channel++)
            {
                for (bin = 0;bin < fft->length;bin++)
                {
                    for(i = 0; i<512; i++)
                    {
                        spectres[i] = fft->spectrum[channel][bin]; //la valeur d'une "barre" du spectre
                    }
                }

            }
            */



        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

        SDL_LockSurface(ecran);
        for(i=0; i<512; i++)
        {
            for(j=0; j<500; j++)
            {
                couleur = j;
                setPixel(ecran, i, j, SDL_MapRGB(ecran->format, 255, (255 * couleur)/ 500, 255));
            }
        }
        SDL_UnlockSurface(ecran);

        SDL_Flip(ecran);
        }

    SDL_Quit();
    FMOD_Sound_Release(musique);
    FMOD_System_Close(system);
    FMOD_System_Release(system);
    return 0;
}

void setPixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;

    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
}
