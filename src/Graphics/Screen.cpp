#include <iostream>
#include <SDL2/SDL.h>
#include <cassert>
#include "Screen.h"

Screen::Screen() :
		m_width(0), m_height(0), m_ptrWindow(nullptr), m_ptrSurface(nullptr)
{
}

// Destroy the SDL window and clean up any resources that were used
Screen::~Screen()
{
	if (m_ptrWindow)
	{
		SDL_DestroyWindow(m_ptrWindow);
		m_ptrWindow = nullptr;
	}
	SDL_Quit();
}

// Initialize SDL library and pass in dimensions for the window
SDL_Window* Screen::init(uint32_t w, uint32_t h, uint32_t mag)
{
	// If initialize fails
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "Error Init failed\n";
		return nullptr;
	}
	// Set the screen class member variables to the passed in dimensions
	m_width = w;
	m_height = h;

	// Create the window
	m_ptrWindow = SDL_CreateWindow("Arcade",
									SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED,
									m_width * mag, m_height * mag,
									SDL_WINDOW_SHOWN);

	if (m_ptrWindow)
	{
		// Create the window surface to draw pixels to
		m_ptrSurface = SDL_GetWindowSurface(m_ptrWindow);

		SDL_PixelFormat *ptrPixelFormat = m_ptrSurface->format;

		Color::initColorFormat(ptrPixelFormat);

		m_clearColor = Color::BLACK();

		// Make the initial screen black
		m_backBuffer.init(ptrPixelFormat->format, m_width, m_height);

		m_backBuffer.clear(m_clearColor);
	}

	return m_ptrWindow;
}

// Block transfer, i.e. copy, the contents of one screen to another
void Screen::swap()
{
	assert(m_ptrWindow);
	if (m_ptrWindow)
	{
		clearScreen();

		SDL_BlitScaled(m_backBuffer.getSurface(), nullptr, m_ptrSurface,
				nullptr);

		SDL_UpdateWindowSurface(m_ptrWindow);

		m_backBuffer.clear(m_clearColor);
	}
}

// Drawing to the screen
// Both draw functions set a specific pixel on the screen to a color
void Screen::draw(int x, int y, const Color &color)
{
	// assert the window exists
	assert(m_ptrWindow);
	if (m_ptrWindow)
	{
		m_backBuffer.setPixel(color, x, y);
	}
}

void Screen::draw(const Vec2D &point, const Color &color)
{
	assert(m_ptrWindow);
	if (m_ptrWindow)
	{
		m_backBuffer.setPixel(color, point.getX(), point.getY());
	}
}

/*
 * An implementation of Bresenham's line algorithm
 *
 * Idea:
 * When a line is between two pixels
 * find the distances between the line and the two pixels
 * use the pixel with the shortest distance
 *
 * steps:
 * Starting from x0, increment by x + 1 until x1
 * decide whether to increment y or not based on distance
 * an error term will determine whether to round up or down the next pixel
 */

void Screen::draw(const Line& line, const Color& color)
{
	// Make sure the window exists
	assert(m_ptrWindow);
	if (m_ptrWindow)
	{
		// Get the starting and ending points for the line
		int x0 = std::round(line.getP0().getX());
		int y0 = std::round(line.getP0().getY());
		int x1 = std::round(line.getP1().getX());
		int y1 = std::round(line.getP1().getY());

		// Calculate the difference between x1 and x0 and y1 and y0
		int dx = x1 - x0;
		int dy = y1 - y0;

		// determine whether to increment x and y by 1 or -1, get the sign
		signed const short incX = (dx > 0) - (dx < 0);
		signed const short incY = (dy > 0) - (dy < 0);

		// get the absolute value of dx and dy
		dx = std::abs(dx) * 2;
		dy = std::abs(dy) * 2;

		// draw the first pixel at whatever position has been passed
		draw(x0, y0, color);

		// to start drawing from the x axis
		if(dx >= dy)
		{
			// get an error term
			int error = dy - dx / 2;

			// keep drawing until x0 is equal to x1
			while(x0 != x1)
			{
				if (error >= 0)
				{
					error -= dx;
					y0 += incY;
				}

				error += dy;
				x0 += incX;

				draw(x0, y0, color);
			}
		}
		else
		{
			int error = dx - dy / 2;

			while(y0 != y1)
			{
				if (error >= 0)
				{
					error -= dy;
					x0 += incX;
				}

				error += dx;
				y0 += incY;

				draw(x0, y0, color);
			}
		}
	}
}

// Fill the screen black
void Screen::clearScreen()
{
	assert(m_ptrWindow);
	if (m_ptrWindow)
	{
		// Fills the whole surface with a specific color
		SDL_FillRect(m_ptrSurface, nullptr, m_clearColor.getPixelColor());
	}
}
