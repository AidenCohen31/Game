#include <SDL.h>
#include <iostream>
#include <fstream>
#include <SDL_image.h>
#include <queue>
#include "drawable.h" 
#include <ctime>
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_FPS 60;

using namespace std;
using namespace Drawables;

SDL_Window* initWindow(){
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    throw "Window Not Able to be Initialized";
  }
  if(!IMG_Init(IMG_INIT_PNG)){
    throw "SDL Image not able to be initialized";
  }

  SDL_Window* window = SDL_CreateWindow(
			    "Game",
			    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			    SCREEN_WIDTH, SCREEN_HEIGHT,
			    SDL_WINDOW_SHOWN
			    );
  
  if(window == NULL){
    throw "Not able to create window";
  }

   return window;     
}

void draw(queue<Drawable*> drawq, SDL_Window* window, SDL_Renderer* renderer){ 
  SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF);
  SDL_RenderClear(renderer);
for(int i = 0; i< drawq.size(); i++){
  drawq.front()->draw(renderer);
  drawq.pop();
}
  SDL_RenderPresent(renderer);

}


int main(int argc, char* args[]) {

  SDL_Window* window = initWindow();
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
  SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
  SDL_Texture* screenTexture = SDL_CreateTextureFromSurface(renderer,screenSurface);
  SDL_FreeSurface(screenSurface);
  SDL_RenderCopy(renderer, screenTexture, NULL,NULL);
  SDL_RenderPresent(renderer);
  SDL_UpdateWindowSurface(window);

  queue<Drawable*> drawq;
  Player *player = new Player();
  drawq.push(player);
  draw(drawq,window,renderer);
  SDL_Event event;
  Uint32 time = SDL_GetTicks()/1000;
while(true){
while (SDL_PollEvent(&event))
{
  player->animationstage+=.5;

	if(event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_a)
		{
      player->posx-=10;
      drawq.push(player);
      draw(drawq,window,renderer);
		}
    else if(event.key.keysym.sym == SDLK_w)
    {
       player->posy-=10;
       drawq.push(player);
      draw(drawq,window,renderer);
    }
    else if(event.key.keysym.sym == SDLK_d)
    {
       player->posx+=10;
       drawq.push(player);
      draw(drawq,window,renderer);
    }
       else if(event.key.keysym.sym == SDLK_s)
    {
       player->posy+=10;
       drawq.push(player);
      draw(drawq,window,renderer);
    }
    
  }
    if(event.type  == SDL_WINDOWEVENT){
      ofstream myfile;
      myfile.open("example.txt");
      myfile << "window";
      myfile.close();

      if(event.window.event == SDL_WINDOWEVENT_CLOSE){
         SDL_DestroyWindow(window);
         SDL_Quit();
         IMG_Quit();
         SDL_DestroyRenderer(renderer);
         return 0;
      }

    }
	}
}

 
  return 0;

}



