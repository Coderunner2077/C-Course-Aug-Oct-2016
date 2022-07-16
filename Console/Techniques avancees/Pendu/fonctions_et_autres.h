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
void definirStructure(MotCache* pointeur, size_t nbCaracteres, char motACopier[]);

void sezam(MotCache *chaine, char lettre, int i);
int gagne(int lettreTrouvee[], int tailleTableau);
int rechercherCaractere(int lettre, char *motSecret, int lettreTrouvee[]);
void viderBuffer();


#endif // FONCTIONS_ET_AUTRES_H_INCLUDED
