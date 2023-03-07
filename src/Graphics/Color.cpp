#include <SDL2/SDL.h>
#include "Color.h"

// Set the pixel format to nullptr
const SDL_PixelFormat *Color::m_format = nullptr;
// Initialize the pixel color format to screen surface
void Color::initColorFormat(const SDL_PixelFormat *format)
{
	Color::m_format = format;
}

// Constructor that accepts a 8 bit value for each RGBA value
Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	setRGBA(r, g, b, a);
}

// Maps the given RGBA values to a pixel format
void Color::setRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	m_color = SDL_MapRGBA(m_format, r, g, b, a);
}

// Set the color value to a 8 bit value
void Color::setRed(uint8_t red)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_color, m_format, &r, &g, &b, &a);
	setRGBA(red, g, b, a);
}

void Color::setGreen(uint8_t green)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_color, m_format, &r, &g, &b, &a);
	setRGBA(r, green, b, a);
}

void Color::setBlue(uint8_t blue)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_color, m_format, &r, &g, &b, &a);
	setRGBA(r, g, blue, a);
}

void Color::setAlpha(uint8_t alpha)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_color, m_format, &r, &g, &b, &a);
	setRGBA(r, g, b, alpha);
}

// Get the 8 bit value for each color
uint8_t Color::getRed() const
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_color, m_format, &r, &g, &b, &a);
	return r;
}

uint8_t Color::getGreen() const
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_color, m_format, &r, &g, &b, &a);
	return g;
}

uint8_t Color::getBlue() const
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_color, m_format, &r, &g, &b, &a);
	return b;
}

uint8_t Color::getAlpha() const
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_color, m_format, &r, &g, &b, &a);
	return a;
}

