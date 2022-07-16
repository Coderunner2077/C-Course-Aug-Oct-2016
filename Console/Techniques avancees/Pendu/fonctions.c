#include "fonctions_et_autres.h"
#include <stdio.h>



char lireCaractere()
{
    char caractere;
    caractere=getchar();//ON LIT LE PREMIER CARACTERE
    caractere=toupper(caractere);//ON MET LE CARACTERE EN MAJUSCULE SI NECESSAIRE

    while(getchar()!='\n');//ON LIT TOUS LES CARACTERES UN A UN (POUR LES EFFACER)

    return caractere;//ON RETOURNE LE PREMIER CARACTERE QU'ON A LU
}

void sezam(MotCache* chaine, char lettre, int i)
{
    chaine->cache[i]=lettre;
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

void definirStructure(MotCache* pointeur, size_t nbCaracteres, char motACopier[])
{
    int i;
    for(i=0;i<nbCaracteres;i++)
    {
        pointeur->cache[i]='*';
        pointeur->decouvert[i]=motACopier[i];
    }
}

int rechercherCaractere(int lettre, char *motSecret, int lettreTrouvee[])
{
    int i, bonneLettre=0;
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
