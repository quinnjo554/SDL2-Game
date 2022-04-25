#include <SDL.h>
#include <SDL_image.h>
#include <stack>
#include <iostream>
#include "MouseDropper.h"
#include "RenderWindow.h"
#include "Lava.hpp"



MouseDropper::MouseDropper()
{}


/*
drops objects when clicked
@param takes lava blocks 

*/
void MouseDropper::dropBlock(std::vector<Lava>* lavaBlock, SDL_Texture* blockText, SDL_Event &e, int& COLOR)
{

	int xMouse, yMouse; //mouse x and y

	//not polling for event because its in the main event pull

	switch (e.type) {
	case SDL_MOUSEMOTION:
	{

		//get the mouse state
		SDL_GetGlobalMouseState(&xMouse, &yMouse);
		std::cout << xMouse << " " << yMouse << "\n";
		
		
			xMouse = e.button.x;
			yMouse = e.button.y;
			//add to the vector every mouse state
			if (e.button.button == SDL_BUTTON_LEFT) {
				(*lavaBlock).push_back({ Vector2f(xMouse,yMouse),blockText });
				(*lavaBlock).push_back({ Vector2f(xMouse,yMouse-5),blockText });
				(*lavaBlock).push_back({ Vector2f(xMouse,yMouse-10),blockText });

			}
		

	}

	break;
	case SDL_MOUSEBUTTONUP:
		xMouse = e.button.x;
		yMouse = e.button.y;
	
		if (e.button.button == SDL_BUTTON_LEFT ) {
			(*lavaBlock).push_back({ Vector2f(xMouse,yMouse),blockText });
			(*lavaBlock).push_back({ Vector2f(xMouse,yMouse - 5),blockText });
			(*lavaBlock).push_back({ Vector2f(xMouse,yMouse - 10),blockText });
		}

		break;   
	
		
	}
	
}

/*
change block switches the color of the falling object
@ param
  Event e event passed for faster result
  int COLOR var for determining the color

*/
void MouseDropper::changeBlock(SDL_Event e,int &COLOR)
{
	//switch key type
	if (e.type == SDL_KEYDOWN) {

		switch (e.key.keysym.sym) {
			//change color if 0 is pressed
		case SDLK_0:
			COLOR = 0;
			break;
			//change color if 1 is pressed
		case SDLK_1:
			COLOR = 1;
			break;
			//change color if 2 is pressed
		case SDLK_2:
			COLOR = 2;
			break;
		
		}
	
		
	}
}
	