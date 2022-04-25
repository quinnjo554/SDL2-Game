#include "SDL.h"
#include "SDL_image.h"
#undef main
#include <iostream>
#include <vector>
#include <stack>
#include "RenderWindow.h"
#include "MoveablePlayer.h"
#include "Utills.h"
#include "MouseDropper.h" 
#include "Lava.hpp"
//DONT USE SDL VSYNC

int main(int argc, char* args[]) {

	//init
	const float timeStep = 0.01f; // time advanced per frame this is 100 time per sec
	float accumulator = 0.0f; // limits updates per sec once threshold is full one time step is passed
	float currenttime = Utils::hireTimeInSeconds(); 
	bool gameRunning = true;
	int COLOR = 0;
	int isHeld = 0;
	int xMouse, yMouse;
	std::vector<Lava> lavaBlocks;
	//window
	RenderWindow window("GAME v1.0", 800, 800);
	//lava block texture
	SDL_Texture* lava = window.loadTexture("Gfx/red.png");
	//water block texture
	 SDL_Texture* water = window.loadTexture("Gfx/waterBlock.png");
	 //sand texture
	 SDL_Texture* sand = window.loadTexture("Gfx/sandBlock.png");
	//moveable texture
	SDL_Texture* playerBlock = window.loadTexture("Gfx/orangeBlock.png");
	//background texture
	SDL_Texture* cave = window.loadTexture("Gfx/background.png");

	SDL_Event event;
	MoveablePlayer backgroundImage(Vector2f(800, 800), cave);
	Lava lavaBlock(Vector2f(200,200),lava);
	
	SDL_Rect wall;
	wall.x = 700;
	wall.y = 700;
	wall.h = 400;
	wall.w = 400;

	std::cout<< window.getRefreshRate() << "\n";

	MoveablePlayer player(Vector2f(150,150), playerBlock);
	MouseDropper b; //shouldnt render untill pressed
	
		
	    //deletes memory
	std::vector<MoveablePlayer>entities = { MoveablePlayer(Vector2f(150,150), lava) };
		{

		MoveablePlayer texture(Vector2f(0, 300), lava);
		entities.push_back(texture);
		
		}

	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		//sdl init reurns 0 if everything is good so this if for the error
		std::cout << "SDL_INIT HAS FAILED: " << SDL_GetError() << std::endl; //get error returns the last error that has occured
	}
	if (!IMG_Init(IMG_INIT_PNG)) { // if you want to change file type do it here
		std::cout << "IMG_init HAS FAILED: " << SDL_GetError() << std::endl;
	}


	while (gameRunning) {

		int startTicks = SDL_GetTicks();
		float newTime = Utils::hireTimeInSeconds(); 
		float frameTime = newTime - currenttime;
		currenttime = newTime;
		accumulator += frameTime;


		while (accumulator >= timeStep) {
			//update
			while (SDL_PollEvent(&event)) {
				//ends game if program ends
				if (event.type == SDL_QUIT) {
					gameRunning = false;
				}
				//pulls for mouse event
				b.changeBlock(event,COLOR);
				if (COLOR == 0) {
					 b.dropBlock(&lavaBlocks, lava, event,COLOR);
				}
			    if (COLOR == 1) {
					b.dropBlock(&lavaBlocks, water, event, COLOR);
					
				}
				

				player.move(event);
				
			}		
				accumulator -= timeStep;
		}
			
			const float alpha = accumulator / timeStep; //alpha is the left over from time step

			//render objects
			window.screenClear(); // clears the screen of all stuff
			//renders background
			SDL_RenderCopy(window.getRender(), cave, NULL, NULL);

			for (Character& i : entities) {  // loop reders player moveable texture
				window.renderer(player);
			}
			
			for (int i = 0; i < lavaBlocks.size(); i++) { //renders lava blocks
				window.renderer(lavaBlocks[ i ]);
				//move the block down
				lavaBlocks[ i ].moved(COLOR); 
			}
			
			
			
			window.display();		
			
			//vSync
			int frameTicks = SDL_GetTicks() - startTicks;

			if (frameTicks < 1000 / window.getRefreshRate()) {
				SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
			}

		}

	
	
	window.cleanUp();
	SDL_Quit();
	return 0;
}