/*This source code copyrighted by Lazy Foo' Productions 2004-2023
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;

//Key press surfaces constants
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture* loadTexture(std::string path);

int main(int argc, char* args[]);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

//The image we show when we close the window
SDL_Surface* gXOut = NULL;

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

//Current displayed texture
SDL_Texture* gTexture = NULL;


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialise PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialise! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;
	
	//Load PNG texture
	gTexture = loadTexture("09_the_viewport/viewport.png");
	if (gTexture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	return success;
}

void close()
{
	//Free loaded image
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	//Destroy Window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* loadedTexture = IMG_LoadTexture(gRenderer, path.c_str());

	if (loadedTexture == NULL)
	{
		printf("Unable to load image %s SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}

	return loadedTexture;

}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			// While application is running
			while (!quit)
			{
				// Handle Events on Queue
				while (SDL_PollEvent(&e) != 0)
				{
					// User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}

					//Top left corner viewport
					SDL_Rect topLeftViewport;
					topLeftViewport.x = 0;
					topLeftViewport.y = 0;
					topLeftViewport.w = SCREEN_WIDTH / 2;
					topLeftViewport.h = SCREEN_HEIGHT / 2;
					SDL_RenderSetViewport(gRenderer, &topLeftViewport);

					//Render texture to screen
					SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

					//Top right viewport
					SDL_Rect topRightViewport;
					topRightViewport.x = SCREEN_WIDTH / 2;
					topRightViewport.y = 0;
					topRightViewport.w = SCREEN_WIDTH / 2;
					topRightViewport.h = SCREEN_HEIGHT / 2;
					SDL_RenderSetViewport(gRenderer, &topRightViewport);

					//Render texture to screen
					SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

					//Bottom viewport
					SDL_Rect bottomViewport;
					bottomViewport.x = 0;
					bottomViewport.y = SCREEN_HEIGHT / 2;
					bottomViewport.w = SCREEN_WIDTH;
					bottomViewport.h = SCREEN_HEIGHT / 2;
					SDL_RenderSetViewport(gRenderer, &bottomViewport);

					//Render texture to screen
					SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

					//Update screen
					SDL_RenderPresent(gRenderer);
				}
			}

			//Hack to get window to stay up
			while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
