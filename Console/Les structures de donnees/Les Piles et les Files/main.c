#include <stdio.h>
#include <stdlib.h>
#include "piles.h"
#include "files.h"

/*
                                                    Piles & Files

LES PILES ET LES FILES SONT DEUX VARIANTES UN PEU PARTICULIERES DES LISTES CHAINNEES. ELLES PERMETTENT DE CONTROLER LA MANIERE DONT
SONT AJOUTES LES NOUVEAUX ELEMENTS. DESORMAIS, IL NE S'AGIRA PLUS QUE D'INSERER DES ELEMENTS AU DEBUT OU A LA FIN DE LA LISTE.
LES PILES ET LES FILES SONT TRES UTILES POUR DES PROGRAMMES QUI TRAITENT DES DONNEES QUI ARRIVENT AU FUR ET A MESURE.

I./ LES PILES
LE CONCEPT DES PILES SE RESUME A UNE PILE DE PIECES OU IL N'EST POSSIBLE D'AJOUTER DES PIECES QU'EN HAUT DE LA PILE, TOUT COMME
IL N'EST POSSIBLE D'ENLEVER LES PIECES QUE DU HAUT DE LA PILE.

1.) LE FONCTIONNEMENT DES PILES
LE PRINCIPE DES PILES EN PROGRAMMATION EST DE STOCKER DES DONNEES AU FUR ET A MUSURES LES UNES AU-DESSUS DES AUTRES POUR POUVOIR
LES RECUPERER PLUS TARD.
LE PLUS INTERRESSANT EST SANS CONTESTE L'OPERATION QUI CONSISTE A EXTRAIRE LES NB DE LA PILE, ON PARLE DE DEPILAGE. ON RECUPERE
LES DONNEES UNE A UNE, EN COMMENCANT PAR LA DERNIERE QUI VIENT D'ETRE POSEE TOUT EN HAUT DE LA PILE. ON ENLEVE LES DONNEES AU FUR
ET A MUSURE, JUSQU'A LA DERNIERE TOUT EN BAS.
ON DIT QUE C'EST UN ALGORITHME LIFO ("LAST IN, FIRST OUT").
LES ELEMENTS D'UNE PILE SONT RELIES ENTRE EUX A LA MANIERE D'UNE LISTE CHAINNEE. ILS POSSEDENT UN POINTEUR VERS L'ELELEMENT SUIVANT,
ET NE SONT DONC PAS FORCEMENT PLACES COTE A COTE EN MEMOIRE. LE DERNIER ELEMENT (TOUT EN BAS DE LA PILE) DOIT POINTER VERS NULL,
POUR INDIQUER QU'ON A... TOUCHE LE FOND.
A QUOI CELA PEUT-IL SERVIR? EH BIEN, IL Y A DES PROGRAMMES OU ON A BESOIN DE STOCKER TEMPORAIREMENT DES DONNEES POUR LES
RESSORTIR DANS DANS 1 ORDRE PRECIS: LE DERNIER ELEMENT QUE J'AI STOCKE DOIT ETRE LE 1ER A RESSORTIR.

2.) CREATION D'UN SYSTEME DE PILES

COMME POUR LES LISTES CHAINNEES, IL N'EXISTE PAS DE SYSTEME DE PILE INTEGRE AU LANGAGE C, IL FO DONC LE CREER MOI-MEME.

CHAQUE ELEMENT DE LA PILE AURA UNE STRUCTURE IDENTIQUE A CELLE DE LA LISTE CHAINNEE:

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};
BIEN SUR, RIEN NE M'EMPECHE DE STOCKER AUTRE CHOSE QU'UN int.

LA STRUCTURE DE CONTROLE CONTIENDRA L'ADRESSE DU PREMIER ELEMENT DE LA PILE, CELUI QUI SE TROUVE TOUT EN HAUT :

typedef typedef Pile Pile;
struct Pile
{
    Element *premier;
};

J'AURAI BESOIN EN TOUT ET POUR TOUT DE DEUX FCTS :
    -   EMPILAGE D'UN ELEMENT
    -   DEPILAGE D'UN ELEMENT
ENFIN, JE VAIS AUSSI ECRIRE UNE FCT D'AFFICHAGE POUR VERIFIER SI LE PROG SE COMPORTE BIEN.

3.) EMPILAGE

void empiler(Pile *pile, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if(pile == NULL || nouveau == NULL)
        exit(EXIT_FAILURE);

    nouveau->nombre = nvNombre;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}

CETTE FONCTION EST IDENTIQUE A LA FONCTION D'INSERTION D'ELEMENT AU DEBUT DE LA LISTE CHAINNEE.

4.) DEPILAGE

LE ROLE DE CETTE FCT NE SERA PAS SEULEMENT DE SUPPRIMER L'ELEMENT TOUT EN HAUT DE LA PILE (SINON, ON L'AURAIT APPELE "suppression"
TOUT COURT), MAIS AUSSI DE RETOURNER L'ELEMENT QU'ELLE DEPILE, I.E. DANS MON CAS LE NB QUI ETAIT STOCKE EN HAUT DE LA PILE.

int depiler(Pile *pile)
{
    if(pile == NULL || pile->premier == NULL)
        exit(EXIT_FAILURE);

    int nombreDepile = 0;
    Element *elementDepilee = pile->premier;
    nombreDepile = elementDepile->nombre;

    pile->premier = elementDepile->suivant;
    free(elementDepile);

    return nombreDepile;
}

5.) AFFICHAGE DE LA PILE

FCT UTILE JUSTE POUR TESTER MES FCTS EMPILAGE ET DEPILAGE, ET AUSSI DONC VISUALISER LE RESULTAT.

void afficherPile(Pile *pile)
{
    if(pile == NULL || pile->premier == NULL)
        exit(EXIT_FAILURE);

    Element *actuel = pile->premier;

    while(actuel != NULL)
    {
        printf("%d\n", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("\n");
}

II./ LES FILES

LES FILES RESSEMBLENT BCP AUX PILES, ELLES FONCTIONNENT JUSTE DANS LE SENS INVERSE.
TOUT COMME DANS UNE FILE D'ATTENTE, LE PREMIER QU'ON FAIT SORTIR DE LA FILE EST LE PREMIER A ETRE ARRIVE. ON PARLE ICI
D'ALGORITHME FIFO ("First in, first out").

EN PROGRAMMATION, LES FILES SONT UTILES POUR METTRE EN ATTENTE DES INFO DANS L'ORDRE DANS LEQUEL ELLES SONT ARRIVEES.
PAR EXEMPLE, LES EVENEMENTS QUE M'ENVOIE LA BIBLIO SDL SONT EUX AUSSI STOCKES DANS UNE FILE. SI JE BOUGE LA SOURIS, UN EVENT
SERA GENERE POUR CHAQUE PIXEL DONT S'EST DEPLACE LE CURSEUR DE LA SOURIS. LA SDL LES STOCKE DANS UNE FILE, PUIS ME LES ENVOIE
UN A UN A CHAQUE FOIS QUE JE FAIS APPEL A SDL_PollEvent(ou SDL_WaitEvent).
EN C, UNE FILE EST UNE LISTE CHAINNEE OU CHAQUE ELEMENT POINTE VERS LE SUIVANT, TOUT COMME LES PILES. LE DERNIER ELEMENT DE LA
FILE POINTE VERS NULL.

1.) CREATION D'UN SYSTEME DE FILE
LES STRUCTURES SONT LES MEMES QUE POUR LES PILES (Y A QU'A REMPLACER Pile par File)

2.) ENFILAGE

LA FCT QUI RAJOUTE UN ELEMENT A LA FILE EST APPELEE FONCTION D'ENFILAGE. IL Y A DEUX CAS A GERER:
    -   SOIT LA FILE EST VIDE, DANS CE CAS ON DOIT JUSTE CREER LA FILE EN FAISANT POINTER premier VERS LE NOUVEL ELEMENT CREE
    -   SOIT LA FILE N'EST PAS VIDE, DANS CE CAS IL FAUT PARCOURIR TOUTE LA FILE EN PARTANT DU PREMIER ELEMENT JUSQU'A ARRIVER
    AU DERNIER. ON RAJOUTERA NOTRE NOUVEL ELEMENT APRES LE DERNIER

AINSI SOIT-ELLE :
void enfiler(File *file, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if(file == NULL || nouveau == NULL)
        exit(EXIT_FAILURE);

    nouveau->nombre = nvNombre;
    nouveau->suivant = NULL;

    if(file->premier != NULL) // LA FILE N'EST PAS VIDE
    {
        Element *elementActuel = file->premier;
        while(elementActuel->suivant != NULL) //ON SE POSITIONNE A LA FIN DE LA FILE
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else // LA FILE EST VIDE, MON ELEMENT EST LE PREMIER
        file->premier = nouveau;
}

JE TRAITE DANS CE CODE DEUX CAS POSSIBLES, CHACUN DEVANT ETRE GERE A PART. LA DIFFERENCE PAR RAPPORT AUX PILES, EST QU'IL FO
SE PLACER A LA FIN DE LA FILE POUR AJOUTER UN NOUVEL ELEMENT.

3.) DEFILAGE

Le defilage ressemble etrangement au depilage. CECI S'EXPLIQUE PAR LE FAIT QUE LES ELEMENTS SONT ENFILES DE MANIERE A PLACER LES
PREMIERS ARRIVES AU DEBUT DE LA FILE. ET OUI, DANS UNE FILE DE 5 ELEMENT, LE 5EME SERA PLACE A LA FIN, MAIS LE 1ER VA SE REROUVER
AU TOUT DEBUT.

AINSI SOIT-ELLE :
int defiler(File *file)
{
    if(file == NULL || file->premier == NULL)
        exit(EXIT_FAILURE);

    int nombreDefile = 0;
    Element *elementDefile = file->premier;
    nombreDefile = elementDefile->nombre;
    file->premier = elementDefile->suivant;
    free(elementDefile);

    return nombreDefile;
}

3.) AFFICHER LA FILE

void afficherFile(File *file)
{
    if(file == NULL)
        exit(EXIT_FAILURE);

    if(file->premmier != NULL)
    {
        Element *elementActuel = file->premier;
        while(elementActuel != NULL)
        {
            printf("%d ", elementActuel->nombre);
            elementActuel = elementActuel->suivant;
        }
    }
    else
        printf("NULL");
    printf("\n");
}

*/

int main()
{
    Pile *maPile = initialiser();
    empiler(maPile, 2);
    empiler(maPile, 4);
    empiler(maPile, 8);
    empiler(maPile, 16);
    empiler(maPile, 32);

    printf("L'etat de la pile : \n");
    afficherPile(maPile);

    printf("\nJe depile :\n");
    printf("%d \n", depiler(maPile));
    printf("%d \n", depiler(maPile));

    printf("\n L'etat de la pile : \n");

    afficherPile(maPile);

    File *maFile = initialiserFile();
    enfiler(maFile, 2);
    enfiler(maFile, 4);
    enfiler(maFile, 8);
    enfiler(maFile, 16);
    enfiler(maFile, 32);

    printf("\nL'etat de la file : \n");
    afficherFile(maFile);
    printf("\nJe defile: \n");
    printf("%d \n", defiler(maFile));
    printf("%d \n", defiler(maFile));
    printf("\nL'etat de la file : \n");
    afficherFile(maFile);



    return 0;
}
