
#pragma once
#include <map>
#include <tuple>
#include <SDL.h>
#include <iostream>
#include <fstream>
using namespace std;
namespace Drawables{


    enum class colors : short{red, blue, green};
    extern map<colors,tuple<int,int,int>> color_map;

class Drawable{
    public:
        virtual void draw(SDL_Renderer* renderer){
        }

};


class Player : public Drawable{

    public:
        void draw(SDL_Renderer* renderer) override;
        int posx = 50;
        int posy = 50;
        double animationstage = 0;
        SDL_Texture* picture = NULL;
};
}