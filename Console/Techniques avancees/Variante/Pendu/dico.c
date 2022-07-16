#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dico.h"
#include "fonctions_et_autres.h"

int piocherMot(char *motPioche)
{

    int nbMots=0, caractereLu=0; size_t nbCaracteres=0;
    FILE* fichier=NULL;
    fichier=fopen("dictionnaire.txt", "w");
    if(fichier!=NULL)
    {
      fputs("ROUGE\nARAIGNEE\nCAUCHEMAR\nANTOINETTE\nSAUTERELLE\nCOLLIER\nSAXOPHONE\nCHILIOGONE\nBONHEUR\nIMAGINATION\nREPUBLIQUE\nLIBERTE\nEQUITATION\nBONBON\n", fichier);
    fclose(fichier);
    }
    else
        printf("Kimpossible");

        fichier=fopen("dictionnaire.txt","r");
    if(fichier!=NULL)
    {
      while(fgets(motPioche, TAILLE_MAX, fichier)!=NULL)
      {
            nbMots++;
      }
      rewind(fichier);

      /*
      // INUTILE CAR JE FAIS APPEL A fgetc ET NON PAS A fgets
      int *liste=NULL;
      liste=malloc(nbMots*sizeof(int));
      if(liste==NULL)
      {
            printf("ERREUR D'ALLOCATION DE MEMOIRE");
            exit(0);
      }
    liste[0]=0;
    for(i=1;(fgets(motPioche, TAILLE_MAX, fichier)!=NULL);i++)
        {
            liste[i]=ftell(fichier);
        }


      for(i=0;i<nbMots;i++)
    {
        printf("%d\n", liste[i]);
    }
    */

    int numMotChoisi=0;
    srand(time(NULL));
    numMotChoisi=rand()%nbMots;
    rewind(fichier);
    while(numMotChoisi>0)
    {

        caractereLu=fgetc(fichier);
        if(caractereLu=='\n')
            numMotChoisi--;

    }
    fgets(motPioche, TAILLE_MAX, fichier);

    motPioche[strlen(motPioche)-1]='\0';
    nbCaracteres=strlen(motPioche);


    printf("\n\nDeviner un mot de %d lettres tire au sort parmi %d mots\n\n", nbCaracteres, nbMots);


      fclose(fichier);
    }
    else
        printf("Impossible d'ouvrir le fichier");

    return 1;
}
