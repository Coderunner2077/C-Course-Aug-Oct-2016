#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constantes.h"
#include "jeu.h"

void jouer(SDL_Surface* ecran)
{
    SDL_Surface *mario[4] = {NULL}; // 4 surfaces pour chacune des directions de mario
    SDL_Surface *mur = NULL, *caisse = NULL, *caisseOK = NULL, *objectif = NULL, *marioActuel = NULL;
    SDL_Rect position, positionJoueur;
    SDL_Event event;

    int continuer = 1, objectifsRestants = 0, i = 0, j = 0;
    int carte[NB_BLOCS_HAUTEUR][NB_BLOCS_LARGEUR] = {0};

    // Chargement des sprites (d�cors, personnage...)
    mur = IMG_Load("mur.jpg");
    caisse = IMG_Load("caisse.jpg");
    caisseOK = IMG_Load("caisse_ok.jpg");
    objectif = IMG_Load("objectif.png");
    mario[BAS] = IMG_Load("mario_bas.gif");
    mario[GAUCHE] = IMG_Load("mario_gauche.gif");
    mario[HAUT] = IMG_Load("mario_haut.gif");
    mario[DROITE] = IMG_Load("mario_droite.gif");

    marioActuel = mario[BAS]; // Mario sera dirig� vers le bas au d�part

    // Chargement du niveau
    if (!chargerNiveau(carte))
        exit(EXIT_FAILURE); // On arr�te le jeu si on n'a pas pu charger le niveau

    // Recherche de la position de Mario au d�part
    for (i = 0 ; i < NB_BLOCS_HAUTEUR ; i++)
    {
        for (j = 0 ; j < NB_BLOCS_LARGEUR ; j++)
        {
            if (carte[i][j] == MARIO) // Si Mario se trouve � cette position sur la carte
            {
                positionJoueur.x = j;
                positionJoueur.y = i;
                carte[i][j] = VIDE;
            }
        }
    }

    // Activation de la r�p�tition des touches
    SDL_EnableKeyRepeat(100, 100);

    while (continuer)
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
                deplacerJoueur(carte, &positionJoueur, HAUT);
                break;
            case SDLK_DOWN:
                marioActuel = mario[BAS];
                deplacerJoueur(carte, &positionJoueur, BAS);
                break;
            case SDLK_RIGHT:
                marioActuel = mario[DROITE];
                deplacerJoueur(carte, &positionJoueur, DROITE);
                break;
            case SDLK_LEFT:
                marioActuel = mario[GAUCHE];
                deplacerJoueur(carte, &positionJoueur, GAUCHE);
                break;
        }
        break;
}

        // Effacement de l'�cran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        // Placement des objets � l'�cran
        objectifsRestants = 0;

        for (i = 0 ; i < NB_BLOCS_HAUTEUR ; i++)
        {
            for (j = 0 ; j < NB_BLOCS_LARGEUR ; j++)
            {
                position.x = j * TAILLE_BLOC;
                position.y = i * TAILLE_BLOC;

                switch(carte[i][j])
                {
                    case MUR:
                        SDL_BlitSurface(mur, NULL, ecran, &position);
                        break;
                    case CAISSE:
                        SDL_BlitSurface(caisse, NULL, ecran, &position);
                        break;
                    case CAISSE_OK:
                        SDL_BlitSurface(caisseOK, NULL, ecran, &position);
                        break;
                    case OBJECTIF:
                        SDL_BlitSurface(objectif, NULL, ecran, &position);
                        objectifsRestants = 1;
                        break;
                }
            }
        }

        // Si on n'a trouv� aucun objectif sur la carte, c'est qu'on a gagn�
        if (!objectifsRestants)
            continuer = 0;

        // On place le joueur � la bonne position
        position.x = positionJoueur.x * TAILLE_BLOC;
        position.y = positionJoueur.y * TAILLE_BLOC;
        SDL_BlitSurface(marioActuel, NULL, ecran, &position);



        SDL_Flip(ecran);
    }

    // D�sactivation de la r�p�tition des touches (remise � 0)
    SDL_EnableKeyRepeat(0, 0);

    // Lib�ration des surfaces charg�es
    SDL_FreeSurface(mur);
    SDL_FreeSurface(caisse);
    SDL_FreeSurface(caisseOK);
    SDL_FreeSurface(objectif);
    for (i = 0 ; i < 4 ; i++)
        SDL_FreeSurface(mario[i]);
}

