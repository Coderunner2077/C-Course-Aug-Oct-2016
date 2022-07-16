#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constantes.h"
#include "editeur.h"
#include "fichiers.h"

void editeur(SDL_Surface* ecran)
{
    SDL_Surface *mur=NULL, *caisse=NULL, *mario=NULL, *objectif=NULL; //BESOIN QUE D'UN SEUL SPRITE POUR POSITION DE DEPART DE MARIO
    SDL_Rect position;
    SDL_Event event;

    int continuer=1, clicDroitEnCours=0, clicGaucheEnCours=0;
    int objetActuel=MUR, i=0, j=0;
    int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR]={0};
    //CHARGEMENT DES OBJETS ET DU NIVEAU
    mur=IMG_Load("images/mur.jpg");
    caisse=IMG_Load("images/caisse.jpg");
    objectif=IMG_Load("images/objectif.png");
    mario=IMG_Load("images/mario_bas.gif");
    if(!chargerNiveau(carte))
    {
        fprintf(stderr,"Impossible de charger le niveau (a partir de editeur.c) : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer=0;//NUL, A AMELIORER
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button == SDL_BUTTON_LEFT)
                {   //JE METS L'OBJET ACTUELLEMENT CHOISI A L'ENDROIT DU CLIC
                    carte[event.button.x / TAILLE_BLOC][event.button.y / TAILLE_BLOC] = objetActuel;
                    clicGaucheEnCours=1;// ON RETIENT QU'UN BOUTON EST ENFONCE
                }
                else if(event.button.button == SDL_BUTTON_RIGHT)
                {
                    carte[event.button.x / TAILLE_BLOC][event.button.y / TAILLE_BLOC] = VIDE;
                    clicDroitEnCours=1;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                if(event.button.button == SDL_BUTTON_LEFT)
                    clicGaucheEnCours = 0;
                else if(event.button.button == SDL_BUTTON_RIGHT)
                    clicDroitEnCours = 0;
                break;
            case SDL_MOUSEMOTION:
                if(clicGaucheEnCours)
                    carte[event.motion.x / TAILLE_BLOC][event.motion.y / TAILLE_BLOC] = objetActuel;
                if(clicDroitEnCours)
                    carte[event.motion.x / TAILLE_BLOC][event.motion.y / TAILLE_BLOC] = VIDE;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                    case SDLK_s:
                        sauvegarderNiveau(carte);
                        break;
                    case SDLK_c:
                        chargerNiveau(carte);
                        break;
                    case SDLK_1:
                        objetActuel=MUR;
                        break;
                    case SDLK_2:
                        objetActuel=CAISSE;
                        break;
                    case SDLK_3:
                        objetActuel = OBJECTIF;
                        break;
                    case SDLK_4:
                        objetActuel = MARIO;
                        break;
                }
                break;
        }

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        for(i=0; i < NB_BLOCS_LARGEUR; i++)
        {
            for(j=0; j < NB_BLOCS_HAUTEUR; j++)
            {
                position.x = i * TAILLE_BLOC;
                position.y = j * TAILLE_BLOC;

                switch(carte[i][j])
                {
                    case MUR:
                        SDL_BlitSurface(mur, NULL, ecran, &position);
                        break;
                    case CAISSE:
                        SDL_BlitSurface(caisse, NULL, ecran, &position);
                        break;
                    case OBJECTIF:
                        SDL_BlitSurface(objectif, NULL, ecran, &position);
                        break;
                    case MARIO:
                        SDL_BlitSurface(mario, NULL, ecran, &position);
                        break;
                }
            }
        }
    SDL_Flip(ecran);
    }

    SDL_FreeSurface(mur);
    SDL_FreeSurface(caisse);
    SDL_FreeSurface(objectif);
    SDL_FreeSurface(mario);

}
