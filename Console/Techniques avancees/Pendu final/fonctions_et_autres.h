#ifndef FONCTIONS_ET_AUTRES_H_INCLUDED
#define FONCTIONS_ET_AUTRES_H_INCLUDED
#include <ctype.h>
#include <string.h>
#define TAILLE_MOT 100
#define TAILLE_MAX   1000
typedef struct MotCache MotCache;
struct MotCache
{
    char cache[TAILLE_MOT];
    char decouvert[TAILLE_MOT];
};
char lireCaractere();
void cacherMot(char *motACacher, size_t tailleMot);
void sezam(char *pointeur, char lettre, int i);
int gagne(int lettreTrouvee[], int tailleTableau);
int rechercherCaractere(int lettre, char *motSecret, int lettreTrouvee[]);
void viderBuffer();
int lire(char* mot, int longueur);
void formaterMot(char *chaine, size_t tailleMotVoulue);




#endif // FONCTIONS_ET_AUTRES_H_INCLUDED
