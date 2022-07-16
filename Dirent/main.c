#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>


#ifndef WIN32
#include <sys/types.h>
#endif // WIN32

int compterFichiers(DIR* rep);
int determinerObjet(const char chaineChemin[]);
int main(int argc, char *argv[])
{
    DIR* rep = NULL;
    FILE* fichier = NULL;
    char nomFichier[100] = {""};
    long numero = 0;
    rep = opendir("C:\\Users\\Harry\\Pictures"); // PROTO : DIR* opendir(const char* chemin);
    char emplacementDossier[200] = {"C:\\Users\\Harry\\Pictures\\"};
    if(rep == NULL) //SI LE DOSSIER N'A PAS PU ETRE OUVERT
    {
        perror("Erreur ");
        exit(1);
        if(errno == EACCES) // errno EST UNE VARIABLE GLOBALE DE TYPE int (POUVANT PRENDRE PLUSIEURS VALEURS DE defines PREDEFINIES) QUI PREND POUR VALEUR L'ERREUR SURVENUE
            puts("Acces interdit");
        //errno NE SI LIMIE PAS A LA MANIPULATION DES DOSSIERS. D'AUTRES FCTS STANDARDS L'UTILISENT, COMME fopen PAR EXEMPLE
    }
    /*UNE AUTRE VARIANTE : AVEC void perror(const char* str);
    if(rep == NULL)
    {
        perror("Erreur ");
        exit(1);
    }
    // LA FCT ATTEND UNE CHAINE DE CARACTERES QUI SERA ECRITE A L'ECRAN, A LA MANIERE DE printf. ENSUITE perror SE CONTENTERA
    // DE DECRIRE L'ERREUR (in English). EN ENVOYANT UNE CHAINE DE CARACTERES NON NULLE ==> ':' DEVANT LE DETAIL D'ERREUR
    */
    puts("Le dossier a ete ouvert avec succes\n");

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MANIPULER DES FICHIERS A L'INTERIEUR DES DOSSIERS

    /*PROTO : struct dirent* readdir(DIR* repertoire);
    readdir() RENVOIE UN POINTEUR SUR UNE STRUCTURE dirent. ET CETTE STRUCTURE SIMULE LE FICHIER DU DOSSIER QUI SERA LU
    readdir() RENVOIE NULL S'IL N'Y A PLUS DE FICHIERS A LIRE

    */
    struct dirent* fichierLu = NULL;
    fichierLu = readdir(rep); // ON LIT LE PREMIER REPERTOIRE DU DOSSIER
    //MAINTENANT, LE POINTEUR fichierLu POINTE VERS LE PREMIER REPERTOIRE DU DOSSIER Pictures
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //LISTER LE CONTENU D'UN REPERTOIRE
    printf("Le fichier lu s'appelle : %s \n", fichierLu->d_name); // LE POINT REPRESENTE LE DOSSIER ACTUEL, CELUI OU JE ME TROUVE
    /*
    fichierLu = readdir(rep);
    printf("Le fichier lu s'appelle : %s \n", fichierLu->d_name); // LES DEUX POINTS REPRESENTENT LE DOSSIER PRECEDENT, CELUI QUI CONTIENT LE DOSSIER OU JE ME TROUVE
    fichierLu = readdir(rep);
    printf("Le fichier lu s'appelle : %s \n", fichierLu->d_name);
    fichierLu = readdir(rep);
    printf("Le fichier lu s'appelle : %s \n", fichierLu->d_name);
    */
    seekdir(rep, 0);
    while((fichierLu = readdir(rep))!=NULL) // je lis TOUT le repertoire, i.e. tant que je ne suis pas arrive au bout du repertoire
    {
        printf("Le fichier lu numero %ld s'appelle : %s \n", telldir(rep), fichierLu->d_name);
        if(strstr(fichierLu->d_name, ".txt")!=NULL)
        {
            sprintf(nomFichier, "%s", fichierLu->d_name);
        }
    }
    char nomFichierComplet[300] = {""};
    sprintf(nomFichierComplet, "%s%s", emplacementDossier, nomFichier);
    fichier = fopen(nomFichierComplet, "w+"); // J'AI UTILISE L'ADRESSE ABSOLUE POUR OUVRIR LE FICHIER
    if(fichier == NULL)
        exit(2);
    fputs("Hello le monde!", fichier);
    fclose(fichier);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // DEPLACEMENT DANS UN REPERTOIRE

    /*EN EFFET, IL Y A UN CURSEUR VIRTUEL, QUI S'INCREMENT A CHAQUE FOIS QUE JE LIS UN FICHIER*/
    // SE REPERER DANS LE REPERTOIRE
    //PROTO : long telldir(DIR* rep);
    printf("Position du curseur virtuel : %ld\n", telldir(rep));
    // RETOURNER AU DEBUT
    rewinddir(rep); // PROTO : void rewinddir(rep);
    printf("Position du curseur virtuel : %ld\n", telldir(rep));
    // DEPLACER LE CURSEUR VIRTUEL
    seekdir(rep, 3);
    fichierLu = readdir(rep);
    printf("\nVoici le 2e fichier du dossier : %s\n", fichierLu->d_name);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // EXERCICES
    // COMPTER LE NB DE FICHIERS DANS LE DOSSIER
    rewinddir(rep); // POUR COMPTER A PARTIR DE DEBUT
    printf("\nVoici le nombre de fichiers contenus dans le dossier actuel : %d\n", compterFichiers(rep));
    // DETERMINER SI LE FICHIER LU EST UN REPERTOIRE OU NON
    rewinddir(rep);
    while((fichierLu = readdir(rep))!=NULL)
    {
        char emplacementFichier[300] = {""};
        strcpy(emplacementFichier, emplacementDossier);
        strcat(emplacementFichier, fichierLu->d_name);
        if(determinerObjet(emplacementFichier))
            printf("%s est un dossier\n", fichierLu->d_name);
        else
            printf("%s n'est pas un dossier\n", fichierLu->d_name);
    }
    if(closedir(rep) == -1) // S'IL Y A EU UN SOUCI AVEC LE FERMETURE DU DOSSIER
        exit(-1);
    printf("Le dossier a ete ferme avec succes");
    return 0;
}

int compterFichiers(DIR* rep)
{
    int compteur = 0;
    struct dirent* fichierLu = NULL;
    while((fichierLu = readdir(rep))!=NULL)
    {
        if(strstr(fichierLu->d_name, ".ini")!=NULL);
        else if(strcmp(fichierLu->d_name, ".")!= 0 && strcmp(fichierLu->d_name, "..")!=0)
            compteur++;
    }

    return compteur;
}

int determinerObjet(const char chaineChemin[])
{
    DIR* rep = NULL;
    rep = opendir(chaineChemin);
    if(rep!=NULL)
    {
        closedir(rep);
        return 1;
    }
    else
    {
        if(errno == ENOTDIR) // SI L'ERREUR SURVENUE EST : "Not a directory"
            return 0;
        else
            return 1;
    }
}
