#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <fmod/fmod.h>
#include <fmod/fmod_common.h>
#include "fonctions.h"


Uint32 obtenirFrequences(Uint32 interval, void* param)
{
    CanalEtSpectres *structure = param;
    FMOD_Channel_GetSpectrum(structure->canal, structure->spectres, 512, 0, FMOD_DSP_FFT_WINDOW_RECT);
    return interval;
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
