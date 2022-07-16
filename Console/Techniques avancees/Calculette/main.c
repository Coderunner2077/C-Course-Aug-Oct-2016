#include "fonctions.h"

int main(int argc, char *argv[])
{
    long quitter=1;
do
{
    double resultat=0, nombre2, nombre1;
    long nombre3, nombre4, resultat2=0;
    int signe, modulo=0, arreter=0;
    printf("==== CALCULATRICE ====\n");
    printf("--- Entrez un premier nombre ---\n");
    nombre1=lireDouble();
    do
    {
        printf("\n--- Entrez le signe ---\n\n");
        printf("--- Pour multiplier, tapez '*'. ---\n---Pour diviser, tapez '/' ---\n");
        printf("--- Pour additionner, tapez '+'. Pour soustraire, tapez '-'. ---\n");
        printf("--- Pour modulo, tapez '%' ---\n");
        signe=lireLettre();
        if(signe!='+'&& signe!='*' && signe!='-' && signe !='/'&& signe!='%')
            {
                printf("*** ENTREE INVALIDE! ***");
                arreter=1;
            }
        else
            arreter=0;

    }while(arreter);
    printf("\n--- Entrez le second nombre ---\n");
    nombre2=lireDouble();

    if(signe=='*')
    resultat=multiplier(nombre1, nombre2);
    else if(signe=='+')
        resultat=nombre1+nombre2;
    else if(signe=='-')
        resultat=nombre1-nombre2;
    else if(signe=='/')
        resultat=nombre1/nombre2;
    else if(signe=='%')
    {
        nombre3=nombre1;
        nombre4=nombre2;
        resultat2=nombre3%nombre4;
        modulo=1;
    }
    if(modulo)
        printf("%ld %c %ld = %ld", nombre3, signe, nombre4, resultat2);
    else
        printf("%f %c %f = %f\n", nombre1, signe, nombre2, resultat);
    printf("\n\nEntrer 1 pour faire un autre calcul. Sinon, entrer 0 pour quitter\n");
    quitter=lireLong();
}while(quitter);

    return 0;
}
