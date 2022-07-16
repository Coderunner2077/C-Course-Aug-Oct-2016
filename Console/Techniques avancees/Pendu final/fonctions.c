#include "fonctions_et_autres.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lire(char* mot, int longueur)
{
    char* positionEntree=NULL;
    if(fgets(mot, longueur, stdin)!=NULL)
    {
        positionEntree=strchr(mot, '\n');
        if(positionEntree!=NULL)
        {
            *positionEntree='\0';
        }
        else
        {
            viderBuffer();
        }
        return 1;

    }
    else
        {
        viderBuffer();
        return 0;
        }

}

char lireCaractere()
{
    char caractere;
    caractere=getchar();//ON LIT LE PREMIER CARACTERE
    caractere=toupper(caractere);//ON MET LE CARACTERE EN MAJUSCULE SI NECESSAIRE

    while(getchar()!='\n');//ON LIT TOUS LES CARACTERES UN A UN (POUR LES EFFACER)

    return caractere;//ON RETOURNE LE PREMIER CARACTERE QU'ON A LU
}

void formaterMot(char *chaine, size_t tailleMotVoulue)
{
    char *positionFinChaine=NULL;
    positionFinChaine=chaine;
    positionFinChaine[tailleMotVoulue]='\0';

}

void cacherMot(char *motACacher, size_t tailleMot)
{
    size_t i;
    for(i=0;i<tailleMot;i++)
    {
        motACacher[i]='*';
    }
    motACacher[tailleMot] = '\0';

}

void sezam(char *pointeur, char lettre, int i)
{
    pointeur[i]=lettre;
}

int gagne(int lettreTrouvee[], int tailleTableau)
{
    int joueurGagne=1, i;
    for(i=0;i<tailleTableau;i++)
    {
        if(lettreTrouvee[i]==0)
            joueurGagne=0;
    }
    return joueurGagne;
}

int rechercherCaractere(int lettre, char *motSecret, int lettreTrouvee[])
{
    int i, bonneLettre = 0;
    for(i=0;motSecret[i]!='\0'; i++)
    {
        if(lettre==motSecret[i])
        {
            lettreTrouvee[i]=1;
            bonneLettre=1;
        }
    }
    return bonneLettre;
}

void viderBuffer()
{
    int c;
    while(c!='\n' && c!=EOF)
    {
        c=getchar();
    }
}
