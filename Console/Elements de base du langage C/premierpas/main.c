/*
Ci-dessous, ce sont des directives de préprocesseur.
Ces lignes permettent d'ajouter des fichiers au projet,
fichiers que l'on appelle bibliothèques.
Grâce à ces bibliothèques, on disposera de fonctions toutes prêtes pour afficher
par exemple un message à l'écran.
*/

#include <stdio.h>
#include <stdlib.h>

/*
Ci-dessous, vous avez la fonction principale du programme, appelée main.
C'est par cette fonction que tous les programmes commencent.
Ici, ma fonction se contente d'afficher Bonjour à l'écran.

*/
//
int main()
{
  printf("Bonjour"); // Cette instruction affiche Bonjour à l'écran
  int a = 0b1100;
  int b = 0b1;
  printf("\nvoila : %d\n", (a & (8 >> 1)));
  printf("\nvoila : %d\n", a);
  return 0;          // Le programme renvoie le nombre 0 puis s'arrête
}
