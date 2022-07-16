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

          switch(choixMenu)
        {
            case 1:

                do
                {
                        printf("1.Facile\n2.Moyen\n3.Difficile\n");
                        scanf("%d",&difficulte);
                        switch(difficulte)
                            {
                            case 1:
                            nombreMax=10;
                            break;
                            case 2:
                            nombreMax=100;
                            break;
                            case 3:
                            nombreMax=1000;
                            break;
                            default:
                            difficulte=0;
                            printf("\ndeconne pas!\n\n");
                            break;
                            }
                }while(!difficulte);

            case 2:
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
                        printf("\nPour recommencer, tapez sur 1.Sinon, tapez 0.\n");
                        scanf("%d",&continuerPartie);
                        }
                    } while(nombreMystere!=nombreEntre);
                    compteur=0;
                }while(continuerPartie);
            break;
            default:
            printf("\nTapez 1, pour choisir la difficulte. Tapez 2 pour commencer la devinette.\n\n");
            break;
        }
    printf("Pour retourner au menu principal, tapez 1. Pour quitter tapez 0.\n");
    scanf("%d",&quitter);
   }while(quitter);




    return 0;
}
