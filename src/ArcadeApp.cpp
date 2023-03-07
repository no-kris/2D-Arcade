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

//Vec2D myVec(5, 4);
//Vec2D myOtherVec(4, 5);
//
//std::cout << myVec;
//
//Vec2D r = myVec + myOtherVec;
//
//std::cout << r;
//
//std::cout << myVec - myOtherVec;
//
//std::cout << "Magnitude: " << myVec.magnitude() << '\n';
//
//std::cout << "Normalize: " << myVec.normalize() << '\n';
//
//std::cout << "Distance: " << myVec.distance(myOtherVec) << '\n';
//
//std::cout << "Dot: " << myVec.dot(myOtherVec) << '\n';
//
//std::cout << "Projection: " << myVec.projectTo(myOtherVec) << '\n';
//
//std::cout << "Angle: " << myVec.angle(myOtherVec) << '\n';
//
//std::cout << "Reflection: " << myVec.reflect(myVec) << '\n';
//
//std::cout << "Rotation: " << myVec.rotate(30) << '\n';
