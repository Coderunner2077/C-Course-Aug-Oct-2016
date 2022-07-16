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
    /* Code source à compiler si la condition est vraie */
#elif condition2
    /* Sinon si la condition 2 est vraie compiler ce code source */
#endif

int main(char argc,char *argv[] )
{
//les #define sont généralement placés dans des .h
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
    //Quand on utilise #define pour rechercher-remplacer un mot par un code source, on dit qu'on crée une macro

__LINE__ : donne le numéro de la ligne actuelle.
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
    Remarque: il n'y a pas d'accolades au préprocesseur.
    Le mot-clé #if permet d'insérer une condition de préprocesseur. #elif signifie else if (sinon si).
La condition s'arrête lorsque j'insére un #endif.
    L'intérêt, c'est qu'on peut ainsi faire des compilations conditionnelles.
En effet, si la condition est vraie, le code qui suit sera compilé. Sinon, il sera tout simplement supprimé du fichier le
temps de la compilation. Il n'apparaîtra donc pas dans le programme final.*/
    //
    //#ifdef et #ifndef
    /*En effet, il est possible d'utiliser #ifdef pour dire « Si la constante est définie ».
#ifndef, lui, sert à dire « Si la constante n'est pas définie »*/

    //ifndef EST INDISPENSABLE pour éviter les inclusions infinies
/*A mettre dans tous les fichiers .h:
#ifndef DEF_NOMDUFICHIER // Si la constante n'a pas été définie le fichier n'a jamais été inclus
#define DEF_NOMDUFICHIER // On définit la constante pour que la prochaine fois le fichier ne soit plus inclus

//Contenu de votre fichier .h (autres include, prototypes, define...) */

//ET #endif A LA FIN
/*Ce qui compte en revanche, c'est de changer de nom de constante à chaque fichier .h différent. Il ne faut pas que ça soit
la même constante pour tous les fichiers .h, sinon seul le premier fichier .h serait lu et pas les autres !
*/
    return 0;

}
