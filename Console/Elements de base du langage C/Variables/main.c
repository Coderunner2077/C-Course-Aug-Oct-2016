#include <stdio.h>
#include <stdlib.h>

int main(int argc, char  *argv[])
{
    int nombreDeVies,niveau=1, age=0;
    nombreDeVies=5;
    int nombreDeButs=0;
    const int NOMBRE_DE_VIES_INITIALES=5;//Déclaration d'une constante. Il est obligatoire de combiner la déclaration et l'affectation de la constante

    printf("Il vous reste %d vies et vous avez le niveau %d\n\nQuel age avez-vous?\n",nombreDeVies, niveau);

    scanf("%d",&age);
    printf("Vous avez %d.\nQuel est votre poids?\n",age);
    double poids=0;
    scanf("%lf",&poids);//Attention, il y a une petite divergence de format entre printf et scanf ! Pour récupérer un float, c'est le format "%f" qu'il faut utiliser, mais pour le type double c'est le format "%lf"
    printf("%f kg?? Il serait temps de maigrir un peu!\n",poids);
    return 0;
}
