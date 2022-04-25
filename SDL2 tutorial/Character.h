#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "Math.h"


//interface for polymorphism
class Character
{
private:

public:
	//moves
	virtual void move(SDL_Event event) = 0;
	virtual Vector2f& getPos() = 0;
	virtual SDL_Rect getCurrentFrame() = 0;
	//returns the texture pointer
	virtual SDL_Texture* getText() = 0;
	
	

};

