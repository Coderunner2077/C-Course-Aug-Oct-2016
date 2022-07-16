#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constantes.h"
#include "fichiers.h"

int chargerNiveau(int niveau[][NB_BLOCS_LARGEUR])
{
    FILE* fichier = NULL;
    char ligneFichier[NB_BLOCS_HAUTEUR * NB_BLOCS_LARGEUR+ 1] = {0};
    int i = 0, j = 0;

    fichier = fopen("niveaux.lvl", "r");
    if (fichier == NULL)
        return 0;

    fgets(ligneFichier, NB_BLOCS_HAUTEUR * NB_BLOCS_LARGEUR + 1, fichier);

    for (i = 0 ; i < NB_BLOCS_HAUTEUR ; i++)
    {
        for (j = 0 ; j < NB_BLOCS_LARGEUR ; j++)
        {
            switch (ligneFichier[i * NB_BLOCS_LARGEUR + j])
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
            }
        }
    }

    fclose(fichier);
    return 1;
}

int sauvegarderNiveau(int niveau[][NB_BLOCS_LARGEUR])
{
    FILE* fichier = NULL;
    int i = 0, j = 0;

    fichier = fopen("niveaux.lvl", "w");
    if (fichier == NULL)
        return 0;

    for (i = 0 ; i < NB_BLOCS_HAUTEUR ; i++)
    {
        for (j = 0 ; j < NB_BLOCS_LARGEUR ; j++)
        {
            fprintf(fichier, "%d", niveau[i][j]);
        }
    }

    fclose(fichier);
    return 1;
}
