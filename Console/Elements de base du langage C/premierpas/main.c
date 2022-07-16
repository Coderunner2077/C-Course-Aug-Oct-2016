/*
Ci-dessous, ce sont des directives de pr�processeur.
Ces lignes permettent d'ajouter des fichiers au projet,
fichiers que l'on appelle biblioth�ques.
Gr�ce � ces biblioth�ques, on disposera de fonctions toutes pr�tes pour afficher
par exemple un message � l'�cran.
*/

#include <stdio.h>
#include <stdlib.h>

/*
Ci-dessous, vous avez la fonction principale du programme, appel�e main.
C'est par cette fonction que tous les programmes commencent.
Ici, ma fonction se contente d'afficher Bonjour � l'�cran.

*/
//
int main()
{
  printf("Bonjour"); // Cette instruction affiche Bonjour � l'�cran
  int a = 0b1100;
  int b = 0b1;
  printf("\nvoila : %d\n", (a & (8 >> 1)));
  printf("\nvoila : %d\n", a);
  return 0;          // Le programme renvoie le nombre 0 puis s'arr�te
}
