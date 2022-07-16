#include <stdio.h>
#include <stdlib.h>
#include "fonctions_et_autres.h"
#include "dico.h"



int main(int argc, char *argv[])
{
    int coupsRestants=10, i=0;
    char maLettre=0;
    char motSecret[TAILLE_MOT]={""};
    size_t nbCaracteres=0;
    if(!piocherMot(motSecret))
        exit(0);
    nbCaracteres=strlen(motSecret);
    int *lettreTrouvee=NULL;
    lettreTrouvee=malloc(nbCaracteres*(sizeof(int)));
    if(lettreTrouvee==NULL)
    {
        printf("\nERREUR D'ALLOCATION DE MEMOIRE");
        exit(0);
    }

    for(i=0;i<nbCaracteres;i++)
    {lettreTrouvee[i]=0;}

    scanf("%d", &i);

    printf(" === LE PENDU ==== \n");
    /*
    scanf("%c",&maLettre);
    printf("%c",maLettre);
    scanf("%c",&maLettre);//CA MARCHE PAS??!!!
    printf("%c",maLettre);
    //C'EST PARCE QUE LE SECOND scanf A STOCKE '\n' (LA TOUCHE "ENTREE")
    */
    do
    {
        printf("Il ne vous reste que %d coups a jouer\n",coupsRestants);
        printf("Quel est le mot secret?\n");
        for(i=0;i<nbCaracteres;i++)
        {
            if(lettreTrouvee[i])
                printf("%c", motSecret[i]);
            else
                printf("*");

        }

        printf("\nProposez une lettre\n");
        maLettre=lireCaractere();
        rechercheLettre(maLettre, nbCaracteres, motSecret, lettreTrouvee);
        gagne(lettreTrouvee, nbCaracteres);


    if(!rechercheLettre(maLettre, nbCaracteres, motSecret, lettreTrouvee))
        coupsRestants--;

    }while(!gagne(lettreTrouvee, nbCaracteres) && coupsRestants>0);
    if(gagne(lettreTrouvee, nbCaracteres))
        printf("\n\nWON! The mystery word surely is : %s\n", motSecret);
    else
        printf("\n\nYou're dead\n\n");

    free(lettreTrouvee);
    return 0;
}

char lireCaractere()
{
    char caractere;
    caractere=getchar();
    caractere=toupper(caractere);

    while(getchar()!='\n');

    return caractere;
}

int gagne(int lettreTrouve[], size_t tailleTableau)
{
    int i, joueurGagne=1;
    for(i=0; i<tailleTableau;i++)
    {
        if(lettreTrouve[i]==0)
            joueurGagne=0;
    }
    return joueurGagne;
}
int rechercheLettre(int lettre, size_t nbLettres, char *chaine, int tableau[])
{
    int i, bonneLettre=0;
    for(i=0;i<nbLettres;i++)
    {
        if(lettre==chaine[i])
            {
                tableau[i]=1;
                bonneLettre=1;
            }
    }
    return bonneLettre;
}

