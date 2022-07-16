#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX  1000

char lireCaractere();
int main(int argc, char *argv[])
{


    FILE* fichier=NULL;
    /*fichier=fopen("test.txt","w");
    char lettre;

    if(fichier!=NULL)
    {
        int caractere='A', caractere2='B';

        fputc(caractere, fichier);
        fputc(caractere2, fichier);
        lettre=lireCaractere();
        fputc(lettre, fichier);
        fputs("\n\n\nCeci est un texte ecrit au biais de la fonction fputs du langage C.\n", fichier);
        fprintf(fichier, "\nCeci est un texte ecrit au biais de la fonction fprintf du langage C.\n");


    }
    else
        printf("ERREUR! IMPOSSIBLE D'OUVRIR LE FICHIER");

        */

        /*
    fichier=fopen("test.txt", "r");
    if(fichier!=NULL)
    {
        char chaine[1000]={""};
        char *lire;

        */

        /*

        int caractereActuel=0;//fputc renvoie un int, mais un char passe aussi bien
        do
        {
            caractereActuel=fgetc(fichier);
            printf("%c", caractereActuel);
        }while(caractereActuel!=EOF);

        */

        /*

        fgets(chaine, TAILLE_MAX, fichier);
        printf("%s",chaine);

        */

        /*

        while(fgets(chaine, TAILLE_MAX, fichier) != NULL)
        {
            printf("%s", chaine);
        }

    printf("\n%ld", ftell(fichier));
    rewind(fichier);
    printf("\n%ld", ftell(fichier));
    fseek(fichier, 50, SEEK_CUR);
    printf("\n%ld", ftell(fichier));
    fseek(fichier, 0, SEEK_END);
    printf("\n%ld", ftell(fichier));
    fseek(fichier, 51, SEEK_SET);
    printf("\n%ld", ftell(fichier));


    }

    fclose(fichier);

    else
        printf("Kimpossibeul");

    */

    FILE* scores=NULL;
    scores=fopen("score.txt", "w");
    if(scores!=NULL)
    {

        fputs("15 40 30", scores);

    fclose(scores);

    }
    else
        printf("kimposs");

    scores=fopen("score.txt", "r");
    if(scores!=NULL)
    {
        int points[3]={0}, i;
        fscanf(scores," %d %d %d", &points[0], &points[1], &points[2]);
    printf("\nVoici les top scores : ");
    for(i=0; i<3;i++)
    {
        printf("\n%d", points[i]);
    }

    fclose(scores);

    }
    else
        printf("kimposs");
    rename("test2.txt","rubbish.txt");
    remove("rubbish.txt");
    return 0;
}

/*
char lireCaractere()
{
    char caractereActuel=0;
    caractereActuel=getchar();

    while(getchar()!='\n');
    return caractereActuel;
}
*/
