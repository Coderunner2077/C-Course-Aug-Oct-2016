#include <stdio.h>
#include <stdlib.h>
#include "liste_chainnee.h"

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if(liste == NULL || element == NULL)
        exit(EXIT_FAILURE);

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;
    liste->nbElements = 1;

    return liste;
}

void insertion(Liste *liste, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if(liste == NULL || nouveau == NULL)
        exit(EXIT_FAILURE);

    nouveau->nombre = nvNombre;
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
    liste->nbElements++;
}

void suppression(Liste *liste)
{
    if(liste == NULL)
        exit(EXIT_FAILURE);

    if(liste->premier != NULL)
    {
        Element *aSupprimer = liste->premier;

        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
    liste->nbElements--;
}

void afficherListe(Liste *liste)
{
    if(liste == NULL)
        exit(EXIT_FAILURE);

    Element *actuel = liste->premier;
    while(actuel != NULL)
    {
        printf("%d -> ", actuel->nombre); // MARCHE PAS SI J'INVERSE L'ORDRE
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

void insererAuMilieu(Liste *liste, Element *ePrecedent, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if(nouveau == NULL || liste == NULL || ePrecedent == NULL)
        exit(EXIT_FAILURE);

    nouveau->nombre = nvNombre;
    Element *actuel = liste->premier;
    while(actuel->nombre != ePrecedent->nombre)
    {
        actuel = actuel->suivant;
    }

    nouveau->suivant = actuel->suivant;
    actuel->suivant = nouveau;
    liste->nbElements++;
}

void supprimerAuMilieu(Liste *liste, Element *aSupprimer)
{
    if(liste == NULL || aSupprimer == NULL)
        exit(EXIT_FAILURE);

    Element *precedent = NULL;
    Element *actuel = liste->premier;
    while(actuel->nombre != aSupprimer->nombre)
    {
        precedent = actuel;
        actuel = actuel->suivant;
    }
    aSupprimer = actuel;
    precedent->suivant = actuel->suivant;
    free(aSupprimer);
    liste->nbElements--;

}

int destructionListe(Liste *liste)
{
    if(liste == NULL)
        exit(EXIT_FAILURE);

    Element *actuel = liste->premier;
    while(actuel->suivant != NULL)
    {

        Element *aSupprimer = actuel->suivant;
        actuel->suivant = actuel->suivant->suivant;
        free(aSupprimer);
    }
    if(liste->premier != NULL)
    {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
        liste->nbElements = 0;
    }
    if(liste->premier == NULL)
        return 1;
    else
        return 0;
}

int listeLength(Liste *liste)
{
    if(liste == NULL)
        exit(EXIT_FAILURE);

    return liste->nbElements;
}
