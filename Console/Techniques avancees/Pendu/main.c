#include <stdio.h>
#include <stdlib.h>
#include "fonctions_et_autres.h"
#include "dico.h"


int main(int argc, char *argv[])
{
    int recommencer=0;
    do
    {

        int coupsRestants=10, i, joueur=1;
        size_t nbCaracteres=0;
        char maLettre=0;
        char motSecret[TAILLE_MAX]={""};


        printf(" \n==== LE PENDU ==== \n");
        printf(" \n CHOISISSEZ LE MODE \n");
        printf(" \n==1 JOUEUR == \n");
        printf(" \n==2 JOUEUR == \n");
        scanf("%d", &joueur);
        viderBuffer(); //INDISPENSABLE: POUR VIDER LE BUFFER


        if(joueur==1)
        {
            if(!piocherMot(motSecret))
                exit(0);
            nbCaracteres=strlen(motSecret);
        }

        else if(joueur==2)
        {

            printf("\n -- Joueur 1, entrez le mot a deviner en lettres capitales-- \n");
            scanf("\n%s", motSecret);
            nbCaracteres=strlen(motSecret);
            viderBuffer();
            printf("\nJoueur 2, devinez un mot de %d lettres \n", nbCaracteres);
        }

        else
        {
            printf("\nENTREE INVALIDE\n\nMODE 1 JOUEUR CHOISI PAR DEFAUT\n");

            if(!piocherMot(motSecret))
                exit(0);
            nbCaracteres=strlen(motSecret);
            joueur=1;
        }


        MotCache mot={"",""};
        MotCache *pointeur=NULL;
        pointeur=&mot;
        definirStructure(pointeur, nbCaracteres, motSecret);

        int *lettreTrouvee=NULL;
        lettreTrouvee=malloc(nbCaracteres*(sizeof(int)));
        if(lettreTrouvee==NULL)
        {
            printf("\nERREUR D'ALLOCATION DE MEMOIRE");
            exit(0);
        }

        for(i=0;i<nbCaracteres;i++)
        {
            lettreTrouvee[i]=0;
        }


        printf("\n=== Mode %d joueur ===\n", joueur);

        while(!gagne(lettreTrouvee, nbCaracteres) && coupsRestants > 0)
        {
            printf("Il ne vous reste que %d coups a jouer\n",coupsRestants);
            printf("Quel est le mot secret?");
            printf("\n%s\n",mot.cache);
            printf("Proposez une lettre\n");
            maLettre=lireCaractere();

            for(i=0;i<nbCaracteres;i++)
            {
                if(maLettre==motSecret[i])
                {
                    sezam(&mot, maLettre, i);
                }
            }
            rechercherCaractere(maLettre, motSecret, lettreTrouvee);

            gagne(lettreTrouvee, nbCaracteres);
            if(!rechercherCaractere(maLettre, motSecret, lettreTrouvee))
                coupsRestants--;
    }
    if(gagne(lettreTrouvee, nbCaracteres))
        printf("\n\nWON! The mystery word surely is: %s\n", mot.cache);
    else
        printf("\n\nYou're dead\n\n The mystery word was: %s", mot.decouvert);


    free(lettreTrouvee);
    printf("\n\nAppuyer sur 1 pour recommencer\n\nAppuyer sur 0 pour quitter");
    scanf("%d", &recommencer);

    }while(recommencer); //10

    return 0;
}
