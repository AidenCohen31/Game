
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
        int animationstage;
        Uint32 lastupdate;
        virtual void draw(SDL_Renderer* renderer){
        };
        virtual int getStage(){};
        virtual Uint32 getUpdate(){};
        virtual void setStage(int anim){};
        virtual void setTime(Uint32 update){};
};


class Player : public Drawable{

    public:
        int posx = 50;
        int posy = 50;
        int animationstage = 0;
        Uint32 lastupdate;
        SDL_Texture* picture = NULL;
        void draw(SDL_Renderer* renderer) override;
        Uint32 getUpdate() override;
        int getStage() override;
        void setStage(int anim) override;
        void setTime(Uint32 update) override;
};
}