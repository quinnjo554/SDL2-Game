#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Math.h"
#include "RenderWindow.h"
#include "Lava.hpp"

class MouseDropper {

private:
	

public:

	MouseDropper();
    void dropBlock(std::vector<Lava>* lavaBlock, SDL_Texture* blockText, SDL_Event &e, int& COLOR);
	void changeBlock(SDL_Event e, int &COLOR);
	

};