#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "MoveablePlayer.h"
#include "RenderWindow.h"

//make this smoother

MoveablePlayer::MoveablePlayer(Vector2f pPos, SDL_Texture* pText)
	: pos(pPos), text(pText)
{

	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 450; // 32
	currentFrame.h = 500; // 32

}

Vector2f& MoveablePlayer::getPos()
{
	return pos;
}


SDL_Rect MoveablePlayer::getCurrentFrame()
{
	return this->currentFrame;
}

SDL_Texture* MoveablePlayer::getText()
{
	return this->text;
}


//Moves player blocks
void MoveablePlayer::move(SDL_Event f) {
	

		if (f.type == SDL_KEYDOWN) {

			switch (f.key.keysym.sym) {
				//left key
			case SDLK_LEFT:
				if (pos.x < -150) {
					pos.x = 800; 
				}
				else
					pos.x -= 10;
				break;
				//right key
			case SDLK_RIGHT:
				if (pos.x > 780) { 
					pos.x = -100;
				}
				else
					pos.x += 10;
				break;
				//up key
			case SDLK_UP:
				pos.y -= 10;
				break;
				//down key
			case SDLK_DOWN:
				pos.y += 10;
				break;

			}
		}
	}
	




