#include "drawable.h"
#include <SDL.h>
#include <tuple>
#include <map>
#include <SDL_image.h>
#include <iostream>
using namespace Drawables;
using namespace std;

map<colors,tuple<int,int,int>> Drawables::color_map = { 
        {colors::red, make_tuple(255,0,0)}, 
        
        {colors::blue, make_tuple(0,255,0)}, 

        {colors::green, make_tuple(0,0,255)}
        
        };

void Player::draw(SDL_Renderer* renderer) {

/*
int r,g,b;
tie(r, g, b) = color_map.at(colors::red);

SDL_SetRenderDrawColor(renderer,r,g,b,255);
*/
SDL_Rect body{posx,posy,256,256};
SDL_Rect anim{(animationstage %5)*256,0,256,256};
if(picture == NULL){
picture = IMG_LoadTexture(renderer, "assets/runfast.png");

}


SDL_RenderClear(renderer);
SDL_RenderCopy(renderer, picture, &anim, &body);

};

void Player::setStage(int anim){
        animationstage = anim;
};

void Player::setTime(Uint32 time){
        lastupdate = time;
};

Uint32 Player::getUpdate(){
        return lastupdate;
};

int Player::getStage(){
        return animationstage;
};



