#include <stdio.h>
#include <stdlib.h>

/*int longueurChain(const char* chaine);
void entrerMots(char* chaine);
int main()
{
    char adresse[1000]="vide et";
    int lenth=0;
    lenth=longueurChain(adresse);
    printf("%d",lenth);
    entrerMots(adresse);
    lenth=longueurChain(adresse);
    printf("\n%d",lenth);
    char* phrase="Phrase de plusieurs mots ";
    lenth=longueurChain(phrase);
    printf("\n%d",lenth);
    printf("\n%c",phrase[19]);
    return 0;
}

void entrerMots(char* chaine)
{
    int i;
    for(i=0;chaine[i]!=' ';i++)
    {
        scanf("\n%s",chaine[i]);
    }

}




int longueurChain(const char* chaine)
    {
        int i, nombreCaracteres=0;
        char caractereActuel;
        for(i=0;chaine[i]!='\0';i++)
        {
            chaine[i];
            nombreCaracteres++;
        }
        return nombreCaracteres;
    }*/
void sezam(char *pnteur);
int main(int argc, char *rgv[])
{
   char *pointeur=NULL;
    char *mot={""};
    char lettre='c';

    pointeur=&mot;
    *pointeur="Bleu";

    printf("%s",mot);
    return 0;
}

void sezam(char *pnteur)
{
    *pnteur="ORANGE";
}

//kimpossible!
