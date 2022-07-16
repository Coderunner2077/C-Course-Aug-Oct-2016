#include <stdio.h>
#include <stdlib.h>
#define NB_BLOCS_HAUTEUR    10
#define NB_BLOCS_LARGEUR    20

int main(int argc, char *argv[])
{
    int carte[NB_BLOCS_HAUTEUR][NB_BLOCS_LARGEUR]={0};
    int i=0, j=0;
    for(i=0; i < NB_BLOCS_HAUTEUR; i++)
    {
        for(j=0; j <NB_BLOCS_LARGEUR; j++)
        {
            if(i==j || (NB_BLOCS_LARGEUR -1 - j)== i)
            carte[i][j]=1;

        }
    }
    for(i=0; i < NB_BLOCS_HAUTEUR; i++)
    {
        for(j=0; j < NB_BLOCS_LARGEUR; j++)
        {
            printf("%d", carte[i][j]);
            if(j==NB_BLOCS_LARGEUR - 1)
            printf("\n");
        }
    }

    return 0;
}
