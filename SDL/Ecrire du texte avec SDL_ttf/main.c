#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
/*
                                                ECRIRE DU TEXTE AVEC SDL_ttf

SDL_ttf est une extension de la SDL, tout comme SDL_image. Il faut donc la telecharger et l'installer.
PAR AILLEURS, SDL_ttf FAIT APPEL A UNE AUTRE BIBLIOTHEQUE FreeType AFIN QUE CELLE-CI LISE LES FICHIERS DE POLICE (.ttf) ET EN SORTE
L'IMAGE. DE SON COTE, SDL_ttf RECUPERE CETTE IMAGE ET LA CONVERTIT POUR LA SDL EN CREANT UNE SDL_Surface.
LA BIBILIO FreeType EST INCLUSE DANS SDL_ttf.

INSTALLATION :
Aller sur:
https://www.libsdl.org/projects/SDL_ttf/release-1.2.html
Dans Binary, cliquer sur ...win32.zip et ...VC.zip
Copier le contenu du win32 dans le dossier de mon projet
Le fichier SDL_ttf...VC.eip contient comme d'habitude un dossier include et un dossier lib. Placer le contenu du dossier include
dans mingw32/include/SDL et le contenu du dossier lib dans mingw32/lib.
Et enfin, modifier les options de linker pour qu'il compile bien mon programme en utilisant la biblio SDL_ttf

I./ CHARGEMENT DE SDL_ttf

AVANT TOUTE CHOSE, IL FAUT PENSER A INCLURE LA SDL_ttf :
#include <SDL/SDL_ttf.h>

1.) DEMARRAGE DE SDL_ttf
TOUT COMME LA SDL, LA SDL_ttf A BESOIN D'ETRE DEMARREE ET ARRETEE
TTF_Init : DEMARRE LA SDL_ttf
TTF_Quit : ARRETE LA SDL_ttf

NOTE : IL N'EST PAS NECESSAIRE QUE LA SDL SOIT DEMARREE AVANT LA SDL_ttf

POUR "INITIALISER" LA SDL_ttf, ON DOIT DONC APPELER TTF_Init(). AUCUN PARAMETRE N'EST NECESSAIRE. LA FCT RENVOIE -1 S'IL Y A EU
UNE ERREUR.
SI JE VEUX ETRE RIGOUREUX, J'INITIALISE AINSI :
if(TTF_Init() == -1)
{
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
}

2.) ARRETER LA SDL_ttf

TTF_Quit();
LA ENCORE, AUCUN PARAMETRE. JE PEUX L'APPELER AVANT OU APRES SDL_Quit, PEU IMPORTE.

3.) CHARGEMENT D'UNE POLICE

a./ CHARGER LA POLICE

MAINTENANT QUE LA SDL_ttf EST CHARGEE, JE DOIS AUSSI CHARGER UNE POLICE. LA ENCORE IL Y A DEUX FONCTIONS :

    -   TTF_OpenFont : OUVRE UN FICHIER DE POLICE (.ttf)
    -   TTF_CloseFont : FERME UNE POLICE OUVERTE

TTF_OpenFont DOIT STOCKER SON RESULTAT DANS UNE VARIABLE DE TYPE TTF_Font. JE DOIS CREER UN POINTEUR DE TTF_Font COMME CECI :

TTF_Font *police = NULL;

LE POINTEUR police CONTIENDRA DONC LES INFO SUR LA POLICE UNE FOIS QU'ON L'AURA OUVERTE. LA FCT TTF_OpenFont PREND 2 PRMTRES :
    -   LE NOM DU FICHIER DE POLICE (AU FORMAT .ttf) A OUVRIR. L'IDEAL EST DE METTRE LE FICHIER DE POLICE DANS LE REPERTOIRE
    DE MON PROJET. EXEMPLE DE FICHIER : arial.ttf
    -   LA TAILLE DE LA POLICE A UTILISER. JE PEUX PAR EXEMPLE UTILISER UNE TAILLE 22.
    CE SONT LES MEMES TAILLES QUE CELLES QUE J'UTILISE DANS UN LOGICIEL DE TRAITEMENT DE TEXTE TEL QUE Word



Y A PLUS QU'A TROUVER CES FAMEUSES POLICES :
--> SOIT SUR MON ORDI, RUBRIQUE C:\Windows\Fonts
--> SOIT SUR LE NET (bon site : dafont.com)
ET Y A PLUS QU'A COPIER LE FICHIER DE POLICE QUI ME PLAIT DANS LE DOSSIER DE MON PROJET.
ATTENTION : IL EST FORTEMENT RECOMMANDE QUE LE NOM DU FICHIER SOIT LE PLUS SIMPLE POSSIBLE (SANS SYMBOLES BIZARRES, TOUT EN
MINUSCULES, SANS ESPACES SURTOUT)

POUR CHARGER LA POLICE Babanas PAR EXEMPLE, ON OUVRIRA LA POLICE COMME CECI :

police = TTF_OpenFont("babanas.ttf", 40);

ATTENTION, TTF_OpenFont STOCKE LE RESULTAT DANS LA VARIABLE police; JE VAIS REUTILISER TOUT A L'HEURE CETTE VARIABLE EN ECRIVANT
DU TEXTE. ELLE PERMETTRA D'INDIQUER LA POLICE QUE JE VEUX UTILISER POUR ECRIRE MON TEXTE.

NOTE: PAS BESOIN D'OUVRIR LA POLICE A CHAQUE FOIS QUE JE VEUX ECRIRE DU TEXTE. JE L'OUVRE UNE FOIS AU DEBUT DU PROG ET LA FERME
A LA FIN.

b./ FERMER LA POLICE

IL FAU PENSER A FERMER CHAQUE POLICE OUVERTE AVANT L'APPEL DU TTF_Quit, COMME CECI :

TTF_CloseFont(police);
TTF_Quit();

ET VOILA LE TRAVAIL

II./ DIFFERENTES METHODES D'ECRITURE

1.) LES TROIS MODES D'ECRITURE

D'APRES LA DOC', IL Y A AU MOINS 12 FCTS DISPO POUR ECRIRE DU TEXTE.
EN FAIT, IL Y A TROIS FACONS DIFFERENTES DE DESSINER DU TEXTE :
    -   Solid : C'EST LA TECHNIQUE LA PLUS RAPIDE. LE TEXTE SERA RAPIDEMENT ECRIT DANS UNE SDL_Surface. LA SURFACE SERA
    TRANSPARENTE (i.e. le fond) MAIS N'UTILISERA QU'UN NIVEAU DE TRANSPARENCE. C'EST PRATIQUE, MAIS LE TEXTE NE SERA PAS TRES
    JOLI, PAS TRES "ARRONDI", SURTOUT S'IL EST ECRIT GROS. TECHNIQUE A PRIVILEGIER SI JE DOIS CHANGER SOUVENT LE TEXTE, PAR
    EXEMPLE AFFICHER LE TEMPS QUI S'ECOULE OU LE NB DE FPS D'UN JEU;
    -   Shaded : CETTE FOIS, LE TEXTE SERA JOLI. LES LETTRES SERONT ANTIALIASEES (I.E. CONTOURS ADOUCIS) ET LE TEXTE APPARAITRA
    PLUS LISSE. IL Y A UN DEFAUT, EN REVANCHE : LE FOND DOIT ETRE D'UNE COULEUR UNIE. IL EST IMPOSSIBLE DE RENDRE LE FOND DE LA
    SDL_Surface TRANSPARENT EN Shaded;
    -   Blended : C'EST LA TECHNIQUE LA PLUS PUISSANTE. LES LETTRES SERONT ANTIALIASEES. EN FAIT ELLE MET AUTANT DE TEMPS QUE
    Shaded A CREER LA SDL_Surface. LA SEULE DIFFERENCE AVEC Shaded, C'EST QUE JE PEUX BLITTER LE TEXTE SUR UNE SURFACE ET LA
    TRANSPARENCE SERA RESPECTEE. ATTENTION, LE CALCUL DU BLIT SERA PLUS LONG QUE POUR Shaded.

Bref:
si texte change souvent ==> Solid
sinon, si je veux blitter sur un fond uni ==> Shaded
Sinon, sinon ==> Blended

2.) LES QUATRE charset
POUR CHACUN DE CES TROIS TYPES D'ECRITURE, IL Y A QUATRE FONCTIONS. CHAQUE FONCTION ECRIT LE TEXTE A L'AIDE D'UN charset DIFFERENT
C'EST A DIRE D'UNE PALETTE DE CARACTERES DIFFERENTE. CES QUATRE charset SONT :
    -   Latin1;
    -   UTF8;
    -   Unicode;
    -   Unicode Glyph.

L'IDEAL EST D'UTILISER Unicode, CAR C'EST UN CHARSET GERANT LA QUASI-TOTALITE DES CARACTERES EXISTANT SUR TERRE. TOUTEFOIS,
UTILISER L'Unicode N'EST PAS TOUJOURS FORCEMENT SIMPLE (UN CARACTERE PREND PLUS QUE LA TAILLE D'UN char EN MEMOIRE). JE NE VERRAI
DONC PAS COMMENT L'UTILISER ICI.

A PRIORI, SI MON PROG ECRIT EN FRANCAIS, LE MODE Latin1 SUFFIT AMPLEMENT. JE PEUX ME CONTENER DE CELUI-LA.

3.) LES TROIS FONCTIONS UTILISANT LE charset Latin1

LES TROIS FCTS UTILISANT LE charset Latin1 SONT :

    -   TTF_RenderText_Solid;
    -   TTF_RenderText_Shaded;
    -   TTF_RenderText_Blended.

4.) EXEMPLE D'ECRITURE DU TEXTE EN BLENDED

ATTENTION, POUR SPECIFIER UNE COULEUR A SDL_ttf, ON NE VA PAS UTILISER LE MEME TYPE QU'AVEC LA SDL (un Uint32 cree a l'aide de
SDL_MapRGB). AU CONTRAIRE, JE VAIS UTILISER UNE STRUCTURE TOUTE PRETE DE LA SDL :
SDL_Color
CETTE STRUCTURE COMPORTE TROIS SOUS-VARIABLES : LA QUANTITE DE ROUGE, DE VERT ET DE BLEU.

POUR CREER UNE VARIABLE couleurNoire, JE DOIS DONC ECRIRE :
SDL_Color couleurNoire = {0, 0, 0};

JE VAIS ECRIRE UN TEXTE EN NOIR DANS UNE SDL_Surface texte :

texte = TTF_RenderText_Blended(police, "Salut les Zeros !", couleurNoire);

LES TROIS PAREMETRES DE TTF_RenderText_Blended SONT DONC LES SUIVANTS :

    -   LA POLICE (DE TYPE TTF_Font)
    -   LE TEXTE A ECRIRE
    -   ET ENFIN, LA COULER DU TEXTE (DE TYPE SDL_Color)

LE RESULTAT EST STOCKE DANS UNE SDL_Surface. SDL_ttf CALCULE AUTOMATIQUEMENT LA TAILLE NECESSAIRE A DONNER A LA SURFACE EN FCT DE
LA TAILLE DU TEXTE ET DU NOMBRE DE CARACTERES QUE J'AI VOULU ECRIRE.

COMME TOUTE SDL_Surface, MON POINTEUR texte CONTIENT LES SOUS-VARIABLES w ET h INDIQUANT RESPECTIVEMENT SA LARGEUR ET SA HAUTEUR.
C'EST DONC UN BON MOYEN DE CONNAITRE LES DIMENSIONS DU TEXTE UNE FOIS QUE CELUI-CI A ETE ECRIT DANS LA SDL_Surface. JE N'AURAI
QU'A ECRIRE :
texte->w pour avoir la largeur
texte->h pour avoir la hauteur

SI JE SOUHAITE CHANGER LE MODE D'ECRITURE DU TEXTE, IL N'Y A QU'UNE LIGNE A MODIFIER : CELLE CREANT LA SURFACE (avec l'appel
de la fonction TTF_RenderText_Blended).

ATTENTION : LA FCT TTF_RenderText_Shaded PREND UN QUATRIEME PAREMETRE, CONTRAIREMENT AUX DEUX AUTRES. CE DERNIER EST LA COULEUR
DE FOND A UTILISER. JE DEVRAI DONC CREER UNE AUTRE VARIABLE DE TYPE SDL_Color POUR INDQUER UNE COULEUR DE FOND (PAR EXEMPLE LE
BLANC).

5.) ATTRIBUTS D'ECRITURE DU TEXTE

IL EST AUSSI POSSIBLE DE SPECIFIER DES ATTRIBUTS D'ECRITURE, COMME GRAS, ITALIQUE OU SOULIGNE.
IL FAUT D'ABORD QUE LA POLICE SOIT CHARGEE. JE DOIS DONC AVOIR UNE VARIABLE police VALIDE. JE PEUX ALORS FAIRE APPEL A LA FCT
TTF_SetFontStyle QUI VA MODIFIER LA POLICE POUR QU'ELLE SOIT EN GRAS, ITALIQUE OU SOULIGNE, COMME JE LE DESIRE.
LA FONCTION PREND DEUX PARAMETRES :
    -   LA POLICE A MODIFIER
    -   UNE COMBINAISON DE FLAGS POUR INDIQUER LE STYLE A DONNER : GRAS, ITALIQUE OU SOULIGNE

VOICI LES CONSTANTES A UTILISER POUR LES FLAGS JUSTEMENT :
    -   TTF_STYLE_NORMAL
    -   TTF_STYLE_BOLD : gras
    -   TTF_STYLE_ITALIC
    -   TTF_STYLE_UNDERLINE

    COMME C'EST UNE LISTE DE FLAGS, JE PEUX LES COMBINER AVEC |

POUR RESTAURER UNE POLICE A L'ETAT NORMAL, IL SUFFIT DE REFAIRE APPEL A LA FCT TTF_SetFontStyle EN UTILISANT LE FLAG :
TTF_STYLE_NORMAL

*/
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *solid = NULL, *shaded = NULL, *blended = NULL, *fond = NULL, *compteur = NULL;
    SDL_Rect position = {0, 0}, positionSolid = {2, 6}, positionShaded = {400, 50}, positionBlended = {2, 100}, pos;
    SDL_Event event;
    SDL_Color couleurNoire = {0, 0, 0};
    SDL_Color couleurVerte = {0, 255, 0};
    Uint32 tempsActuel = 0, tempsPrecedent = 0;
    int continuer = 1, compteurNB = 0;
    char temps[20] = {""};
    TTF_Font *police = NULL, *police2 = NULL; //REF LIGNE 55
    SDL_Init(SDL_INIT_VIDEO);
    if(TTF_Init() == -1) //REF LIGNE 31
{
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
}
    ecran = SDL_SetVideoMode(789, 462, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);
    fond = IMG_Load("canards.jpg");
    police = TTF_OpenFont("bananas.ttf", 40);
    police2 = TTF_OpenFont("angelina.ttf", 65);
    solid = TTF_RenderText_Solid(police, "- Qui cest lui", couleurNoire);
    shaded = TTF_RenderText_Shaded(police, "- Joussipa, mais je le sens pas ce type", couleurNoire, couleurVerte);
    blended = TTF_RenderText_Blended(police, "Viens viens, que chti difonce!", couleurNoire); //APPAREMMENT PAS DE '!' DANS babanas
    TTF_SetFontStyle(police, TTF_STYLE_ITALIC | TTF_STYLE_BOLD);
    //INITIALISATION DU TEMPS ET DU TEXTE
    tempsActuel = SDL_GetTicks();
    sprintf(temps,"Temps : %d", compteurNB);
    compteur = TTF_RenderText_Solid(police2, temps, couleurNoire);

    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                }
        }
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); // !!! --> EMPLACEMENT
            tempsActuel = SDL_GetTicks();
            if(tempsActuel - tempsPrecedent >= 100)
            {
                compteurNB += 100;
                sprintf(temps, "Temps : %d", compteurNB);
                SDL_FreeSurface(compteur); // !!!! ON SUPPRIME LA SURFACE PRECEDENTE

                compteur = TTF_RenderText_Solid(police2, temps, couleurNoire);
                tempsPrecedent = tempsActuel;
            }
            else
                SDL_Delay(100 - (tempsActuel - tempsPrecedent));


        SDL_BlitSurface(fond, NULL, ecran, &position);
        SDL_BlitSurface(solid, NULL, ecran, &positionSolid);
        SDL_BlitSurface(shaded, NULL, ecran, &positionShaded);
        SDL_BlitSurface(blended, NULL, ecran, &positionBlended);
        pos.x = 0;
        pos.y = ecran->h - compteur->h;
        SDL_BlitSurface(compteur, NULL, ecran, &pos);

        SDL_Flip(ecran);
    }

    SDL_FreeSurface(fond);
    SDL_FreeSurface(solid);
    SDL_FreeSurface(shaded);
    SDL_FreeSurface(blended);
    SDL_FreeSurface(compteur);
    TTF_CloseFont(police);
    TTF_CloseFont(police2);

    TTF_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}
