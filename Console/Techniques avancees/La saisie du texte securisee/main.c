#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lire(char *chaine, int longueur);
void viderBuffer();
long lireLong();
double lireDouble();

int main(int argc, char *argv[])
{
/*
LES DEUX LIMITES PRINCIPALES DE scanf:
1.ENTRER UNE CHAINE AVEC DES ESPACES
2.ENTRER UNE CHAINE DE CARACTERES TROP LONGUE

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//1. UNE CHAINE AVEC DES ESPACES

LA FONCTION scanf S'ARRETE QUAND ELLE TOMBE SUR UN ESPACE, UNE TABULATION OU UNE ENTREE. POURTANT, L'UNE DE CES
TOUCHES AINSI QUE LE TEXTE APPAREMMENT DISPARU SE TROUVE TOUJOURS EN MEMOIRE DANS CE QUE L'ON APPELLE LE BUFFER.
ET LA PROCHAINE FOIS QUE L'ON APPELERA scanf, CELLE-CI LIRA TOUTE SEULE LE TEXTE QUI ETAIT RESTE EN ATTENTE DANS
 LA MEMOIRE.

*/
char name[50]={""}, ville[15]={""};

printf("Votre nom et prenom?");
scanf("%s", name);
printf("\nVous vous appelez donc %s", name);
printf("\nVille?");
scanf("%s", ville);//scanf LIT TOUTE SEULE LE MOT DUBOIS QUI ETAIT RESTE EN ATTENTE DANS LE BUFFER.
printf("\nVous habitez donc %s?", ville);




char nom[10]={0};
fgets(nom, 10, stdin);
printf("Je m'appelle %s!", nom);//LE PREMIER scanf FAIT ENCORE SON EFFET. UN VRAI CAUCHEMAR...

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//2. UNE CHAINE TROP LONGUE
char nomCourt[5]={0};
printf("\nSi j'ecris plus de caracteres qu'il n'y a d'espace prevu pour les stocker, je fais un depassement de");
printf("\nmemoire, appele aussi buffer overflow.");
printf("\nEn effet, scanf va continuer a ecrire, sans se preoccuper de la limite du nombre de cases reservees,");
printf("\ndans des zones memoire qui n'etaient pas prevues pour cela.");
printf("\nLes caracteres en trop ecrasent d'autres informations en memoire. C'est cela, le buffer overflow\n");
printf("\n\n\nEntrer un mot de plus ou moins 4 lettres (i.e. FAIRE OU NE PAS FAIRE UN BUFFER OVERFLOW...)\n");
scanf("%s", nomCourt);
printf("\n%s\n", nomCourt);

/*

IL FAUT SAVOIR QUE SI LE PROGRAMME NE CONTROLE PAS CE GENRE DE CAS, L'UTILISATEUR PEUT ECRIRE CE QU'IL VEUT A LA
SUITE EN MEMOIRE. EN PARTICULIER, IL PEUT INSERER DU CODE EN MEMOIRE ET FAIRE EN SORTE QU'IL SOIT EXECUTE PAR LE
PROGRAMME.
C'EST L'ATTAQUE PAR BUFFER OVERFLOW, UNE ATTAQUE DE PIRATE CELEBRE MAIS DIFFICILE A REALISER.

 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//RECUPERER UNE CHAINE DE CARACTERES
/*

    Il existe plusieurs fonctions standards en C qui permettent de récupérer une chaîne de texte. Hormis la
fonction scanf (trop compliquée pour être étudiée ici), il existe :

gets : une fonction qui lit toute une chaîne de caractères, mais très dangereuse car elle ne permet pas de
contrôler les buffer overflow !
fgets : l'équivalent de gets mais en version sécurisée, permettant de contrôler le nombre de caractères écrits
en mémoire.

*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//LA FONCTION fgets
//fgets: CETTE FONCTION NE FAIT PAS QUE LIRE DES FICHIERS...
//PROTOYYPE DE LA FONCTION fgets (SITUE DANS stdio.h) :
char *fgets(char *str, int num, FILE* stream);
/*
- str : UN POINTEUR VERS UN TABLEAU ALLOUE EN MEMOIRE OU LA FONCTION VA POUVOIR ECRIRE LE TEXTE ENTRE PAR L'UTILISATEUR
- num : LA TAILLE DU TABLEAU str ENVOYE EN PREMIER PARAMETRE
- stream: UN POINTEUR SUR LE FICHIER A LIRE. DANS LE CAS PRESENT, LE FICHIER A LIRE EST L'ENTREE STANDARD,
    C'EST-A-DIRE LE CLAVIER.
    ==>POUR DEMANDER A LIRE L'ENTREE STANDARD, J'ENVERRAI LE POINTEUR stdin, QUI EST AUTOMATIQUEMENT DEFINI DANS
        LES HEADER DE LA BIBLIOTHEQUE STANDARD DU C POUR REPRESENTER LE CLAVIER
*/


fgets(nom, 10, stdin);//POUR EVACUER LA TOUCHE ENTREE DU scanf DE LA LIGNE 42
printf("\nComment je m'appelle?\n");
fgets(nom, 10, stdin);
printf("Je m'appelle %s!", nom);// LA TOUCHE ENTREE EST EGALEMENT RENVOYEE PAR fgets. QUE FAIRE?
//REMARQUE: fgets SITUE LE CARACTERE '\n' AVANT '\0'

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//CREER SA PROPRE FONCTION  DE SAISIE UTILISANT fgets

/*
LA FONCTION lire VA APPELER fgets, ET SI TOUT S'EST BIEN PASSE, ELLE VA RECHERCHER LE CARACTERE '\n' A L'AIDE DE
 LA FONCTION strchr. SI UN '\n' EST TROUVE, ELLE LE REMPLACE PAR UN '\0' POUR EVITER DE CONSERVER UNE ENTREE

*/
//ELIMINER LE SAUT DE LIGNE '\n'...
//... GRACE A LA FONCTION lire
printf("\nResaisir le nom et remarquer que le point d'exclamation se trouve au bon endroit\n");
lire(nom, 10);
printf("\nJe m'appelle %s!", nom);
//REMARQUE: CE N'EST PAS GRAVE D'AVOIR DEUX '\0' A LA SUITE, L'ORDINATEUR CONSIDERE QUE LA CHAINE S'ARRETE AU 1ER
// '\0' RENCONTREE

//QUE CE PASSE-T-IL SI JE TENTE D'ENTRER PLUS DE CARACTERES QU'IL N'Y A D'ESPACE RESERVE POUR CELA?
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//LE FONCTIONNEMENT DE fgets

/*
LE RESTE DE LA CHAINE "EN TROP" QUE J'AI TENTE D'ENTRER ET QUI N'A PAS PU ETRE LU FAUTE DE MEMOIRE DANS MON TABLEAU
DE STOCKAGE, N'A PAS DISPARU. IL EST TOUJOURS DANS LE BUFFER.
LE BUFFER EST UNE SORTE DE ZONE MEMOIRE QUI RECOIT DIRECTEMENT L'ENTREE CLAVIER ET QUI SERT D'INTERMEDIAIRE ENTRE
LE CLAVIER ET MON TABLEAU DE STOCKAGE. EN C, ON DISPOSE D'UN POINTEUR VERS LE BUFFER. C'EST CE FAMEUX stdin.
EXPLICATION DETAILLEE:
JE TAPE UNE "PHRASE D'UNE CERTAINE TAILLE" AU CLAVIER ==> L'OS COPIE DIRECTEMENT CE TEXTE DANS LE BUFFER
==> fgets EXTRAIT DU BUFFER LES CARACTERES QUI S'Y TROUVENT ET LES COPIENT DANS LA ZONE MEMOIRE QUE JE LUI INDIQUE
 (MON TABLEAU CHAINE)
==> APRES AVOIR EFFECTUE SON TRAVAIL DE COPIE, fgets ENLEVE DU BUFFER CE QU'ELLE A PU COPIER
  ^
 /!\    SEULS LES CARACTERES LUS SERONT DONC SUPPRIMES DU BUFFER.
_____

SUIVANT NOTRE EXEMPLE: AVEC UN char chaine[10] ==> SEULEMENT "PHRASE D'" POURRAIT ETRE COPIE DANS chaine[10]
==> "UNE CERTAINE TAILLE" N'AURAIT PAS PU ETRE COPIE DANS chaine[10]
==>"UNE CERTAINE TAILLE" N'ETANT DONC PAS LU, NE SERA PAS SUPPRIME DU BUFFER...
==> ... TANT QUE JE NE VIDE PAS LE BUFFER

CONCLUSION: DONC, SI L'UTILISATEUR TAPE TROP DE CARACTERES, LA FONCTION fgets NOUS PROTEGE CONTRE LE DEBORDEMENT
DE MEMOIRE, MAIS IL RESTE TOUJOURS DES TRACES DU TEXTE EN TROP DANS LE BUFFER. IL FAUT VIDER LE BUFFER

*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//VIDER LE BUFFER
/*

ON VA DONC AMELIORER NOTRE FONCTION lire ET APPELER -- SI BESOIN EST -- UNE SOUS-FONCTION viderBuffer POUR FAIRE
EN SORTE QUE LE BUFFER SOIT VIDEE SI ON A RENTREE TROP DE CARACTERES:
*/
//SOUS-FONCTION viderBuffer
/*
LA FONCTION lire APPELLE viderBuffer DANS 2 CAS:
    - SI LA CHAINE DE CARACTERES EST TROP LONGUE (EVENTUELLEMENT ON LE SAIT CAR ON N'A PAS TROUVEE DE '\n' DANS
        LA CHAINE COPIEE)
    - S'IL Y A EU UNE ERRER (PEU IMPORTE LAQUELLE), IL FAUT VIDER LE BUFFER PAR SECURITE POUR QU'IL N'Y AIT PLUS
    RIEN

LA FONCTION viderBuffer LIT DANS LE BUFFER CARACTERE PAR CARACTERE GRACE A getchar(). CELLE-CI RENVOIE UN int
(ET NON UN CHAR, VA SAVOIR POURQUOI, PEU IMPORTE). ON SE CONTENTE DE RECUPERER CE int DANS UNE VARIABLE TEMPORAIRE
c. ON BOUCLE TANT QU'ON N'A PAS RECUPERE LE CARACTERE '\n' ET LE SYMBOLE EOF (FIN DE FICHIER), QUI SIGNIFIENT
TOUS DEUX "VOUS ETES ARRIVE A LA FIN DU BUFFER". ON ARRETE DE BOUCLER DES QUE L'ON TOMBE SUR L'UN DES DEUX
CARACTERES.
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// CONVERTIR LA CHAINE EN NOMBRE

/*

MAIS COMMENT FAIT-ON POUR RECUPERER UN NOMBRE?

fgets (ET DONC lire AUSSI) EST UNE FONCTION DE BASE QUI NE PEUT RECUPERER QUE DU TEXTE.
MAIS IL EXISTE D'AUTRES FONCTIONS QUI PERMETTENT DE CONVERTIR ENSUITE UN TEXTE EN NOMBRE

*/

//strtol : CONVERTIR UNE CHAINE EN LONG
//PROTOTYPE:
long strtol(const char *start, char **end, int base); // !!!!!! const!!!!!!!!!!
/*
LA FONCTION LIT LA CHAINE DE CARACTERES QUE JE LUI ENVOIE (start) ET ESSAIE DE LA CONVERTIR EN long EN UTILISANT
LA BASE INDIQUEE (GENERALEMENT, ON TRAVALLE EN BASE 10, CAR ON UTILISE 10 CHIFFRES DIFFERENTS DE 0 A 9, DONC ON
MET 10). ELLE RETOURNE LE NOMBRE QU'ELLE A REUSSI A LIRE.
QUANT AU POINTEUR DE POINTEUR end, LA FONCTION S'EN SERT POUR RENVOYER LA POSITION DU PREMIER CARACTERE QU'ELLE A
LU ET QUI N'ETAIT PAS UN NOMBRE. ON S'EN SERVIRA PAS, ON PEUT DONC LUI ENVOYER NULL POUR LUI FAIRE COMPRENDRE
QU'ON NE VEUT RIEN RECUPERER.

LA CHAINE DOIT COMMENCER PAR UN NOMBRE (PRECEDE EVENTUELLEMENT D'ESPACES), TOUT LE RESTE EST IGNORE.

*/

//QUELQUES EXEMPLES D'UTILISATION:

long i;

i=strtol("148", NULL, 10);//i=148
i=strtol("148.215", NULL, 10);// i=148
i=strtol("148+25", NULL, 10); // i=148
i=strtol("    148.215", NULL, 10); //i=148
i=strtol("    148+24", NULL, 10); // i=148
i=strtol("    148 feuilles mortes", NULL, 10); //i=148
i=strtol("    Il y a 148 feilles mortes", NULL, 10); //i=0 (erreur: LA CHAINE NE COMMENCE PAS PAR UN NOMBRE)

/*
TOUTES LES CHAINES QUI COMMENCENT PAR UN NOMBRE (OU DES ESPACES SUIVIS D'UN NOMBRE) SERONT CONVERTIES EN long
JUSQU'A LA PREMIERE LETTRE OU AU PREMIER CARACTERE INVALIDE ('.','+', etc.)

ON PEUT CREER UNE FONCION lireLong QUI VA APPELER NOTRE PREMIERE FONCTION lire (QUI LIT DU TEXTE) ET ENSUITE
CONVERTIR LE TEXTE SAISI EN NOMBRE
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FONCTION lireLong

long age=0;
printf("\nQuel age avez-vous?\n");
age=lireLong();
printf("Vous avez donc %ld ans", age);

//ET QU'EN EST-IL DE LA CONVERSION D'UNE CHAINE EN DOUBLE?

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FONCTION strtod
//strtod EST IDENTIQUE A strtol, A CETTE DIFFERENCE PRES QU'ELLE ESSAIE DE LIRE UN NOMBRE DECIMAL ET RENVOIE UN DOUBLE
//PROTOTYPE
double strtod(const char *start, char **end);
//REMARQUE : LE TROISIEME PARAMETRE base A DISPARU
//CONTRAIREMENT A strtol, ELLE PREND EN COMPTE LE POINT. MAIS ATTENTION, ELLE NE CONNAIT PAS LA VIRGULE.

//fonction lireDouble
//QUI VA APPELER LA FONCTION lire ET ENSUITE CONVERTIR LE TEXTE SAISI EN DOUBLE
double poids;
printf("\nQuel est mon poids? Honnetement...\n");
poids=lireDouble();
printf("\nJe pese %f kg", poids);

    return 0;
}

int lire(char *chaine, int longueur)//REF ligne 100 !!!!!!!!!!!!! PARAMETRES!!!!!!
{
    char *positionEntree=NULL;
    //ON LIT LE TEXTE SAISI AU CLAVIER
    if(fgets(chaine, longueur, stdin)!=NULL)//PAS D'ERREUR DE SAISIE?
    {
    positionEntree=strchr(chaine, '\n');//ON RECHERCHE L'"ENTREE"
        if(positionEntree!=NULL)//SI ON A TROUVE UN RETOUR A LA LIGNE
            {
            *positionEntree='\0';// ON REMPLACE SA VALEUR DIRECTEMENT DANS LA MEMOIRE PAR LE CARACTERE DE FIN DE CHAINE
            }
         else
            {
             viderBuffer();
            }
        return 1;//ON RETOURNE 1 POUR SIGNIFIER QUE LA FONCTION S'EST DEROULEE SANS ERREUR

    }
    else
    {
        viderBuffer();
        return 0;//ON RENVOIE 0 SI IL Y A EU UNE ERREUR
    }
}

void viderBuffer()// REF LIGNE 146
{
    int c;
    while(c!='\n' && c!=EOF)
    {
        c=getchar();
    }
}

long lireLong() // REF LIGNE 210
{
    char nombreTexte[100]={0};// 100 CASES DEVRAIENT SUFFIRE
    if(lire(nombreTexte, 100))// SI LECTURE DU TEXTE OK
        {
            //==>CONVERTIR LE NOMBRE EN LONG ET LE RETOURNER
           return strtol(nombreTexte, NULL, 10);
        }
    else
        {
            //SI PROBLEME DE LECTURE, RENVOYER 0
            return 0;
        }
}

double lireDouble()// REF LIGNE 226
{
    char nombreTexte[100]={0};
    char *virgule=NULL;
    if(lire(nombreTexte, 100))
    {
        if(strchr(nombreTexte, ',')!=NULL)//PETITE AMELIORATION POUR QUE lireDouble ACCEPTE LES VIRGULES
            {
                virgule=strchr(nombreTexte, ',');
                *virgule='.';
            }
        return strtod(nombreTexte, NULL);
    }
    else
        return 0;
}
