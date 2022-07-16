#include <stdio.h>
#include <stdlib.h>
#include "tableaux.h"





int main()
{

    const int MAX=47;
    /*
    int tableau[4]={2,4,6,8};
    int tab[4];
    int tableau3[7]={45,29,48,33,72,15,50};
    */
    int i=0;
    int tableau4[30]={0};

    for(i=0;i<30;i++)
    {
        tableau4[i]=30-i;
    }




    /*
    int tableau[4]={1,2,3,4};



    sommeCases(tableau,4);

    moyenneTableau(tableau,4);
    printf("\n\n\n");
    copierTableau(tableau,tab,4);
    printf("\n\n\n");
    maximumTableau(tableau3,MAX,7);
    printf("\n\n\n");
    */
    ordonnerTableau(tableau4,30);


    return 0;
}

