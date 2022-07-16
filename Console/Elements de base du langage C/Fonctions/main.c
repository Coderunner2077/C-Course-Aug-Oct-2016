#include <stdio.h>
#include <stdlib.h>

/*
double conversion(double euros)
{
    return  6.55957*euros;
}
int main(int argc, char* argv[])
{
    double euro=0;
    printf("Combien d'euros voulez-vous convertir en francs?\n\n");
    scanf("%lf",&euro);
    printf("%f euro(s)=%f franc(s)",euro,conversion(euro));
    return 0;
}
*/


/*
double conversion(double euros)
{
    double francs=0;
    francs=6.55957*euros;
    return  francs;
}
int main(int argc, char* argv[])
{
    double euro=0,franc=0;
    int quitter;
    for(quitter=0;quitter!=2;quitter--)
    {
    printf("Combien d'euros voulez-vous convertir en francs?\n\n");
    scanf("%lf",&euro);
    franc=conversion(euro);
    printf("%f euro(s)=%f franc(s)",euro,franc);
    printf("\nPour quitter, tapez 1\n\n");
    scanf("%d",&quitter);
    }
    return 0;
}
*/

/*
double conversion(double francs)
{
    double euros=0;
    euros=francs/6.55957;
    return euros;
}
int main(int argc, char* argv[])
{
    double euro=0,franc=0;
    int quitter=0;
    do
    {
    printf("Combien de francs voulez-vous convertir en euros?\n\n");
    scanf("%lf",&franc);
    euro=conversion(franc);
    printf("%f franc(s)=%f euro(s)",franc,euro);
    printf("\nPour aller au menu principal, tapez 1. Pour quitter, tapez 0\n\n");

    scanf("%d",&quitter);
    }while(quitter);
    return 0;
}
*/

/*
void punition(int nombreLignes)
{
    int i;
    for(i=0;i<nombreLignes;i++)
    {
        printf("\nJe ne recopierai pas!\n");
    }
}
int main(int argc, char* argv[])
{
    punition(1000);

    return 0;
}
*/


//Air d'un rectangle:les deux façons de proceder(void ou pas void)

/*
void aireRectangle(double hauteur,double largeur)
{
    double aire=0;
    aire=hauteur*largeur;
    printf("L'aire du rectangLe de %f cm de hauteur et de %f cm de largeur est de %f cm2\n",hauteur,largeur,aire);
}
int main(int argc, char* argv[])
{
    double h=0,l=0;
    printf("hauteur?\n");
    scanf("%lf",&h);
    printf("largeur?\n");
    scanf("%lf",&l);
    aireRectangle(h,l);

    return 0;
}
*/

double aireRectangle(double hauteur,double largeur)
{
    double aire=0;
    aire=hauteur*largeur;

    return aire;
}

int main(int argc, char* argv[])
{
    double h=0,l=0;
    printf("hauteur?\n");
    scanf("%lf",&h);
    printf("largeur?\n");
    scanf("%lf",&l);
    aireRectangle(h,l);
    printf("L'aire du rectangLe de %f cm de hauteur et de %f cm de largeur est de %f cm2\n",h,l,aireRectangle(h,l));

    return 0;
}



