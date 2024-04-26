#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "background.h"
#include "pres.h"

int main(void)
{	int nbr_de_pas=1;
	int aller=1;
	SDL_Surface *screen=NULL;
	background bg;
	background bg2;

	Personne perso;
	Personne perso2;
	SDL_Event event;
	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	screen=SDL_SetVideoMode(1360,1200,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(screen==NULL)
	{
		printf("unable to set video mode:%s\n",SDL_GetError());
		return 1;
	}
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);

           
	initBack2(&bg);//initback
	initBack22(&bg2);//initback
	

	initialiserperso(&perso);
	initialiserperso2(&perso2);



	while (aller)
	{		
		
		
		SDL_PollEvent(&event);
     	switch(event.type)
        {
            case SDL_QUIT:
                aller = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
			case SDLK_RIGHT:
 if(bg.camera2.x<458){
			                            printf("la pos est y=%d et x=%d\n",bg.camera2.y,bg.camera2.x);
				scrolling(&bg,0,nbr_de_pas);}	//scrollingymin;	

		
					
                        break;
                        case SDLK_LEFT:
                    
           if(bg.camera2.x>0){
				scrolling(&bg,1,nbr_de_pas);}//scrolllingysar;


		 
                        break;
			 case SDLK_UP:
                            printf(" la pos est y=%d et x=%d\n",bg.camera2.y,bg.camera2.x);
			 
 if(bg.camera2.y>254){
					scrolling(&bg,2,nbr_de_pas);}//scrollingymin;
	

                        break;
 			 case SDLK_DOWN:
 			  if(bg.camera2.y<465){

					scrolling(&bg,3,nbr_de_pas);}	//scrollingymin;	
                        break;	
 			 case SDLK_a:
 			  if(bg2.camera22.y>254){
			                            printf(" la pos est y=%d et x=%d\n",bg2.camera22.y,bg2.camera22.x);
					scrolling2(&bg2,2,nbr_de_pas);}//scrollingymin;

                        break;
                        case SDLK_s:
 			  if(bg2.camera22.y<465){
			                            printf("la pos est y=%d et x=%d\n",bg2.camera22.y,bg2.camera22.x);
					scrolling2(&bg2,3,nbr_de_pas);}//scrollingymin;

                        break;
                        case SDLK_d:
 			  if(bg2.camera22.x<249){
			                            printf("la pos est y=%d et x=%d\n",bg2.camera22.y,bg2.camera22.x);
					scrolling2(&bg2,0,nbr_de_pas);}//scrollingymin;

                        break;
                        case SDLK_f:
           if(bg2.camera22.x>0){
			                            printf("main 2 la pos est y=%d et x=%d\n",bg2.camera22.y,bg2.camera22.x);
					scrolling2(&bg2,1,nbr_de_pas);}//scrollingymin;

                        break;
      		 }
      		 	
            break;

       
       
  
 	}  

                        animerBackground(&bg2);	
               		animerBackground(&bg);	
			afficheBack2(bg,screen);
			afficheBack22(bg2,screen);


			afficher_perso(screen,perso);	
			afficher_perso2(screen,perso2);	
deplacer_perso(&perso);
		deplacer_perso2(&perso2);
                 
			SDL_Flip(screen);
	}



	
	SDL_Quit();
      Mix_FreeMusic (bg.son1);
      Mix_FreeMusic (bg.son1);
 Mix_CloseAudio();

	return 1;
}
