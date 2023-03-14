#ifndef GRAPHICS_SCREEN_H_
#define GRAPHICS_SCREEN_H_

#include <stdint.h>
#include "ScreenBuffer.h"
#include "Color.h"
#include "Vec2D.h"
#include "Line.h"

struct SDL_Window;
struct SDL_Surface;

class Screen
{
public:
	Screen();
	// do not allow for copying the screen
	Screen(const Screen& cpScreen) = delete;
	Screen& operator=(const Screen& cpScreen) = delete;
	virtual ~Screen();

	SDL_Window *init(uint32_t w, uint32_t h, uint32_t mag);
	void swap();

	inline void setClearColor(const Color& clearColor) { m_clearColor = clearColor; }
	inline uint32_t width() const { return m_width; }
	inline uint32_t height() const { return m_height; }

	// Drawing to the screen
	void draw(int x, int y, const Color& color);
	void draw(const Vec2D& point, const Color& color);
	void drawBresenhams(const Line& line, const Color& color);

private:
	void clearScreen();

	ScreenBuffer m_backBuffer;
	Color m_clearColor;

	uint32_t m_width;
	uint32_t m_height;

	SDL_Window *m_ptrWindow;
	SDL_Surface *m_ptrSurface;
};

#endif /* GRAPHICS_SCREEN_H_ */
