#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#ifndef WIN32
    #include <sys/types.h>
    #define CLEAR   "clear" //system("clear") POUR UNIX
#else
    #define CLEAR   "cls" // system("cls") pour WINDOWS
#endif // WIN32

void lire(char s[]);
void viderBuffer();
int isDir(char nomObjet[]);
void lireDossier(char nomDossier[], DIR* rep);
int parcourirDossier(char chemin[], DIR* rep, int compteur);

int main(int argc, char *argv[])
{
    int compteur = 0;
    char chemin[300] = "";
    DIR* rep = opendir(chemin);
    compteur = parcourirDossier(chemin, rep, compteur);
    /*
    if(rep == NULL)
    {
        perror("");
        exit(-1);
        continuer = 0;
    }
    else
    {
        struct dirent* dossier = NULL;
        printf("\nVoici le contenu du dossier :\n");
        while((dossier = readdir(rep))!= NULL)
        {
            if(strcmp(dossier->d_name, ".")!=0 && strcmp(dossier->d_name, "..")!=0&& strstr(dossier->d_name, ".ini")==NULL)
            {
                printf("%s\n", dossier->d_name);
            }
        }
    */
    closedir(rep);
    return 0;
}

void lire(char s[])
{
    char *positionEntree = NULL;
    char temp[300] = "";
    if(fgets(temp, 300, stdin)!=NULL)
    {
        if(strchr(temp, '\n')!=NULL)
        {
            positionEntree = strchr(temp, '\n');
            *positionEntree = '\0';
        }
        else
            viderBuffer();
    }
    else
        viderBuffer();
    strcat(s, temp);
}

void viderBuffer()
{
    int c;
    while(c!='\n' && c!=EOF)
        c = getchar();
}

int isDir(char nomObjet[])
{
    DIR* rep = NULL;
    rep = opendir(nomObjet);
    if(rep !=NULL)
    {
        closedir(rep);
        return 1;
    }
    else
    {
        if(errno == ENOTDIR)
            return 0;
        else
            return 1;
    }
}

void lireDossier(char nomDossier[], DIR* rep)
{
    struct dirent* fichierLu = NULL;
    printf("\n--- Le contenu du dossier %s ---\n", nomDossier);
    while((fichierLu = readdir(rep))!=NULL)
    {
        if(strcmp(fichierLu->d_name, ".") !=0 && strcmp(fichierLu->d_name, "..") != 0 && strstr(fichierLu->d_name, ".ini") == NULL)
            printf("%s\n", fichierLu->d_name);
    }
    printf("\n--- Que voulez-vous ouvrir? ---\n");
}

int parcourirDossier(char chemin[], DIR* rep, int compteur)
{
    char temp[300] = {""};
    char slash[300] = {"/"};
    char cheminBis[300]={""};
    if(compteur !=0)
    {
        strcat(slash, chemin);
        strcat(cheminBis, slash);
        //sprintf(cheminBis, "%s/%s", temp, chemin);
        //strcat(slash, chemin);
        //strcat(cheminBis, slash);
    }
    else
        strcpy(cheminBis, chemin);
    lire(cheminBis);
    system(CLEAR);

    if(!isDir(cheminBis))
    {
        printf("%s n'est pas un dossier.\n", cheminBis);
        exit(-1);
    }

    rep = opendir(cheminBis);
    if(rep == NULL)
    {
        printf("Le dossier %s n'a pas pu etre ouvert, compteur : %d", cheminBis, compteur);
        exit(-2);
    }

    lireDossier(cheminBis, rep);
    closedir(rep);
    compteur++;
    parcourirDossier(cheminBis, rep, compteur);
    return compteur;
}
