#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double nombre1=0,nombre2=0,resultat=0,operation=0;//absolu=0,dessus=0,dessous=0,racine=0;
    int nombre3=0,nombre4=0,resultat2=0,operation2=0;//absolu2=0;
    /*
    printf("Tapez un nombre quelconque\n");
    scanf("%lf",&nombre1);
    printf("Entrez un second nombre\n");
    scanf("%lf",&nombre2);
    resultat=nombre1+nombre2;
    printf("%f+%f=%f\n",nombre1,nombre2,resultat);
    printf("Tapez un nombre quelconque\n");
    scanf("%lf",&nombre1);
    printf("Entrez un second nombre\n");
    scanf("%lf",&nombre2);
    resultat=nombre1/nombre2;
    printf("%f/%f=%f\n",nombre1,nombre2,resultat);
    printf("Tapez un nombre quelconque\n");
    scanf("%d",&nombre3);
    printf("Entrez un second nombre\n");
    scanf("%d",&nombre4);
    resultat2=nombre3%nombre4;
    printf("%d modulo %d=%d\n",nombre3,nombre4,resultat2);
    resultat=5.0/2.0;
    printf("5/2=%f\n",resultat);
    */

    /*
    printf("Tapez 3 nombres quelconques\n");
    scanf("%lf",&nombre1);
    scanf("%lf",&nombre2);
    scanf("%d",&nombre3);
    resultat=(nombre1+nombre2)*nombre3;
    printf("(%f+%f)*%d=%f\n",nombre1,nombre2,nombre3,resultat);
    resultat++;//INCREMENTATION qui équivaut à : resultat=resultat+1;
    printf("plus 1=%f\n",resultat);
    resultat--;
    resultat--;//Décrémentation
    printf("moins 1=%f\n",resultat);
    //Voici les autres raccourcis:
    resultat*=2;//Equivaut à resultat=resultat*2;
    printf("foix deux=%f\n",resultat);
    resultat+=6;
    resultat-=20;
    resultat/=4;
    resultat2=resultat;
    resultat2%=2;
    printf("Et le resultat final, après maintes opErations raccourcies est: %d.\n",resultat2);
    */

    /*
    printf("Entrez un nombre entier:\n");
    scanf("%d",&nombre3);
    nombre3=nombre3*nombre3;
    printf("Ce nombre au carrE est egal a: %d\n",nombre3);
    */

    /*
    //Remarque: toutes les fonctions suivantes, hormis la fonction abs, renvoient un nombre de type double
    nombre1=-20.50;
    absolu=fabs(nombre1);
    nombre3=-20;
    absolu2=abs(nombre3);
    printf("|%f|=%f\n",nombre1,absolu);
    printf("|%d|=%d\n",nombre3,absolu2);//Elle renvoie donc un nombre entier de type int et non un double comme fabs
    nombre2=3.01;
    dessus=ceil(nombre2);
    printf("Arrondi superieur de %f = %f\n",nombre2,dessus);
    nombre2=3.99;
    dessous=floor(nombre2);
    printf("Arrondi inferieur de %f = %f\n",nombre2,dessous);
    resultat=pow(dessous,3);//pow(nombre, puissance);
    printf("%f^3=%f\n",dessous,resultat);
    nombre1=225;
    racine=sqrt(nombre1);
    printf("Racine carree de %f est %f\n",nombre1,racine);
    */
    /*
    sin, cos, tan
Le fonctionnement est le même, ces fonctions renvoient un double.

Ces fonctions attendent une valeur en radians.

    asin, acos, atan

Ce sont les fonctions arc sinus, arc cosinus et arc tangente, d'autres fonctions de trigonométrie.
Elles s'utilisent de la même manière et renvoient un double.

    exp

Cette fonction calcule l'exponentielle d'un nombre. Elle renvoie un double (oui, oui, elle aussi).

    log

Cette fonction calcule le logarithme népérien d'un nombre (que l'on note aussi « ln »).

    log10
Cette fonction calcule le logarithme base 10 d'un nombre
    */

    /*
    printf("Tapez un nombre quelconque\n");
    scanf("%lf",&nombre1);
    printf("Entrez un second nombre\n");
    scanf("%lf",&nombre2);
    printf("Pour les additionner, tapez 1. Soustraire, tapez 2. Multiplier, tapez 3. Et diviser, tapez 4\n");
    scanf("%lf",&operation);
    If(operation==1)
    {
        resultat=nombre1+nombre2;
        printf("%f+%f=%f\n",nombre1,nombre2,resultat);
    }
    if(operation==2)
    {
        resultat=nombre1-nombre2;
        printf("%f-%f=%f\n",nombre1,nombre2,resultat);
    }
    if(operation==3)
    {
        resultat=nombre1*nombre2;
        printf("%f*%f=%f\n",nombre1,nombre2,resultat);
    }
    if(operation==4)
    {
        resultat=nombre1/nombre2;
        printf("%f/%f=%f\n",nombre1,nombre2,resultat);
    }
    else
    {
        printf("Desole, cette calculatrice n'effectue que les quatre operations de base\n");
    }
    */
    printf("Tapez un nombre quelconque\n");
    scanf("%d",&nombre3);
    printf("Entrez un second nombre\n");
    scanf("%d",&nombre4);
    printf("Pour les additionner, tapez 1. Soustraire, tapez 2. Multiplier, tapez 3. Et diviser, tapez 4\n");
    scanf("%d",&operation2);
    switch(operation2)
    {
        case 1:
            resultat2=nombre3+nombre4;
            printf("%d+%d=%d\n",nombre3,nombre4,resultat2);
        break;
        case 2:
            resultat2=nombre3-nombre4;
            printf("%d-%d=%d\n",nombre3,nombre4,resultat2);
        break;
        case 3:
            resultat2=nombre3*nombre4;
            printf("%d*%d=%d\n",nombre3,nombre4,resultat2);
        break;
        case 4:
            nombre1=nombre3;
            nombre2=nombre4;
            resultat=nombre1/nombre2;
            printf("%d/%d=%f\n",nombre3,nombre4,resultat);
        break;
        default:
            printf("Desole, cette calculatrice n'effectue que les quatre operations de base\n");
        break;
    }

    return 0;
}
