#pragma once
#include "Stroke.cpp"
#include <vector>
#include <SDL.h>
class Stroke{
private:
    std::vector<SDL_Point> points;
};