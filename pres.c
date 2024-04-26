#include "pres.h"

void initialiserperso(Personne *perso)
{	
	perso->image_p=IMG_Load("perso.bmp");
	perso->pos_perso.x=0;
	perso->pos_perso.y=300;
	perso->pos_perso.w=120;
	perso->pos_perso.h=120;
    perso->keystate = SDL_GetKeyState(NULL);

}

void initialiserperso2(Personne *perso)
{	
	perso->image_p=IMG_Load("perso.bmp");
	perso->pos_perso2.x=665;
	perso->pos_perso2.y=300;
	
    perso->keystate = SDL_GetKeyState(NULL);
}

void afficher_perso(SDL_Surface *screen,Personne perso)
{	
	SDL_BlitSurface(perso.image_p,NULL,screen,&perso.pos_perso);
}
void afficher_perso2(SDL_Surface *screen,Personne perso)
{	
	SDL_BlitSurface(perso.image_p,NULL,screen,&perso.pos_perso2);
}

void deplacer_perso(Personne *perso)
{	

        
                
   ///----------keystate ki nenzel  aal balssa ili feha  SDLK_UP twali 1         
if(perso->keystate[SDLK_UP])
{
if(perso->pos_perso.y>0){
                            perso->pos_perso.y=perso->pos_perso.y-2;
                            printf("la pos est y=%d et x=%d\n",perso->pos_perso.y,perso->pos_perso.x);
}
}
 ///----------keystate kif nenzel  aal blassa ili feha  SDLK_DOWN twali 1                   
if(perso->keystate[SDLK_DOWN])
{
if(perso->pos_perso.y<428){
                            perso->pos_perso.y=perso->pos_perso.y+2;
                            printf("la pos est y=%d et x=%d\n",perso->pos_perso.y,perso->pos_perso.x);
}
}
 ///----------keystate kif nenzel  aal blassa ili feha   SDLK_RIGHT twali 1   
if(perso->keystate[SDLK_RIGHT])
{
if(perso->pos_perso.x<512){
                            perso->pos_perso.x=perso->pos_perso.x+2;
                            printf("la pos est y=%d et x=%d\n",perso->pos_perso.y,perso->pos_perso.x);
}
}
///----------keystate kif nenzel  aal blssa ili feha        SDLK_LEFT twali 1 
if(perso->keystate[SDLK_LEFT])
{
if(perso->pos_perso.x>0){
                            perso->pos_perso.x=perso->pos_perso.x-2;
                            printf("la pos est y=%d et x=%d\n",perso->pos_perso.y,perso->pos_perso.x);
}
}

           
}

//------------------mm chhoose sur pers2------------------------------------
void deplacer_perso2(Personne *perso)
{	

         
              
                        
if(perso->keystate[SDLK_o])
{
if(perso->pos_perso2.y>0){
                            perso->pos_perso2.y=perso->pos_perso2.y-2;
                            printf("la pos2 est y=%d et x=%d\n",perso->pos_perso2.y,perso->pos_perso2.x);
}

}
if(perso->keystate[SDLK_l])
{
if(perso->pos_perso2.y<428){
                            perso->pos_perso2.y=perso->pos_perso2.y+2;
                            printf("la pos2 est y=%d et x=%d\n",perso->pos_perso2.y,perso->pos_perso2.x);
}
}
if(perso->keystate[SDLK_m])
{
if(perso->pos_perso2.x<1241){
                            perso->pos_perso2.x=perso->pos_perso2.x+2;
                            printf("la pos2 est y=%d et x=%d\n",perso->pos_perso2.y,perso->pos_perso2.x);
}
}
if(perso->keystate[SDLK_k])
{
if(perso->pos_perso2.x>665){
                            perso->pos_perso2.x=perso->pos_perso2.x-2;
                            printf("la pos2 est y=%d et x=%d\n",perso->pos_perso2.y,perso->pos_perso2.x);
}
}
                       
            
}


void free_perso(Personne perso)
{
	SDL_FreeSurface(perso.image_p);
}















