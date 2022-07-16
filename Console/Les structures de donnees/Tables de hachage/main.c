#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Effectif Effectif;
struct Effectif
{
    char nom[100];
    char age[7];
    char note[6];
};
void copierStructure(Effectif *copie, Effectif* original[], int i)
{

    strcpy(copie->nom, original[i]->nom);
    strcpy(copie->age, original[i]->age);
    strcpy(copie->note, original[i]->note);

}
int hachage(Effectif eleve[], int tailleTableau, char *chaine)
{
    int i = 0, j = 0, nombreHache = 0, nbHacheColli = 0, nbMagique = 0, continuer = 1, collision = 0;
    char motCollision[100] = {""};

    for(i=0; chaine[i]!='\0'; i++)
    {
        nombreHache += chaine[i];
    }
    nombreHache %= 100;

    while(continuer)
    {
    if(nombreHache >= tailleTableau)
        nombreHache -= tailleTableau / 2;

    for(i=0; i<tailleTableau; i++)
    {
       if(eleve[i].nom != chaine && nombreHache != 0)
       {
           for(j=0; eleve[i].nom[j]!='\0'; j++)
           {
               nbHacheColli += eleve[i].nom[j];
           }
           nbHacheColli %= 100;
           if(nombreHache == nbHacheColli)
           {
               collision++;
               if(nombreHache >= 100)
                    nombreHache = 1;
           }
       }
    }
    if(!collision)
        continuer = 0;
    else
        nombreHache++;
    collision = 0;
    }
    return nombreHache;
}
Effectif* rechercheTableHachage(Effectif *table[], Effectif eleve[], int tailleTableau, char *name)
{
    int nombreHache = 0;
    size_t n;
    n = strlen(name);

    char *motCollision = malloc((n + 1) * sizeof(char));
    Effectif *elementRecherche = NULL;
    nombreHache = hachage(eleve, tailleTableau, name);
    while(strcmp(table[nombreHache]->nom, name) != 0)
    {
        //sprintf(motCollision, "%s", );
        nombreHache++;
        if(nombreHache >= tailleTableau)
            nombreHache = 0;
    }
    elementRecherche = table[nombreHache];
    return elementRecherche;
}

