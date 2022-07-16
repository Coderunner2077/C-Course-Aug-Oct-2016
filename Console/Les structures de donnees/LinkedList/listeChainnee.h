#ifndef LISTECHAINNEE_H_INCLUDED
#define LISTECHAINNEE_H_INCLUDED
typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    int nbElements;
    Element *premier;
};

Liste *initialisation();
void insertion(Liste *liste, int nvNombre);
void suppression(Liste *liste);
void afficherListe(Liste *liste);
void insererAuMilieu(Liste *liste, Element *ePrecedent, int nvNombre);
void supprimerAuMilieu(Liste *liste, Element *aSupprimer);
int destructionListe(Liste *liste);
int listeLength(Liste *liste);



#endif // LISTECHAINNEE_H_INCLUDED
