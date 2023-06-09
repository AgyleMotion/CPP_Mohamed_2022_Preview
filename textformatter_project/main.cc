#include <iostream>
#include "font.hh"
#include "font_face.hh"
#include "bitmap.hh"
#include "color.hh"
#include "bound_box.hh"
#include "glyph.hh"
using namespace std; 


// we are not implementing this yet, but at least it should compile!
// note: this function is not called, so it does not have to work!
/*
void test_text() {
  const font_face fonts("font.conf"); // load up different fonts(face, size)
  const font* default_font = fonts.get("Helvetica", 20);
  const font* big = fonts.get("Helvetica", 28);
  const font* small = fonts.get("Helvetica", 12);
  bitmap bm(512, 512);
  bound_box b = bm.bounds().inset(10);
  bm.rect(10,10,bm.width() - 20, bm.height() - 20, color::WHITE);
  float x = 11, y = 30; // start of text
}
*/

void test_basic_drawing() {
  bitmap bm(512, 512);
  bm.horiz_line(10, 200, 100, color::RED);
  bm.vert_line(30, 100, 300, color::BLUE);
  bm.rect(100,150, 50,25, color::GREEN);
  bm.fill_rect(100,250,50,25, color::YELLOW);
  bm.line(10, 10, 100, 100, color::PINK); // Diagonal line 
  bm.save("draw.webp"); //see https://developers.google.com/speed/webp/docs/api
}

int main() {

  cout << "Hellooo"<<endl;
  test_basic_drawing();
}
