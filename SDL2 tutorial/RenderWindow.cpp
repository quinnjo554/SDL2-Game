#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "RenderWindow.h"


RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
{

	//inits window 
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_w, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		//if window fails to init present the error to the user
		std::cout << "Window failed to init. Error: " << SDL_GetError() << "\n";
	}

	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);

}

int RenderWindow::getRefreshRate()
{
	int displayIndex = SDL_GetWindowDisplayIndex(window);

	SDL_DisplayMode mode;
	SDL_GetDisplayMode(displayIndex, 0, &mode);
	return mode.refresh_rate;
}


SDL_Texture* RenderWindow::loadTexture(const char* p_pathFile)
{

	//init texture
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(render, p_pathFile);

	

	if (texture == NULL) {
		std::cout << "Failed to load Texture: Error " << SDL_GetError << "\n";
	}

	return texture;
}

void RenderWindow::cleanUp() 
{
	SDL_DestroyWindow(window);
}

SDL_Renderer* RenderWindow::getRender()
{
	return render;
}

void RenderWindow::screenClear() 
{
	SDL_RenderClear(render);
}

//if you need to render other classes add here
void RenderWindow::renderer(Character& e) //passing by refrence makes it much faster
{
	SDL_Rect source;
	source.x = e.getCurrentFrame().x;
	source.y = e.getCurrentFrame().y;
	source.w = e.getCurrentFrame().w;
	source.h = e.getCurrentFrame().h;

	SDL_Rect destination;
	destination.x = e.getPos().x;
	destination.y = e.getPos().y; // multiply by a scale for zoom: all by scale
	destination.w = e.getCurrentFrame().w /2;
	destination.h = e.getCurrentFrame().h /2;

	SDL_RenderCopy(render, e.getText() , &source, &destination);
}

void RenderWindow::display() {
	SDL_RenderPresent(render);
}








