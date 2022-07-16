#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX  1000
#include <liste_chainnee.h>
int main(int argc, char* argv[])
{
    //PROTOTYPE DE fopen:
    //FILE* fopen(const char* nomDuFichier, const char* modeOuverture);
    //LA FONCTION RENVOIE DONC UN POINTEUR SUR UNE STRUCTURE DE TYPE FILE (CELLE-CI EST DEFINIE DANS stdlib.h)
    FILE* fichier=NULL; //IL EST EXTREMEMENT IMPORTANT DE RECUPERER CE POINTEUR. JE LE CREE AU DEBUT DE MA FONCTION
    //C'EST UNE REGLE FONDAMENTALE QUE D'INITIALISER LES POINTEURS DES LE DEBUT POUR EVITER TOUTE ERREUR PAR LA SUITE
    //NOTE: je ne modifierai jamais le contenu d'un FILE directement, car la forme de cette strucure peut changer d'un OS a l'autre
    // (je ne ferai pas fichier.element par exemple). Je passerai par des fonctions qui manipulent le FILE à ma place)
    fichier=fopen("test.txt","r+");
    int age=0;
    int caractereActuel=0;
    char chaine[TAILLE_MAX]={""};
    int score[3]={0};
    if(fichier!=NULL)
    {

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //ECRIRE DANS LE FICHIER
        //int fputc(int caractere,FILE* nomDuFichier);
        fputc('A',fichier);
        fputc('B',fichier);

        //char* fputs(const char* chaine,FILE* nomDuFichier);
        fputs("\nYo, keep it up!\nAnd take it easy.", fichier);
        printf("\n\nQuel age avez-vous?");
        scanf("%d",&age);

        //fprintf : UN AUTRE EXEMPLAIRE DE LA FONCTION PRINTF. FAUDRA JUSTE INDIQUER UN POINTEUR DE FILE EN PREMIER PARAMETRE
        fprintf(fichier,"\nCelui qui ecrit ceci a %d ans.",age);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //LIRE LE FICHIER

        //int fgetc(FILE* nomDuFichier); LIT UN SEUL CARACTERE A LA FOIS, MAIS AUSSI TOUS LES CARACTERES SI ON FAIT UNE BOUCLE
        do
        {
            caractereActuel = fgetc(fichier);//ON LIT LE CARACTERE
            printf("%c",caractereActuel);//ON L'AFFICHE

        }while(caractereActuel!=EOF);//On continue tant que fgetc n'a pas retourné EOF
        //EOF EST UN #define QUI S'AFFICHE LORSQU'ON ARRIVE A LA FIN DU FICHIER OU S'IL Y A UNE ERREUR

        //char* fgets(char* chaine, int nmbreDeCaracteresALire, FILE* nomDuFichier); LIT MAXIMUM UNE LIGNE (S'ARRETE AU 1ER '\n' RENCONTREE))
    rewind(fichier);
    fgets(chaine,TAILLE_MAX,fichier);
//Le paremetre TAILLE_MAX demande à la fonction fgets de s'arrêter de lire la ligne si elle contient plus de TAILLE_MAX caractères.
    printf("%s",chaine);//ON NE LIT QUE LA PREMIERE LIGNE
    while(fgets(chaine, TAILLE_MAX, fichier)!=NULL)//TADAM!! ON LIT LIGNE PAR LIGNE JUSQU'A LA FIN
    {
        printf("%s", chaine);
    }

    fclose(fichier);
    }
    else
        printf("Impossible d'ouvrir le fichier");
    FILE* fichier2=NULL;
    fichier2=fopen("test2.txt","w");
    if(fichier2!=NULL)
    {
        fputs("10 15 20",fichier2);
        fclose(fichier2);
    }
    else
        printf("Impossible d'ouvrir le fichier text2.txt");

    fichier2=fopen("test2.txt","r+");
    if(fichier2 !=NULL)
        {
        fscanf(fichier2,"%d %d %d", &score[0],&score[1],&score[2]);//la fonction fscanf attend trois nombres séparés par un espace ("%d %d %d"). Elle les stocke ici dans notre tableau de trois blocs
        printf("\nLes meilleurs scores obtenus sont %d, %d et %d",score[0],score[1],score[2]);
        printf("\n%ld",ftell(fichier2));
        fseek(fichier2, 5,SEEK_SET);
        printf("\n%ld",ftell(fichier2));
        rewind(fichier2);//marche si j'ecris pas void au debut
        printf("\n%ld",ftell(fichier2));
        fseek(fichier2, 10, SEEK_CUR);
        printf("\n%ld",ftell(fichier2));
    /*Il existe trois fonctions à connaître pour indiquer la position ou positionner le curseur virtuel:

ftell : indique à quelle position vous êtes actuellement dans le fichier ;
fseek : positionne le curseur à un endroit précis ;
rewind : remet le curseur au début du fichier (c'est équivalent à demander à la fonction fseek de positionner le curseur au
début).

    PROTOTYPES:
        long ftell(FILE* nomDuFichier);
        void rewind(FILE* nomDuFichier);
        int fseek(FILE* nomDuFichier, long deplacement, int origine);

    fseek : PERMET DE DEPLACER LE CURSEUR D'UN CERTAIN NOMRBRE DE CARACTERES (INDIQUEE PAR DEPLACEMENT) A PARTIR DE LA POSITION
    INDIQUEE PAR L'ORIGINE
        => LE NOMBRE DEPLACEMENT PEUT ETRE UN NOMBRE POSITIF(--->), NUL, OU UN NOMBRE NEGATIF(<---)
        =>QUANT AU NOMBRE ORIGINE, JE PEUX METTRE COMME VALEUR L'UNE DES TROIS CONSTANTES (GENERALEMENT DES define) ci-dessous:
                 SEEK_SET : INDIQUE LE DEBUT DU FICHIER
                 SEEK_CUR : INDIQUE LA POSITION ACTUELLE
                 SEEK_END : INDIQUE LA FIN DU FICHIER;
*/



        fclose(fichier2);
        }
    else
        printf("Impossible d'ouvrir le fichier text2.txt");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //RENOMMER UN FICHIER
    //int rename(const char* ancienNom, const char* nouveauNom);
    //La fonction renvoie 0 si elle a réussi à renommer, sinon elle renvoie une valeur différente de 0.
    rename("test3.txt","fichierASupprimer.txt");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //SUPPRIMER UN FICHIER
    //int remove(const char* fichierASupprimer);
    //FONCTION A MANIER AVEC PRUDENCE CAR LA SUPPRESSION EST DEFINITIVE
    if(!remove("fichierASupprimer.txt"))
        printf("\n\nLe fichier ""fichierASupprimer.txt"" a ete supprime avec succes");

    FILE *myFile = NULL;
    myFile = fopen("myFile.txt", "r");

    int tab[2] = {0};
    char *myString[100] = {""};
    if(myFile != NULL) {
        fputs("voila 123 10323", myFile);
        rewind(myFile);
        fscanf(myFile, "%s %d %d", myString, &tab[0], &tab[1]);
        printf("\nVoici les CHAINES ET nombres lus et stockes grace a fscanf : %s, %d, %d \n", myString, tab[0], tab[1]);
        rewind(myFile);
        while(fgets(myString, TAILLE_MAX, myFile) != NULL)
            printf(myString);

        fclose(myFile);
    }


    return 0;
}
