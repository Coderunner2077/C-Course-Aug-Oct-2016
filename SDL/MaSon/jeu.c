#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constantes.h"
#include "jeu.h"
#include "fichiers.h"
#include "instructions.h"

int jouer(SDL_Surface *ecran)
{
    long k = 0, niveau = 0, gameOver = 0;
    do
    {
    SDL_Surface *mur = NULL, *caisse = NULL, *objectif = NULL, *marioActuel = NULL, *caisse_OK = NULL;
    SDL_Surface *mario[4]={NULL};
    SDL_Event event;
    SDL_Rect position, positionJoueur;


    int continuer = 1, i = 0, j = 0, objectifsRestants = 1;
    int carte[NB_BLOCS_HAUTEUR][NB_BLOCS_LARGEUR] = {0};

    mur = IMG_Load("mur.jpg");
    caisse = IMG_Load("caisse.jpg");
    objectif = IMG_Load("objectif.png");
    caisse_OK = IMG_Load("caisse_OK.jpg");

    mario[BAS] = IMG_Load("mario_bas.gif");
    mario[HAUT] = IMG_Load("mario_haut.gif");
    mario[DROITE] = IMG_Load("mario_droite.gif");
    mario[GAUCHE] = IMG_Load("mario_gauche.gif");

    marioActuel = mario[BAS];

    if(!chargerNiveau(carte, niveau))
    {
        fprintf(stderr,"Erreur de chargement du niveau : %s", SDL_GetError());
        return 0;
    }
    for(i = 0; i < NB_BLOCS_HAUTEUR; i++)
    {
        for(j = 0; j < NB_BLOCS_LARGEUR; j++)
        {
            if(carte[i][j] == MARIO)// --> JE CHERCHE ET JE DEFINIS LA POSITION DU JOUEUR;
            {
                positionJoueur.x = j;
                positionJoueur.y = i;
                carte[i][j] = VIDE;
            }
        }
    }
    SDL_EnableKeyRepeat(100, 100); // --> J'ACTIVE LA REPETITION DES TOUCHES

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
                    case SDLK_UP:
                        marioActuel = mario[HAUT];
                        deplacerJoueur(carte, &positionJoueur, HAUT);// -->
                        break;
                    case SDLK_DOWN:
                        marioActuel = mario[BAS];
                        deplacerJoueur(carte, &positionJoueur, BAS);// -->
                        break;
                    case SDLK_LEFT:
                        marioActuel = mario[GAUCHE];
                        deplacerJoueur(carte, &positionJoueur, GAUCHE);// -->
                        break;
                    case SDLK_RIGHT:
                        marioActuel = mario[DROITE];
                        deplacerJoueur(carte, &positionJoueur, DROITE);// -->
                        break;
                }
                break;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        objectifsRestants=0;// -->
        for(i = 0; i < NB_BLOCS_HAUTEUR; i++)
        {
            for(j = 0; j < NB_BLOCS_LARGEUR; j++)
            {
                position.x = j * TAILLE_BLOC; // -->
                position.y = i * TAILLE_BLOC; // -->
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
                        objectifsRestants=1; // -->!!!
                        break;
                    case CAISSE_OK:
                        SDL_BlitSurface(caisse_OK, NULL, ecran, &position);
                        break;
                }
            }
        }
        if(!objectifsRestants) // --> !!
            continuer = 0;

        position.x = positionJoueur.x * TAILLE_BLOC;
        position.y = positionJoueur.y * TAILLE_BLOC;
        SDL_BlitSurface(marioActuel, NULL, ecran, &position);

        SDL_Flip(ecran);
    }

    SDL_EnableKeyRepeat(0, 0);
    SDL_FreeSurface(mur);
    SDL_FreeSurface(caisse);
    SDL_FreeSurface(caisse_OK);
    SDL_FreeSurface(marioActuel);
    SDL_FreeSurface(objectif);
    for(i = 0; i < 4; i++)
        SDL_FreeSurface(mario[i]);
    if(!objectifsRestants)
    {
        niveau++;
        afficherBravo(ecran);
        if(niveau > 2)
            gameOver = 1;
    }
    else
        gameOver = 1;
    }while(!gameOver);
    return 1;
}
//OBLIGATOIRE D'INDIQUER LA TAILLE DE LA SECONDE DIMENSION POUR FAIRE COMPRENDRE A LA MACHINE ==> TABLEAU 2D
void deplacerJoueur(int carte[][NB_BLOCS_LARGEUR], SDL_Rect *pos, int direction)
{
    switch(direction)
    {
        case HAUT:
            if(pos->y - 1 < 0)//LE JOUEUR EST DEJA TOUT EN HAUT DE LA CARTE
                break;// POUR SORTIR DU switch ET DONC POUR EMPECHER LE DEPLACEMENT // --> !!!!!!!! GESTION DES COLLISIONS!!
            if(carte[pos->y - 1][pos->x] == MUR)
                break;
            if((carte[pos->y - 1][pos->x] == CAISSE || carte[pos->y - 1][pos->x] == CAISSE_OK) &&(carte[pos->y - 2][pos->x] ==
                CAISSE || carte[pos->y - 2][pos->x] == CAISSE_OK || carte[pos->y - 2][pos->x] == MUR || pos->y - 2 < 0))
               break;
            deplacerCaisse(&carte[pos->y - 1][pos->x], &carte[pos->y - 2][pos->x]); // --> !!! '&' !!! // ON VERIFIE D'ABORD S'IL Y A UNE CAISE A DEPLACER
            pos->y--; // -->
            break;
        case BAS:
            if(pos->y + 1 >= NB_BLOCS_HAUTEUR)
                break;
            if(carte[pos->y + 1][pos->x] == MUR)
                break;
            if((carte[pos->y + 1][pos->x] == CAISSE || carte[pos->y + 1][pos->x] == CAISSE_OK) && (pos->y + 2 >= NB_BLOCS_HAUTEUR ||
                carte[pos->y + 2][pos->x] == MUR || carte[pos->y + 2][pos->x] == CAISSE || carte[pos->y + 2][pos->x] == CAISSE_OK))
                break;
            deplacerCaisse(&carte[pos->y + 1][pos->x], &carte[pos->y + 2][pos->x]);
            pos->y++;
            break;
        case GAUCHE:
            if(pos->x - 1 < 0)
                break;
            if(carte[pos->y][pos->x - 1] == MUR)
                break;
            if((carte[pos->y][pos->x - 1] == CAISSE || carte[pos->y][pos->x - 1] == CAISSE_OK) && (pos->x - 2 < 0 ||
                carte[pos->y][pos->x - 2] == MUR || carte[pos->y][pos->x - 2] == CAISSE || carte[pos->y][pos->x - 2] == CAISSE_OK))
                break;
            deplacerCaisse(&carte[pos->y][pos->x - 1], &carte[pos->y][pos->x - 2]);
            pos->x--;
            break;
        case DROITE:
            if(pos->x + 1 >=NB_BLOCS_LARGEUR)
                break;
            if(carte[pos->y][pos->x + 1] == MUR)
                break;
            if((carte[pos->y][pos->x + 1] == CAISSE || carte[pos->y][pos->x + 1] == CAISSE_OK) && (pos->x - 2 >= NB_BLOCS_LARGEUR
                || carte[pos->y][pos->x + 2] == MUR || carte[pos->y][pos->x + 2] == CAISSE || carte[pos->y][pos->x + 2] == CAISSE_OK))
                break;
            deplacerCaisse(&carte[pos->y][pos->x + 1], &carte[pos->y][pos->x + 2]);
            pos->x++;
            break;
    }
}

void deplacerCaisse(int *premiereCase, int *secondeCase) //--> !!!!!!!!!!
{
    if(*premiereCase == CAISSE || *premiereCase == CAISSE_OK) //--> PAS BESOIN DE TRAITER secondeCase = VIDE!!
        {
        if(*secondeCase == OBJECTIF)
            *secondeCase = CAISSE_OK;
        else
            *secondeCase = CAISSE;
        if(*premiereCase == CAISSE_OK)
            *premiereCase = OBJECTIF;
        else
            *premiereCase = VIDE;
        }
}
