#include "background.h"
#include "pres.h"
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>

void initBack2 (background *b)
{
//background2
b->imgback =IMG_Load("back.png");
b->positionbackground.x=0;
b->positionbackground.y=0;
//b->positionbackground.w=SCREEN_W/2;
//b->positionbackground.y=SCREEN_H;
//camera2
b->camera2.x=0;
b->camera2.y=300;
b->camera2.w=SCREEN_W; 
b->camera2.h=SCREEN_H;
//musique

        b->son1=Mix_LoadMUS("son.mp3"); //Chargement de la musique
        b->son1=Mix_LoadMUS("musique.mp3"); //Chargement de la musique
	b->image_bats=IMG_Load("bats.png");  
	b->pos_image_bats.x=500;
	b->pos_image_bats.y=100;
	b->single_bats.w=100;
	b->single_bats.h=100;
	b->single_bats.x=0;
	b->single_bats.y=0;
	b->bats_f=0;
//------------------------------------------font--------------------------
TTF_Init();
b->score.font=TTF_OpenFont("arial.ttf",50);

b->score.color=(SDL_Color) {0,255,0};
b->score.text=TTF_RenderText_Blended(b->score.font,"score1 : 0",b->score.color);




b->score.postext.x=100;
b->score.postext.y=0;


//--------------------------initialisation de  score -----------------
b->num_score=0;



}




void initBack22 (background *b)
{
//-------------------------background2
b->imgback =IMG_Load("back.png");
b->positionbackground2.x=SCREEN_W/2;
b->positionbackground2.y=0;

//-----------------------camera2    va afficher a chaque fois une partie du backg------------
b->camera22.x=0;
b->camera22.y=300;
b->camera22.w=SCREEN_W; 
b->camera22.h=SCREEN_H;

b->image_bats=IMG_Load("bats.png");  
//x=500 va etre dans la partie 2 du bckg (avec patrage)--------------------------
	b->pos_image_bats.x=800;
	b->pos_image_bats.y=100;
	b->single_bats.w=100;
	b->single_bats.h=100;
	b->single_bats.x=0;
	b->single_bats.y=0;
	b->bats_f=0;
TTF_Init();
b->score.font=TTF_OpenFont("arial.ttf",50);

b->score.color=(SDL_Color) {0,255,0};
b->score.text=TTF_RenderText_Blended(b->score.font,"score2: 0",b->score.color);




b->score.postext.x=800;
b->score.postext.y=0;



b->num_score=0;




}

void afficheBack22(background b, SDL_Surface *ecran)
{
 

char ch_score[12];
//--------------la fonction sprintf va ecrire -------------------------
 sprintf(ch_score,"score 2: %d",b.num_score);
b.score.text=TTF_RenderText_Blended(b.score.font,ch_score,b.score.color);

SDL_BlitSurface(b.imgback ,&b.camera22,ecran,&b.positionbackground2);

displaybatsffaFWa(b,ecran);
  SDL_BlitSurface(b.score.text,NULL,ecran,&b.score.postext);

}


void afficheBack2(background b, SDL_Surface *ecran)
{
 

char ch_score[12];
 sprintf(ch_score,"score 1: %d",b.num_score);

b.score.text=TTF_RenderText_Blended(b.score.font,ch_score,b.score.color);


SDL_BlitSurface(b.imgback ,&b.camera2,ecran,&b.positionbackground);//&b.camera
displaybatsffaFWa(b,ecran);
  SDL_BlitSurface(b.score.text,NULL,ecran,&b.score.postext);

}

//----------------fonction scrolling permet de : quand le personnage avance, le score va etre de plus en plus grand ---------
void scrolling (background *b,int direction,int pas)

{

if (direction ==0){//a droite du backg1  


	b->camera2.x+= pas;
        b->num_score+=1;
	
        }
else if (direction ==1){//a gauche du backg1          

	b->camera2.x-=pas; 
        b->num_score+=1;
	}
 
else if (direction ==2){//en haut du backg 1 et 2


         b->camera2.y-= pas;
        b->num_score+=1;
	}
else if (direction ==3){//         


	 b->camera2.y+= pas;
        b->num_score+=1;
	 }

}

void scrolling2 (background *b,int direction,int pas)
{

if (direction ==0){//a droite du backg1 


	b->camera22.x+= pas;
        b->num_score+=1;
	
        }
else if (direction ==1){//a gauche du backg1           


	b->camera22.x-=pas; 
        b->num_score+=1;
	}
 
else if (direction ==2){//en haut du backg 1 et 2 


         b->camera22.y-= pas;
        b->num_score+=1;
	}
else if (direction ==3){//         


	 b->camera22.y+= pas;
        b->num_score+=1;
	 }

}

void displaybatsffaFWa(background b,SDL_Surface *ecran){
			
 		SDL_BlitSurface(b.image_bats,&(b.single_bats), ecran, &b.pos_image_bats);
}
void animerBackground(background *b){//annimation de l'image
		 	
	if (b->bats_f >=0 && b->bats_f<6) {
	b->single_bats.x=b->bats_f * b->single_bats.w;
	b->bats_f++;
	}
	
	if ( b->bats_f == 6) {
	b->single_bats.x=b->bats_f * b->single_bats.w;
	b->bats_f=0;//a partir de 6 on repete lanimation 
	}
 
	 
}









