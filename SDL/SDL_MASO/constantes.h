/*
constantes.h
------------


Rôle : définit des constantes pour tout le programme (taille de la fenêtre...)
*/
#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

    #define TAILLE_BLOC         34 // Taille d'un bloc (carré) en pixels
    #define NB_BLOCS_LARGEUR    20
    #define NB_BLOCS_HAUTEUR    16
    #define LARGEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_LARGEUR
    #define HAUTEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_HAUTEUR


    enum {HAUT, BAS, GAUCHE, DROITE};
    enum {VIDE, MUR, CAISSE, OBJECTIF, MARIO, CAISSE_OK};

#endif
