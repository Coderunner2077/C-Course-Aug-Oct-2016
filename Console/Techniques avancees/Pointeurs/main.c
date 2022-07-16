#include <stdio.h>
#include <stdlib.h>

/*

void decoupeMinutes(int *pointeurHeures, int *pointeurMinutes);

int main(int argc, char *argv[])
{
    int h=0, m=90;
    decoupeMinutes(&h,&m);
    printf("%d heure(s) et %d minutes\n",h,m);
    return 0;
}

void decoupeMinutes(int *pointeurHeures,int *poineurMinutes)
{
    *pointeureures=*pointeurMinutes/60;
    *pointeurMinutes=*pointeurMinutes%60;




}
*/


int main(int argc, char *argv[])
{
    int variable=10, variable2=20;
    int *pointeur=NULL,*pointeur2=NULL;


    printf("\nadresse de la variable de valeur %d=%p\n",variable,&variable);//écrit dans le système hexadécimal
    printf("\nadresse de la variable de valeur %d=%d\n",variable,&variable);//écrit dans le système décimal

    printf("\nadresse de la variable de valeur %d=%p\n",variable2,&variable2);
    printf("\npointeur=%d\n",pointeur);
    pointeur=&variable;
    pointeur2=&variable2;
    printf("\nl'adresse de la variable renvoyee par le pointeur=%d\n",pointeur);//écrit dans le système décimal
    printf("\nl'adresse de la variable renvoyee par le pointeur=%p\n",pointeur);
    printf("\nl'adresse de la variable2 renvoyee par le pointeur2=%d\n",pointeur2);
    printf("\nvaleur de la variable renvoyee par le pointeur=%d\n",*pointeur);
    printf("\nvaleur de la variable2 renvoyee par le pointeur2=%d\n",*pointeur2);
    printf("\nl'adresse du pointeur=%p",&pointeur);
    printf("\nl'adresse du pointeur2=%p",&pointeur2);
    *pointeur+=1;
    printf("\n\nvaleur de la variable changee au biais du pointeur : %d",variable);


    return 0;
}


/*
void tripleNombre(int *pointeurSurNombre);

int main(int argc, char *argv[])
{
    int nombre=5;//1.UNE VARIABLE nombre EST CREE DANS MAIN
    tripleNombre(&nombre);//2.ON APPELLE LA FONCTION tripleNombre.ON LUI ENVOIE EN PARAMETRE L'ADRESSE DE NOTRE VARIABLE nombre
    printf("%d",nombre);//5.DE RETOUR DANS NOTRE FONCTION main, NOTRE nombre VAUT MAINTENANT 15 CAR LA FONCTION triplePointeur A DIRECTEMENT MODIFIE LA VALEUR DE nombre

    return 0;
}

void tripleNombre(int *pointeurSurNombre)//3.LA FONCTION RECOIT L'ADRESSE DE NOTRE VARIABLE nombre. A L'INTERIEUR DE LA FONCTION tripleNombre, ON A DONC UN POINTEUR pointeurSurNombre QUI CONTIENT L'ADRESSE DE LA VARIABLE nombre
{
    *pointeurSurNombre*=3;//4.MAINTENANT QU'ON A UN POINTEUR SUR nombre,ON PEUT  MODIFIER DIRECTEMENT LA VARIABLE nombre EN MEMOIRE! IL SUFFIT D'UTILISER *pointeurSurNombre POUR DESIGNER LA VARIABLE nombre. ON MULTIPLIE AINSI LA VARIABLE nomre PAR 3
}

*/

/*

void tripleNombre(int *pointeurSurNombre);

int main(int argc, char *argv[])
{
    int nombre=5;
    int *pointeur=&nombre;
    tripleNombre(pointeur);
    printf("%d",nombre);

    return 0;
}


void tripleNombre(int *pointeurSurNombre)
{
    *pointeurSurNombre*=3;
}

*/
