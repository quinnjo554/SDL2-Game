#pragma once //makes sure stuff doesnt get copied multiple times
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Character.h"

class RenderWindow {

public:
	RenderWindow(const char* p_title, int p_w, int p_h);

	int getRefreshRate();

	SDL_Texture* loadTexture(const char* p_pathFile); //loads a texture with a given path

	void screenClear(); //clears screen

	void renderer(Character &pE); //renders any character

	void display();

	void cleanUp();//destructor
	//returns the renderer
	SDL_Renderer* getRender();
private:
	//init window and render
	SDL_Window* window = NULL; 
	SDL_Renderer* render = NULL;
};
