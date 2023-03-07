#include <SDL2/SDL.h>
#include <cassert>
#include "ScreenBuffer.h"

ScreenBuffer::ScreenBuffer() :
		m_surface(nullptr)
{

}

ScreenBuffer::ScreenBuffer(const ScreenBuffer &scBuffer)
{
	// Create a new surface for the copy
	m_surface = SDL_CreateRGBSurfaceWithFormat(0, scBuffer.m_surface->w,
			scBuffer.m_surface->h, 0, scBuffer.m_surface->format->format);
	// Copy all the pixels from another surface
	SDL_BlitSurface(scBuffer.m_surface, nullptr, m_surface, nullptr);
}

// Free the surface pointer if it exists
ScreenBuffer::~ScreenBuffer()
{
	if (m_surface)
	{
		SDL_FreeSurface(m_surface);
	}
}

void ScreenBuffer::init(uint32_t format, uint32_t width, uint32_t height)
{
	m_surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 0, format);
	clear();
}

// Clear the screen
void ScreenBuffer::clear(const Color &c)
{
	// assert that the screen exists
	assert(m_surface);
	// If it does, then fully fill the surface with a color
	if (m_surface)
	{
		SDL_FillRect(m_surface, nullptr, c.getPixelColor());
	}
}

// Overloading equality operator
ScreenBuffer& ScreenBuffer::operator=(const ScreenBuffer &scBuffer)
{
	// If the copy is equal to the original return the original
	if (this == &scBuffer)
	{
		return *this;
	}
	// Free the memory for the screen surface if it is not freed
	if (m_surface != nullptr)
	{
		SDL_FreeSurface(m_surface);
		m_surface = nullptr;
	}
	if (scBuffer.m_surface != nullptr)
	{
		// Create a new surface for the copy
		m_surface = SDL_CreateRGBSurfaceWithFormat(0, scBuffer.m_surface->w,
				scBuffer.m_surface->h, 0, scBuffer.m_surface->format->format);
		// Copy all the pixels from another surface
		SDL_BlitSurface(scBuffer.m_surface, nullptr, m_surface, nullptr);
	}

	return *this;
}

void ScreenBuffer::setPixel(const Color &color, int x, int y)
{
	// assert that the screen exists
	assert(m_surface);

	// Set up surface to access pixels
	// Bound the x, y coordinates to the max space the screen uses
	if (m_surface && (y < m_surface->h && y >= 0 && x >= 0 && x < m_surface->w))
	{
		SDL_LockSurface(m_surface);

		uint32_t *pixels = static_cast<uint32_t*>(m_surface->pixels);

		size_t index = getIndex(y, x);

		pixels[index] = color.getPixelColor();
	}

	SDL_UnlockSurface(m_surface);
}

uint32_t ScreenBuffer::getIndex(int r, int c)
{
	// assert that the screen exists
	assert(m_surface);
	// If there is a screen, get the index of that pixel
	if (m_surface)
	{
		return r * m_surface->w + c;
	}
	return 0;
}

