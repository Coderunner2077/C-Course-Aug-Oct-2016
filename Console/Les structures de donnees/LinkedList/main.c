#include <stdio.h>
#include <stdlib.h>
#include "liste_chainnee.h"
/*
                                                    LES LISTES CHAINNEES

INTRODUCTION : UNE LISTE CHAINNEE EST UN MOYEN D'ORGANISER UNE SERIE DE DONNEES EN MEMOIRE. CELA CONSISTE A ASSEMBLER DES STRUCTURES
EN LES LIANT ENTRE ELLES A L'AIDE DES POINTEURS. CHAQUE ELEMENT DE CETTE LISTE PEUT CONTENIR CE QUE L'ON VEUT (UN INT, UN DOUBLE...).
CONTRAIREMENT AUX TABLEAUX, CETTE LISTE N'EST PAS FIGEE, MAIS FLEXIBLE. ON peut Y RAJOUTER OU ENLEVER UN ELEMENT A TOUT MOMENT.
AUTRE DIFFERENCE MAJEURE PAR RAPPORT AUX TABLEAUX : LES CASES NE SONT PAS COTE A COTE EN MEMOIRE.

VOICI LE SCHEMA :
    structure de      1er element           2nd element             dernier element pointant sur NULL
    controle
    [PREMIER]   ->   [DONNEES | POINTEUR] ->[DONNNEES |POINTEUR] -> [DONNEES | POINTEUR] -> NULL

    LES ELEMENTS SONT AGENCES ENTRE EUX EN FORMANT UNE CHAINE DE POINTEURS, D'OU LE NOM DE LISTE CHAINNEE.
    IL S'AGIRA ICI DE CREER MES PROPRES STRUCTURES ET FCTS ET LES TRANSFORMER EN UN SYSTEME CAPABLE DE SE REGULER TOUT SEUL.

I./ CONSTRUCTION D'UNE LISTE CHAINNEE
1.) UN ELEMENT DE LA LISTE
JE VAIS D'ABORD CREER UNE LISTE CHAINNEE DE NB ENTIERS. CHAQUE ELEMENT DE LA LISTE AURA LA FORME SUIVANTE :

    typedef struct Element Element
    struct Element
    {
        int nombre;
        Element *suivant;
    };

CETTE STRUCTURE CONTIENT :
    -   UNE DONNEE, ICI UN NOMBRE DE TYPE int. ON POURRAIT REMPLACER CELLE-LA PAR N'IMPORTE QUELLE AUTRE DONNEE. C'EST A MOI
    DE L'ADAPTER EN FCT DES BESOINS DE MON PROG. remarque : si on veut travailler de manière générique, l'idéal est de faire un
    pointeur sur void : void*. Cela permet de faire pointer sur n'importe quelle type de données.
    -   UN POINTEUR VERS UN ELEMENT DE MEME TYPE APPELE suivant.C'EST CE QUI PERMET DE LIER LES ELEMENTS LES UNS AUX AUTRES :
        CHAQUE ELEMENT SAIT OU SE TROUVE L'ELEMENT SUIVANT EN MEMOIRE. EN EFFET, LES CASES NE SONT PAS COTE A COTE EN MEMOIRE, ET
        CELA OFFRE DAVANTAGE DE SOUPLESSE (CAR ON PEUT PLUS FACILEMENT AJOUTER DES CASES PAR LA SUITE AU BESOIN)
    REMARQUE : en revanche, il est impossible de déterminer à partir de cet élément quel est l'élément précédent : car on ne
    peut pas revenir en arrière à partir d'un élément avec ce type de liste. On parle de liste "simplement chaînnée", alors que
    les listes "doublement chaînnées" ont des pointeurs dans les deux sens et n'ont pas ce défaut. Maaaiiiis, elles sont plus
    complexes!

    ON DUPLIQUERA DONC CETTE STRUCTURE AUTANT DE FOIS QU'IL Y A D'ELEMENTS.

2.) LA STRUCTURE DE CONTROLE

JE VAIS AVOIR BESOIN D'UNE AUTRE STRUCTURE POUR CONTROLER L'ENSEMBLE DE LA LISTE CHAINNEE. ELLE AURA LA FORME SUIVANTE :

    typedef struct Liste Liste;
    struct Liste
    {
        Element *premier;
    };

CETTE STRUCUTRE Liste CONTIENT UN POINTEUR VERS LE PREMIER ELELEMENT DE LA LISTE. EN EFFET, IL FO CONSERVER L'ADRESSE DU PREMIER
ELEMENT POUR SAVOIR OU COMMENCE LA LISTE. SI ON CONNAIT LE PREMIER ELEMENT, ON PEUT RETROUVER TOUS LES AUTRES EN SAUTANT D'ELEMENT
EN ELEMENTS A L'AIDE DES POINTEURS suivant.
Remarque : il serait bien d'ajouter la taille de la liste comme sous-variable. Car une seule sous-variable, ça le fait pas.

IL N'Y AURA BESOIN DE CREER QU'UN SEUL EXEMPLAIRE DE LA STRUCTURE Liste. ELLE PERMET DE CONTROLER TOUTE LA LISTE.

3.) LE DERNIER ELEMENT DE LA LISTE

IL NE MANQUE PLUS QUE LE DERNIER ELEMENT DE LA LISTE. EN EFFET, FAUDRA BIEN ARRETER DE PARCOURIR LA LISTE A UN MOMENT DONNE.
IL SERAIT POSSIBLE D'AJOUTER DANS LA STRUCTURE Liste UN POINTEUR VERS LE DERNIER Element. MAIS IL Y A PLUS SIMPLE :
    IL SUFFIT DE FAIRE POINTER LE DERNIER ELEMENT DE LA LISTE VERS NULL, I.E. METTRE SON POINTEUR suivant A NULL.

II./ LES FONCTIONS DE LA GESTION DE LA LISTE
ARRIVE A CE STADE, IL NE MANQUE PLUS QUE LES FONCTIONS QUI VONT MANIPULER LA LISTE CHAINNEE.
1.) INITIALISER LA LISTE
C'EST LA TOUTE 1RE FCT QUE JE DEVRAI APPELER. ELLE CREE LA STRUCTURE DE CONTROLE ET LE 1ER ELEMENT DE LA LISTE.
LA VOICI :

Liste *initialistation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));
    il(liste == NULL || element == NULL)
        exit(EXIT_FAILURE);

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

ON ALLOUE DONC LA STRUCTURE DE CONTROLE AVEC UN malloc(). LA TAILLE A ALLOUER EST CALCULEE AUTOMATIQUEMENT AVEC sizeof(*liste).
L'ORDI SAURA DONC QU'IL DOIT ALLOUER L'ESPACE NECESSAIRE AU STOCKAGE DE LA STRUCTURE Liste. Remarque : j'aurai pu écire
sizeof(*Liste), mais si plus tard je souhaite modifier le type du pointeur liste, je devrai aussi adapter le sizeof.

IDEM POUR L'ALLOCATION EN MEMOIRE DU 1ER ELEMENT DE LA LISTE. EN CAS D'ERREUR  => exit.

SI TOUT S'EST BIEN PASSE, ON DEFINIT LES VALEURS DE MON PREMIER ELEMENT :
    -   LA DONNEE nombre EST MISE A 0 PAR DEFAUT
    -   LE POINTEUR SUIVANT POINTE VERS NULL CAR POUR L'INSTANT MON 1ER ELEMENT EST AUSSI MON DERNIER.

2.) AJOUTER UN ELEMENT

OU VAIS-JE AJOUTER UN NOUVEL ELEMENT : AU DEBUT? AU MILIEU? OU A LA FIN?
EH BIEN J'AI LE CHOIX. POUR L'INSTANT, JE VAIS L'AJOUTER AU DEBUT CAR C'EST PLUS SIMPLE.

VOICI LA FCT :
void insertion(Liste *liste, int nvNomrre)
{
    Element *nouveau = malloc(sizeof(*nouveau));

    if(nouveau == NULL || liste == NULL)
        exit(EXIT_FAILURE);

    nouveau->nombre = nvNombre;
    // INSERTION DE L'ELEMENT AU DEBUT DE LA LISTE
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

POUR INSERER UN NOUVEL ELEMENT DANS LA LISTE CHAINNEE, IL EST PRIMORDIAL DE METTRE A JOUR CORRECTEMENT LES POINTEURS, DANS CET
ORDRE PRECIS :
    -   FAIRE POINTER MON NOUVEL ELEMENT VERS SON FUTUR SUCCESSEUR, QUI EST L'ACTUEL PREMIER ELEMENT DE LA LISTE;
    -   FAIRE POINTER LE POINTEUR premier VERS MON NOUVEL ELEMENT.

3.) SUPPRIMER UN ELEMENT

ICI, JE ME PENCHERAI SUR LA SUPPRESSION SEULEMENT DU PREMIER ELEMENT DE LA LISTE.

void suppression(Liste *liste)
{
    if(liste == NULL)
        exit(EXIT_FAILURE);
    if(liste->premier != NULL) // ON VERIFIE QU'IL Y A BIEN AU MOINS UN ELEMENT DANS LA LISTE
    {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;

        free(aSupprimer);
    }
}
DONC, FAIRE LES CHOSES DANS CET ORDRE PRECIS :
    -   ON SAUVEGARDE L'ADRESSE DE L'ELEMENT A SUPPRIMER DANS UN POINTEUR aSupprimer
    -   FAIRE POINTER premier VERS LE SECOND ELEMENT
    -   SUPPRIMER LE PREMIER ELELEMNT AVEC UN free

4.) AFFICHER LA LISTE CHAINNEE

IL SUFFIT DE PARTIR DU 1ER ELEMENT ET D'AFFICHER CHAQUE ELEMENT, UN A UN, EN "SAUTANT" DE BLOC EN BLOC

void afficherListe(Liste *liste)
{
    if(liste == NULL)
        exit(EXIT_FAILURE);
    Element *actuel = liste->premier;
    while(actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;

    }
    printf("NULL\n");
}
CETTE FCT EST SIMPLE : ON PART DU 1ER ELEMENT ET ON AFFICHE LE CONTENU DE CHAQUE ELEMENT DE LA LISTE (UN NOMBRE). ON SE SERT DU
POINTEUR suivant POUR PASSER A L'ELEMENT QUI SUIT A CHAQUE FOIS.

III./ ALLER PLUS LOIN

1.) INSERTION D'UN ELEMENT EN MILIEU DE LISTE

*/


int main()
{
    Liste *maListe = initialisation();
    suppression(maListe);
    insertion(maListe, 16);
    insertion(maListe, 8);
    insertion(maListe, 4);
    insertion(maListe, 2);
    insertion(maListe, 1);

    suppression(maListe);
    Element ePrecedent;
    ePrecedent.nombre = 2;
    insererAuMilieu(maListe, &ePrecedent, 3);
    Element ePrecedent2;
    ePrecedent2.nombre = 8;
    insererAuMilieu(maListe, &ePrecedent2, 12);
    Element aSupprimer;
    aSupprimer.nombre = 12;
    supprimerAuMilieu(maListe, &aSupprimer);
    afficherListe(maListe);
    printf("\nLa longueur de la liste :%d\n", listeLength(maListe));
    insertion(maListe, 1);
    afficherListe(maListe);
    destructionListe(maListe);
    afficherListe(maListe);


    return 0;
}
