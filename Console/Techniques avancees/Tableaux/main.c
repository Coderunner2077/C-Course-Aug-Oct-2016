#include <stdio.h>
#include <stdlib.h>


/*Elements de base de Tableaux

int main()
{
    int i=0;
    int tableau[4];
    tableau[0]=2;
    tableau[1]=4;
    tableau[2]=6;
    tableau[3]=8;
    printf("%d\n",tableau);//renvoie a l'adresse de la premiere case du tableau, car le tableau est un pointeur
    printf("%d\n",*tableau);//renvoie la valeur de la 1re case
    printf("%d\n\n\n",tableau[0]);//renvoie la valeur de la 1re case
    for(i=0;i<4;i++)
    {
      printf("%d\n",tableau[i]);
    }
    //initialiser un tableau:
    for (i=0;i<4;i++)
    {
        tableau[i]=0;
    }
    printf("\n\n\n");
    for(i=0;i<4;i++)
    {
        printf("%d\n",tableau[i]);
    }
    printf("\n\n\n");
    //affichage d'adresses de chaque case du tableau
    for(i=0;i<4;i++)
    {
        printf("%d\n",&tableau[i]);
    }


    printf("\n\n\n");

    //Une autre façon d'initialiser:
    int tab[5]={1,2,3,4,5};
    for(i=0;i<5;i++)
    {
        printf("%d\n",tab[i]);
    }
    printf("\n\n\n");
    //Idem
    int tab2[5]={0};

    for(i=0;i<5;i++)
    {
        printf("%d\n",tab2[i]);
    }
    printf("\n\n\n");

    //idem

    int tab3[5]={1};//la 1re case=1 et toutes les autres prennent automatiquement la valeur 0
    for(i=0;i<5;i++)
    {
        printf("%d\n",tab3[i]);
    }

    printf("\n\n\n")

    return 0;
}

*/

//passage de tableaux à une fonction

void zeroAffiche(int tableau[], int tailleTableau);//peut aussi s'écrire: void zeroAffiche(int *tableau, int tailleTableau);


int main(int argc, char *argv[])
{
    int tab[4]={1,2,3,4};int i=0;
    int tablo[30]={-457,879,777};
    printf("%d\n", tab[3]);
    for(i=0;i<30;i++)
    {
        tablo[i]=30-i;

    }
    for(i=0;i<30;i++)
    {
        printf("\n%d",tablo[i]);
    }
    printf("\n\n");

    for(i=0;i<4;i++)
    {
        printf("%d\n",tab[i]);
    }
    printf("\n\n\n");
    zeroAffiche(tab,4);
    return 0;
}

void zeroAffiche(int tableau[], int tailleTableau)//peut aussi s'écrire: void zeroAffiche(int *tableau, int tailleTableau);
{
    int i=0;

    for(i=0;i<tailleTableau;i++)
    {
    tableau[i]=0;//j'initialise le tableau
    printf("%d\n",tableau[i]);
    }

}
