#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constantes.h"
#include "fichiers.h"
#include "editeur.h"

void editeur(SDL_Surface *ecran, long level)
{
    SDL_Surface *mur = NULL, *caisse = NULL, *caisse_OK = NULL, *objectif = NULL,
    *mario = NULL, *objetChoisi = NULL;//BESOIN QUE D'UN SEUL SPRITE POUR POSITION DE DEPART DE MARIO
    SDL_Rect position, posObjet;
    SDL_Event event;
    int carte[NB_BLOCS_HAUTEUR][NB_BLOCS_LARGEUR] = {0};
    int i = 0, j = 0, objetActuel = 0, continuer = 1, clicGaucheEnCours = 0,
    clicDroitEnCours = 0, unSeulMario = 0;
    int *ancienMario = NULL;
    //CHARGEMENT DES OBJETS ET DU NIVEAU
    mur = IMG_Load("mur.jpg");
    caisse = IMG_Load("caisse.jpg");
    caisse_OK = IMG_Load("caisse_OK.jpg");
    objectif = IMG_Load("objectif.png");
    mario = IMG_Load("mario_bas.gif");

    if(!chargerNiveau(carte, level))
        exit(EXIT_FAILURE);

    objetActuel = MUR;
    objetChoisi = mur;

    for(i=0; i<NB_BLOCS_HAUTEUR; i++)
    {
        for(j=0; j<NB_BLOCS_LARGEUR; j++)
        {
            switch(carte[i][j])
            {
                case MARIO:
                    carte[i][j] = VIDE;
                    break;
            }
        }
    }

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
                    case SDLK_c:
                        chargerNiveau(carte, level);
                        break;
                    case SDLK_s:
                        sauvegarderNiveau(carte, level);
                        break;
                    case SDLK_1:
                        objetActuel = MUR;
                        objetChoisi = mur;
                        break;
                    case SDLK_2:
                        objetActuel = CAISSE;
                        objetChoisi = caisse;
                        break;
                    case SDLK_3:
                        objetActuel = CAISSE_OK;
                        objetChoisi = caisse_OK;
                        break;
                    case SDLK_4:
                        objetActuel = OBJECTIF;
                        objetChoisi = objectif;
                        break;
                    case SDLK_5:
                        objetActuel = MARIO;
                        objetChoisi = mario;
                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button == SDL_BUTTON_LEFT)
                {//JE METS L'OBJET ACTUELLEMENT CHOISI A L'ENDROIT DU CLIC
                    if(carte[event.button.y/TAILLE_BLOC][event.button.x / TAILLE_BLOC] == VIDE)
                    {
                        carte[event.button.y/TAILLE_BLOC][event.button.x / TAILLE_BLOC] = objetActuel;
                        if(objetActuel == MARIO)
                        {
                            unSeulMario++;
                            if(unSeulMario >1)
                                carte[event.button.y/TAILLE_BLOC][event.button.x / TAILLE_BLOC] = VIDE;
                        }
                    }
                        clicGaucheEnCours = 1;// ON RETIENT QU'UN BOUTON EST ENFONCE

                }
                else if(event.button.button == SDL_BUTTON_RIGHT)
                {
                    if(carte[event.motion.y / TAILLE_BLOC][event.motion.x / TAILLE_BLOC] == MARIO)
                        unSeulMario = 0;
                    carte[event.button.y / TAILLE_BLOC][event.button.x / TAILLE_BLOC] = VIDE;
                    clicDroitEnCours = 1;
                }
                break;
            case SDL_MOUSEMOTION:
                if(event.motion.x <= LARGEUR_FENETRE - objetChoisi->w / 2)
                    posObjet.x = event.motion.x - objetChoisi->w / 2;
                if(event.motion.y <= HAUTEUR_FENETRE - objetChoisi->h / 2)
                    posObjet.y = event.motion.y - objetChoisi->h / 2;
                if(objetActuel != MARIO)
                {
                    if(clicGaucheEnCours)
                    {
                            carte[event.motion.y / TAILLE_BLOC][event.motion.x / TAILLE_BLOC] = objetActuel;
                    }
                }
                if(clicDroitEnCours)
                    carte[event.motion.y / TAILLE_BLOC][event.motion.x / TAILLE_BLOC] = VIDE;
                break;
            case SDL_MOUSEBUTTONUP:
                if(event.button.button == SDL_BUTTON_LEFT)
                    clicGaucheEnCours = 0;
                if(event.button.button == SDL_BUTTON_RIGHT)
                    clicDroitEnCours = 0;
                break;
        }
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        for(i=0; i<NB_BLOCS_HAUTEUR; i++)
        {
            for(j=0; j<NB_BLOCS_LARGEUR;j++)
            {
                position.x = j*TAILLE_BLOC;
                position.y = i*TAILLE_BLOC;
                switch(carte[i][j])
                {
                    case MUR:
                        SDL_BlitSurface(mur, NULL, ecran, &position);
                        break;
                    case CAISSE:
                        SDL_BlitSurface(caisse, NULL, ecran, &position);
                        break;
                    case CAISSE_OK:
                        SDL_BlitSurface(caisse_OK, NULL, ecran, &position);
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

    SDL_BlitSurface(objetChoisi, NULL, ecran, &posObjet);
    SDL_Flip(ecran);
    }

    SDL_FreeSurface(mur);
    SDL_FreeSurface(caisse);
    SDL_FreeSurface(caisse_OK);
    SDL_FreeSurface(mario);
    SDL_FreeSurface(objectif);
    SDL_FreeSurface(objetChoisi);
}
