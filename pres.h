#ifndef PERS_H_INCLUDED
#define PERS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <stdbool.h>



typedef struct
{
  	SDL_Surface *image_p;

  	SDL_Rect pos_perso;
  	SDL_Rect pos_perso2;
    Uint8 *keystate; // kima tableau fih les buttons de clavier  o kif nenzil ala lettre donne 1 , sinon 0

}Personne;



//-----------------les entetes---------------------------------------------------

//--initialisation  de perso 1-----------
void initialiserperso(Personne *perso);

//----------initialisation de perso 2------------------
void initialiserperso2(Personne *perso);

//---------------deplacement d'un perso1-------------------
void deplacer_perso(Personne *perso);
//---------------deplacement d'un perso1-------------------
void deplacer_perso2(Personne *perso);
//-----------affichage  de pers 1 et 2-----------------------
void afficher_perso(SDL_Surface *screen,Personne perso);
void afficher_perso2(SDL_Surface *screen,Personne perso);

//-----------------liberation de perso--------------------------
void free_perso(Personne perso);








#endif
