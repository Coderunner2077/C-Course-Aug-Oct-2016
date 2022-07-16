#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

void jouer(SDL_Surface *ecran);//J'AURAIS PU ENVOYER UN BOLEEN POUR DIRE SI OUI OU NON ON A GAGNE
void deplacerJoueur(int carte[][NB_BLOCS_HAUTEUR], SDL_Rect *pos, int direction);
void deplacerCaisse(int *premiereCase, int *secondeCase);

#endif // JEU_H_INCLUDED
