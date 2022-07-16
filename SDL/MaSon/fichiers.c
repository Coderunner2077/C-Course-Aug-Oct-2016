#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constantes.h"
#include "fichiers.h"
//LA FCT SUIVANTE RENVOIE 1 SI LE CHARGEMENT A REUSSI ET 0 S'IL A ECHOUE
int chargerNiveau(int niveau[][NB_BLOCS_LARGEUR], long level)
{
    FILE* fichier = NULL;
    int i=0, j =0;
    long position = 0;
    char ligneFichier[NB_BLOCS_HAUTEUR * NB_BLOCS_LARGEUR + 1] = {0};//POUR STOCKER TEMPORAIREMENT LE RESULTAT DU CHARGEMENT DE NIVEAU

    fichier = fopen("niveaux.lvl", "r");//LE FICHIER niveax.lvl CONTIENT UNE LIGNE QUI EST UNE SUITE DE NOMBRES. CHAQUE NOMBRE REPRESENTE
    if(fichier == NULL)
        return 0; // -->

    if(level)
    {
        position = level * NB_BLOCS_HAUTEUR * NB_BLOCS_LARGEUR + 1;
        fseek(fichier, position, SEEK_SET);
    }

    fgets(ligneFichier, NB_BLOCS_HAUTEUR * NB_BLOCS_LARGEUR + 1, fichier);

    //CONVERTISSONS LES VALEURS ASCII EN NOMBRES :
    for(i=0; i <= NB_BLOCS_HAUTEUR; i++)
    {
        for(j=0; j <=NB_BLOCS_LARGEUR; j++)
        {
            switch(ligneFichier[(i * NB_BLOCS_LARGEUR) + j])//ON SAIT QUE LES 12 PREMIERS CARACTERES DU FICHIER REPRESENTENT LA 1RE LIGNE, LES 12 SECONDS, LA SECONDE, ETC.
            {
                case '0':
                    niveau[i][j] = 0;
                    break;
                case '1':
                    niveau[i][j] = 1;
                    break;
                case '2':
                    niveau[i][j] = 2;
                    break;
                case '3':
                    niveau[i][j] = 3;
                    break;
                case '4':
                    niveau[i][j] = 4;
                    break;
                case '5':
                    niveau[i][j] = 5;
                    break;
            }//CE SONT DES "LETTRES" QUI SONT STOCKES DANS LE FICHIER. ==>  DES '0' ET NON PAS DES 0
        }

    }
    fclose(fichier); // -->
    return 1; // -->
}

int sauvegarderNiveau(int niveau[][NB_BLOCS_LARGEUR], long level)
{
    FILE* fichier = NULL;
    int i = 0, j = 0;
    long position = 0;

    fichier = fopen("niveaux.lvl", "r+");//AVEC "w" : fseek NE VEUT PAS MARCHER
    if(fichier == NULL)
        return 0;


    if(level)
    {
        position = level * NB_BLOCS_HAUTEUR * NB_BLOCS_LARGEUR + 1;
        fseek(fichier, position, SEEK_SET);
    }
    if(fgetc(fichier) == '\n');
    for(i=0; i < NB_BLOCS_HAUTEUR; i++)
    {
        for(j=0; j < NB_BLOCS_LARGEUR; j++)
        {
            fprintf(fichier, "%d", niveau[i][j]); // --> !!!!!! PAS ligneFichier!
        }//J'UTILISE fprintf POUR "TRADUIRE" LES NOMBRES TU TABLEAU niveau EN CARACTERES ASCII
    }
    fputc('\n',fichier);
    fclose(fichier);
    return 1;
}

void afficherBravo(SDL_Surface *ecran)
{
    SDL_Surface *bravo = NULL;
    SDL_Rect position;
    SDL_Event event;
    int cont = 1;

    bravo = IMG_Load("bravo.jpg");


    while(cont)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_KEYDOWN:
                cont = 0;
                break;
        }
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    position.x = LARGEUR_FENETRE / 2 - bravo->w / 2;
    position.y = HAUTEUR_FENETRE / 2 - bravo->h / 2;
    SDL_BlitSurface(bravo, NULL, ecran, &position);
    SDL_Flip(ecran);
    }
    SDL_FreeSurface(bravo);
}
