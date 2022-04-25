#include "Lava.hpp"

Lava::Lava(Vector2f p_pos, SDL_Texture* p_text) :pos(p_pos), text(p_text)
{

	PCurrentFrame.x = 0;
	PCurrentFrame.y = 0;
	PCurrentFrame.w = 10;
	PCurrentFrame.h = 10;

	mCollider.w = 10; 
	mCollider.h = 10;
	
}
void Lava::move(SDL_Event event){ 
	//basic move method
	float gravity = 3.3;
	pos.y += gravity;

	if (pos.y > 780) {
		pos.y = 780;
	}
	
}

void Lava::moved(int &COLOR)
{
	if (COLOR == 0) {
		//sets gravity
		float gravity = 3.3;
		pos.y += gravity;
		//collision
		if (pos.y > 795) {
			pos.y = 795;
		}
	}
	
	if (COLOR == 1) {
		//sets gravity
		float gravity = 3.3;
		pos.y += gravity;
		//collision
		if (pos.y > 795) {
			pos.y = 795;
		}
	}
	
	if (COLOR == 2) {
		//sets gravity
		float gravity = 3.3;
		pos.y += gravity;
		//collision
		if (pos.y > 795) {
			pos.y = 795;
		}
	}
}

Vector2f& Lava::getPos()
{
	return pos;
}

SDL_Rect Lava::getCurrentFrame()
{
	return this->PCurrentFrame;
	
}



SDL_Texture* Lava::getText()
{
	return text;
}

