#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    const int MIN=1;
    unsigned int nombreMax=100,difficulte=0,nombreMystere=0,nombreEntre=0,compteur=0,continuerPartie=1,choixMenu=0,quitter=1;
    srand(time(NULL));
    do
    {
        printf("===DEVINETTE===\n\n1.Choisir la difficulte\n2.C'est parti!\n\n");
        scanf("%d",&choixMenu);

            if(choixMenu==1)
            {
                do
                {
                    printf("1.Facile\n2.Moyen\n3.Difficile\n");
                    scanf("%d",&difficulte);


                    switch(difficulte)
                    {
                        case 1:
                        nombreMax=100;
                        break;
                        case 2:
                        nombreMax=1000;
                        break;
                        case 3:
                        nombreMax=10000;
                        break;
                        default:
                        difficulte=0;
                        printf("\nENTREE INVALIDE!\n\n");
                        break;
                    }
                }while(difficulte < 1 || difficulte >3);
            }


            else if(choixMenu==2)
            {
                do
                {
                    nombreMystere=(rand()%(nombreMax-MIN+1))+MIN;

                    do
                    {
                        printf("Quel est le nombre?\n");
                        scanf("%d",&nombreEntre);
                        compteur++;
                        if(nombreEntre>nombreMystere)
                        printf("C'est moins\n");
                        else if(nombreEntre<nombreMystere)
                        printf("C'est plus\n");
                        else
                        {
                        printf("Bravo, vous avez trouve le nombre mystere\n");
                        printf("Vous l'avez trouve du %deme coup!\n\n",compteur);
                        printf("\nPour recommencer, entrez 1.Sinon, entrez un autre nombre.\n");
                        scanf("%d",&continuerPartie);

                        }
                    } while(nombreMystere!=nombreEntre);
                    compteur=0;
                }while(continuerPartie==1);
            }
            else
            {
                printf("\nIl faut entrer 1 pour choisir la difficulte, ou 2 pour commencer directement la partie.\n\n");
            }
        printf("Pour retourner au menu principal, entrez 1. Si vous voulez quitter, entrez un autre nombre.\n");
        scanf("%d",&quitter);

   }while(quitter==1);

    return 0;
}
