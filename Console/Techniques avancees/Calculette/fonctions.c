#include "fonctions.h"


long multiplier(long nombre1, long nombre2)
{
    long produit=0;
    produit=nombre1*nombre2;
    return produit;
}

int lireLettre()
{
    int c=getchar();
    while(getchar()!='\n');

    return c;
}
int lire(char *texte, int longueur)
{
    char *positionEntree=NULL;
    if(fgets(texte, longueur, stdin)!=NULL)
    {
        positionEntree=strchr(texte, '\n');
        if(positionEntree!=NULL)
            *positionEntree='\0';
        else
            viderBuffer();
        return 1;
    }
    else
        {
            viderBuffer();
            return 0;
        }

}
void viderBuffer()
{
    int c;
    while(c!='\n' && c!=EOF)
    {
        c=getchar();
    }
}
long lireLong()
{
    char nombreTexte[15]={0};
    if(lire(nombreTexte, 15))
    {
        return strtol(nombreTexte, NULL, 10);
    }
    else
        return 0;

}

double lireDouble()
{
    char nombreTexte[15]={0};
    char *virgule=NULL;
    if(lire(nombreTexte, 15))
    {
        virgule=strchr(nombreTexte, ',');
        if(virgule!=NULL)
            *virgule='.';
        return strtod(nombreTexte, NULL);
    }
    else
        return 0;
}
