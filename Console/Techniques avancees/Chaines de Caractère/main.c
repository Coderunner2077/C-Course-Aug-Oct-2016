#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int longueurChain(char* chaine);
int main(int argc, char *argv[])
{

/*


    //char A='A', lettreEntre;

    printf("\n\n\n%c\n",A);
    while(lettreEntre!='Z')
    {
    scanf("%c",&lettreEntre);
    printf("%d\n\n",lettreEntre);
    }
*/

  /*Voici à peu près tout ce qu'il faut savoir sur le type char. Retenez bien :

=>le type char permet de stocker des nombres allant de -128 à 127, unsigned char des nombres de 0 à 255 ;
=>il y a une table que votre ordinateur utilise pour convertir les lettres en nombres et inversement, la table ASCII ;
=>on peut donc utiliser le type char pour stocker UNE lettre ;
=>'A' est remplacé à la compilation par la valeur correspondante (65 en l'occurrence). On utilise donc les apostrophes pour
 obtenir la valeur d'une lettre.
 */
    char chaine[6];// tableau de 6 chars pour S+a+l+u+t+\0
    //Initialisation de la chaine, méthode manuelle peu efficace
    chaine[0]='S';
    chaine[1]='a';
    chaine[2]='l';
    chaine[3]='u';
    chaine[4]='t';
    chaine[5]='\0';//le caractère de fin de chaine OBLIGATOIRE qui indique à l'ordinateur que la chaîne s'arrête là

    printf("%s",chaine);
    /*Grâce à '\0', je n'ai pas besoin de retenir la taille de mon tableau car il indique que le tableau s'arrête à cet endroit.
    Je peux passer mon tableau de char à une fonction sans avoir à ajouter à côté une variable indiquant la taille du
    tableau.
    Cela n'est valable que pour les chaînes de caractères (c'est-à-dire le type char*, qu'on peut aussi écrire char[]).
    Pour les autres types de tableaux, je suis toujours obligé de retenir la taille du tableau quelque part.
    */
    char chaine2[]="hello ";//taille du tableau chaine est automatiquement calculée
    //j'aurais aussi pu écrire: char* chaine="hello ";
    //Attention, ça ne marche que pour l'initialisation
    printf("%s\n",chaine2);
    char chaine3[100];//Attention => suffisemment grand pour pouvoir stocker les prénoms même les plus longs
    printf("\nComment tu s'appelles ton fils?\n");
    scanf("\n%s",chaine3);
    printf("\n%s ? Ok\n",chaine3);


    //Fonctions de manipulation des chaines
    //Penser à inclure la bibliothèque string.h
    //strlen : Fonction calculant la longueur d'une chaine (sans le \0)!!!!!!
    //son prototype:size_t strlen(const char* chaine);
    //(const char* chaine) fait que la fonction s'interdit de modifier le contenu de char* chaine
    int lenthChaine;
    size_t longueurChaine;
    longueurChaine=strlen(chaine3);
    printf("\nLe prenom %s comporte %d caracteres\n",chaine3,longueurChaine);
    //size_t est un type spécial inventé, remplacé ici par int
    lenthChaine=strlen(chaine2);
    printf("\n%s = %d caraceres\n",chaine2,lenthChaine);//un int fait tout aussi bien l'affaire
    printf("name?=");
    char name[100];
    scanf("%s",name);
    int myLength = longueurChain(name);
    printf("\n\nAttention chaine modifiee : %s = %d caracteres",name, myLength);
    char copie[100];

    //FONCTION COPIER UNE CHAINE
    /* On crée une chaîne "chaine" qui contient un peu de texte
    et une copie (vide) de taille 100 pour être sûr d'avoir la place
    pour la copie */
    strcpy(copie,name);//char* strcpy(char* copieDeLaChaine, const char* chaineACopier);
    printf("\n\n%s?",copie);
    //L'avantage de créer un tableau un peu plus grand, c'est que de cette façon la chaîne copie sera capable de recevoir d'autres chaînes peut-être plus grandes dans la suite du programme.

    //FONCTION CONCATENER DEUX CHAINES
    //Cette fonction ajoute une chaîne à la suite d'une autre. On appelle cela la concaténation
    //char* strcat(char* chaine1, const char* chaine2); On concatène chaine2 dans chaine1. Chaine2 elle-meme reste inchangée
    strcat(chaine2, name);
    printf("\n%s\n",chaine2);

    //FONCTION COMPARER DEUX CHAINES
    strcmp(chaine3,name);
    if(strcmp(chaine3,name)==0)
        printf("les prenoms sont identiques");
    if(strcmp(chaine3,name)>0)
        printf("%s est plus long que %s",chaine3,name);
    if(strcmp(chaine3,name)<0)
        printf("%s est moins long que %s",chaine3,name);
       // prototype: int strcmp(const char* chaine1, const char* chaine2);
    /*Il est important de récupérer ce que la fonction renvoie. En effet, strcmp renvoie :

0 si les chaînes sont identiques ;
une autre valeur positive ou négative si les chaines 2 sont différentes (positive si chaine1>chaine2, négative si chaine1<chaine2)*/


    //FONCTION RECHERCHER UN CARACTERE
    //char* strchr(const char* chaine, int caractereARechercher); !!!! UN int ET NON UN char
    //Remarque: caractereARechercher est de type int. Ce n'est pas un probleme, car au fond un caractere est et restera toujours un nombre
    char *phrase="Est-ce que le ciel est bleu aujourdhui?", *suiteChaine=NULL;
    int lettre='b';

    suiteChaine=strchr(phrase,lettre);
    printf("\nRechercher de caractere, suite chaine : %s",suiteChaine);
    printf("\n%s",phrase);
    //La fonction renvoie un pointeur vers le premier caractère qu'elle a trouvé, c'est-à-dire qu'elle renvoie l'adresse de ce
    //caractère dans la mémoire. Elle renvoie NULL si elle n'a rien trouvé


    //FONCTION RECHERCHER UN CARACTERE (VARIANTE)
    //char* strrchr(const char* chaine, int caractereARechercher);
    //Fonction strictement identique a strchr, sauf que celle-la renvoie un pointeur qui pointe vers le dernier caractere trouvé
    //dans la chaine plutôt que le premier


    //FONCTION RECHERCHER PREMIER CARACTERE DE LA LISTE
    //prototype: char* strpbrk(const char* chaine, const char *lettresARechercher);
    //recherche un des caractères dans la liste que je lui donnee sous forme de chaîne, contrairement à strchr qui ne peut
    // rechercher qu'un seul caractère à la fois.
    char *liste="qbj", *liste2;
    printf("\n\nstrpbrk : %s",strpbrk(phrase,liste));
    liste2=strpbrk("Exemple de texte","adt");
    if(liste2!=NULL)
        printf("\n\nVoici la fin de chaine a partir du premier des caracteres trouve : %s", liste2);
    //Remarque: Pour cet exemple, j'ai directement écrit les valeurs à envoyer à la fonction (entre guillemets). Je ne suis en effet pas obligé d'employer une variable à tous les coups, on peut très bien écrire la chaîne directement.
    //Il faut simplement retenir la règle suivante :

    // - si j'utilisee les guillemets "", cela signifie chaîne ;
    // - si j'utilise les apostrophes '', cela signifie caractère.

    // FONCTION RECHERCHER UNE CHAINE DANS UNE AUTRE
    //char* strstr(const char* chaine, const* char chaineARechercher);
    //Le prototype est similaire à strpbrk, mais attention à ne pas confondre : strpbrk recherche UN des caractères,
    //tandis que strstr recherche la premiere occurence de toute une chaine
    char *mot="ciel";
    printf("\n\nce %s",strstr(phrase, mot));

    //Jusqu'ici, je me suis contenté d'afficher la chaîne à partir du pointeur retourné par les fonctions.
    // Dans la pratique, ça n'est pas très utile. Je ferai juste un if (resultat != NULL) pour savoir si la recherche a ou non donné quelque chose, et j'afficherai « Le texte que vous recherchiez a été trouvé "

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // SPRINTF : FONCTION ECRIRE DANS UNE CHAINE

    //Remarque: cette fonction se trouve dans stdio.h contrairement aux autres fonctions qui sont dans string.h

    char chaine4[100];//s'assurer que la chaine est suffisemment longue pour accueillir tout le texte que le sprintf va lui envoyer
    int age=2;

    sprintf(chaine4,"Tu as deja %d ans?!",age);//J'écris "Tu as deja 15 ans" dans chaine4
    //Elle s'utilise de la même manière que printf, mis à part le fait que je lui donne en premier paramètre un pointeur   !!!!!!
    //vers la chaîne qui doit recevoir le texte
    printf("\n\n%s",chaine4);



    return 0;
}
//
    //je crée une fonction similaire à strlen
    int longueurChain(char* chaine)
    {
        int i, nombreCaracteres=0;
        char caractereActuel;
        strupr(chaine);
        for(i=0;chaine[i]!='\0';i++)
        {
            nombreCaracteres++;
        }
        return nombreCaracteres;
    }
