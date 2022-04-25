#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Math.h"
#include "Character.h"

class MoveablePlayer : public Character
{

private:

	Vector2f pos; // vector class technically
	SDL_Rect currentFrame;
	SDL_Texture* text; //the memory location for texture
	

public:

	MoveablePlayer(Vector2f pPos, SDL_Texture* pText);
	Vector2f& getPos();
	SDL_Rect getCurrentFrame();
	SDL_Texture* getText();
	//moves the charatcer block 
	void move(SDL_Event f);
	
};