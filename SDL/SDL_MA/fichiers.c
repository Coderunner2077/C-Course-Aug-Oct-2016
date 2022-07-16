#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "constantes.h"
#include "fichiers.h"
//LA FCT SUIVANTE RENVOIE 1 SI LE CHARGEMENT A REUSSI ET 0 S'IL A ECHOUE
int chargerNiveau(int niveau[][NB_BLOCS_HAUTEUR])
{
    FILE *fichier=NULL;
    char ligneFichier[NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 1]={0};//POUR STOCKER TEMPORAIREMENT LE RESULTAT DU CHARGEMENT DE NIVEAU
    int i=0, j=0;

    fichier=fopen("niveaux.lvl", "r");//LE FICHIER niveax.lvl CONTIENT UNE LIGNE QUI EST UNE SUITE DE NOMBRES. CHAQUE NOMBRE REPRESENTE UNE CASE DU NIVEAU
    if(fichier==NULL)
    {
        fprintf(stderr, "Erreur d'ouverture du fichier : %s\n", SDL_GetError());
        return 0;
    }
    fgets(ligneFichier, NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR +1, fichier);
    //CONVERTISSONS LES VALEURS ASCII EN NOMBRES :
    for(i=0; i < NB_BLOCS_LARGEUR; i++)
    {
        for(j=0; j < NB_BLOCS_HAUTEUR; j++)
        {
            switch(ligneFichier[(i * NB_BLOCS_LARGEUR)+j])//ON SAIT QUE LES 12 PREMIERS CARACTERES DU FICHIER REPRESENTENT LA 1RE LIGNE, LES 12 SECONDS, LA SECONDE, ETC.
            {
                case '0':
                    niveau[j][i]=0;
                    break;
                case '1':
                    niveau[j][i]=1;
                    break;
                case '2':
                    niveau[j][i]=2;
                    break;
                case '3':
                    niveau[j][i]=3;
                    break;
                case '4':
                    niveau[j][i]=4;
                    break;
            }//CE SONT DES "LETTRES" QUI SONT STOCKES DANS LE FICHIER. ==>  DES '0' ET NON PAS DES 0
        }
    }

    fclose(fichier);
    return 1;
}

int sauvegarderNiveau(int niveau[][NB_BLOCS_HAUTEUR])
{
    FILE* fichier=NULL;
    int i=0, j=0;
    fichier=fopen("niveaux.lvl","w");
    if(fichier==NULL)
    {
        fprintf(stderr, "Erreur d'ouverture du fichier : %s\n", SDL_GetError());
        return 0;
    }
    for(i=0; i < NB_BLOCS_LARGEUR; i++)
    {
        for(j=0; j < NB_BLOCS_HAUTEUR; j++)
        {
            fprintf(fichier, "%d", niveau[j][i]); //J'UTILISE fprintf POUR "TRADUIRE" LES NOMBRES TU TABLEAU niveau EN CARACTERES ASCII
        }
    }
    fclose(fichier);
    return 1;
}
