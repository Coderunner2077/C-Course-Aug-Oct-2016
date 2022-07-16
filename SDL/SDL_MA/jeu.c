#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constantes.h"
#include "jeu.h"



void jouer(SDL_Surface *ecran)
{
    SDL_Surface *mario[4]={NULL};//4 SURFACES POUR 4 DIRECTIONS DE MARIO
    SDL_Surface *mur=NULL, *caisse=NULL, *caisseOK=NULL, *objectif=NULL, *marioActuel=NULL;
    SDL_Rect position, positionJoueur;
    SDL_Event event;
    int continuer=1, objectifsRestants=0, i=0, j=0;
    int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] = {0};// UN TABLEAU A DEUX DIMENSIONS

    mario[HAUT]=IMG_Load("images/mario_haut.gif");
    mario[BAS]=IMG_Load("images/mario_bas.gif");
    mario[GAUCHE]=IMG_Load("images/mario_gauche.gif");
    mario[DROITE]=IMG_Load("images/mario_droite.gif");
    mur=IMG_Load("images/mur.jpg");
    caisse=IMG_Load("images/caisse.jpg");
    caisseOK=IMG_Load("images/caisse_ok.jpg");
    objectif=IMG_Load("images/objectif.png");
    marioActuel=mario[BAS];// Mario SERA DIRIGE VERS LE BAS AU DEPART
    //CHARGEMENT DU NIVEAU QUI EST STOCKE DANS LE FICHIER niveaux.1v1
    if(!chargerNiveau(carte))
    {
        fprintf(stderr, "Erreur de chargement du niveau : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);//ON ARRETE LE JEU SI ON N'A PAS PU CHARGER LE NIVEAU
    }

    for(i=0; i<NB_BLOCS_LARGEUR;i++)
    {
        for(j=0; j<NB_BLOCS_HAUTEUR; j++)
        {
            if(carte[i][j] == MARIO)
            {
                positionJoueur.x = i;
                positionJoueur.y = j;
                carte[i][j] = VIDE;
            }
        }
    }
    SDL_EnableKeyRepeat(100, 100);

    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer=0;
                        break;
                    case SDLK_UP:
                        marioActuel=mario[HAUT];
                        deplacerJoueur(carte, &positionJoueur, HAUT);
                        break;
                    case SDLK_DOWN:
                        marioActuel=mario[BAS];
                        deplacerJoueur(carte, &positionJoueur, BAS);
                        break;
                    case SDLK_LEFT:
                        marioActuel=mario[GAUCHE];
                        deplacerJoueur(carte, &positionJoueur, GAUCHE);
                        break;
                    case SDLK_RIGHT:
                        marioActuel=mario[DROITE];
                        deplacerJoueur(carte, &positionJoueur, DROITE);
                        break;
                }
            break;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        objectifsRestants = 0;
        for(i=0; i<NB_BLOCS_LARGEUR; i++)
        {
            for(j=0; j<NB_BLOCS_HAUTEUR; j++)
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
        if(!objectifsRestants)//SI ON N'A TROUVE AUCUN OBJECTIF SUR LA CARTE, C'EST QU'ON A GAGNE
            continuer=0;

        //ON PLACE LE JOUEUR A LA BONNE POSITION :
        position.x = positionJoueur.x * TAILLE_BLOC;
        position.y = positionJoueur.y * TAILLE_BLOC;
        SDL_BlitSurface(marioActuel, NULL, ecran, &position);
        SDL_Flip(ecran);
    }
    // DESACTIVATION DE LA REPETITION DES TOUCHES (remise a 0):
    SDL_EnableKeyRepeat(0, 0);
    //LIBERATION DES SURFACS CHARGEES :
    SDL_FreeSurface(mur);
    SDL_FreeSurface(caisse);
    SDL_FreeSurface(caisseOK);
    SDL_FreeSurface(objectif);
    for(i=0; i<4; i++)
        SDL_FreeSurface(mario[i]);
}
//OBLIGATOIRE D'INDIQUER LA TAILLE DE LA SECONDE DIMENSION POUR FAIRE COMPRENDRE A LA MACHINE ==> TABLEAU 2D
void deplacerJoueur(int carte[][NB_BLOCS_HAUTEUR], SDL_Rect *pos, int direction)
{
    switch(direction)
    {
        case HAUT:
            if(pos->y - 1 < 0)//LE JOUEUR EST DEJA TOUT EN HAUT DE LA CARTE
                break;// POUR SORTIR DU switch ET DONC POUR EMPECHER LE DEPLACEMENT
            if(carte[pos->x][pos->y - 1]==MUR)
                break;
            if((carte[pos->x][pos->y - 1] == CAISSE || carte[pos->x][pos->y - 1] == CAISSE_OK) && (pos->y - 2 < 0 || carte[pos->x][pos->y - 2] == MUR || carte[pos->x][pos->y - 2] == CAISSE || carte[pos->x][pos->y - 2] == CAISSE_OK))
                break;
            deplacerCaisse(&carte[pos->x][pos->y - 1], &carte[pos->x][pos->y - 2]); // ON VERIVIE D'ABORD S'IL Y A UNE CAISE A DEPLACER
            pos->y--; //ON PEUT ENFIN FAIRE MONTER LE JOUEUR
            break;
        case BAS:
            if(pos->y + 1 >= NB_BLOCS_HAUTEUR)
                break;
            if(carte[pos->x][pos->y + 1] == MUR)
                break;
            if((carte[pos->x][pos->y + 1] == CAISSE || carte[pos->x][pos->y + 1] == CAISSE_OK) &&
               (pos->y + 2 >= NB_BLOCS_HAUTEUR  || carte[pos->x][pos->y + 2] == MUR ||
                 carte[pos->x][pos->y + 2] == CAISSE || carte[pos->x][pos->y + 2] == CAISSE_OK))
                break;
            deplacerCaisse(&carte[pos->x][pos->y + 1], &carte[pos->x][pos->y + 2]);
            pos->y++;
            break;
        case DROITE:
            if(pos->x + 1 >= NB_BLOCS_LARGEUR)
                break;
            if(carte[pos->x + 1][pos->y] == MUR)
                break;
            if((carte[pos->x + 1][pos->y] == CAISSE || carte[pos->x + 1][pos->y] == CAISSE_OK) &&
               (pos->x + 2 >= NB_BLOCS_LARGEUR  || carte[pos->x + 2][pos->y] == MUR ||
                carte[pos->x + 2][pos->y] == CAISSE || carte[pos->x + 2][pos->y] == CAISSE_OK))
                break;
            deplacerCaisse(&carte[pos->x + 1][pos->y], &carte[pos->x + 2][pos->y]);
            pos->x++;
            break;
        case GAUCHE:
            if(pos->x - 1 < 0)
                break;
            if(carte[pos->x - 1][pos->y] == MUR)
                break;
            if((carte[pos->x - 1][pos->y] == CAISSE || carte[pos->x - 1][pos->y] == CAISSE_OK) &&
               (pos->x - 2 < 0 || carte[pos->x - 2][pos->y] == MUR || carte[pos->x - 2][pos->y] == CAISSE ||
                carte[pos->x - 2][pos->y] == CAISSE_OK))
                break;
            deplacerCaisse(&carte[pos->x - 1][pos->y], &carte[pos->x - 2][pos->y]);
            pos->x--;
            break;
    }
}

void deplacerCaisse(int *premiereCase, int *secondeCase)
{
    if(*premiereCase == CAISSE || *premiereCase == CAISSE_OK)
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
