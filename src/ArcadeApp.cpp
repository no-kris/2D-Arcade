#include <iostream>
#include <iomanip>
#include <SDL2/SDL.h>
#include "Vec2D.h"
#include "Utils.h"
#include "Color.h"
#include "Screen.h"
#include "Line.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 3;

int main(int argc, char **argv)
{
	Screen screen;

	screen.init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
	Line line = {Vec2D(SCREEN_WIDTH / 2, 0), Vec2D(SCREEN_WIDTH / 2, SCREEN_HEIGHT)};
	screen.draw(line, Color::GREEN());
	screen.swap();

	SDL_Event sdlEvent;
	bool running = true;

	while (running)
	{
		while (SDL_PollEvent(&sdlEvent))
		{
			if (sdlEvent.type == SDL_QUIT)
			{
				running = false;
			}
		}
	}

	return 0;
}
