//fonction somme pour tableau




int sommeCases(int tableau[], int tailleTableau)
{
    int i, somme=0;
    for(i=0;i<tailleTableau;i++)
    {
        printf("%d\n",tableau[i]);
        somme+=tableau[i];
    }
    printf("\n\nSomme des valeurs du tableau=%d",somme);
    return somme;
}

double moyenneTableau(int tableau[], int tailleTableau)
{
    int i;
    double moyenne=0;
    for(i=0;i<tailleTableau;i++)
    {
        printf("%d\n",tableau[i]);
        moyenne+=tableau[i];

    }
    moyenne/=tailleTableau;

    printf("\n\nMoyenne des valeurs du tableau=%f\n",moyenne);
    return moyenne;
}
void copierTableau(int tableauOriginal[],int tableauCopie[], int tailleTableau)
{
    int i;

    printf("\n\n");
    for(i=0;i<tailleTableau;i++)
    {
        tableauCopie[i]=tableauOriginal[i];
        printf("%d\n",tableauCopie[i]);
    }

}

void maximumTableau(int tableau[], const int valeurMax, int tailleTableau)
{
    int i;
    for(i=0;i<tailleTableau;i++)
    {
        if(tableau[i]>valeurMax)
            tableau[i]=0;
        printf("%d\n",tableau[i]);
    }

}

void ordonnerTableau(int tableau[],int tailleTableau)
{
    int i=0, k=0;
    int tab[200]={0};
    for (i=0;i<tailleTableau;i++)
    {
        printf("%d\n",tableau[i]);
    }
    printf("\n\n");

    for (i=0;i<tailleTableau;i++)

    {
    for (k=0;k<tailleTableau;k++)
    {
         if(tableau[k]>=tableau[k+1])
         {

             tab[i]=tableau[k];
             tableau[k]=tableau[k+1];
             tableau[k+1]=tab[i];
         }

    }

    }
    for(i=0;i<tailleTableau;i++)
    {printf("%d\n",tableau[i]);}
}
