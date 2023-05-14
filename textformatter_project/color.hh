#ifndef COLOR__HH__
#define COLOR__HH__

#include <ostream>

class color {
private:
public:
   uint32_t val;
  color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {}
  color(uint32_t rgba) : val(rgba) {}
  color() : val(0) {}
  color darker() const ; 
  color lighter() const;
	static color RED, GREEN, BLUE, WHITE, BLACK, YELLOW, PINK;
  friend std::ostream& operator <<(std::ostream& s, const color c);
};

#endif
