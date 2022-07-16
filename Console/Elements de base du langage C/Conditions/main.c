#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    int choixMenu=0;

    do
    {
    printf("=== Menu ===\n\n1.Royal Cheese\n2.Mc Deluxe\n3.Mc Bacon\n4.Big Mac\n\nVotre choix?\n");
    scanf("%d",&choixMenu);
    printf("\n");
    switch(choixMenu)
        {
        case 1:
            printf("Vous avez choisi Royal Cheese");
            break;
        case 2:
            printf("Vous avez choisi Mc Deluxe");
            break;
        case 3:
            printf("Vous avez choisi Mc Bacon");
            break;
        case 4:
            printf("Vous avez choisi Big Mac");
            break;
        default:
            printf("y a pas");
            break;
        }

    printf("\n\n");
    }while(choixMenu<1||choixMenu>4);


    double age=0,revenu=0;
    do
    {
    printf("quel age avez-vous?\n");
    scanf("%lf",&age);
    if(age<6||age>130)
    printf("\n\nMon oeil!\n\n");
    }while(age < 6 || age >130);
    do
    {
    printf("combien gagnez-vous?\n");
    scanf("%lf",&revenu);
    if(revenu<0)
        printf("\n\nVous dites?\n\n");
    }while(revenu < 0);

    if(age>=30&&revenu>2500)
    {
        printf("Bienvenue!\n");
    }
    else
    {
        printf("casse-toi, pauvre con!\n");

    }



    /*
    double age=0,youngster=0,revenu=0;
    printf("quel age avez-vous?\n");
    scanf("%lf",&age);
    printf("combien gagnez-vous?\n");
    scanf("%lf",&revenu);
    youngster=age>=30;

    if(youngster||!(revenu<2500))
    {
        printf("Bienvenue!\n");
        printf("%f",youngster);
    }
    else
    {
        printf("casse-toi, pauvre con!\n");

    }
    */

/*
    double age=0,majeur=0,qi=0,note=0;
    printf("quel age avez-vous?\n");
    scanf("%lf",&age);
    majeur=age>=18;
    qi=(majeur)?115:110;//On appelle cela des expressions ternaires. Les ternaires permettent, sur une seule ligne, de changer la valeur d'une variable en fonction d'une condition
    if(majeur)
        printf("Votre qi est superieur a %f!\n",qi);
    else
        printf("Votre qui est inferieur a %f\n",qi);
    do
    {
    printf("quel est votre moyenne generale?\n");
    scanf("%lf",&note);

    if(note>=0&&note<=20)
    {
        qi=(note>=16)?135:120;
    if(qi>=135)
        printf("votre qi est finalement sup a %f\n",qi);
    else
        printf("votre qi est inferieur a %f\n",qi);
    }
    else
        printf("\n\nune note comprise entre 0 et 20 svp!\n\n");
    }while(note<0||note>20);

    */
    return 0;
}
