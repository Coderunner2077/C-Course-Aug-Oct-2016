#ifndef STRUCTURES_ENUMERATIONS_H_INCLUDED
#define STRUCTURES_ENUMERATIONS_H_INCLUDED



#endif // STRUCTURES_ENUMERATIONS_H_INCLUDED



    struct NomDeMaStrucure//astuce: 1re lettre MAJ pour diff�rencier des variables
    {
        int variable1;
        int variable2;
        int autreVariable;
        double nombreDecimal;
    };//; EST OBLIGATOIRE
    //Je cr�e une structure Coordonnees pour de bon
    typedef struct Coordonnees Coordonnees;//qui signifie <<Coordonnees>> �quivaut � <<struct Coordonnees>>
    struct Coordonnees
    {
        int x;
        int y;
    };
    typedef struct Coordinates Coordinates;
    struct Coordinates {
        int x;
        int y;
    };
    //Tableaux dans une structure


    typedef struct Personne Personne;
    struct Personne
    {
        char prenom[100];
        char nom[100];
        char ville[100];
        int age;
        int garcon;//un Bool�en
    };
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //EXEMPLE D'ENUMERATION
    typedef enum Volume Volume;
    enum Volume
    {
        FAIBLE, MOYEN, FORT
    };
    /*

    Pour cr�er une �num�ration, on utilise le mot-cl� enum. Notre �num�ration s'appelle ici Volume. C'est un type de variable
    personnalis� qui peut prendre une des trois valeurs qu'on a indiqu�es : soit FAIBLE, soit MOYEN, soit FORT

    */

    typedef enum Son Son;
    enum Son
    {
        LOW = 10, MEDIUM = 50, HIGH = 100
    };

