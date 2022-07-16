#ifndef FONCTIONS_ET_AUTRES_H_INCLUDED
#define FONCTIONS_ET_AUTRES_H_INCLUDED
#include <ctype.h>
#include <string.h>
#include <time.h>
#define TAILLE_MOT 100
#define TAILLE_MAX 110
char lireCaractere();

int gagne(int lettreTrouve[], size_t tailleTableau);

int rechercheLettre(int lettre, size_t nbLettres, char *chaine, int tableau[]);


#endif // FONCTIONS_ET_AUTRES_H_INCLUDED
