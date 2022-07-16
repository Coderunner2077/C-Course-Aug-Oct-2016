#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>


int lireScore()
{
    FILE* fichier = NULL;
    int topScore = 0;

    fichier = fopen("score.txt", "r");
    if(fichier == NULL)
    {
        fprintf(stderr, "Erreur d'ouverture du fichier de score");
        exit(EXIT_FAILURE);
    }
    fscanf(fichier, "%d", &topScore);// !!!!!!!!!!!!!!!!!!!!!!!!

    fclose(fichier);
    return topScore;
}

int enregistrerScore(int newScore)
{
    FILE* fichier = NULL;
    fichier = fopen("score.txt", "w+");
    if(fichier == NULL)
    {
        fprintf(stderr, "Erreur d'ouverture du fichier de score");
        return 0;
    }
    fprintf(fichier,"%d", newScore);
    fclose(fichier);
    return 1;
}
