#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Character.h"
#include "RenderWindow.h"
#ifndef Lava_HEADER
#define Lava_HEADER


class Lava : public Character {
public:
//constructor
Lava(Vector2f p_pos, SDL_Texture* p_text);


 void move(SDL_Event event);

 //this moves the Blocks and switches color
 void moved(int& COLOR);

 Vector2f& getPos();

 SDL_Rect getCurrentFrame();
 //returns the texture pointer
 SDL_Texture* getText();

 //will be used for adding collision 
 bool checkCollision(SDL_Rect a, SDL_Rect b);
 
 

 

private:

	Vector2f pos; 

	SDL_Rect PCurrentFrame;

	SDL_Texture* text;
	
	int mVelX, mVelY;

	//blocks collision boxes
	SDL_Rect mCollider;

  
	
};

#endif