void deplacerJoueur(int carte[][NB_BLOCS_LARGEUR], SDL_Rect *pos, int direction)
{
    switch(direction)
    {
        case HAUT:
            if (pos->y - 1 < 0) // Si le joueur d�passe l'�cran, on arr�te
                break;
            if (carte[pos->y - 1][pos->x] == MUR) // S'il y a un mur, on arr�te
                break;
            // Si on veut pousser une caisse, il faut v�rifier qu'il n'y a pas de mur derri�re (ou une autre caisse, ou la limite du monde)
            if ((carte[pos->y -1][pos->x] == CAISSE || carte[pos->y -1][pos->x] == CAISSE_OK) &&
                (pos->y - 2 < 0 || carte[pos->y - 2][pos->x] == MUR ||
                carte[pos->y - 2][pos->x] == CAISSE || carte[pos->y - 2][pos->x] == CAISSE_OK))
                break;

            // Si on arrive l�, c'est qu'on peut d�placer le joueur !
            // On v�rifie d'abord s'il y a une caisse � d�placer
            deplacerCaisse(&carte[pos->y - 1][pos->x], &carte[pos->y - 2][pos->x]);

            pos->y--; // On peut enfin faire monter le joueur (oufff !)
            break;


        case BAS:
            if (pos->y + 1 >= NB_BLOCS_HAUTEUR)
                break;
            if (carte[pos->y + 1][pos->x] == MUR)
                break;

            if ((carte[pos->y + 1][pos->x] == CAISSE || carte[pos->y + 1][pos->x] == CAISSE_OK) &&
                (pos->y + 2 >= NB_BLOCS_HAUTEUR || carte[pos->y + 2][pos->x] == MUR ||
                carte[pos->y + 2][pos->x] == CAISSE || carte[pos->y + 2][pos->x] == CAISSE_OK))
                break;


            deplacerCaisse(&carte[pos->y + 1][pos->x], &carte[pos->y + 2][pos->x]);

            pos->y++;
            break;


        case GAUCHE:
            if (pos->x - 1 < 0)
                break;
            if (carte[pos->y][pos->x - 1] == MUR)
                break;

            if ((carte[pos->y][pos->x - 1] == CAISSE || carte[pos->y][pos->x - 1] == CAISSE_OK) &&
                (pos->x - 2 < 0 || carte[pos->y][pos->x - 2] == MUR ||
                carte[pos->y][pos->x- 2] == CAISSE || carte[pos->y][pos->x - 2] == CAISSE_OK))
                break;


            deplacerCaisse(&carte[pos->y][pos->x - 1], &carte[pos->y][pos->x - 2]);

            pos->x--;
            break;


        case DROITE:
            if (pos->x + 1 >= NB_BLOCS_LARGEUR)
                break;
            if (carte[pos->y][pos->x + 1] == MUR)
                break;

            if ((carte[pos->y][pos->x +1] == CAISSE || carte[pos->y][pos->x + 1] == CAISSE_OK) &&
                (pos->x + 2 >= NB_BLOCS_LARGEUR || carte[pos->y][pos->x + 2] == MUR ||
                carte[pos->y][pos->x + 2] == CAISSE || carte[pos->y][pos->x + 2] == CAISSE_OK))
                break;

            deplacerCaisse(&carte[pos->y][pos->x + 1], &carte[pos->y][pos->x + 2]);

            pos->x++;
            break;
    }
}

void deplacerCaisse(int *premiereCase, int *secondeCase)
{
    if (*premiereCase == CAISSE || *premiereCase == CAISSE_OK)
    {
        if (*secondeCase == OBJECTIF)
            *secondeCase = CAISSE_OK;
        else
            *secondeCase = CAISSE;

        if (*premiereCase == CAISSE_OK)
            *premiereCase = OBJECTIF;
        else
            *premiereCase = VIDE;
    }
}
