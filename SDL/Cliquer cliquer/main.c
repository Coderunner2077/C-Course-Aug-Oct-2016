#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "score.h"

int main(int argc, char *argv[])
{
    int recommencer = 0;
    do
    {
    SDL_Surface *ecran = NULL, *compteARebour = NULL, *compteur = NULL, *quitterOuPas = NULL, *surfaceScore = NULL,
                *surfaceBravo = NULL;
    SDL_Rect posCompteAR = {0, 0}, posCompteur = {0, 300}, posQuitter = {0, 550}, posTopScore = {400, 0}, posBravo = {0, 150};
    SDL_Event event;
    SDL_Color couleurNoire = {0, 0, 0}, couleurBleue = {0, 0, 255};
    TTF_Font *police = NULL;
    int continuer = 1, intcompteAR = 10000, nombreClics = 0, topScore = 0, gagne = 0;
    char temps[20] = {""}, clics[10] = {""}, chaineScore[20] = {""};
    Uint32 tempsActuel = 0, tempsPrecedent = 0;
    SDL_Init(SDL_INIT_VIDEO | SDL_DOUBLEBUF);
    TTF_Init();
    ecran = SDL_SetVideoMode(700, 600, 32, SDL_HWSURFACE);
    police = TTF_OpenFont("arial.ttf", 40);

    // !!! INITIALISATION DU TEMPS ET DU TEXTE
    tempsActuel = SDL_GetTicks(); // !!!!
    sprintf(temps, "Temps Restant : %d", intcompteAR);// !!!!!
    compteARebour = TTF_RenderText_Solid(police, temps, couleurNoire);
    sprintf(clics, "Nombre de clics : %d", nombreClics);
    compteur = TTF_RenderText_Solid(police, clics, couleurNoire);
    quitterOuPas = TTF_RenderText_Solid(police, "Tapez 1 pour recommencer", couleurNoire);
    topScore = lireScore();
    sprintf(chaineScore, "Top Score : %d", topScore);
    surfaceScore = TTF_RenderText_Solid(police, chaineScore, couleurNoire);
    surfaceBravo = TTF_RenderText_Solid(police, "Bravo! Vous avez battu le record!", couleurBleue);
    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                recommencer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        recommencer = 0;
                        break;
                    case SDLK_1:
                        continuer = 0;
                        recommencer = 1;
                        break;
                    case SDLK_0:
                        continuer = 0;
                        recommencer = 0;
                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button == SDL_BUTTON_LEFT && intcompteAR > 0)
                    nombreClics++;
                    SDL_FreeSurface(compteur);
                    sprintf(clics, "Nombre de clics : %d", nombreClics);
                    compteur = TTF_RenderText_Solid(police, clics, couleurNoire);
                    break;
        }
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        if(intcompteAR > 0)
        {
            tempsActuel = SDL_GetTicks();
            if(tempsActuel - tempsPrecedent > 100)
            {
                intcompteAR -=100;
                SDL_FreeSurface(compteARebour);
                sprintf(temps, "Temps Restant : %d", intcompteAR);
                compteARebour = TTF_RenderText_Solid(police, temps, couleurNoire);

                tempsPrecedent = tempsActuel;
            }
            else
                SDL_Delay(100 -(tempsActuel - tempsPrecedent));
        }
        else
        {
           SDL_BlitSurface(quitterOuPas, NULL, ecran, &posQuitter);
        }
        if(nombreClics > topScore && intcompteAR == 0)
        {
            topScore = nombreClics;
            gagne = enregistrerScore(nombreClics);
            sprintf(chaineScore, "Top Score : %d", topScore);
            SDL_FreeSurface(surfaceScore);
            surfaceScore = TTF_RenderText_Solid(police, chaineScore, couleurNoire);
        }
        if(gagne)
            SDL_BlitSurface(surfaceBravo, NULL, ecran, &posBravo);
        SDL_BlitSurface(surfaceScore, NULL, ecran, &posTopScore);
        SDL_BlitSurface(compteARebour, NULL, ecran, &posCompteAR);
        SDL_BlitSurface(compteur, NULL, ecran, &posCompteur);
        SDL_Flip(ecran);
    }
    SDL_FreeSurface(compteARebour);
    SDL_FreeSurface(compteur);
    SDL_FreeSurface(surfaceScore);
    SDL_FreeSurface(quitterOuPas);
    SDL_FreeSurface(surfaceBravo);
    TTF_CloseFont(police);


    TTF_Quit();
    SDL_Quit();
    }while(recommencer);

    return EXIT_SUCCESS;
}
