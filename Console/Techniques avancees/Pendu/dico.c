#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_et_autres.h"
#include "dico.h"

int piocherMot(char *motPioche)
{
    int nbMots=0, numMotChoisi=0, caractereLu=0;
    size_t nbCaracteres=0;

    FILE* dico=NULL;
    dico=fopen("dico.txt", "w");
    if(dico!=NULL)
    {
        fputs("ROUGE\nARAIGNEE\nCAUCHEMAR\nANTOINETTE\nSAUTERELLE\nCOLLIER\nSAXOPHONE\nCHILIOGONE\nBONHEUR\nIMAGINATION\nREPUBLIQUE\nLIBERTE\nEQUITATION\nBONBON\n", dico);
    fclose(dico);
    }
    else
        printf("Kimpossible");

    dico=fopen("dico.txt", "r");
    if(dico!=NULL)
    {
        while(fgets(motPioche, TAILLE_MAX, dico)!=NULL)
        {
            nbMots++;
        }

        numMotChoisi=numMotAleatoire(nbMots);
        rewind(dico);
        while(numMotChoisi>0)
        {
            caractereLu=fgetc(dico);
            if(caractereLu=='\n')
                numMotChoisi--;
        }
        fgets(motPioche, TAILLE_MAX, dico);
        motPioche[strlen(motPioche)-1]='\0';
        nbCaracteres=strlen(motPioche);

        printf("\nDevinez un mot de %d lettres tire au sort dans une liste de %d mots\n", nbCaracteres, nbMots);

        fclose(dico);

    }
    else
        printf("Kimpossible");


    return 1;
}

int numMotAleatoire(int nombreMots)
{
    srand(time(NULL));
    return rand()%nombreMots;
}
