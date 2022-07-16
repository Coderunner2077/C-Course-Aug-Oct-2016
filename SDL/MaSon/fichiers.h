#ifndef FICHIERS_H_INCLUDED
#define FICHIERS_H_INCLUDED

int chargerNiveau(int niveau[][NB_BLOCS_LARGEUR], long level);
int sauvegarderNiveau(int niveau[][NB_BLOCS_LARGEUR], long level);
void afficherBravo(SDL_Surface *ecran);

#endif // FICHIERS_H_INCLUDED
