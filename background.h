#ifndef BACKGROUND_H_INCLUDE
#define BACKGROUND_H_INCLUDE
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "pres.h"
#define SCREEN_W 1360
#define SCREEN_H 765

//-----------------------structure de texte -------------------------------------
typedef struct struct_text{
 TTF_Font *font;
 SDL_Color color;
 SDL_Surface* text;
 SDL_Rect postext;
}Text;
//---------------------------------structure back---------------------------------
typedef struct
{
	SDL_Surface *imgback;
	SDL_Rect positionbackground;
	SDL_Rect positionbackground2;
	SDL_Rect camera2;//pour le scrolling / pour afficher a chaque fois une partie du backg
	SDL_Rect camera22;//pour le scrolling
        Mix_Music *son1;
	SDL_Surface *image_bats;  
	SDL_Rect pos_image_bats;
	SDL_Rect single_bats;	
	int bats_f;
        int num_score;
	Text score; 


}background;
void initBack2(background *b); 
void initBack22(background *b); 
void afficheBack2 (background b, SDL_Surface *ecran);
void afficheBack22 (background b, SDL_Surface *ecran);
void scrolling (background *b,int direction,int pas);
void scrolling2 (background *b,int direction,int pas);
void animerBackground(background *b);
void displaybatsffaFWa(background b,SDL_Surface *ecran);
void afficher(background b,SDL_Surface *ecran);


#endif  
