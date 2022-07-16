#include <stdio.h>
#include <stdlib.h>
#include "piles.h"

Pile *initialiser()
{
    Pile *pile = malloc(sizeof(*pile));
    if(pile == NULL)
        exit(EXIT_FAILURE);

    pile->premier = NULL;
    return pile;
}

void empiler(Pile *pile, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if(pile == NULL || nouveau == NULL)
        exit(EXIT_FAILURE);

    nouveau->nombre = nvNombre;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}

int depiler(Pile *pile)
{
    if(pile == NULL || pile->premier == NULL)
        exit(EXIT_FAILURE);
    int nombreDepile = 0;
    Element *elementDepile = pile->premier;
    nombreDepile = elementDepile->nombre;
    pile->premier = elementDepile->suivant;
    free(elementDepile);

    return nombreDepile;
}

void afficherPile(Pile *pile)
{
    if(pile == NULL)
        exit(EXIT_FAILURE);
    if(pile->premier != NULL)
    {
        Element *elementActuel = pile->premier;
        while(elementActuel != NULL)
        {
            printf("%d\n", elementActuel->nombre);
            elementActuel = elementActuel->suivant;
        }
    }
    else
        printf("NULL\n");
    printf("\n");
}
