#include <stdio.h>
#include <stdlib.h>
#include "Structures_Enumerations.h"

void initialiserStructure(Coordonnees *point);

int main (int argc, char *argv[])
{
    /*Il existe deux sortes de "types de variables personnalisees": les structure et les enumerations
    On les place dans le fichier .h, tout comme les prototypes et les #define*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //STRUCTURES
    //Definir une structure:


    struct Coordonnees point;//JE PEUX FAIRE UN ALIAS DE STRUCTURE AFIN D'EVITER DE REECRIRE struct AVEC L'INSTRUCTION SPECIALE typedef A AJOUTER JUSTE AVANT LA DEFINITION DE LA STRUCTURE
    //JE MODIFIE LES COORDONNES DU POINT
        point.x=10;
        point.y=20;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //MODIFIER LES COMPOSANTES DE LA STRUCTURE

    //POUR ACCEDER A CHAQUE VARIABLE ON DOIT DONC ECRIRE: variable.nomDeLaComposante

/*
    Personne utilisateur;
    printf("\nVotre nom?");
    scanf("%s",utilisateur.nom);
    printf("\nVotre prenom?");
    scanf("%s",utilisateur.prenom);
    printf("\nAge?\n");
    scanf("%d",&utilisateur.age);
    printf("\nVotre ville?");

    scanf("%s",utilisateur.ville);

    printf("\nVous vous appelez %s %s et vous avez %d ans et vous habitez a %s.\n", utilisateur.prenom,utilisateur.nom,utilisateur.age,utilisateur.ville);

    */

    Personne joueur[2];
    int i;
    for(i=0;i<2;i++)
    {
        printf("\ngarcon? Si oui, entrez un nombre positif");

        scanf("%d",&joueur[i].garcon);
        printf("\nVotre nom?");
        scanf("%s",joueur[i].nom);
        printf("\nVotre prenom?");
        scanf("%s",joueur[i].prenom);
        printf("\nAge?\n");
        scanf("%d",&joueur[i].age);
        printf("\nVotre ville?");
        scanf("%s",joueur[i].ville);
        if(joueur[i].garcon)
            printf("\nJoueur[%d], vous etes Monsieur ",i);
        else
            printf("\nJoueur[%d], vous etes Madame ",i);

        printf("%s %s, vous avez %d ans, vous habitez %s ",joueur[i].prenom, joueur[i].nom, joueur[i].age, joueur[i].ville);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //INITIALISER UNE STRUCTURE (METHODE PLUS SIMPLE,A PRIVILIEGIER)
    //L'INITIALISATION QUI RESSEMBLE A CELLE D'UN TABLEAU
    Coordonnees pointA={0,0};//ça donnera dans l'ordre pointA.x=0 et pointA.y=0;
    Personne utilisateur2={"","","",0,0};//EN EFFET, J'AI DROIT D'INITIALISER UNE CHAINE EN ECRIVANT JUSTE "" (RIEN ENTRE LES GUILLEMETS)

    //INITIALISER AU BIAIS D'UNE FONCTION
    Coordonnees* pointC=NULL;//UN POINTEUR DE STRUCTURE QUI SE CREE DE LA MEME MANIERE QU'UN POINTEUR DE INT, DE DOUBLE, ETC.
    //<=>Coordonnees *point=NULL; sauf que là on peut déclarer plusieurs pointeurs de meme type a la fois

    //=>ENVOI DE LA STRUCTURE A UNE FONCTION
    Coordonnees pointB;
    initialiserStructure(&pointB);
    printf("\nPointB(%d;%d)",pointB.x,pointB.y);
    //UN RACCOURCI TRES PRATIQUE
    printf("\n\nLe pointeur (*variable).nomDeLaComposante=0 peut s'ecrire comme suit: \npointeur->nomDeLaComposante=0");
    //Attention, on ne peut utiliser la flèche que sur un pointeur.
    //Si je travaille directement sur la variable, je dois utiliser le point comme on l'a vu au début.

    //PENSE-BETE
    Coordonnees monPoint;
    Coordonnees *pointeur=&monPoint;
    monPoint.x=10;//On travaille sur une variable, on utilise le point
    pointeur->x=20;//On travaille sur un pointeur, on utilise la flèche
    printf("\nmonPoint = %d\n",monPoint.x);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //ENUMERATIONS
    /*Une énumération ne contient pas de « sous-variables » comme c'était le cas pour les structures. C'est une liste de
    « valeurs possibles » pour une variable. Une énumération ne prend donc qu'une case en mémoire et cette case peut prendre
    une des valeurs que vous définissez (et une seule à la fois)*/
    Volume musique = MOYEN;//J'AI EN MEME TEMPS CREE ET INITIALISE UNE VARIABLE musique DE TYPE VOLUME
    //JE PEUX CHANGER PLUS TARD LA VALEUR DE musique POUR FAIBLE OU FORT
    printf("Volume : %d", musique);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //ACCOCIATION DE NOMBRES AUX VALEURS
    //Remarque:LES VALEURS DE ENUM SONT EN MAJUSCULES...TOUT COMME LES CONSTANTES ET LES DEFINE
    //DISONS QU'IL Y A UNE ANALOGIE ENTRE EUX TOUS: Le compilateur associe automatiquement un nombre à chacune des valeurs
    // possibles de l'énumération
    //DANS NOTRE CAS,FAIBLE VAUT 0. MOYEN VAUT 1 et FORT VAUT 2
    printf("\nnVolume de la musique= %d",musique);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //ACCOCIER UNE VALEUR PRECISE
    //JE PEUX FAIRE LE TRAVAIL DU COMPILATEUR, MAIS... A MA GUISE!
    //AINSI:
    Son musique2=LOW;// SUR UN ORDI AVEC LE VOLUME DE 0 A 100, CELA VA CORRESPONDRE A 10 % DU VOLUME
    printf("\nVolume de la musique= %d",musique2);
    return 0;
}


void initialiserStructure(Coordonnees *point)
{
    //*point.x=0 FAUX!!
    //*point.x=0 FAUX!!!!!!
    //Ce serait trop facile… Pourquoi on ne peut pas faire ça ? Parce que le point de séparation s'applique sur le mot point
    // et non sur *point en entier. Or, moi ce que je veux, c'est accéder à *point pour en modifier la valeur.
    //Pour régler le problème, il faut placer des parenthèses autour de *point. Comme cela, le point de séparation s'appliquera
    // à *point et non juste à point
    (*point).x=0;//autre ecriture, plus rapide: point->x=0;
    (*point).y=0;

}
