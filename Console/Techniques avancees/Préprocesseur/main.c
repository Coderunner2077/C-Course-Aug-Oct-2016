#include <stdio.h>
#include <stdlib.h>
#define NOMBRE_DE_VIES_INITIALES    3
#define LARGEUR_FENETRE     800
#define HAUTEUR_FENETRE     600
#define NOMBRE_PIXELS    (LARGEUR_FENETRE*HAUTEUR_FENETRE)
#define TAILLE_MAX     1000
#define TERME_DEFINI_SANS_DEFINITION
#define MACRO()     printf("\nMon premier macro");
#define RACONTER_SA_VIE()   printf("\nJe m'appelle Brice");\
                            printf("\nJe viens de Nice");\
                            printf("\nEt j'aime la glisse");
#define MAJEUR(age)  if(age >= 18)\
                     printf("\nVous etes majeur\n");\
                     else\
                     printf("\nVous etes mineur");
#define MINEUR(age,name)   if(age<18)\
                            printf("\nVous etes mineur %s\n",name);
#if condition
    /* Code source � compiler si la condition est vraie */
#elif condition2
    /* Sinon si la condition 2 est vraie compiler ce code source */
#endif

int main(char argc,char *argv[] )
{
//les #define sont g�n�ralement plac�s dans des .h
    int vies=NOMBRE_DE_VIES_INITIALES;
    printf("%d",vies);
    int pixels=NOMBRE_PIXELS;//ON PEUT FAIRE AINSI TOUTES LES OPERATIONS DE BASE(+,-,*,/,%)
    printf("\n%d",pixels);
    char chaine[TAILLE_MAX];//ON PEUT LE FAIRE CAR TAILLE_MAX N'EST PAS UNE VARIABLE NI UNE CONSTANTE, MAIS UNE VALEUR REMPLACEE AVANT LA COMPILATION
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //CONSTANTES PREDEFINIES
    printf("\nErreur de la ligne %d du fichier %s",__LINE__,__FILE__);
    printf("\nCe fichier a ete compile le %s a %s",__DATE__,__TIME__);
    /*
    //Quand on utilise #define pour rechercher-remplacer un mot par un code source, on dit qu'on cr�e une macro

__LINE__ : donne le num�ro de la ligne actuelle.
__FILE__ : donne le nom du fichier actuel.
__DATE__ : donne la date de la compilation.
__TIME__ : donne l'heure de la compilation
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //LES MACROS
    //MACROS SANS PARAMETRES
    MACRO()
    RACONTER_SA_VIE()

    //MACROS AVEC PARAMETRES
    int age=26;
    MAJEUR(age)

    MAJEUR(17)
    MINEUR(16,"Marc")

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //CONDIIONS
    /*
    Remarque: il n'y a pas d'accolades au pr�processeur.
    Le mot-cl� #if permet d'ins�rer une condition de pr�processeur. #elif signifie else if (sinon si).
La condition s'arr�te lorsque j'ins�re un #endif.
    L'int�r�t, c'est qu'on peut ainsi faire des compilations conditionnelles.
En effet, si la condition est vraie, le code qui suit sera compil�. Sinon, il sera tout simplement supprim� du fichier le
temps de la compilation. Il n'appara�tra donc pas dans le programme final.*/
    //
    //#ifdef et #ifndef
    /*En effet, il est possible d'utiliser #ifdef pour dire � Si la constante est d�finie �.
#ifndef, lui, sert � dire � Si la constante n'est pas d�finie �*/

    //ifndef EST INDISPENSABLE pour �viter les inclusions infinies
/*A mettre dans tous les fichiers .h:
#ifndef DEF_NOMDUFICHIER // Si la constante n'a pas �t� d�finie le fichier n'a jamais �t� inclus
#define DEF_NOMDUFICHIER // On d�finit la constante pour que la prochaine fois le fichier ne soit plus inclus

//Contenu de votre fichier .h (autres include, prototypes, define...) */

//ET #endif A LA FIN
/*Ce qui compte en revanche, c'est de changer de nom de constante � chaque fichier .h diff�rent. Il ne faut pas que �a soit
la m�me constante pour tous les fichiers .h, sinon seul le premier fichier .h serait lu et pas les autres !
*/
    return 0;

}
