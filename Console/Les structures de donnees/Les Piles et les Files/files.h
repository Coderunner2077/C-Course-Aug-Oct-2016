#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED
#include "piles.h"

typedef struct File File;
struct File
{
    Element *premier;
};
File *initialiserFile();
void enfiler(File *file, int nvNombre);
int defiler(File *file);
void afficherFile(File *file);


#endif // FILES_H_INCLUDED
