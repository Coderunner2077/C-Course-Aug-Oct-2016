#include <stdio.h>
#include <stdlib.h>

typedef struct Coordonnees Coordonnees;
struct Coordonnees
{
    int x;
    int y;
};

int main(int argc, char* argv[])
{
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //ALLOCATION MANUELLE (OU DYNAMIQUE) DE LA MEMOIRE
    //sizeof() : UNE FONCTIONNALITE DE BASE DU LANGAGE C POUR VERIFIER LA TAILLE EN OCTETS DES TYPES DE VARIABLES
    char lettre = 'A';
    printf("char : %d octet(s),\n", sizeof(lettre));
    printf("char* : %d octet(s),\n", sizeof(char*));
    printf("int : %d octet(s),\n", sizeof(int));
    printf("long : %d octet(s),\n", sizeof(long));
    printf("float : %d octet(s),\n", sizeof(float));
    printf("double : %d octet(s),\n", sizeof(double));
    printf("Certaines de ces tailles peuvent varier d'une machine a l'autre\n");
    printf("Struct Coordonnees : %d octet(s),\n", sizeof(Coordonnees));
    printf("Plus une structure contient de sous-variables, plus elle prend de memoire\n");

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //void* malloc(size_t nombreOctetsNecessaires);
    //void* EST UNE SORTE DE POINTEUR UNIVERSEL SUR TOUT TYPE ==> PARCE QUE malloc NE SAIT PAS QUEL TYPE DE VARIABLE ELLE VA RETOURNER,

    int* memoireAllouee=NULL;
    printf("L'adresse du pointeur avant l'allocation de mémoire par l'OS : %p\n", memoireAllouee);
    memoireAllouee=malloc(sizeof(int));
    printf("L'adresse qui m'a ete reservee par l'OS et qui est contenue dans le pointeur memoireAllouee : %p\n",memoireAllouee);
    printf("Valeur de la variable memoireAllouee apres allocation dynamique : %d\n", *memoireAllouee);
    if(memoireAllouee == NULL)
    {
        printf("L'allocation de memoire a echoue car il n'y avait plus de memoire de libre.\n Le programme va fermer\n");
        exit(0);
    }
    //JE PEUX UTILISER ICI LA MEMOIRE
    free(memoireAllouee);//ON N'A PLUS BESOIN DE LA MEMOIRE, ON LA LIBERE
    // EXEMPLE CONCRET
    int* age=NULL;
    age=malloc(sizeof(int));
    if(age==NULL)
    {
        printf("L'allocation de memoire a echoue car il n'y avait plus de memoire de libre.\n Le programme va fermer\n");
        exit(0);
    }
    printf("Quel est votre age?\n");
    scanf("%d", age);
    printf("Vous avez donc %d ans\n",*age);

    free(age);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //ALLOCATION DYNAMIQUE D'UN TABLEAU
    int nombreDAmis=0;
    int* ageAmis=NULL;
    printf("Combien d'amis avez-vous ?");
    scanf("%d",&nombreDAmis);
    if(nombreDAmis > 0)
    {
    ageAmis=malloc(nombreDAmis*sizeof(int)); //CE CODE PERMET DE CREER UN TABLEAU DE TYPE int QUI A UNE TAILLE EXACTEMENT CORRESPONDANT AU NOMBRE D'AMIS
    if(ageAmis==NULL)
    {
        printf("L'allocation de memoire a echoue car il n'y avait plus de memoire de libre.\n Le programme va fermer\n");
        exit(0);
    }

    int i;
    for(i=0;i<nombreDAmis;i++)
    {
        printf("L'age de l'ami numero %d?\n",i+1);
        scanf("%d",&ageAmis[i]);
    }
    printf("\nVos amis ont les ages suivants :\n");
    for(i=0;i<nombreDAmis;i++)
    {
        printf("\n%d ans",ageAmis[i]);
    }
    free(ageAmis);
    }
    return 0;
}
