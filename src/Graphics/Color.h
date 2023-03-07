#ifndef GRAPHICS_COLOR_H_
#define GRAPHICS_COLOR_H_

#include <stdint.h>

struct SDL_PixelFormat;

class Color
{
public:
	// Describes how pixels are formated on screen surface
	static const SDL_PixelFormat *m_format;
	static void initColorFormat(const SDL_PixelFormat *format);

	// Predefining some colors
	static Color BLACK() { return Color(0, 0, 0, 255); }
	static Color WHITE() { return Color(255, 255, 255, 255); }
	static Color BLUE() { return Color(0, 0, 255, 255); }
	static Color GREEN() { return Color(0, 255, 0, 255); }
	static Color RED() { return Color(255, 0, 0, 255); }
	static Color YELLOW() { return Color(255, 255, 0, 255); }
	static Color AQUA() { return Color(0, 255, 255, 255); }
	static Color MAGENTA() { return Color(255, 0, 255, 255); }
	static Color CYAN() { return Color(37, 240, 217, 255); }
	static Color PINK() { return Color(252, 197, 224, 255); }
	static Color ORANGE() { return Color(245, 190, 100, 255); }

	Color() :
			m_color(0)
	{
	}

	// Constructs a RGBA color
	Color(uint32_t color) :
			m_color(color)
	{
	}

	// Sets each individual RGBA to a value between 0 and 255 (uint8_t)
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	// Check if colors are the same
	bool operator==(const Color &c) const { return m_color == c.m_color; }
	bool operator!=(const Color &c) const { return !(*this == c); }

	inline uint32_t getPixelColor() const { return m_color; }

	void setRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	void setRed(uint8_t red);
	void setGreen(uint8_t green);
	void setBlue(uint8_t blue);
	void setAlpha(uint8_t alpha);

	uint8_t getRed() const;
	uint8_t getGreen() const;
	uint8_t getBlue() const;
	uint8_t getAlpha() const;

private:
	uint32_t m_color;
};

#endif /* GRAPHICS_COLOR_H_ */
