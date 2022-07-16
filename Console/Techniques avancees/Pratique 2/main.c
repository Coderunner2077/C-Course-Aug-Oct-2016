#include <stdio.h>
#include <stdlib.h>

typedef struct Colors Colors;
struct Colors
{
    char det[100];
};
int main(int argc, char *argv[])
{
    int effectifs=0, i, noteImpossible=0;
    int *noteEleve=NULL;

    printf("Nb eleves?");
    scanf("%d", &effectifs);
    noteEleve=malloc(effectifs*sizeof(int));
    if(noteEleve==NULL)
    {
        printf("ERREUR!!");
        exit(0);
    }


    do
    {
    noteImpossible=0;
    printf("\nQuelles notes?\n");

        for(i=0;i<effectifs;i++)
    {
        scanf("%d", &noteEleve[i]);
        if(noteEleve[i] > 20 || noteEleve[i] < 0)
            noteImpossible=1;

    }

    }while(noteImpossible);
    printf("\nVoici les notes :\n");
    for(i=0;i<effectifs;i++)
    {
        printf("Eleve numero %d : %d \n", i+1, noteEleve[i]);
    }
    free(noteEleve);
    int nbCouleurs=0;
    Colors *couleurs={NULL};
    printf("\nCombien de couleurs?\n");
    scanf("%d", &nbCouleurs);
    couleurs=malloc(nbCouleurs*sizeof(Colors));
    printf("\nEntrez les 3 couleurs du drapeau francais\n");
    for(i=0;i<nbCouleurs;i++)
    {
        scanf("%s", &couleurs[i].det);//IMPOSSIBLE A FAIRE SANS STRUCT
    }
    printf("Voici les couleurs de la France :\n");
    for(i=0;i<nbCouleurs;i++)
    {
        printf("\n%s", couleurs[i].det);
    }

    free(couleurs);


    return 0;
}