int main()
{
    int i = 0, k = 0, tailleTableau = 100;
    Effectif *infoEleve2 = malloc(sizeof(Effectif));
    Effectif *test = malloc(sizeof(Effectif));
    Effectif *test2 = NULL;
    Effectif eleve[100] = {{"Julien Bassoli", "21 ans", "15/20"}, {"Aurelien Lefebvre", "20 ans", "6/20"},
    {"Luc Lebel", "18 ans", "18/20"}, {"Marc Pinard", "17 ans", "9/20"}, {"Jules Bassoli", "21 ans", "14/20"},
    {"Aurel Lefebvre", "20 ans", "12/20"}, {"Lucien Lebel", "18 ans", "16/20"}, {"Mars Pinard", "17 ans", "9/20"},
    {"Juliena Bassoli", "21 ans", "14/20"}, {"Aureliena Lefebvre", "20 ans", "12/20"}, {"Luca Lebel", "18 ans", "18/20"},
    {"Marca Pinard", "17 ans", "9/20"}, {"Julesa Bassoli", "21 ans", "1/20"}, {"Aurela Lefebvre", "20 ans", "12/20"},
    {"Luciena Lebel", "18 ans", "7/20"}, {"Marsa Pinard", "17 ans", "19/20"}, {"Julieno Bassoli", "21 ans", "14/20"},
    {"Aurelieno Lefebvre", "20 ans", "12/20"}, {"Luco Lebel", "18 ans", "7/20"}, {"Marco Pinard", "17 ans", "9/20"},
    {"Juleso Bassoli", "21 ans", "14/20"}, {"Aurelo Lefebvre", "20 ans", "20/20"}, {"Lucieno Lebel", "18 ans", "6/20"},
    {"Marso Pinard", "17 ans", "9/20"}, {"Julienao Bassoli", "21 ans", "14/20"}, {"Aurelienao Lefebvre", "20 ans", "12/20"},
    {"Lucao Lebel", "18 ans", "18/20"}, {"Marcao Pinard", "17 ans", "9/20"}, {"Julesao Bassoli", "21 ans", "6/20"},
    {"Aurelao Lefebvre", "20 ans", "12/20"}, {"Lucienao Lebel", "18 ans", "18/20"}, {"Marsao Pinard", "17 ans", "9/20"},
    {"Julieni Bassoli", "21 ans", "14/20"}, {"Aurelieni Lefebvre", "20 ans", "12/20"}, {"Luci Lebel", "18 ans", "5/20"},
    {"Marci Pinard", "17 ans", "9/20"}, {"Julesi Bassoli", "21 ans", "14/20"}, {"Aureli Lefebvre", "20 ans", "12/20"},
    {"Lucieni Lebel", "18 ans", "18/20"}, {"Marsi Pinard", "17 ans", "8/20"}, {"Julienai Bassoli", "21 ans", "14/20"},
    {"Aurelienai Lefebvre", "20 ans", "12/20"}, {"Lucai Lebel", "18 ans", "17/20"}, {"Marcai Pinard", "17 ans", "9/20"},
    {"Julesai Bassoli", "21 ans", "11/20"}, {"Aurelai Lefebvre", "20 ans", "12/20"}, {"Lucienai Lebel", "18 ans", "4/20"},
    {"Marsai Pinard", "17 ans", "9/20"}, {"Julienoi Bassoli", "21 ans", "13/20"}, {"Aurelienoi Lefebvre", "20 ans", "12/20"},
    {"Lucoi Lebel", "18 ans", "11/20"}, {"Marcoi Pinard", "17 ans", "9/20"}, {"Julesoi Bassoli", "21 ans", "14/20"},
    {"Aureloi Lefebvre", "20 ans", "12/20"}, {"Lucienoi Lebel", "18 ans", "18/20"}, {"Marsoi Pinard", "17 ans", "9/20"},
    {"Julienaoi Bassoli", "21 ans", "14/20"}, {"Aurelienaoi Lefebvre", "20 ans", "12/20"}, {"Lucaoi Lebel", "18 ans", "18/20"},
    {"Marcaoi Pinard", "17 ans", "9/20"}, {"Julesaoi Bassoli", "21 ans", "14/20"}, {"Aurelaoi Lefebvre", "20 ans", "12/20"},
    {"Lucienaoi Lebel", "18 ans", "18/20"}, {"Marsaoi Pinard", "17 ans", "9/20"}, {"Julienio Bassoli", "21 ans", "14/20"},
    {"Aurelienio Lefebvre", "20 ans", "12/20"}, {"Lucio Lebel", "18 ans", "11/20"}, {"Marcio Pinard", "17 ans", "9/20"},
    {"Julesio Bassoli", "21 ans", "14/20"}, {"Aurelio Lefebvre", "20 ans", "12/20"}, {"Lucienio Lebel", "18 ans", "18/20"},
    {"Marsio Pinard", "17 ans", "13/20"}, {"Julienioa Bassoli", "21 ans", "14/20"}, {"Aurelienioa Lefebvre", "20 ans", "12/20"},
    {"Lucioa Lebel", "18 ans", "18/20"}, {"Marcioa Pinard", "17 ans", "9/20"}, {"Julesioa Bassoli", "21 ans", "13/20"},
    {"Aurelioa Lefebvre", "20 ans", "12/20"}, {"Lucienioa Lebel", "18 ans", "18/20"}, {"Marsioa Pinard", "17 ans", "9/20"},
    {"Oilerua Lefebvre", "20 ans", "7/20"}};
    Effectif* tableau[100] = {NULL};
    //VARIANTE : Effectif** tableau = malloc(100 * sizeof(Effectif));
    /*for(i=0; i<100; i++)
         tableau[i]= &eleve[i];
    */
    for(i=0; i<100; i++)
    {
        int nombreHache = 0;
        nombreHache = hachage(eleve, 100, eleve[i].nom);
        printf("%d\n", nombreHache);
        if(tableau[nombreHache] == NULL)
            tableau[nombreHache] = &eleve[i];
        else
        {
            while(tableau[k] != NULL)
            {
                nombreHache++;
                k = nombreHache;
                if(k >= tailleTableau)
                    nombreHache = 0;
            }
            tableau[k] = &eleve[i];
        }
    }
    //copierStructure(infoEleve2, tableau, 3);
    //memcpy(test, tableau[0], sizeof(Effectif));
    //strcpy(infoEleve2.nom, tableau[1]->nom);
    for(i=0; i<100; i++)
    {
        printf("%s\n",tableau[i]);

        printf("\n");
    }
    test2 = rechercheTableHachage(tableau, eleve, 100, "Aurelioa Lefebvre");
    printf("Donnees recherchees : %s, %s, %s", test2->nom, test2->age, test2->note);
    /*
    printf("%s\n", eleve[1].nom);
    printf("%s\n", infoEleve2->nom);
    printf("%s\n", test->nom);
    printf("%s\n", tableau[9]);
    */
    return 0;
}
