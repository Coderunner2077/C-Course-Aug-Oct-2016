#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    /*
    double compteur=10000;
    while (compteur==0)
    {
    printf("Le compteur est a %f!\n",compteur);
    compteur--;
    }
    */


    double nombreEntre=0;
    int warning=3;
    int code=1234;
    do
    {
        printf("Entrez le code\n");
        scanf("%lf",&nombreEntre);
        if(nombreEntre!=code)
        {
            warning--;
            if(warning >= 1)
                printf("Il ne vous reste que %d essais !\n",warning);
            else
                printf("Vous avez entre %d. Il ne vous reste plus d'essais !\n", (int)nombreEntre);
        }
    } while(nombreEntre != code && warning >= 1);
      if(nombreEntre==code)
      {
        printf("\n\n\n===ACCES GRANTED===\n\n\n");
      }
      else
        printf("\n\n\n===vous etes bloque a vie===\n\n\n");
        //Remarque: Cette boucle s'ex�cutera toujours au moins une fois, meme si la condition est fausse des le depart. Ce n'est pas le cas pour while (qui se trouve au debut de la condition).



    int compteur;

    for(compteur=0;compteur<100000;compteur++)
       {
        printf("%d\n",compteur);
       }

    /*Il y a trois instructions condens�es, chacune s�par�e par un point-virgule.

La premi�re est l'initialisation : cette premi�re instruction est utilis�e pour pr�parer notre variable compteur.
Dans notre cas, on initialise la variable � 0.
La seconde est la condition : comme pour la boucle while, c'est la condition qui dit si la boucle doit �tre r�p�t�e ou non.
Tant que la condition est vraie, la boucle for continue.
Enfin, il y a l'incr�mentation : cette derni�re instruction est ex�cut�e � la fin de chaque tour de boucle pour mettre � jour
la variable compteur. La quasi-totalit� du temps on fera une incr�mentation, mais on peut aussi faire une d�cr�mentation
(variable--) ou encore n'importe quelle autre op�ration (variable += 2; pour avancer de 2 en 2 par exemple).
    */


    return 0;
}
