#ifndef GRAPHICS_SCREENBUFFER_H_
#define GRAPHICS_SCREENBUFFER_H_

#include "Color.h"

struct SDL_Surface;

class ScreenBuffer
{
public:
	ScreenBuffer();
	ScreenBuffer(const ScreenBuffer& scBuffer);
	virtual ~ScreenBuffer();

	void init(uint32_t format, uint32_t widht, uint32_t height);

	inline SDL_Surface *getSurface() { return m_surface; }

	void clear(const Color& c = Color::BLACK());

	void setPixel(const Color& color, int x, int y);

	ScreenBuffer& operator=(const ScreenBuffer& scBuffer);

private:
	SDL_Surface *m_surface;
	uint32_t getIndex(int r, int c);
};

#endif /* GRAPHICS_SCREENBUFFER_H_ */
