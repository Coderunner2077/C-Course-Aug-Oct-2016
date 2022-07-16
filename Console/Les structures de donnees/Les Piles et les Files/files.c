#include <stdio.h>
#include <stdlib.h>
#include "files.h"

File *initialiserFile()
{
    File *file = malloc(sizeof(*file));
    if(file == NULL)
        exit(EXIT_FAILURE);

    file->premier = NULL;
    return file;
}

void enfiler(File *file, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if(file == NULL || nouveau == NULL)
        exit(EXIT_FAILURE);

    nouveau->nombre = nvNombre;
    nouveau->suivant = NULL; // !!!!!!!!!!!!
    if(file->premier != NULL)
    {
        Element *elementActuel = file->premier;
        while(elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else
        file->premier = nouveau;
}

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

void afficherFile(File *file)
{
    if(file == NULL)
        exit(EXIT_FAILURE);

    if(file->premier != NULL)
    {
        Element *elementActuel = file->premier;
        while(elementActuel != NULL)
        {
            printf("%d ", elementActuel->nombre);
            elementActuel = elementActuel->suivant;
        }
    }
    else
        printf("NULL\n");
    printf("\n");
}
