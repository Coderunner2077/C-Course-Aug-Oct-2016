#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
typedef struct CanalEtSpectres CanalEtSpectres;
struct CanalEtSpectres
{
    FMOD_CHANNEL *canal;
    float spectres[512];
};
Uint32 obtenirFrequences(Uint32 interval, void* param);
void setPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);


#endif // FONCTIONS_H_INCLUDED
