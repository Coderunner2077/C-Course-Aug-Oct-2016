#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

enum{VIDE, PLAY, PAUSE, STOP, FORWARD, BACKWARD, BARRE, NEXT, PLAYED, TOPLAY, TITLE, VOLUME, REPLAY, REPLAY_OFF, DUREE, TEMPS_RESTANT,
MUTE, MUTE_OFF, BARRE_VOLUME};

void chargerSon(long numeroMorceau, char emplacementMorceau[])
{
    char emplacementFichier[150] = {"bibliotheque\\"};
    char *positionEntree = NULL;
    long compteur = 1;

    DIR *rep = NULL;
    rep = opendir("bibliotheque");
    if(rep == NULL)
    {
        fprintf(stderr, "Erreur d'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    struct dirent* fichierLu = NULL;
    seekdir(rep, 2);
    fichierLu = readdir(rep);
    printf("%s\n", fichierLu->d_name);
    strcat(emplacementFichier, fichierLu->d_name);
    printf("%s\n", emplacementFichier);
    FILE* fichier = NULL;
    fichier = fopen(emplacementFichier, "r");
    if(fichier == NULL)
    {
        fprintf(stderr, "Impossible d'ouvrir le playlist wesh");
        exit(EXIT_FAILURE);
    }
    else
    {
        while(compteur <= numeroMorceau)
        {
            fgets(emplacementMorceau, 150, fichier);
            if(strstr(emplacementMorceau, "#EXT")== NULL)
                compteur++;
        }
        positionEntree = strchr(emplacementMorceau, '\n');
        *positionEntree = '\0';
        printf("%s", emplacementMorceau);
        printf("test");
        fclose(fichier);
    }
    closedir(rep);
}

long determinerMorceau(long *numeroMorceau, int *replay, int *commande, long *lastSong, char sonActuel[])
{
    char emplacementFichier[150] = {"bibliotheque\\"}, empMorceau[150] = {""};
    long compteur = 1, verif, numLigneMorceau = 0;
    char *virgule = NULL;
    DIR *rep = NULL;
    rep = opendir("bibliotheque");
    if(rep == NULL)
    {
        fprintf(stderr, "Erreur d'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    struct dirent* fichierLu = NULL;
    seekdir(rep, 2);
    fichierLu = readdir(rep);
    strcat(emplacementFichier, fichierLu->d_name);
    FILE* fichier = NULL;
    fichier = fopen(emplacementFichier, "r");
    if(fichier == NULL)
    {
        fprintf(stderr, "Impossible d'ouvrir le playlist");
        exit(EXIT_FAILURE);
    }
     while(fgets(empMorceau, 150, fichier) != NULL)
    {

        if(strstr(empMorceau, ".mp3") != NULL)
            *lastSong = *lastSong + 1;
    }
    compteur = 0;
    if(*commande == FORWARD && *numeroMorceau < *lastSong)
    {
        *numeroMorceau = *numeroMorceau + 1;
    }
    else if(*commande == FORWARD && *numeroMorceau == *lastSong && *replay < 0)
    {
        *numeroMorceau = 1;
    }
    else if(*commande == FORWARD && *numeroMorceau == *lastSong && *replay == 0)
     *numeroMorceau = *lastSong;
    else if(*commande == BACKWARD || *numeroMorceau > 1)
        *numeroMorceau = *numeroMorceau - 1;
    numLigneMorceau = *numeroMorceau * 2;
    rewind(fichier);
    while(compteur <= numLigneMorceau)
    {
        fgets(empMorceau, 150, fichier);
        compteur++;
        if(compteur == numLigneMorceau)
        {
            sprintf(sonActuel, "%s", strchr(empMorceau, ','));
            virgule = strchr(sonActuel, ',');
            *virgule = ' ';
            verif = compteur;
        }
    }
    fclose(fichier);
    closedir(rep);
    return numLigneMorceau;
}

int main(int argc, char *argv[])
{
    char emplacementMorceau[150] = {""}, sonActuel[150] = {""};
    long numeroMorceau = 4, lastSong = 0, verif = 0;
    int commande = 0, replay = 0;
    commande = FORWARD;
    replay = -1;
    chargerSon(numeroMorceau, emplacementMorceau);
    printf("\n%stest", emplacementMorceau);
    verif = determinerMorceau(&numeroMorceau, &replay, &commande, &lastSong, sonActuel);
    printf("\n\nNumero morceau : %ld", numeroMorceau);

    printf("\n Valeur test :%s", sonActuel);
    return 0;
}
